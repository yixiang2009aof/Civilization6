// DLG_KeJi.cpp : 实现文件
//

#include "stdafx.h"
#include "CIV6.h"
#include "DLG_KeJi.h"
#include "afxdialogex.h"
#include "v.h"


// DLG_KeJi 对话框

IMPLEMENT_DYNAMIC(DLG_KeJi, CDialogEx)

DLG_KeJi::DLG_KeJi(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
{

}

DLG_KeJi::~DLG_KeJi()
{
}

void DLG_KeJi::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO1, m_zhonglei);
	DDX_Control(pDX, IDC_EDIT1, m_type);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT3, m_d);
	DDX_Control(pDX, IDC_EDIT4, m_cost);
	DDX_Control(pDX, IDC_COMBO3, m_advi);
	DDX_Control(pDX, IDC_COMBO4, m_era);
	DDX_Control(pDX, IDC_EDIT17, m_shu);
	DDX_Control(pDX, IDC_EDIT39, m_yinshu);
	DDX_Control(pDX, IDC_COMBO5, m_kejishizheng);
	DDX_Control(pDX, IDC_COMBO20, m_boost);
	DDX_Control(pDX, IDC_COMBO11, m_texing);
	//  DDX_Control(pDX, IDC_COMBO13, unit);
	DDX_Control(pDX, IDC_COMBO13, m_unit);
	DDX_Control(pDX, IDC_EDIT6, m_num);
	DDX_Control(pDX, IDC_COMBO14, m_gailiang);
	DDX_Control(pDX, IDC_COMBO15, m_jianzhu);
	DDX_Control(pDX, IDC_COMBO16, m_ziyuan);
	DDX_Control(pDX, IDC_COMBO21, m_keji);
	DDX_Control(pDX, IDC_COMBO22, m_shizheng);
	DDX_Control(pDX, IDC_COMBO23, m_dis);
	DDX_Control(pDX, IDC_LIST1, m_blist);
	DDX_Control(pDX, IDC_LIST3, m_list);
	DDX_Control(pDX, IDC_CHECK1, m_chongfu);
	DDX_Control(pDX, IDC_EDIT54, m_yinshu2);
	DDX_Control(pDX, IDC_EDIT55, m_miaoshu);
	DDX_Control(pDX, IDC_EDIT56, m_miaoshu2);
}

void DLG_KeJi::csh()
{
	int i;
	m_xuanze = 0;
	m_zhonglei.SetCheck(1);
	((CButton *)(this->GetDlgItem(IDC_RADIO2)))->SetCheck(0);
	m_blist.ResetContent();
	m_kejishizheng.ResetContent();
	m_kejishizheng.AddString(L"无");
	for (i = 1; i <= technum; i++)
	{
		m_kejishizheng.AddString(tech[i].name);
	}
	m_kejishizheng.SetCurSel(0);

	m_type.SetWindowTextW(L"");
	m_name.SetWindowTextW(L"");
	m_d.SetWindowTextW(L"");
	m_cost.SetWindowTextW(L"1");
	m_shu.SetWindowTextW(L"0");
	m_yinshu.SetWindowTextW(L"");
	m_yinshu2.SetWindowTextW(L"");
	m_miaoshu.SetWindowTextW(L"");
	m_miaoshu2.SetWindowTextW(L"");
	m_num.SetWindowTextW(L"1");
	m_advi.SetCurSel(0);
	m_era.SetCurSel(0);
	m_unit.SetCurSel(0);
	m_gailiang.SetCurSel(0);
	m_jianzhu.SetCurSel(0);
	m_ziyuan.SetCurSel(0);
	m_keji.SetCurSel(0);
	m_shizheng.SetCurSel(0);
	m_dis.SetCurSel(0);
	m_kejishizheng.SetCurSel(0);
	m_boost.SetCurSel(0);
	m_texing.SetCurSel(0);
	m_list.ResetContent();
	m_blist.ResetContent();
}


