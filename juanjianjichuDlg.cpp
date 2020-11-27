
// juanjianjichuDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "juanjianjichu.h"
#include "juanjianjichuDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

int num;
int emptyline;
int nline;
int emptyn;
int sentence;
int daima_num;
// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

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

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CjuanjianjichuDlg 对话框



CjuanjianjichuDlg::CjuanjianjichuDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_JUANJIANJICHU_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CjuanjianjichuDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_edit1);
	DDX_Control(pDX, IDC_EDIT2, m_edit2);
}

BEGIN_MESSAGE_MAP(CjuanjianjichuDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, &CjuanjianjichuDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CjuanjianjichuDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON1, &CjuanjianjichuDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CjuanjianjichuDlg::OnBnClickedButton4)
	ON_EN_CHANGE(IDC_EDIT2, &CjuanjianjichuDlg::OnEnChangeEdit2)
	ON_BN_CLICKED(IDC_BUTTON5, &CjuanjianjichuDlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// CjuanjianjichuDlg 消息处理程序

BOOL CjuanjianjichuDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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
	SetWindowText(_T("WordCount"));
	
	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CjuanjianjichuDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CjuanjianjichuDlg::OnPaint()
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
HCURSOR CjuanjianjichuDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


//CString nline1;

void CjuanjianjichuDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	TCHAR szFilter[] = _T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
	// 构造打开文件对话框   
	CFileDialog fileDlg(TRUE, _T("txt"), NULL, 0, szFilter, this);
	CString strFilePath;
	// 显示打开文件对话框   
	if (IDOK == fileDlg.DoModal())
	{
		// 得到我们的选择文件的地址，用于之后的打开文件的操作
		strFilePath = fileDlg.GetPathName();
		//添加读取这个文件内容的代码，CFile::modeRead是说以只读文件的模式打开
		CStdioFile file;
		file.Open(strFilePath, CFile::modeRead);
		//逐行读取字符串
		CString strText;
		CString str1;
		nline = 0;      //行数                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                           		num = 0;
		emptyline = 0;  //空行数
		char steep = ' ';
		char word1 = '.';
		char word2 = '!'; 
		char word3 = '?';
		emptyn = 0;     //空格数目
		sentence = 0;
		daima_num = 0;
		while (file.ReadString(str1))
		{
			strText = strText + str1 + _T("\r\n");
			nline += 1;
			num += str1.GetLength();
		if(((str1.Find('#',0))!=0)&& ((str1.Find('*', 0)) != 0))
		{
			int position = 0;
			while ((position = str1.Find(steep, position)) != -1)
			{
				position++;
				emptyn++; //统计空格数
			}

			int position1 = 0;
			while ((position1 = str1.Find(word1,position1)) != -1)
			{
				position1++;
				sentence ++; //统计句子数

			}
			int position2 = 0;
			while ((position2 = str1.Find(word2, position2)) != -1)
			{
				position2++;
				sentence++; //统计句子数
			}
			int position3 = 0;
			while ((position3 = str1.Find(word3, position3)) != -1)
			{
				position3++;
				sentence++; //统计句子数
			}
		}
                                        else   if (str1.Find('#',0)==0)
			{
				daima_num++;
			}
			if (str1 == (CString)'\0')
			{
				emptyline += 1;
			}

        }
		SetDlgItemText(IDC_EDIT1, strText);//这里是时候我们将我们的内容显示到ID是IDD_ESEND的组件中（实际上这是一个编辑框）
		file.Close();
	}
}

void CjuanjianjichuDlg::OnBnClickedButton1()
{
	CString strOutPut;
	strOutPut.Format(_T("字符总个数：%d \r\n句子数为：%d \r\n单词数为：%d \r\n行数为：%d \r\n空行数为：%d \r\n代码行数为：%d"),num,sentence, emptyn+sentence,nline,emptyline,daima_num);
	SetDlgItemText(IDC_EDIT2, strOutPut);
	// TODO: 在此添加控件通知处理程序代码
}


void CjuanjianjichuDlg::OnBnClickedButton4()
{
	SetDlgItemText(IDC_EDIT1, _T(""));
	SetDlgItemText(IDC_EDIT2, _T(""));
	// TODO: 在此添加控件通知处理程序代码
}


void CjuanjianjichuDlg::OnEnChangeEdit2()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}
