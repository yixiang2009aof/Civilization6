// DLG_JianZhu.cpp : 实现文件
//

#include "stdafx.h"
#include "CIV6.h"
#include "DLG_JianZhu.h"
#include "afxdialogex.h"
#include "v.h"


// DLG_JianZhu 对话框

IMPLEMENT_DYNAMIC(DLG_JianZhu, CDialogEx)

DLG_JianZhu::DLG_JianZhu(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
{

}

DLG_JianZhu::~DLG_JianZhu()
{
}

void DLG_JianZhu::csh()
{
	m_type.SetWindowTextW(L"");
	m_name.SetWindowTextW(L"");
	m_d.SetWindowTextW(L"");
	m_dis.SetCurSel(0);
	m_pur.SetCurSel(0);
	m_advi.SetCurSel(0);
	m_pb.SetCurSel(0);
	m_tihuan.SetCurSel(0);
	m_huchi.SetCurSel(0);
	m_tech.SetCurSel(0);
	m_civic.SetCurSel(0);
	m_tx.SetCurSel(0);
	m_tj.SetCurSel(0);
	m_cost.SetWindowTextW(L"1");
	m_house.SetWindowTextW(L"0");
	m_enter.SetWindowTextW(L"0");
	m_pmax.SetWindowTextW(L"-1");
	m_wmax.SetWindowTextW(L"-1");
	m_main.SetWindowTextW(L"0");
	m_range.SetWindowTextW(L"0");
	m_food.SetWindowTextW(L"1");
	m_channeng.SetWindowTextW(L"1");
	m_gold.SetWindowTextW(L"1");
	m_keyan.SetWindowTextW(L"1");
	m_wenhua.SetWindowTextW(L"1");
	m_xinyang.SetWindowTextW(L"1");
	m_food.EnableWindow(false);
	m_channeng.EnableWindow(false);
	m_gold.EnableWindow(false);
	m_keyan.EnableWindow(false);
	m_wenhua.EnableWindow(false);
	m_xinyang.EnableWindow(false);
	m_river.SetCheck(0);
	m_c1.SetCheck(0);
	m_c2.SetCheck(0);
	m_c3.SetCheck(0);
	m_c4.SetCheck(0);
	m_c5.SetCheck(0);
	m_c6.SetCheck(0);
}

void DLG_JianZhu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_type);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT3, m_d);
	DDX_Control(pDX, IDC_EDIT4, m_cost);
	DDX_Control(pDX, IDC_COMBO1, m_dis);
	DDX_Control(pDX, IDC_COMBO2, m_pur);
	DDX_Control(pDX, IDC_COMBO3, m_advi);
	DDX_Control(pDX, IDC_EDIT5, m_house);
	//  DDX_Control(pDX, IDC_EDIT6, m_main);
	DDX_Control(pDX, IDC_EDIT7, m_pmax);
	DDX_Control(pDX, IDC_EDIT8, m_wmax);
	DDX_Control(pDX, IDC_EDIT9, m_main);
	DDX_Control(pDX, IDC_EDIT6, m_enter);
	DDX_Control(pDX, IDC_EDIT10, m_range);
	DDX_Control(pDX, IDC_CHECK1, m_river);
	DDX_Control(pDX, IDC_COMBO6, m_pb);
	DDX_Control(pDX, IDC_COMBO4, m_tech);
	DDX_Control(pDX, IDC_COMBO5, m_civic);
	DDX_Control(pDX, IDC_COMBO7, m_tx);
	DDX_Control(pDX, IDC_COMBO8, m_tj);
	DDX_Control(pDX, IDC_EDIT11, m_food);
	DDX_Control(pDX, IDC_EDIT12, m_channeng);
	DDX_Control(pDX, IDC_EDIT13, m_gold);
	DDX_Control(pDX, IDC_EDIT14, m_keyan);
	//  DDX_Control(pDX, IDC_EDIT15, m_shizheng);
	DDX_Control(pDX, IDC_EDIT15, m_wenhua);
	DDX_Control(pDX, IDC_EDIT16, m_xinyang);
	DDX_Control(pDX, IDC_CHECK2, m_c1);
	DDX_Control(pDX, IDC_CHECK3, m_c2);
	DDX_Control(pDX, IDC_CHECK4, m_c3);
	DDX_Control(pDX, IDC_CHECK5, m_c4);
	DDX_Control(pDX, IDC_CHECK6, m_c5);
	DDX_Control(pDX, IDC_CHECK7, m_c6);
	DDX_Control(pDX, IDC_COMBO9, m_tihuan);
	DDX_Control(pDX, IDC_COMBO10, m_huchi);
}


BEGIN_MESSAGE_MAP(DLG_JianZhu, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK2, &DLG_JianZhu::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK3, &DLG_JianZhu::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &DLG_JianZhu::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &DLG_JianZhu::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &DLG_JianZhu::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &DLG_JianZhu::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_BUTTON2, &DLG_JianZhu::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &DLG_JianZhu::OnBnClickedButton1)
END_MESSAGE_MAP()


// DLG_JianZhu 消息处理程序


void DLG_JianZhu::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_c1.GetCheck())
	{
		m_food.EnableWindow(true);
	}
	else
	{
		m_food.EnableWindow(false);
	}
}


void DLG_JianZhu::OnBnClickedCheck3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_c2.GetCheck())
	{
		m_channeng.EnableWindow(true);
	}
	else
	{
		m_channeng.EnableWindow(false);
	}
}


void DLG_JianZhu::OnBnClickedCheck4()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_c3.GetCheck())
	{
		m_gold.EnableWindow(true);
	}
	else
	{
		m_gold.EnableWindow(false);
	}
}


void DLG_JianZhu::OnBnClickedCheck5()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_c4.GetCheck())
	{
		m_keyan.EnableWindow(true);
	}
	else
	{
		m_keyan.EnableWindow(false);
	}
}


void DLG_JianZhu::OnBnClickedCheck6()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_c5.GetCheck())
	{
		m_wenhua.EnableWindow(true);
	}
	else
	{
		m_wenhua.EnableWindow(false);
	}
}


void DLG_JianZhu::OnBnClickedCheck7()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_c6.GetCheck())
	{
		m_xinyang.EnableWindow(true);
	}
	else
	{
		m_xinyang.EnableWindow(false);
	}
}


void DLG_JianZhu::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	csh();
}


void DLG_JianZhu::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString type, name, d, cost;

	m_type.GetWindowTextW(type);
	m_name.GetWindowTextW(name);
	m_d.GetWindowTextW(d);
	m_cost.GetWindowTextW(cost);

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
	if (cost.IsEmpty())
	{
		MessageBox(L"请将相关数据填写完整");
		return;
	}

	pro->jianzhu(this);
	pro->baocunone(&dat);
}
