
// CIV6Dlg.cpp : 实现文件
//

#include "stdafx.h"
#include "CIV6.h"
#include "CIV6Dlg.h"
#include "afxdialogex.h"
#include "v.h"


#ifdef _DEBUG
#define new DEBUG_NEW
#endif


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


// CCIV6Dlg 对话框



CCIV6Dlg::CCIV6Dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CIV6_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CCIV6Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_TAB1, m_tab);
	DDX_Control(pDX, IDC_BUTTON4, m_qian);
	DDX_Control(pDX, IDC_BUTTON5, m_hou);
	DDX_Control(pDX, IDC_BUTTON1, m_delete);
	DDX_Control(pDX, IDC_BUTTON2, m_output);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT3, m_zuozhe);
	DDX_Control(pDX, IDC_EDIT4, m_miaoshu);
	DDX_Control(pDX, IDC_MFCEDITBROWSE1, m_mulu);
	DDX_Control(pDX, IDC_EDIT17, m_zhongwen);
}

BEGIN_MESSAGE_MAP(CCIV6Dlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CCIV6Dlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CCIV6Dlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CCIV6Dlg::OnBnClickedButton3)
	ON_NOTIFY(TCN_SELCHANGE, IDC_TAB1, &CCIV6Dlg::OnTcnSelchangeTab1)
	ON_WM_DESTROY()
	ON_BN_CLICKED(IDC_BUTTON6, &CCIV6Dlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CCIV6Dlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON4, &CCIV6Dlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CCIV6Dlg::OnBnClickedButton5)
	ON_WM_DROPFILES()
END_MESSAGE_MAP()


// CCIV6Dlg 消息处理程序

BOOL CCIV6Dlg::OnInitDialog()
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
	//int i;
	m_tab.InsertItem(0, _T("建筑"));
	m_tab.InsertItem(1, _T("奇观"));
	m_tab.InsertItem(2, _T("文明"));
	m_tab.InsertItem(3, _T("领袖"));
	m_tab.InsertItem(4, _T("科技市政"));
	m_tab.InsertItem(5, _T("单位"));
	m_tab.InsertItem(6, _T("政体政策"));
	m_tab.InsertItem(7, _T("信条"));
	m_tab.InsertItem(8, _T("文明图"));
	m_tab.InsertItem(9, _T("领袖图"));
	m_tab.InsertItem(10, _T("单位图"));
	m_tab.InsertItem(11, _T("其他图"));
	m_tab.InsertItem(12, _T("条件"));
	m_tab.InsertItem(13, _T("特性"));
	m_name.SetWindowTextW(L"name");
	m_zhongwen.SetWindowTextW(L"名称");
	m_zuozhe.SetWindowTextW(L"你猜");
	m_miaoshu.SetWindowTextW(L"这是一个DLC。");

	CRect rec;
	m_tab.GetClientRect(&rec);//获得TAB控件的坐标

							  //定位选项卡页的位置，这里可以根据情况自己调节偏移量
	rec.bottom += 88;
	rec.left += 19;
	rec.top += 119;
	rec.right += 15;

	//创建子页面
	m_JianZhu.Create(IDD_DIALOG1, GetDlgItem(IDD_CIV6_DIALOG));
	m_QiGuan.Create(IDD_DIALOG2, GetDlgItem(IDD_CIV6_DIALOG));
	m_WenMing.Create(IDD_DIALOG3, GetDlgItem(IDD_CIV6_DIALOG));
	m_LingXiu.Create(IDD_DIALOG4, GetDlgItem(IDD_CIV6_DIALOG));
	m_KeJi.Create(IDD_DIALOG5, GetDlgItem(IDD_CIV6_DIALOG));
	m_DanWei.Create(IDD_DIALOG6, GetDlgItem(IDD_CIV6_DIALOG));
	m_ZhengCe.Create(IDD_DIALOG7, GetDlgItem(IDD_CIV6_DIALOG));
	m_XinTiao.Create(IDD_DIALOG8, GetDlgItem(IDD_CIV6_DIALOG));
	m_ZiYuan.Create(IDD_DIALOG9, GetDlgItem(IDD_CIV6_DIALOG));
	m_JuZuo.Create(IDD_DIALOG10, GetDlgItem(IDD_CIV6_DIALOG));
	m_WeiRen.Create(IDD_DIALOG11, GetDlgItem(IDD_CIV6_DIALOG));
	m_ZiRanQiGuan.Create(IDD_DIALOG12, GetDlgItem(IDD_CIV6_DIALOG));
	m_TiaoJian.Create(IDD_DIALOG13, GetDlgItem(IDD_CIV6_DIALOG));
	m_TeXing.Create(IDD_DIALOG14, GetDlgItem(IDD_CIV6_DIALOG));
	//将子页面移动到指定的位置
	m_JianZhu.MoveWindow(&rec);
	m_QiGuan.MoveWindow(&rec);
	m_WenMing.MoveWindow(&rec);
	m_LingXiu.MoveWindow(&rec);
	m_KeJi.MoveWindow(&rec);
	m_DanWei.MoveWindow(&rec);
	m_ZhengCe.MoveWindow(&rec);
	m_XinTiao.MoveWindow(&rec);
	m_ZiYuan.MoveWindow(&rec);
	m_JuZuo.MoveWindow(&rec);
	m_WeiRen.MoveWindow(&rec);
	m_ZiRanQiGuan.MoveWindow(&rec);
	m_TiaoJian.MoveWindow(&rec);
	m_TeXing.MoveWindow(&rec);

	csh();
	if (dat.Open(L"civ6.dat", CFile::modeRead | CFile::shareDenyNone))
	{
		if (dat.GetLength())//读取工程数据
		{
			GetDlgItem(IDC_BUTTON1)->EnableWindow(true);
			GetDlgItem(IDC_BUTTON2)->EnableWindow(true);
			GetDlgItem(IDC_BUTTON4)->EnableWindow(true);
			pro = new project(&dat);
			dat.Close();
			if (!dat.Open(L"civ6.dat", CFile::modeNoTruncate | CFile::modeWrite))
			{
				MessageBox(L"打开工程失败！");
				exit(1);
			}
		}
		else
		{
			dat.Close();
			if (dat.Open(L"civ6.dat", CFile::modeCreate | CFile::modeWrite))
			{
				pro = new project();
			}
			else
			{
				MessageBox(L"新建工程失败！");
				exit(1);
			}
		}
	}
	else
	{
		if (dat.Open(L"civ6.dat", CFile::modeCreate | CFile::modeWrite))
		{
			pro = new project();
		}
		else
		{
			MessageBox(L"新建工程失败！");
			exit(1);
		}
	}
	dat.SeekToEnd();
	pro->ck = this;

	shuaxin();

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CCIV6Dlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CCIV6Dlg::OnPaint()
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
HCURSOR CCIV6Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CCIV6Dlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	pro->shanchu();
}


