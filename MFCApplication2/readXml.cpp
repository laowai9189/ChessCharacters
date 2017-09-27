#include "stdafx.h"
#include "readXml.h"
#include <string>
#include <iostream>
#include <AccCtrl.h>
#include <map>

#define TRANSFORM


// 是否启用map转换，建议启用
// 使用map转换的话，同一个常量字符串不会做两次转换
#define TEST_TYPE_MAP

typedef map<const char*, const char*> strmap;

class CUtf8String
{
public:
	inline CUtf8String(const char* gb2312)
	{
		m_bIsConst = true;
#ifdef TEST_TYPE_MAP
		if (m[gb2312])
		{
			m_utf8 = m[gb2312];
			return;
		}
#endif
		int buffLen = 0;
		WCHAR wbuff[5120];
		MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wbuff, 5120);
		buffLen = WideCharToMultiByte(CP_UTF8, 0, wbuff, -1, NULL, 0, 0, 0);
		m_utf8 = new char[buffLen + 1];
		WideCharToMultiByte(CP_UTF8, 0, wbuff, -1, (LPSTR)m_utf8, buffLen, 0, 0);
#ifdef TEST_TYPE_MAP
		m[gb2312] = m_utf8;
#endif
	}

	inline CUtf8String(char* gb2312)
	{
		m_bIsConst = false;
		int buffLen = 0;
		WCHAR wbuff[5120];
		MultiByteToWideChar(CP_ACP, 0, gb2312, -1, wbuff, 5120);
		buffLen = WideCharToMultiByte(CP_UTF8, 0, wbuff, -1, NULL, 0, 0, 0);
		m_utf8 = new char[buffLen + 1];
		WideCharToMultiByte(CP_UTF8, 0, wbuff, -1, (LPSTR)m_utf8, buffLen, 0, 0);
	}

	inline ~CUtf8String()
	{
#ifndef TEST_TYPE_MAP
		if (m_utf8)
		{
			delete m_utf8;
			m_utf8 = 0;
		}
#else
		if (!m_bIsConst)
		{
			if (m_utf8)
			{
				delete m_utf8;
				m_utf8 = 0;
			}
		}
#endif
	}

	inline operator char*()
	{
		return (char*)m_utf8;
	}
private:
	const char* m_utf8;
	bool m_bIsConst;
#ifdef TEST_TYPE_MAP
	static strmap m;
#endif
};

class CGb2312String
{
public:
	inline CGb2312String(const char* utf8)
	{
#ifdef TEST_TYPE_MAP
		if (m[utf8])
		{
			m_gb2312 = 0;
			m_gb2312 = m[utf8];
		}
#endif
		int buffLen = 0;
		WCHAR wbuff[5120];
		MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wbuff, 5120);
		buffLen = WideCharToMultiByte(CP_ACP, 0, wbuff, -1, NULL, 0, 0, 0);
		m_gb2312 = new char[buffLen + 1];
		WideCharToMultiByte(CP_ACP, 0, wbuff, -1, (LPSTR)m_gb2312, buffLen, 0, 0);
#ifdef TEST_TYPE_MAP
		m[utf8] = m_gb2312;
#endif
	}

	inline CGb2312String(char* utf8)
	{
#ifdef TEST_TYPE_MAP
		if (m[utf8])
		{
			m_gb2312 = 0;
			m_gb2312 = m[utf8];
		}
#endif
		int buffLen = 0;
		WCHAR wbuff[5120];
		MultiByteToWideChar(CP_UTF8, 0, utf8, -1, wbuff, 5120);
		buffLen = WideCharToMultiByte(CP_ACP, 0, wbuff, -1, NULL, 0, 0, 0);
		m_gb2312 = new char[buffLen + 1];
		WideCharToMultiByte(CP_ACP, 0, wbuff, -1, (LPSTR)m_gb2312, buffLen, 0, 0);
#ifdef TEST_TYPE_MAP
		m[utf8] = m_gb2312;
#endif
	}

	inline ~CGb2312String()
	{
#ifndef TEST_TYPE_MAP
		if (m_gb2312)
		{
			delete m_gb2312;
			m_gb2312 = 0;
		}
#endif
	}

	inline operator char*()
	{
		return (char*)m_gb2312;
	}
