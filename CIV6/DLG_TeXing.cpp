// DLG_TeXing.cpp : 实现文件
//

#include "stdafx.h"
#include "CIV6.h"
#include "DLG_TeXing.h"
#include "afxdialogex.h"
#include "v.h"


// DLG_TeXing 对话框

IMPLEMENT_DYNAMIC(DLG_TeXing, CDialogEx)

DLG_TeXing::DLG_TeXing(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG14, pParent)
{

}

DLG_TeXing::~DLG_TeXing()
{
}

void DLG_TeXing::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_type);
	DDX_Control(pDX, IDC_COMBO3, m_tiaojian);
	DDX_Control(pDX, IDC_EDIT2, m_miaoshu);
	DDX_Control(pDX, IDC_EDIT3, m_fujia);
	DDX_Control(pDX, IDC_CHECK3, m_f1);
	DDX_Control(pDX, IDC_CHECK31, m_f2);
	DDX_Control(pDX, IDC_CHECK4, m_f3);
	DDX_Control(pDX, IDC_COMBO17, m_yongyou);
	DDX_Control(pDX, IDC_COMBO4, m_texing);
	DDX_Control(pDX, IDC_COMBO2, m_arg1);
	DDX_Control(pDX, IDC_COMBO5, m_arg2);
	DDX_Control(pDX, IDC_COMBO11, m_arg3);
	DDX_Control(pDX, IDC_COMBO12, m_arg4);
	DDX_Control(pDX, IDC_COMBO13, m_arg5);
	DDX_Control(pDX, IDC_COMBO14, m_arg6);
	DDX_Control(pDX, IDC_COMBO15, m_arg7);
	DDX_Control(pDX, IDC_COMBO16, m_arg8);
	//  DDX_Control(pDX, IDC_CHECK5, m_p);
	DDX_Control(pDX, IDC_CHECK78, m_xwenzi);
	DDX_Control(pDX, IDC_EDIT4, m_wenzi);
}


BEGIN_MESSAGE_MAP(DLG_TeXing, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK4, &DLG_TeXing::OnBnClickedCheck4)
	ON_CBN_SELCHANGE(IDC_COMBO4, &DLG_TeXing::OnCbnSelchangeCombo4)
	ON_BN_CLICKED(IDC_BUTTON3, &DLG_TeXing::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &DLG_TeXing::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_CHECK78, &DLG_TeXing::OnBnClickedCheck78)
END_MESSAGE_MAP()


// DLG_TeXing 消息处理程序


void DLG_TeXing::csh()
{
	m_type.SetWindowTextW(L"");
	m_miaoshu.SetWindowTextW(L"");
	m_fujia.EnableWindow(false);
	m_fujia.SetWindowTextW(L"-1");
	m_wenzi.EnableWindow(false);
	m_wenzi.SetWindowTextW(L"");
	m_tiaojian.SetCurSel(0);
	m_texing.SetCurSel(0);
	m_yongyou.SetCurSel(0);
	m_f1.SetCheck(0);
	m_f2.SetCheck(0);
	m_f3.SetCheck(0);
	m_xwenzi.SetCheck(0);
	//m_p.SetCheck(0);
	GetDlgItem(ARG1)->SetWindowTextW(L"产出类型：");
	GetDlgItem(ARG2)->SetWindowTextW(L"数值：");
	GetDlgItem(ARG1)->ShowWindow(true);
	GetDlgItem(ARG2)->ShowWindow(true);
	GetDlgItem(ARG3)->ShowWindow(false);
	GetDlgItem(ARG4)->ShowWindow(false);
	GetDlgItem(ARG5)->ShowWindow(false);
	GetDlgItem(ARG6)->ShowWindow(false);
	GetDlgItem(ARG7)->ShowWindow(false);
	GetDlgItem(ARG8)->ShowWindow(false);
	m_arg1.ResetContent();
	m_arg1.AddString(L"食物");
	m_arg1.AddString(L"产能");
	m_arg1.AddString(L"金币");
	m_arg1.AddString(L"文化");
	m_arg1.AddString(L"科研");
	m_arg1.AddString(L"信仰");
	m_arg1.SetCurSel(0);
	m_arg2.ResetContent();
	m_arg2.SetCurSel(0);
	m_arg1.ShowWindow(true);
	m_arg2.ShowWindow(true);
	m_arg3.ShowWindow(false);
	m_arg4.ShowWindow(false);
	m_arg5.ShowWindow(false);
	m_arg6.ShowWindow(false);
	m_arg7.ShowWindow(false);
	m_arg8.ShowWindow(false);
	arg1 = 78;
	arg2 = 5;
	arg3 = arg4 = arg5 = arg6 = arg7 = arg8 = 0;
	number = 2;
}