void CCIV6Dlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str1, str2, str3;
	CString zhongwen;
	CString mulu;

	m_name.GetWindowTextW(str1);
	m_zuozhe.GetWindowTextW(str2);
	m_miaoshu.GetWindowTextW(str3);
	m_zhongwen.GetWindowTextW(zhongwen);
	m_mulu.GetWindowTextW(mulu);
	if (str1.IsEmpty())
	{
		MessageBox(L"请将DLC信息填写完整");
		return;
	}
	if (str2.IsEmpty())
	{
		MessageBox(L"请将DLC信息填写完整");
		return;
	}
	if (str3.IsEmpty())
	{
		MessageBox(L"请将DLC信息填写完整");
		return;
	}
	if (zhongwen.IsEmpty())
	{
		MessageBox(L"请将DLC信息填写完整");
		return;
	}
	if (mulu.IsEmpty())
	{
		MessageBox(L"请将DLC信息填写完整");
		return;
	}
	pro->shengcheng(str1, str2, str3, mulu,zhongwen);
	MessageBox(L"DLC生成成功^_^");
}


void CCIV6Dlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (building)
	{
		delete[] building;
	}
	if (tech)
	{
		delete[] tech;
	}
	if (civic)
	{
		delete[] civic;
	}
	if (texing)
	{
		delete[] texing;
	}
	if (tiaojian)
	{
		delete[] tiaojian;
	}
	if (zongtexing)
	{
		delete[] zongtexing;
	}
	if (zongtiaojian)
	{
		delete[] zongtiaojian;
	}
	if (ziyuan)
	{
		delete[] ziyuan;
	}
	if (ability)
	{
		delete[] ability;
	}
	if (jinsheng)
	{
		delete[] jinsheng;
	}
	if (unit)
	{
		delete[] unit;
	}
	if (wenming)
	{
		delete[] wenming;
	}
	dat.Close();
	/*if (dat.Open(L"civ6.dat", CFile::modeCreate | CFile::modeWrite))
	{
		pro->baocun(&dat);
		dat.Close();
	}
	else
	{
		MessageBox(L"保存工程失败！");
		exit(1);
	}*/
	if (pro)
	{
		delete pro;
	}

	exit(0);
}


