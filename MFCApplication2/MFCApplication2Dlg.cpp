
// MFCApplication2Dlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include <io.h>
#include "MFCApplication2.h"
#include "MFCApplication2Dlg.h"
#include "afxdialogex.h"
#include "readXml.h"
#include "chessCharacters.h"
#include "wholePieces.h"
#include "libxl.h"
#include "toExcel.h"
#include "atlstr.h"
#include <atlconv.h>
#include <iostream>
#include <math.h>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;
using namespace libxl;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

LPCWSTR stringToLPCWSTR(std::string orig)
{
	size_t origsize = orig.length() + 1;
	const size_t newsize = 100;
	size_t convertedChars = 0;
	wchar_t *wcstring = (wchar_t *)malloc(sizeof(wchar_t) *(orig.length() - 1));
	mbstowcs_s(&convertedChars, wcstring, origsize, orig.c_str(), _TRUNCATE);


	return wcstring;
}

void Tranfile(const char* pszFileCopee, const char* pszFileCoper)
{
	fstream fsCopee(pszFileCopee, ios::binary | ios::in);
	fstream fsCoper(pszFileCoper, ios::binary | ios::out);
	fsCoper << fsCopee.rdbuf();
}


class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

static CString Show()
{
	TCHAR           szFolderPath[MAX_PATH] = { 0 };
	CString         strFolderPath = TEXT("");

	BROWSEINFO      sInfo;
	::ZeroMemory(&sInfo, sizeof(BROWSEINFO));
	sInfo.pidlRoot = 0;
	sInfo.lpszTitle = _T("��ѡ��һ���ļ��У�");
	sInfo.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;
	sInfo.lpfn = NULL;

	// ��ʾ�ļ���ѡ��Ի���  
	LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);
	if (lpidlBrowse != NULL)
	{
		// ȡ���ļ�����  
		if (::SHGetPathFromIDList(lpidlBrowse, szFolderPath))
		{
			strFolderPath = szFolderPath;
		}
	}
	if (lpidlBrowse != NULL)
	{
		::CoTaskMemFree(lpidlBrowse);
	}

	return strFolderPath;

}

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()



// CMFCApplication2Dlg �Ի���

//���ļ����µ����е��ļ�������vector
void /*CMFCApplication2Dlg::*/getFilesAll(string path, vector<string>& files, vector<string>& names)
{
	//�ļ���� 
	long  hFile = 0;
	//�ļ���Ϣ 
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			if ((fileinfo.attrib & _A_SUBDIR))
			{
				if (strcmp(fileinfo.name, ".") != 0 && strcmp(fileinfo.name, "..") != 0)
				{
					//files.push_back(p.assign(path).append("\\").append(fileinfo.name) );
					getFilesAll(p.assign(path).append("\\").append(fileinfo.name), files, names);
				}
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
				names.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}

CMFCApplication2Dlg::CMFCApplication2Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCAPPLICATION2_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplication2Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCApplication2Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CMFCApplication2Dlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CMFCApplication2Dlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCApplication2Dlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CMFCApplication2Dlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCApplication2Dlg::OnBnClickedButton2)
	ON_EN_CHANGE(IDC_EDIT2, &CMFCApplication2Dlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCApplication2Dlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCApplication2Dlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT3, &CMFCApplication2Dlg::OnEnChangeEdit3)
	ON_NOTIFY(NM_CUSTOMDRAW, IDC_PROGRESS1, &CMFCApplication2Dlg::OnNMCustomdrawProgress1)
END_MESSAGE_MAP()


// CMFCApplication2Dlg ��Ϣ�������

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCApplication2Dlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCApplication2Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



CString CMFCApplication2Dlg::return_path()
{
	return path;
}

//vector<string> CMFCApplication2Dlg::Files() const
//{
//	return CMFCApplication2Dlg::files;
//}

void CMFCApplication2Dlg::OnBnClickedOk()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnOK();
}


void CMFCApplication2Dlg::OnBnClickedCancel()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CDialogEx::OnCancel();
}


