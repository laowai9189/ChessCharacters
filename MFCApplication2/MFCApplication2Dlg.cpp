
// MFCApplication2Dlg.cpp : 实现文件
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


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

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

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
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
	sInfo.lpszTitle = _T("请选择一个文件夹：");
	sInfo.ulFlags = BIF_DONTGOBELOWDOMAIN | BIF_RETURNONLYFSDIRS | BIF_NEWDIALOGSTYLE | BIF_EDITBOX;
	sInfo.lpfn = NULL;

	// 显示文件夹选择对话框  
	LPITEMIDLIST lpidlBrowse = ::SHBrowseForFolder(&sInfo);
	if (lpidlBrowse != NULL)
	{
		// 取得文件夹名  
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



// CMFCApplication2Dlg 对话框

//将文件夹下的所有的文件名存入vector
void /*CMFCApplication2Dlg::*/getFilesAll(string path, vector<string>& files, vector<string>& names)
{
	//文件句柄 
	long  hFile = 0;
	//文件信息 
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


// CMFCApplication2Dlg 消息处理程序

BOOL CMFCApplication2Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCApplication2Dlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
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
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnOK();
}


void CMFCApplication2Dlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CMFCApplication2Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
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
		AfxMessageBox(_T("无法打开文件"));
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
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}



void CMFCApplication2Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
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
			/*if (result_type == "断线" || result_type == "局时" || result_type == "步时" || result_type == "判负" || result_type == "判和" || result_type == "认负" || result_type == "议和")
				continue;*/
			if (result_type == "困毙" || result_type == "绝杀")
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
					if ((&(*it_move) - &from_x[0]) == ceil(from_x.size() / 2))	//提取中局的局面
						break;
 					/*if ((&(*it_move) - &from_x[0]) == (from_x.size() - 11))
						break;*/	//提取残局的局面
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
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication2Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString dir = Show();
	string g = "\\";
	CString gang = CA2T(g.c_str());
	fulldir = dir + gang + name;
	SetDlgItemTextW(IDC_EDIT2, fulldir);
	CreateDirectory(fulldir, NULL);
}


void CMFCApplication2Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
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
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMFCApplication2Dlg::OnNMCustomdrawProgress1(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMCUSTOMDRAW pNMCD = reinterpret_cast<LPNMCUSTOMDRAW>(pNMHDR);
	// TODO: 在此添加控件通知处理程序代码
	*pResult = 0;
}