void CCIV6Dlg::OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult)
{
	// TODO: 在此添加控件通知处理程序代码
	switch (m_tab.GetCurSel())
	{
	case 0:
	default:
		m_JianZhu.ShowWindow(SW_SHOW);
		m_QiGuan.ShowWindow(SW_HIDE);
		m_WenMing.ShowWindow(SW_HIDE);
		m_LingXiu.ShowWindow(SW_HIDE);
		m_KeJi.ShowWindow(SW_HIDE);
		m_DanWei.ShowWindow(SW_HIDE);
		m_ZhengCe.ShowWindow(SW_HIDE);
		m_XinTiao.ShowWindow(SW_HIDE);
		m_ZiYuan.ShowWindow(SW_HIDE);
		m_JuZuo.ShowWindow(SW_HIDE);
		m_WeiRen.ShowWindow(SW_HIDE);
		m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		m_TiaoJian.ShowWindow(SW_HIDE);
		m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 1:
		m_JianZhu.ShowWindow(SW_HIDE);
		m_QiGuan.ShowWindow(SW_SHOW);
		m_WenMing.ShowWindow(SW_HIDE);
		m_LingXiu.ShowWindow(SW_HIDE);
		m_KeJi.ShowWindow(SW_HIDE);
		m_DanWei.ShowWindow(SW_HIDE);
		m_ZhengCe.ShowWindow(SW_HIDE);
		m_XinTiao.ShowWindow(SW_HIDE);
		m_ZiYuan.ShowWindow(SW_HIDE);
		m_JuZuo.ShowWindow(SW_HIDE);
		m_WeiRen.ShowWindow(SW_HIDE);
		m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		m_TiaoJian.ShowWindow(SW_HIDE);
		m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 2:
		m_JianZhu.ShowWindow(SW_HIDE);
		m_QiGuan.ShowWindow(SW_HIDE);
		m_WenMing.ShowWindow(SW_SHOW);
		m_LingXiu.ShowWindow(SW_HIDE);
		m_KeJi.ShowWindow(SW_HIDE);
		m_DanWei.ShowWindow(SW_HIDE);
		m_ZhengCe.ShowWindow(SW_HIDE);
		m_XinTiao.ShowWindow(SW_HIDE);
		m_ZiYuan.ShowWindow(SW_HIDE);
		m_JuZuo.ShowWindow(SW_HIDE);
		m_WeiRen.ShowWindow(SW_HIDE);
		m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		m_TiaoJian.ShowWindow(SW_HIDE);
		m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 3:
		m_JianZhu.ShowWindow(SW_HIDE);
		m_QiGuan.ShowWindow(SW_HIDE);
		m_WenMing.ShowWindow(SW_HIDE);
		m_LingXiu.ShowWindow(SW_SHOW);
		m_KeJi.ShowWindow(SW_HIDE);
		m_DanWei.ShowWindow(SW_HIDE);
		m_ZhengCe.ShowWindow(SW_HIDE);
		m_XinTiao.ShowWindow(SW_HIDE);
		m_ZiYuan.ShowWindow(SW_HIDE);
		m_JuZuo.ShowWindow(SW_HIDE);
		m_WeiRen.ShowWindow(SW_HIDE);
		m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		m_TiaoJian.ShowWindow(SW_HIDE);
		m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 4:
		m_JianZhu.ShowWindow(SW_HIDE);
		m_QiGuan.ShowWindow(SW_HIDE);
		m_WenMing.ShowWindow(SW_HIDE);
		m_LingXiu.ShowWindow(SW_HIDE);
		m_KeJi.ShowWindow(SW_SHOW);
		m_DanWei.ShowWindow(SW_HIDE);
		m_ZhengCe.ShowWindow(SW_HIDE);
		m_XinTiao.ShowWindow(SW_HIDE);
		m_ZiYuan.ShowWindow(SW_HIDE);
		m_JuZuo.ShowWindow(SW_HIDE);
		m_WeiRen.ShowWindow(SW_HIDE);
		m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		m_TiaoJian.ShowWindow(SW_HIDE);
		m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 5:
		m_JianZhu.ShowWindow(SW_HIDE);
		m_QiGuan.ShowWindow(SW_HIDE);
		m_WenMing.ShowWindow(SW_HIDE);
		m_LingXiu.ShowWindow(SW_HIDE);
		m_KeJi.ShowWindow(SW_HIDE);
		m_DanWei.ShowWindow(SW_SHOW);
		m_ZhengCe.ShowWindow(SW_HIDE);
		m_XinTiao.ShowWindow(SW_HIDE);
		m_ZiYuan.ShowWindow(SW_HIDE);
		m_JuZuo.ShowWindow(SW_HIDE);
		m_WeiRen.ShowWindow(SW_HIDE);
		m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		m_TiaoJian.ShowWindow(SW_HIDE);
		m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 6:
		m_JianZhu.ShowWindow(SW_HIDE);
		m_QiGuan.ShowWindow(SW_HIDE);
		m_WenMing.ShowWindow(SW_HIDE);
		m_LingXiu.ShowWindow(SW_HIDE);
		m_KeJi.ShowWindow(SW_HIDE);
		m_DanWei.ShowWindow(SW_HIDE);
		m_ZhengCe.ShowWindow(SW_SHOW);
		m_XinTiao.ShowWindow(SW_HIDE);
		m_ZiYuan.ShowWindow(SW_HIDE);
		m_JuZuo.ShowWindow(SW_HIDE);
		m_WeiRen.ShowWindow(SW_HIDE);
		m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		m_TiaoJian.ShowWindow(SW_HIDE);
		m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 7:
		m_JianZhu.ShowWindow(SW_HIDE);
		m_QiGuan.ShowWindow(SW_HIDE);
		m_WenMing.ShowWindow(SW_HIDE);
		m_LingXiu.ShowWindow(SW_HIDE);
		m_KeJi.ShowWindow(SW_HIDE);
		m_DanWei.ShowWindow(SW_HIDE);
		m_ZhengCe.ShowWindow(SW_HIDE);
		m_XinTiao.ShowWindow(SW_SHOW);
		m_ZiYuan.ShowWindow(SW_HIDE);
		m_JuZuo.ShowWindow(SW_HIDE);
		m_WeiRen.ShowWindow(SW_HIDE);
		m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		m_TiaoJian.ShowWindow(SW_HIDE);
		m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 8:
		m_JianZhu.ShowWindow(SW_HIDE);
		m_QiGuan.ShowWindow(SW_HIDE);
		m_WenMing.ShowWindow(SW_HIDE);
		m_LingXiu.ShowWindow(SW_HIDE);
		m_KeJi.ShowWindow(SW_HIDE);
		m_DanWei.ShowWindow(SW_HIDE);
		m_ZhengCe.ShowWindow(SW_HIDE);
		m_XinTiao.ShowWindow(SW_HIDE);
		m_ZiYuan.ShowWindow(SW_SHOW);
		m_JuZuo.ShowWindow(SW_HIDE);
		m_WeiRen.ShowWindow(SW_HIDE);
		m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		m_TiaoJian.ShowWindow(SW_HIDE);
		m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 9:
		m_JianZhu.ShowWindow(SW_HIDE);
		m_QiGuan.ShowWindow(SW_HIDE);
		m_WenMing.ShowWindow(SW_HIDE);
		m_LingXiu.ShowWindow(SW_HIDE);
		m_KeJi.ShowWindow(SW_HIDE);
		m_DanWei.ShowWindow(SW_HIDE);
		m_ZhengCe.ShowWindow(SW_HIDE);
		m_XinTiao.ShowWindow(SW_HIDE);
		m_ZiYuan.ShowWindow(SW_HIDE);
		m_JuZuo.ShowWindow(SW_SHOW);
		m_WeiRen.ShowWindow(SW_HIDE);
		m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		m_TiaoJian.ShowWindow(SW_HIDE);
		m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 10:
		m_JianZhu.ShowWindow(SW_HIDE);
		m_QiGuan.ShowWindow(SW_HIDE);
		m_WenMing.ShowWindow(SW_HIDE);
		m_LingXiu.ShowWindow(SW_HIDE);
		m_KeJi.ShowWindow(SW_HIDE);
		m_DanWei.ShowWindow(SW_HIDE);
		m_ZhengCe.ShowWindow(SW_HIDE);
		m_XinTiao.ShowWindow(SW_HIDE);
		m_ZiYuan.ShowWindow(SW_HIDE);
		m_JuZuo.ShowWindow(SW_HIDE);
		m_WeiRen.ShowWindow(SW_SHOW);
		m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		m_TiaoJian.ShowWindow(SW_HIDE);
		m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 11:
		m_JianZhu.ShowWindow(SW_HIDE);
		m_QiGuan.ShowWindow(SW_HIDE);
		m_WenMing.ShowWindow(SW_HIDE);
		m_LingXiu.ShowWindow(SW_HIDE);
		m_KeJi.ShowWindow(SW_HIDE);
		m_DanWei.ShowWindow(SW_HIDE);
		m_ZhengCe.ShowWindow(SW_HIDE);
		m_XinTiao.ShowWindow(SW_HIDE);
		m_ZiYuan.ShowWindow(SW_HIDE);
		m_JuZuo.ShowWindow(SW_HIDE);
		m_WeiRen.ShowWindow(SW_HIDE);
		m_ZiRanQiGuan.ShowWindow(SW_SHOW);
		m_TiaoJian.ShowWindow(SW_HIDE);
		m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 12:
		m_JianZhu.ShowWindow(SW_HIDE);
		m_QiGuan.ShowWindow(SW_HIDE);
		m_WenMing.ShowWindow(SW_HIDE);
		m_LingXiu.ShowWindow(SW_HIDE);
		m_KeJi.ShowWindow(SW_HIDE);
		m_DanWei.ShowWindow(SW_HIDE);
		m_ZhengCe.ShowWindow(SW_HIDE);
		m_XinTiao.ShowWindow(SW_HIDE);
		m_ZiYuan.ShowWindow(SW_HIDE);
		m_JuZuo.ShowWindow(SW_HIDE);
		m_WeiRen.ShowWindow(SW_HIDE);
		m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		m_TiaoJian.ShowWindow(SW_SHOW);
		m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 13:
		m_JianZhu.ShowWindow(SW_HIDE);
		m_QiGuan.ShowWindow(SW_HIDE);
		m_WenMing.ShowWindow(SW_HIDE);
		m_LingXiu.ShowWindow(SW_HIDE);
		m_KeJi.ShowWindow(SW_HIDE);
		m_DanWei.ShowWindow(SW_HIDE);
		m_ZhengCe.ShowWindow(SW_HIDE);
		m_XinTiao.ShowWindow(SW_HIDE);
		m_ZiYuan.ShowWindow(SW_HIDE);
		m_JuZuo.ShowWindow(SW_HIDE);
		m_WeiRen.ShowWindow(SW_HIDE);
		m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		m_TiaoJian.ShowWindow(SW_HIDE);
		m_TeXing.ShowWindow(SW_SHOW);
		break;
	}
	*pResult = 0;
}