BEGIN_MESSAGE_MAP(DLG_KeJi, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &DLG_KeJi::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &DLG_KeJi::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON1, &DLG_KeJi::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DLG_KeJi::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DLG_KeJi::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &DLG_KeJi::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON8, &DLG_KeJi::OnBnClickedButton8)
	ON_CBN_SELCHANGE(IDC_COMBO20, &DLG_KeJi::OnCbnSelchangeCombo20)
	ON_BN_CLICKED(IDC_BUTTON5, &DLG_KeJi::OnBnClickedButton5)
END_MESSAGE_MAP()


// DLG_KeJi 消息处理程序


void DLG_KeJi::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;
	if (m_xuanze == 1)
	{
		m_xuanze = 0;
		m_blist.ResetContent();
		m_kejishizheng.ResetContent();
		m_kejishizheng.AddString(L"无");
		for (i = 1; i <= technum; i++)
		{
			m_kejishizheng.AddString(tech[i].name);
		}
		m_kejishizheng.SetCurSel(0);
	}
}


void DLG_KeJi::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;
	if (m_xuanze == 0)
	{
		m_xuanze = 1;
		m_blist.ResetContent();
		m_kejishizheng.ResetContent();
		m_kejishizheng.AddString(L"无");
		for (i = 1; i <= civicnum; i++)
		{
			m_kejishizheng.AddString(civic[i].name);
		}
		m_kejishizheng.SetCurSel(0);
	}
}


void DLG_KeJi::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;
	CString str, temp;

	i = m_kejishizheng.GetCurSel();
	m_kejishizheng.GetWindowTextW(temp);
	if (i)
	{
		str.Format(L"%d:%s", i, temp);
		m_blist.InsertString(-1, str);
	}
}


void DLG_KeJi::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;

	i = m_blist.GetCurSel();
	m_blist.DeleteString(i);
}


void DLG_KeJi::OnBnClickedButton3()
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


void DLG_KeJi::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;

	i = m_list.GetCurSel();
	m_list.DeleteString(i);
}


void DLG_KeJi::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	csh();
}


void DLG_KeJi::OnCbnSelchangeCombo20()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;

	i = m_boost.GetCurSel();
	if (tc[i][0] == 1)
	{
		m_unit.EnableWindow(true);
	}
	else
	{
		m_unit.EnableWindow(false);
	}
	if (tc[i][1] == 1)
	{
		m_num.EnableWindow(true);
	}
	else
	{
		m_num.EnableWindow(false);
	}
	if (tc[i][2] == 1)
	{
		m_gailiang.EnableWindow(true);
	}
	else
	{
		m_gailiang.EnableWindow(false);
	}
	if (tc[i][3] == 1)
	{
		m_jianzhu.EnableWindow(true);
	}
	else
	{
		m_jianzhu.EnableWindow(false);
	}
	if (tc[i][4] == 1)
	{
		m_ziyuan.EnableWindow(true);
	}
	else
	{
		m_ziyuan.EnableWindow(false);
	}
	if (tc[i][5] == 1)
	{
		m_keji.EnableWindow(true);
	}
	else
	{
		m_keji.EnableWindow(false);
	}
	if (tc[i][6] == 1)
	{
		m_shizheng.EnableWindow(true);
	}
	else
	{
		m_shizheng.EnableWindow(false);
	}
	if (tc[i][7] == 1)
	{
		m_dis.EnableWindow(true);
	}
	else
	{
		m_dis.EnableWindow(false);
	}
}


void DLG_KeJi::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString type, name, d, cost, shu;

	m_type.GetWindowTextW(type);
	m_name.GetWindowTextW(name);
	m_d.GetWindowTextW(d);
	m_cost.GetWindowTextW(cost);
	m_shu.GetWindowTextW(shu);

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
	if (shu.IsEmpty())
	{
		MessageBox(L"请将相关数据填写完整");
		return;
	}

	pro->keji(this);
	pro->baocunone(&dat);
}