void CMFCApplication2Dlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CFileDialog dlg(TRUE);
	if (dlg.DoModal() == IDCANCEL)
		return;
	CFile m_file;
	if (m_file.m_hFile = CFile::hFileNull)
		OnClose();
	CString m_filePath, m_fileName;
	m_fileName = dlg.GetFileName();
	m_filePath = dlg.GetPathName();
	path = m_filePath;
	string s1 = ".xml";
	string s2 = ".cbf";
	CString cs1 = CA2T(s1.c_str());
	CString cs2 = CA2T(s2.c_str());
	name = m_fileName.TrimRight(cs1);
	name = m_fileName.TrimRight(cs2);
	if (!m_file.Open(m_filePath, CFile::modeReadWrite))
	{
		AfxMessageBox(_T("�޷����ļ�"));
		m_fileName.Empty();
		return;
	}
	//ULONGLONG FileLength = m_file.GetLength() / 1024;
	//UINT newFileLength = (UINT)FileLength;
	SetDlgItemTextW(IDC_EDIT1, name);
	//SetDlgItemTextW(IDC_EDIT1, m_filePath);
}


void CMFCApplication2Dlg::OnEnChangeEdit1()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}



void CMFCApplication2Dlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	//SetDlgItemTextW(IDC_EDIT2, path);
	try
	{
		vector<string>::iterator it_s;
		vector<int>::iterator it_move;
		string str = "original_data.xls";
		string str1 = "original_label.xls";
		toExcel te, te1;
		te.set_format();
		te1.set_format();
		int count = 0;
		for (it_s = allfiles.begin(); it_s != allfiles.end();++it_s)
		{
			int index = &(*it_s) - &allfiles[0];
			CString eipath = CA2T(it_s->c_str());
			readXml rx;
			rx.read_path(eipath);
			rx.read_move();
			string fen = rx.read_fen();
			int result = rx.read_result();
			string result_type = rx.read_resulttype();
			/*if (result_type == "����" || result_type == "��ʱ" || result_type == "��ʱ" || result_type == "�и�" || result_type == "�к�" || result_type == "�ϸ�" || result_type == "���")
				continue;*/
			if (result_type == "����" || result_type == "��ɱ")
			{
				chessCharacters ca;
				ca.set_fen(fen);
				ca.set_array();
				vector<int> from_x = rx.From_x();
				vector<int> from_y = rx.From_y();
				vector<int> to_x = rx.To_x();
				vector<int> to_y = rx.To_y();
				for (it_move = from_x.begin(); it_move != from_x.end(); ++it_move)
				{
					int i = &(*it_move) - &from_x[0];
					ca.change_array(from_x[i], from_y[i], to_x[i], to_y[i]);
					if ((&(*it_move) - &from_x[0]) == /*(from_x.size() - 11)*/ceil(from_x.size() / 2))
						break;
				}
				int* x = ca.get_point();
				wholePieces wp(x);
				te.write_whole(allnames[index], ca, wp, count, result, result_type);
				te1.write_array(x, count++, result);
			}
		}
		te.save(str);
		te1.save(str1);
	}
	catch (CMemoryException* e)
	{
		string s1 = "error1";
		CString cs1(s1.c_str());
		SetDlgItemTextW(IDC_EDIT2, cs1);
	}
	catch (CFileException* e)
	{
		string s1 = "error2";
		CString cs1(s1.c_str());
		SetDlgItemTextW(IDC_EDIT2, cs1);
	}
	catch (CException* e)
	{
		string s1 = "error3";
		CString cs1(s1.c_str());
		SetDlgItemTextW(IDC_EDIT2, cs1);
	}
}


void CMFCApplication2Dlg::OnEnChangeEdit2()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication2Dlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString dir = Show();
	string g = "\\";
	CString gang = CA2T(g.c_str());
	fulldir = dir + gang + name;
	SetDlgItemTextW(IDC_EDIT2, fulldir);
	CreateDirectory(fulldir, NULL);
}


void CMFCApplication2Dlg::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString dirs = Show();
	vector<string> files;
	vector<string> names;
	vector<string>::iterator i;
	string paths = CT2A((LPCTSTR)dirs);
	getFilesAll(paths, files, names);
	allfiles = files;
	allnames = names;
	SetDlgItemTextW(IDC_EDIT1, dirs);
}




void CMFCApplication2Dlg::OnEnChangeEdit3()
{
	// TODO:  ����ÿؼ��� RICHEDIT �ؼ���������
	// ���ʹ�֪ͨ��������д CDialogEx::OnInitDialog()
	// ���������� CRichEditCtrl().SetEventMask()��
	// ͬʱ�� ENM_CHANGE ��־�������㵽�����С�

	// TODO:  �ڴ���ӿؼ�֪ͨ����������
}


void CMFCApplication2Dlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	*pResult = 0;
}