void CCIV6Dlg::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 在此处添加消息处理程序代码
	if (building)
	{
		delete[] building;
	}
	if (tech)
	{
		delete[] tech;
	}
	if (civic)
	{
		delete[] civic;
	}
	if (texing)
	{
		delete[] texing;
	}
	if (tiaojian)
	{
		delete[] tiaojian;
	}
	if (zongtexing)
	{
		delete[] zongtexing;
	}
	if (zongtiaojian)
	{
		delete[] zongtiaojian;
	}
	if (ziyuan)
	{
		delete[] ziyuan;
	}
	if (ability)
	{
		delete[] ability;
	}
	if (jinsheng)
	{
		delete[] jinsheng;
	}
	if (unit)
	{
		delete[] unit;
	}
	if (wenming)
	{
		delete[] wenming;
	}
	dat.Close();
	/*if (dat.Open(L"civ6.dat", CFile::modeCreate | CFile::modeWrite))
	{
		pro->baocun(&dat);
		dat.Close();
	}
	else
	{
		MessageBox(L"保存工程失败！");
		exit(1);
	}*/
	if (pro)
	{
		delete pro;
	}
}


void CCIV6Dlg::xuanxiang(CComboBox * box, int num, civ6 * shuju)
{
	int i;
	box->ResetContent();
	box->AddString(L"无");
	for (i = 1; i <= num; i++)
	{
		box->AddString(shuju[i].name);
	}
	box->SetCurSel(0);
}