private:
	const char* m_gb2312;
#ifdef TEST_TYPE_MAP
	static strmap m;
#endif
};

#ifdef TEST_TYPE_MAP
strmap CUtf8String::m;
strmap CGb2312String::m;
#endif



//===================无聊的分割线==========================

#define U   (CUtf8String)

#define W   (CGb2312String)

readXml::readXml()
{
}

void readXml::read_path(CString s)
{
	path = s;
}

void readXml::read_move()
{
	string str = CT2A((LPCTSTR)path);
	TiXmlDocument doc(str.c_str());
	bool loadOkay = doc.LoadFile();
	if (!loadOkay) {
		printf("Could not load this file %s,Error='%s'.Exiting.\n", str.c_str(), doc.ErrorDesc());
		exit(1);
	}
	TiXmlElement* root = doc.RootElement();
	for (TiXmlElement* movelist = root->FirstChildElement("MoveList"); movelist; movelist = movelist->NextSiblingElement("MoveList"))
	{
		for (TiXmlElement* move = movelist->FirstChildElement("Move"); move; move = move->NextSiblingElement("Move"))
		{
			TiXmlAttribute* attr = move->FirstAttribute();
			const char* a = attr->Value();
			string s(a);
			s.erase(2, 1);
			int b1 = atoi(s.substr(0, 1).c_str());
			int b2 = atoi(s.substr(1, 1).c_str());
			int b3 = atoi(s.substr(2, 1).c_str());
			int b4 = atoi(s.substr(3, 1).c_str());
			from_x.push_back(b1);
			from_y.push_back(b2);
			to_x.push_back(b3);
			to_y.push_back(b4);
		}
	}
}

string readXml::read_fen()
{
	string str = CT2A((LPCTSTR)path);
	TiXmlDocument doc(str.c_str());
	bool loadOkay = doc.LoadFile();
	if (!loadOkay) {
		printf("Could not load this file %s,Error='%s'.Exiting.\n", str.c_str(), doc.ErrorDesc());
		exit(1);
	}
	TiXmlElement* root = doc.RootElement();
	for (TiXmlElement* head = root->FirstChildElement("Head"); head; head = head->NextSiblingElement("Head"))
	{
		for (TiXmlElement* fen = head->FirstChildElement("FEN"); fen; fen = fen->NextSiblingElement("FEN"))
		{
			string s(fen->GetText());
			return s;
		}
	}
}

int readXml::read_result()
{
	string str = CT2A((LPCTSTR)path);
	TiXmlDocument doc(str.c_str());
	bool loadOkay = doc.LoadFile();
	if (!loadOkay) {
		printf("Could not load this file %s,Error='%s'.Exiting.\n", str.c_str(), doc.ErrorDesc());
		exit(1);
	}
	TiXmlElement* root = doc.RootElement();
	for (TiXmlElement* head = root->FirstChildElement("Head"); head; head = head->NextSiblingElement("Head"))
	{
		for (TiXmlElement* result = head->FirstChildElement("RecordResult"); result; result = result->NextSiblingElement("RecordResult"))
		{
			return atoi(result->GetText());
		}
	}
}


string readXml::read_resulttype()
{
	string str = CT2A((LPCTSTR)path);
	TiXmlDocument doc(str.c_str());
	bool loadOkay = doc.LoadFile();
	if (!loadOkay) {
		printf("Could not load this file %s,Error='%s'.Exiting.\n", str.c_str(), doc.ErrorDesc());
		exit(1);
	}
	TiXmlElement* root = doc.RootElement();
	for (TiXmlElement* head = root->FirstChildElement("Head"); head; head = head->NextSiblingElement("Head"))
	{
		for (TiXmlElement* URL = head->FirstChildElement("URL"); URL; URL = URL->NextSiblingElement("URL"))
		{
			string s = W(URL->GetText());
			string ss = s.substr(s.size() - 4, 4);
			return ss;
		}
	}
}

readXml::~readXml()
{
}