void DLG_TeXing::OnBnClickedCheck4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_f3.GetCheck())
	{
		m_fujia.EnableWindow(true);
	}
	else
	{
		m_fujia.EnableWindow(false);
	}
}


void DLG_TeXing::OnCbnSelchangeCombo4()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;
	number = 0;
	i = m_texing.GetCurSel();

	if (arg1 = pro->canshu(GetDlgItem(ARG1), &m_arg1, texing[i].arg1))
	{
		number++;
	}
	if (arg2 = pro->canshu(GetDlgItem(ARG2), &m_arg2, texing[i].arg2))
	{
		number++;
	}
	if (arg3 = pro->canshu(GetDlgItem(ARG3), &m_arg3, texing[i].arg3))
	{
		number++;
	}
	if (arg4 = pro->canshu(GetDlgItem(ARG4), &m_arg4, texing[i].arg4))
	{
		number++;
	}
	if (arg5 = pro->canshu(GetDlgItem(ARG5), &m_arg5, texing[i].arg5))
	{
		number++;
	}
	if (arg6 = pro->canshu(GetDlgItem(ARG6), &m_arg6, texing[i].arg6))
	{
		number++;
	}
	if (arg7 = pro->canshu(GetDlgItem(ARG7), &m_arg7, texing[i].arg7))
	{
		number++;
	}
	if (arg8 = pro->canshu(GetDlgItem(ARG8), &m_arg8, texing[i].arg8))
	{
		number++;
	}
	pro->canshu(NULL, NULL, L"");//重置可选参数信息
}


void DLG_TeXing::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	csh();
}


void DLG_TeXing::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	CString temp, str;
	CString type;

	m_type.GetWindowTextW(type);

	if (type.IsEmpty())
	{
		MessageBox(L"请将相关数据填写完整");
		return;
	}

	argstr = L"";
	m_type.GetWindowTextW(str);
	if (arg1)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG1), &m_arg1, arg1).IsEmpty()))//参数字符串为空说明无效或没有选择的可选参数
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", str, ::argstr[arg1], pro->fancanshu(GetDlgItem(ARG1), &m_arg1, arg1));
			argstr += temp;
		}
	}
	if (arg2)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG2), &m_arg2, arg2).IsEmpty()))//参数字符串为空说明无效或没有选择的可选参数
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", str, ::argstr[arg2], pro->fancanshu(GetDlgItem(ARG2), &m_arg2, arg2));
			argstr += temp;
		}
	}
	if (arg3)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG3), &m_arg3, arg3).IsEmpty()))//参数字符串为空说明无效或没有选择的可选参数
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", str, ::argstr[arg3], pro->fancanshu(GetDlgItem(ARG3), &m_arg3, arg3));
			argstr += temp;
		}
	}
	if (arg4)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG4), &m_arg4, arg4).IsEmpty()))//参数字符串为空说明无效或没有选择的可选参数
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", str, ::argstr[arg4], pro->fancanshu(GetDlgItem(ARG4), &m_arg4, arg4));
			argstr += temp;
		}
	}
	if (arg5)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG5), &m_arg5, arg5).IsEmpty()))//参数字符串为空说明无效或没有选择的可选参数
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", str, ::argstr[arg5], pro->fancanshu(GetDlgItem(ARG5), &m_arg5, arg5));
			argstr += temp;
		}
	}
	if (arg6)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG6), &m_arg6, arg6).IsEmpty()))//参数字符串为空说明无效或没有选择的可选参数
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", str, ::argstr[arg6], pro->fancanshu(GetDlgItem(ARG6), &m_arg6, arg6));
			argstr += temp;
		}
	}
	if (arg7)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG7), &m_arg7, arg7).IsEmpty()))//参数字符串为空说明无效或没有选择的可选参数
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", str, ::argstr[arg7], pro->fancanshu(GetDlgItem(ARG7), &m_arg7, arg7));
			argstr += temp;
		}
	}
	if (arg8)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG8), &m_arg8, arg8).IsEmpty()))//参数字符串为空说明无效或没有选择的可选参数
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", str, ::argstr[arg8], pro->fancanshu(GetDlgItem(ARG8), &m_arg8, arg8));
			argstr += temp;
		}
	}
	pro->fancanshu(NULL, NULL, 0);
	pro->texing(this);
	pro->baocunone(&dat);
}


void DLG_TeXing::OnBnClickedCheck78()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_xwenzi.GetCheck())
	{
		m_wenzi.EnableWindow(true);
	}
	else
	{
		m_wenzi.EnableWindow(false);
	}
}