void CCIV6Dlg::xuanxiangwu(CComboBox * box, int num, civ666 * shuju)
{
	int i;
	box->ResetContent();
	for (i = 0; i < num; i++)
	{
		box->AddString(shuju[i].name);
	}
	box->SetCurSel(0);
}


void CCIV6Dlg::xuanxiangwu(CComboBox * box, int num, civ6 * shuju)
{
	int i;
	box->ResetContent();
	for (i = 1; i <= num; i++)
	{
		box->AddString(shuju[i].name);
	}
	box->SetCurSel(0);
}


void CCIV6Dlg::csh()
{
	int i;
	//设置主界面
	GetDlgItem(IDC_BUTTON1)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON2)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON3)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON4)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(false);
	GetDlgItem(IDC_BUTTON6)->EnableWindow(true);
	//设置选项窗口
	m_JianZhu.ShowWindow(SW_SHOW);
	m_QiGuan.ShowWindow(SW_HIDE);
	m_WenMing.ShowWindow(SW_HIDE);
	m_LingXiu.ShowWindow(SW_HIDE);
	m_KeJi.ShowWindow(SW_HIDE);
	m_DanWei.ShowWindow(SW_HIDE);
	m_ZhengCe.ShowWindow(SW_HIDE);
	m_XinTiao.ShowWindow(SW_HIDE);
	m_ZiYuan.ShowWindow(SW_HIDE);
	m_JuZuo.ShowWindow(SW_HIDE);
	m_WeiRen.ShowWindow(SW_HIDE);
	m_ZiRanQiGuan.ShowWindow(SW_HIDE);
	m_TiaoJian.ShowWindow(SW_HIDE);
	m_TeXing.ShowWindow(SW_HIDE);
	//读取建筑数据
	Cbuilding build;
	build.Open();
	build.MoveFirst();
	for (buildingnum = 0; !build.IsEOF(); build.MoveNext())
	{
		buildingnum++;
	}
	build.MoveFirst();
	building = new struct civ6[buildingnum + 1001];
	for (i = 1; i <= buildingnum; i++)
	{
		building[i].id = build.m_ID;
		building[i].type = build.m_type;
		building[i].name = build.m_loc;
		build.MoveNext();
	}
	//读取科技数据
	Ctech tech6;
	tech6.Open();
	tech6.MoveFirst();
	for (technum = 0; !tech6.IsEOF(); tech6.MoveNext())
	{
		technum++;
	}
	tech6.MoveFirst();
	tech = new struct civ6[technum + 1001];
	for (i = 1; i <= technum; i++)
	{
		tech[i].id = tech6.m_ID;
		tech[i].type = tech6.m_type;
		tech[i].name = tech6.m_loc;
		tech6.MoveNext();
	}
	//读取市政数据
	Ccivic civic6;
	civic6.Open();
	civic6.MoveFirst();
	for (civicnum = 0; !civic6.IsEOF(); civic6.MoveNext())
	{
		civicnum++;
	}
	civic6.MoveFirst();
	civic = new struct civ6[civicnum + 1001];
	for (i = 1; i <= civicnum; i++)
	{
		civic[i].id = civic6.m_ID;
		civic[i].type = civic6.m_type;
		civic[i].name = civic6.m_loc;
		civic6.MoveNext();
	}
	//读取特性数据
	Ctexing texing6;
	texing6.Open();
	texing6.MoveFirst();
	for (texingnum = 0; !texing6.IsEOF(); texing6.MoveNext())
	{
		texingnum++;
	}
	texing6.MoveFirst();
	texing = new struct civ666[texingnum + 1000];
	for (i = 0; i < texingnum; i++)
	{
		texing[i].id = texing6.m_ID;
		texing[i].type = texing6.m_type;
		texing[i].name = texing6.m_loc;
		texing[i].arg1 = texing6.m_arg1;
		texing[i].arg2 = texing6.m_arg2;
		texing[i].arg3 = texing6.m_arg3;
		texing[i].arg4 = texing6.m_arg4;
		texing[i].arg5 = texing6.m_arg5;
		texing[i].arg6 = texing6.m_arg6;
		texing[i].arg7 = texing6.m_arg7;
		texing[i].arg8 = texing6.m_arg8;
		texing6.MoveNext();
	}
	//读取条件数据
	Ctiaojian tiaojian6;
	tiaojian6.Open();
	tiaojian6.MoveFirst();
	for (tiaojiannum = 0; !tiaojian6.IsEOF(); tiaojian6.MoveNext())
	{
		tiaojiannum++;
	}
	tiaojian6.MoveFirst();
	tiaojian = new struct civ666[tiaojiannum + 1000];
	for (i = 0; i < tiaojiannum; i++)
	{
		tiaojian[i].id = tiaojian6.m_ID;
		tiaojian[i].type = tiaojian6.m_type;
		tiaojian[i].name = tiaojian6.m_loc;
		tiaojian[i].arg1 = tiaojian6.m_arg1;
		tiaojian[i].arg2 = tiaojian6.m_arg2;
		tiaojian[i].arg3 = tiaojian6.m_arg3;
		tiaojian[i].arg4 = tiaojian6.m_arg4;
		tiaojian[i].arg5 = tiaojian6.m_arg5;
		tiaojian[i].arg6 = tiaojian6.m_arg6;
		tiaojian[i].arg7 = tiaojian6.m_arg7;
		tiaojian[i].arg8 = tiaojian6.m_arg8;
		tiaojian6.MoveNext();
	}
	//读取总特性数据
	Czongtexing zongtexing6;
	zongtexing6.Open();
	zongtexing6.MoveFirst();
	for (zongtexingnum = 0; !zongtexing6.IsEOF(); zongtexing6.MoveNext())
	{
		zongtexingnum++;
	}
	zongtexing6.MoveFirst();
	zongtexing = new struct civ6[zongtexingnum + 1001];
	for (i = 1; i <= zongtexingnum; i++)
	{
		zongtexing[i].id = zongtexing6.m_ID;
		zongtexing[i].type = zongtexing6.m_type;
		zongtexing[i].name = zongtexing6.m_loc;
		zongtexing6.MoveNext();
	}
	//读取总条件数据
	Czongtiaojian zongtiaojian6;
	zongtiaojian6.Open();
	zongtiaojian6.MoveFirst();
	for (zongtiaojiannum = 0; !zongtiaojian6.IsEOF(); zongtiaojian6.MoveNext())
	{
		zongtiaojiannum++;
	}
	zongtiaojian6.MoveFirst();
	zongtiaojian = new struct civ6[zongtiaojiannum + 1001];
	for (i = 1; i <= zongtiaojiannum; i++)
	{
		zongtiaojian[i].id = zongtiaojian6.m_ID;
		zongtiaojian[i].type = zongtiaojian6.m_type;
		zongtiaojian[i].name = zongtiaojian6.m_loc;
		zongtiaojian6.MoveNext();
	}
	//读取资源数据
	Cziyuan ziyuan6;
	ziyuan6.Open();
	ziyuan6.MoveFirst();
	for (ziyuannum = 0; !ziyuan6.IsEOF(); ziyuan6.MoveNext())
	{
		ziyuannum++;
	}
	ziyuan6.MoveFirst();
	ziyuan = new struct civ6[ziyuannum + 1001];
	for (i = 1; i <= ziyuannum; i++)
	{
		ziyuan[i].id = ziyuan6.m_ID;
		ziyuan[i].type = ziyuan6.m_type;
		ziyuan[i].name = ziyuan6.m_loc;
		ziyuan6.MoveNext();
	}
	//读取能力数据
	Cability ability6;
	ability6.Open();
	ability6.MoveFirst();
	for (abilitynum = 0; !ability6.IsEOF(); ability6.MoveNext())
	{
		abilitynum++;
	}
	ability6.MoveFirst();
	ability = new struct civ6[abilitynum + 1001];
	for (i = 1; i <= abilitynum; i++)
	{
		ability[i].id = ability6.m_ID;
		ability[i].type = ability6.m_type;
		ability[i].name = ability6.m_loc;
		ability6.MoveNext();
	}
	//读取晋升数据
	Cjinsheng jinsheng6;
	jinsheng6.Open();
	jinsheng6.MoveFirst();
	for (jinshengnum = 0; !jinsheng6.IsEOF(); jinsheng6.MoveNext())
	{
		jinshengnum++;
	}
	jinsheng6.MoveFirst();
	jinsheng = new struct civ6[jinshengnum + 1001];
	for (i = 1; i <= jinshengnum; i++)
	{
		jinsheng[i].id = jinsheng6.m_ID;
		jinsheng[i].type = jinsheng6.m_type;
		jinsheng[i].name = jinsheng6.m_loc;
		jinsheng6.MoveNext();
	}
	//读取单位数据
	Cunit unit6;
	unit6.Open();
	unit6.MoveFirst();
	for (unitnum = 0; !unit6.IsEOF(); unit6.MoveNext())
	{
		unitnum++;
	}
	unit6.MoveFirst();
	unit = new struct civ6[unitnum + 1001];
	for (i = 1; i <= unitnum; i++)
	{
		unit[i].id = unit6.m_ID;
		unit[i].type = unit6.m_type;
		unit[i].name = unit6.m_loc;
		unit6.MoveNext();
	}
	//读取文明数据
	Cwenming wenming6;
	wenming6.Open();
	wenming6.MoveFirst();
	for (wenmingnum = 0; !wenming6.IsEOF(); wenming6.MoveNext())
	{
		wenmingnum++;
	}
	wenming6.MoveFirst();
	wenming = new struct civ6[wenmingnum + 1001];
	for (i = 1; i <= wenmingnum; i++)
	{
		wenming[i].id = wenming6.m_ID;
		wenming[i].type = wenming6.m_type;
		wenming[i].name = wenming6.m_loc;
		wenming6.MoveNext();
	}
	//读取议程数据
	Cyicheng yicheng6;
	yicheng6.Open();
	yicheng6.MoveFirst();
	for (yichengnum = 0; !yicheng6.IsEOF(); yicheng6.MoveNext())
	{
		yichengnum++;
	}
	yicheng6.MoveFirst();
	yicheng = new struct civ6[yichengnum + 1001];
	for (i = 1; i <= yichengnum; i++)
	{
		yicheng[i].id = yicheng6.m_ID;
		yicheng[i].type = yicheng6.m_type;
		yicheng[i].name = yicheng6.m_loc;
		yicheng6.MoveNext();
	}
	//读取科技市政提升数据
	Ctisheng tisheng6;
	tisheng6.Open();
	tisheng6.MoveFirst();
	for (tishengnum = 0; !tisheng6.IsEOF(); tisheng6.MoveNext())
	{
		tishengnum++;
	}
	tisheng6.MoveFirst();
	tisheng = new struct civ6[tishengnum + 101];
	for (i = 1; i <= tishengnum; i++)
	{
		tisheng[i].id = tisheng6.m_ID;
		tisheng[i].type = tisheng6.m_type;
		tisheng[i].name = tisheng6.m_loc;
		tisheng6.MoveNext();
	}
	//读取政策数据
	Czhengce zhengce6;
	zhengce6.Open();
	zhengce6.MoveFirst();
	for (zhengcenum = 0; !zhengce6.IsEOF(); zhengce6.MoveNext())
	{
		zhengcenum++;
	}
	zhengce6.MoveFirst();
	zhengce = new struct civ6[zhengcenum + 1001];
	for (i = 1; i <= zhengcenum; i++)
	{
		zhengce[i].id = zhengce6.m_ID;
		zhengce[i].type = zhengce6.m_type;
		zhengce[i].name = zhengce6.m_loc;
		zhengce6.MoveNext();
	}
}


