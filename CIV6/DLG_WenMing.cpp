// DLG_WenMing.cpp : 实现文件
//

#include "stdafx.h"
#include "CIV6.h"
#include "DLG_WenMing.h"
#include "afxdialogex.h"
#include "v.h"


// DLG_WenMing 对话框

IMPLEMENT_DYNAMIC(DLG_WenMing, CDialogEx)

DLG_WenMing::DLG_WenMing(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

DLG_WenMing::~DLG_WenMing()
{
}

void DLG_WenMing::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_type);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT3, m_d);
	DDX_Control(pDX, IDC_EDIT40, m_txtype);
	DDX_Control(pDX, IDC_EDIT4, m_txname);
	DDX_Control(pDX, IDC_EDIT39, m_txd);
	DDX_Control(pDX, IDC_COMBO1, m_qiyuan);
	DDX_Control(pDX, IDC_COMBO4, m_jianzhu);
	DDX_Control(pDX, IDC_COMBO5, m_danwei);
	DDX_Control(pDX, IDC_COMBO11, m_texing);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_EDIT6, m_c1);
	DDX_Control(pDX, IDC_EDIT7, m_c2);
	DDX_Control(pDX, IDC_EDIT8, m_c3);
	DDX_Control(pDX, IDC_EDIT9, m_c4);
	DDX_Control(pDX, IDC_EDIT10, m_c5);
	DDX_Control(pDX, IDC_EDIT41, m_c6);
	DDX_Control(pDX, IDC_EDIT42, m_c7);
	DDX_Control(pDX, IDC_EDIT11, m_c8);
	DDX_Control(pDX, IDC_EDIT18, m_c9);
	DDX_Control(pDX, IDC_EDIT43, m_c10);
	DDX_Control(pDX, IDC_EDIT44, m_c11);
	DDX_Control(pDX, IDC_EDIT12, m_c12);
	DDX_Control(pDX, IDC_EDIT13, m_c14);
	DDX_Control(pDX, IDC_EDIT45, m_c13);
	DDX_Control(pDX, IDC_EDIT46, m_c15);
	DDX_Control(pDX, IDC_EDIT47, m_c17);
	DDX_Control(pDX, IDC_EDIT14, m_c16);
	DDX_Control(pDX, IDC_EDIT15, m_c18);
	DDX_Control(pDX, IDC_EDIT48, m_c19);
	DDX_Control(pDX, IDC_EDIT16, m_c20);
	DDX_Control(pDX, IDC_CHECK9, m_heliu);
	DDX_Control(pDX, IDC_CHECK10, m_ziyuan);
	DDX_Control(pDX, IDC_CHECK11, m_dimao);
	DDX_Control(pDX, IDC_CHECK55, m_dixing);
	DDX_Control(pDX, IDC_COMBO17, m_ziyuanc);
	DDX_Control(pDX, IDC_COMBO18, m_dimaoc);
	DDX_Control(pDX, IDC_COMBO19, m_dixingc);
	DDX_Control(pDX, IDC_EDIT19, m_heliug);
	DDX_Control(pDX, IDC_EDIT49, m_ziyuang);
	DDX_Control(pDX, IDC_EDIT50, m_dimaog);
	DDX_Control(pDX, IDC_EDIT51, m_dixingg);
	DDX_Control(pDX, IDC_EDIT52, m_jianzhud);
	DDX_Control(pDX, IDC_EDIT53, m_danweid);
}

void DLG_WenMing::csh()
{
	m_type.SetWindowTextW(L"");
	m_name.SetWindowTextW(L"");
	m_d.SetWindowTextW(L"");
	m_txtype.SetWindowTextW(L"");
	m_txname.SetWindowTextW(L"");
	m_txd.SetWindowTextW(L"");
	m_qiyuan.SetCurSel(0);
	m_jianzhu.SetCurSel(0);
	m_danwei.SetCurSel(0);
	m_jianzhud.SetWindowTextW(L"");
	m_danweid.SetWindowTextW(L"");
	m_texing.SetCurSel(0);
	m_list.ResetContent();
	m_c1.SetWindowTextW(L"城市1");
	m_c2.SetWindowTextW(L"城市2");
	m_c3.SetWindowTextW(L"城市3");
	m_c4.SetWindowTextW(L"城市4");
	m_c5.SetWindowTextW(L"城市5");
	m_c6.SetWindowTextW(L"城市6");
	m_c7.SetWindowTextW(L"城市7");
	m_c8.SetWindowTextW(L"城市8");
	m_c9.SetWindowTextW(L"城市9");
	m_c10.SetWindowTextW(L"城市10");
	m_c11.SetWindowTextW(L"城市11");
	m_c12.SetWindowTextW(L"城市12");
	m_c13.SetWindowTextW(L"城市13");
	m_c14.SetWindowTextW(L"城市14");
	m_c15.SetWindowTextW(L"城市15");
	m_c16.SetWindowTextW(L"城市16");
	m_c17.SetWindowTextW(L"城市17");
	m_c18.SetWindowTextW(L"城市18");
	m_c19.SetWindowTextW(L"城市19");
	m_c20.SetWindowTextW(L"城市20");
	m_heliu.SetCheck(0);
	m_ziyuan.SetCheck(0);
	m_dimao.SetCheck(0);
	m_dixing.SetCheck(0);
	m_ziyuanc.SetCurSel(0);
	m_dimaoc.SetCurSel(0);
	m_dixingc.SetCurSel(0);
	m_heliug.SetWindowTextW(L"2");
	m_ziyuang.SetWindowTextW(L"2");
	m_dimaog.SetWindowTextW(L"2");
	m_dixingg.SetWindowTextW(L"2");
	m_ziyuanc.EnableWindow(false);
	m_dimaoc.EnableWindow(false);
	m_dixingc.EnableWindow(false);
	m_heliug.EnableWindow(false);
	m_ziyuang.EnableWindow(false);
	m_dimaog.EnableWindow(false);
	m_dixingg.EnableWindow(false);
}


