// DLG_ZhengCe.cpp : 实现文件
//

#include "stdafx.h"
#include "CIV6.h"
#include "DLG_ZhengCe.h"
#include "afxdialogex.h"
#include "v.h"


// DLG_ZhengCe 对话框

IMPLEMENT_DYNAMIC(DLG_ZhengCe, CDialogEx)

DLG_ZhengCe::DLG_ZhengCe(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG7, pParent)
{

}

DLG_ZhengCe::~DLG_ZhengCe()
{
}

void DLG_ZhengCe::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RADIO1, m_zhonglei);
	DDX_Control(pDX, IDC_EDIT1, m_type);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT62, m_d);
	DDX_Control(pDX, IDC_COMBO5, m_qianzhi);
	DDX_Control(pDX, IDC_COMBO20, m_caowei);
	DDX_Control(pDX, IDC_COMBO24, m_guoshi);
	DDX_Control(pDX, IDC_COMBO14, m_texing);
	DDX_Control(pDX, IDC_LIST3, m_list);
	DDX_Control(pDX, IDC_EDIT4, m_duan);
	DDX_Control(pDX, IDC_EDIT17, m_chang);
	DDX_Control(pDX, IDC_EDIT3, m_guyou);
	DDX_Control(pDX, IDC_EDIT39, m_dishi);
	DDX_Control(pDX, IDC_EDIT40, m_dianshu);
	DDX_Control(pDX, IDC_EDIT60, m_yuzhi);
	DDX_Control(pDX, IDC_EDIT61, m_shizhe);
	DDX_Control(pDX, IDC_COMBO12, m_chuancheng);
	DDX_Control(pDX, IDC_CHECK2, m_cjunshi);
	DDX_Control(pDX, IDC_CHECK34, m_cjingji);
	DDX_Control(pDX, IDC_CHECK8, m_cwaijiao);
	DDX_Control(pDX, IDC_CHECK79, m_ctongyong);
	DDX_Control(pDX, IDC_EDIT11, m_junshi);
	DDX_Control(pDX, IDC_EDIT18, m_jingji);
	DDX_Control(pDX, IDC_EDIT44, m_waijiao);
	DDX_Control(pDX, IDC_EDIT45, m_tongyong);
}


BEGIN_MESSAGE_MAP(DLG_ZhengCe, CDialogEx)
	ON_BN_CLICKED(IDC_RADIO1, &DLG_ZhengCe::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &DLG_ZhengCe::OnBnClickedRadio2)
	ON_BN_CLICKED(IDC_BUTTON5, &DLG_ZhengCe::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON10, &DLG_ZhengCe::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON3, &DLG_ZhengCe::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &DLG_ZhengCe::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_CHECK2, &DLG_ZhengCe::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK34, &DLG_ZhengCe::OnBnClickedCheck34)
	ON_BN_CLICKED(IDC_CHECK8, &DLG_ZhengCe::OnBnClickedCheck8)
	ON_BN_CLICKED(IDC_CHECK79, &DLG_ZhengCe::OnBnClickedCheck79)
END_MESSAGE_MAP()


// DLG_ZhengCe 消息处理程序


void DLG_ZhengCe::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_xuanze == 1)
	{
		m_xuanze = 0;
	}
}


void DLG_ZhengCe::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_xuanze == 0)
	{
		m_xuanze = 1;
	}
}

void DLG_ZhengCe::csh()
{
	m_xuanze = 0;
	m_zhonglei.SetCheck(1);
	((CButton *)(this->GetDlgItem(IDC_RADIO2)))->SetCheck(0);
	m_list.ResetContent();
	m_type.SetWindowTextW(L"");
	m_name.SetWindowTextW(L"");
	m_d.SetWindowTextW(L"");
	m_duan.SetWindowTextW(L"");
	m_chang.SetWindowTextW(L"");
	m_guyou.SetWindowTextW(L"");
	m_dishi.SetWindowTextW(L"2");
	m_dianshu.SetWindowTextW(L"3");
	m_yuzhi.SetWindowTextW(L"100");
	m_shizhe.SetWindowTextW(L"2");
	m_junshi.SetWindowTextW(L"1");
	m_jingji.SetWindowTextW(L"1");
	m_waijiao.SetWindowTextW(L"1");
	m_tongyong.SetWindowTextW(L"1");
	m_junshi.EnableWindow(false);
	m_jingji.EnableWindow(false);
	m_waijiao.EnableWindow(false);
	m_tongyong.EnableWindow(false);
	m_qianzhi.SetCurSel(0);
	m_caowei.SetCurSel(0);
	m_guoshi.SetCurSel(0);
	m_chuancheng.SetCurSel(0);
	m_texing.SetCurSel(0);
	m_cjunshi.SetCheck(0);
	m_cjingji.SetCheck(0);
	m_cwaijiao.SetCheck(0);
	m_ctongyong.SetCheck(0);
}


void DLG_ZhengCe::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	CString type, name;

	m_type.GetWindowTextW(type);
	m_name.GetWindowTextW(name);

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

	pro->zhengce(this);
	pro->baocunone(&dat);
}


void DLG_ZhengCe::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	csh();
}


void DLG_ZhengCe::OnBnClickedButton3()
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


void DLG_ZhengCe::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;

	i = m_list.GetCurSel();
	m_list.DeleteString(i);
}


void DLG_ZhengCe::OnBnClickedCheck2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_cjunshi.GetCheck())
	{
		m_junshi.EnableWindow(true);
	}
	else
	{
		m_junshi.EnableWindow(false);
	}
}


void DLG_ZhengCe::OnBnClickedCheck34()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_cjingji.GetCheck())
	{
		m_jingji.EnableWindow(true);
	}
	else
	{
		m_jingji.EnableWindow(false);
	}
}


void DLG_ZhengCe::OnBnClickedCheck8()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_cwaijiao.GetCheck())
	{
		m_waijiao.EnableWindow(true);
	}
	else
	{
		m_waijiao.EnableWindow(false);
	}
}


void DLG_ZhengCe::OnBnClickedCheck79()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_ctongyong.GetCheck())
	{
		m_tongyong.EnableWindow(true);
	}
	else
	{
		m_tongyong.EnableWindow(false);
	}
}