void CCIV6Dlg::shuaxin()
{
	//界面1数据初始化
	xuanxiang(&(m_JianZhu.m_pb), buildingnum, building);
	xuanxiang(&(m_JianZhu.m_huchi), buildingnum, building);
	xuanxiang(&(m_JianZhu.m_tihuan), buildingnum, building);
	xuanxiang(&(m_JianZhu.m_tech), technum, tech);
	xuanxiang(&(m_JianZhu.m_civic), civicnum, civic);
	xuanxiang(&(m_JianZhu.m_tx), zongtexingnum, zongtexing);
	xuanxiang(&(m_JianZhu.m_tj), zongtiaojiannum, zongtiaojian);
	//界面2数据初始化
	xuanxiang(&(m_QiGuan.m_res), ziyuannum, ziyuan);
	xuanxiang(&(m_QiGuan.m_tech), technum, tech);
	xuanxiang(&(m_QiGuan.m_civic), civicnum, civic);
	xuanxiang(&(m_QiGuan.m_tx), zongtexingnum, zongtexing);
	xuanxiang(&(m_QiGuan.m_tj), zongtiaojiannum, zongtiaojian);
	//界面3数据初始化
	xuanxiang(&(m_WenMing.m_jianzhu), buildingnum, building);
	xuanxiang(&(m_WenMing.m_danwei), unitnum, unit);
	xuanxiang(&(m_WenMing.m_texing), zongtexingnum, zongtexing);
	xuanxiangwu(&(m_WenMing.m_ziyuanc), ziyuannum, ziyuan);
	//界面4数据初始化
	xuanxiangwu(&(m_LingXiu.m_wenming), wenmingnum, wenming);
	xuanxiangwu(&(m_LingXiu.m_yicheng), yichengnum, yicheng);
	xuanxiang(&(m_LingXiu.m_shouxuan), yichengnum, yicheng);
	xuanxiang(&(m_LingXiu.m_wjianzhu), buildingnum, building);
	xuanxiang(&(m_LingXiu.m_wdanwei), unitnum, unit);
	xuanxiang(&(m_LingXiu.m_jianzhu), buildingnum, building);
	xuanxiang(&(m_LingXiu.m_danwei), unitnum, unit);
	xuanxiang(&(m_LingXiu.m_texing), zongtexingnum, zongtexing);
	//界面5数据初始化
	xuanxiang(&(m_KeJi.m_kejishizheng), technum, tech);
	xuanxiangwu(&(m_KeJi.m_boost), tishengnum, tisheng);
	xuanxiang(&(m_KeJi.m_texing), zongtexingnum, zongtexing);
	xuanxiangwu(&(m_KeJi.m_unit), unitnum, unit);
	xuanxiangwu(&(m_KeJi.m_jianzhu), buildingnum, building);
	xuanxiangwu(&(m_KeJi.m_ziyuan), ziyuannum, ziyuan);
	xuanxiangwu(&(m_KeJi.m_keji), technum, tech);
	xuanxiangwu(&(m_KeJi.m_shizheng), civicnum, civic);
	//界面6数据初始化
	xuanxiang(&(m_DanWei.m_texing), zongtexingnum, zongtexing);
	xuanxiang(&(m_DanWei.m_tech), technum, tech);
	xuanxiang(&(m_DanWei.m_civic), civicnum, civic);
	xuanxiang(&(m_DanWei.m_build), buildingnum, building);
	xuanxiang(&(m_DanWei.m_tihuan), unitnum, unit);
	xuanxiang(&(m_DanWei.m_shengji), unitnum, unit);
	xuanxiang(&(m_DanWei.m_ziyuan), ziyuannum, ziyuan);
	//界面7数据初始化
	xuanxiangwu(&(m_ZhengCe.m_qianzhi), civicnum, civic);
	xuanxiang(&(m_ZhengCe.m_guoshi), zhengcenum, zhengce);
	xuanxiang(&(m_ZhengCe.m_texing), zongtexingnum, zongtexing);
	//界面8数据初始化
	xuanxiang(&(m_XinTiao.m_texing), zongtexingnum, zongtexing);
	//界面13数据初始化
	xuanxiangwu(&(m_TiaoJian.m_tj), tiaojiannum, tiaojian);
	//界面14数据初始化
	xuanxiangwu(&(m_TeXing.m_texing), texingnum, texing);
	xuanxiang(&(m_TeXing.m_tiaojian), zongtiaojiannum, zongtiaojian);

	//初始化界面
	m_JianZhu.csh();
	m_QiGuan.csh();
	m_WenMing.csh();
	m_LingXiu.csh();
	m_KeJi.csh();
	m_DanWei.csh();
	m_ZhengCe.csh();
	m_XinTiao.csh();
	m_TiaoJian.csh();
	m_TeXing.csh();
}