BEGIN_MESSAGE_MAP(DLG_WenMing, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK9, &DLG_WenMing::OnBnClickedCheck9)
	ON_BN_CLICKED(IDC_CHECK10, &DLG_WenMing::OnBnClickedCheck10)
	ON_BN_CLICKED(IDC_CHECK11, &DLG_WenMing::OnBnClickedCheck11)
	ON_BN_CLICKED(IDC_CHECK55, &DLG_WenMing::OnBnClickedCheck55)
	ON_BN_CLICKED(IDC_BUTTON4, &DLG_WenMing::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &DLG_WenMing::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DLG_WenMing::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DLG_WenMing::OnBnClickedButton3)
END_MESSAGE_MAP()


// DLG_WenMing 消息处理程序


void DLG_WenMing::OnBnClickedCheck9()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_heliu.GetCheck())
	{
		m_heliug.EnableWindow(true);
	}
	else
	{
		m_heliug.EnableWindow(false);
	}
}


void DLG_WenMing::OnBnClickedCheck10()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_ziyuan.GetCheck())
	{
		m_ziyuanc.EnableWindow(true);
		m_ziyuang.EnableWindow(true);
	}
	else
	{
		m_ziyuanc.EnableWindow(false);
		m_ziyuang.EnableWindow(false);
	}
}


void DLG_WenMing::OnBnClickedCheck11()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_dimao.GetCheck())
	{
		m_dimaoc.EnableWindow(true);
		m_dimaog.EnableWindow(true);
	}
	else
	{
		m_dimaoc.EnableWindow(false);
		m_dimaog.EnableWindow(false);
	}
}


void DLG_WenMing::OnBnClickedCheck55()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_dixing.GetCheck())
	{
		m_dixingc.EnableWindow(true);
		m_dixingg.EnableWindow(true);
	}
	else
	{
		m_dixingc.EnableWindow(false);
		m_dixingg.EnableWindow(false);
	}
}


void DLG_WenMing::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	csh();
}


void DLG_WenMing::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;
	CString str, temp;

	i = m_texing.GetCurSel();
	m_texing.GetWindowTextW(temp);
	if (i)
	{
		str.Format(L"%d:%s", i, temp);
		m_list.InsertString(-1, str);
	}
}


void DLG_WenMing::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;

	i = m_list.GetCurSel();
	m_list.DeleteString(i);
}


void DLG_WenMing::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString type, name, d;
	CString ttype, tname, td;

	m_type.GetWindowTextW(type);
	m_name.GetWindowTextW(name);
	m_d.GetWindowTextW(d);
	m_txtype.GetWindowTextW(ttype);
	m_txname.GetWindowTextW(tname);
	m_txd.GetWindowTextW(td);

	if (type.IsEmpty())
	{
		MessageBox(L"请将相关数据填写完整");
		return;
	}
	if (name.IsEmpty())
	{
		MessageBox(L"请将相关数据填写完整");
		return;
	}
	if (d.IsEmpty())
	{
		MessageBox(L"请将相关数据填写完整");
		return;
	}
	if (ttype.IsEmpty())
	{
		MessageBox(L"请将相关数据填写完整");
		return;
	}
	if (tname.IsEmpty())
	{
		MessageBox(L"请将相关数据填写完整");
		return;
	}
	if (td.IsEmpty())
	{
		MessageBox(L"请将相关数据填写完整");
		return;
	}
	
	pro->wenming(this);
	pro->baocunone(&dat);
}