void CCIV6Dlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (dat.Open(L"civ6.dat", CFile::modeCreate | CFile::modeWrite))
	{
		dat.Close();
		if (building)
		{
			delete[] building;
		}
		if (tech)
		{
			delete[] tech;
		}
		if (civic)
		{
			delete[] civic;
		}
		if (texing)
		{
			delete[] texing;
		}
		if (tiaojian)
		{
			delete[] tiaojian;
		}
		if (zongtexing)
		{
			delete[] zongtexing;
		}
		if (zongtiaojian)
		{
			delete[] zongtiaojian;
		}
		if (pro)
		{
			delete pro;
		}
		csh();
	}
	else
	{
		MessageBox(L"新建工程失败！");
		exit(1);
	}
}


void CCIV6Dlg::OnBnClickedButton7()
{
	// TODO: 在此添加控件通知处理程序代码
	pro->xinjian();
	GetDlgItem(IDC_BUTTON4)->EnableWindow(true);
	GetDlgItem(IDC_BUTTON5)->EnableWindow(false);
}


void CCIV6Dlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;
	i = pro->qian();
	if (i)
	{
		if (i < 0)
		{
			GetDlgItem(IDC_BUTTON4)->EnableWindow(false);
		}
	}
	else
	{
		GetDlgItem(IDC_BUTTON4)->EnableWindow(false);
	}
	GetDlgItem(IDC_BUTTON5)->EnableWindow(true);
}


void CCIV6Dlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;
	i = pro->hou();
	if (i < 0)
	{
		GetDlgItem(IDC_BUTTON5)->EnableWindow(false);
	}
	GetDlgItem(IDC_BUTTON4)->EnableWindow(true);
}


void CCIV6Dlg::OnDropFiles(HDROP hDropInfo)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	TCHAR fn[255];
	ZeroMemory(fn, 255);
	DragQueryFile(hDropInfo, 0, fn, 254);
	if (lstrlen(fn) != 0)
	{
		m_mulu.SetWindowTextW(fn);
	}

	CDialogEx::OnDropFiles(hDropInfo);
}
