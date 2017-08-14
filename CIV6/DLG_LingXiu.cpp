// DLG_LingXiu.cpp : 实现文件
//

#include "stdafx.h"
#include "CIV6.h"
#include "DLG_LingXiu.h"
#include "afxdialogex.h"
#include "v.h"


// DLG_LingXiu 对话框

IMPLEMENT_DYNAMIC(DLG_LingXiu, CDialogEx)

DLG_LingXiu::DLG_LingXiu(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

DLG_LingXiu::~DLG_LingXiu()
{
}

void DLG_LingXiu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_type);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT3, m_d);
	DDX_Control(pDX, IDC_EDIT17, m_yinshu);
	//  DDX_Control(pDX, IDC_EDIT40, m_tname);
	DDX_Control(pDX, IDC_EDIT40, m_ttype);
	DDX_Control(pDX, IDC_EDIT4, m_tname);
	DDX_Control(pDX, IDC_EDIT39, m_td);
	DDX_Control(pDX, IDC_COMBO4, m_wenming);
	DDX_Control(pDX, IDC_COMBO5, m_yicheng);
	DDX_Control(pDX, IDC_COMBO35, m_wjianzhu);
	DDX_Control(pDX, IDC_COMBO36, m_wdanwei);
	DDX_Control(pDX, IDC_EDIT5, m_zhong);
	DDX_Control(pDX, IDC_EDIT6, m_zlv);
	DDX_Control(pDX, IDC_EDIT62, m_zlan);
	DDX_Control(pDX, IDC_EDIT7, m_ztou);
	DDX_Control(pDX, IDC_EDIT8, m_fhong);
	DDX_Control(pDX, IDC_EDIT9, m_flv);
	DDX_Control(pDX, IDC_EDIT63, m_flan);
	DDX_Control(pDX, IDC_EDIT41, m_ftou);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_COMBO32, m_texing);
	DDX_Control(pDX, IDC_COMBO9, m_jianzhu);
	DDX_Control(pDX, IDC_EDIT52, m_jianzhud);
	DDX_Control(pDX, IDC_COMBO10, m_danwei);
	DDX_Control(pDX, IDC_EDIT53, m_danweid);
	DDX_Control(pDX, IDC_COMBO6, m_shouxuan);
	DDX_Control(pDX, IDC_EDIT44, m_ai);
	DDX_Control(pDX, IDC_COMBO33, m_xitong);
	DDX_Control(pDX, IDC_COMBO34, m_xuanxiang);
	DDX_Control(pDX, IDC_EDIT64, m_shuzhi);
	DDX_Control(pDX, IDC_LIST4, m_ailist);
	DDX_Control(pDX, IDC_EDIT65, m_shoudu);
}

void DLG_LingXiu::csh()
{
	int i;
	m_type.SetWindowTextW(L"");
	m_name.SetWindowTextW(L"");
	m_d.SetWindowTextW(L"");
	m_yinshu.SetWindowTextW(L"");
	m_ttype.SetWindowTextW(L"");
	m_tname.SetWindowTextW(L"");
	m_td.SetWindowTextW(L"");
	m_jianzhud.SetWindowTextW(L"");
	m_danweid.SetWindowTextW(L"");
	m_shoudu.SetWindowTextW(L"");
	m_ai.SetWindowTextW(L"");
	m_shuzhi.SetWindowTextW(L"0");
	m_zhong.SetWindowTextW(L"0");
	m_zlv.SetWindowTextW(L"0");
	m_zlan.SetWindowTextW(L"0");
	m_ztou.SetWindowTextW(L"255");
	m_fhong.SetWindowTextW(L"255");
	m_flv.SetWindowTextW(L"255");
	m_flan.SetWindowTextW(L"255");
	m_ftou.SetWindowTextW(L"255");
	m_wenming.SetCurSel(0);
	m_yicheng.SetCurSel(0);
	m_wjianzhu.SetCurSel(0);
	m_wdanwei.SetCurSel(0);
	m_jianzhu.SetCurSel(0);
	m_danwei.SetCurSel(0);
	m_shouxuan.SetCurSel(0);
	m_xitong.SetCurSel(0);
	m_xuanxiang.ResetContent();
	for (i = 1; i <= buildingnum; i++)
	{
		m_xuanxiang.AddString(building[i].name);
	}
	m_xuanxiang.SetCurSel(0);
	m_texing.SetCurSel(0);
	m_list.ResetContent();
	m_ailist.ResetContent();
}


BEGIN_MESSAGE_MAP(DLG_LingXiu, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON3, &DLG_LingXiu::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &DLG_LingXiu::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON1, &DLG_LingXiu::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DLG_LingXiu::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON11, &DLG_LingXiu::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON5, &DLG_LingXiu::OnBnClickedButton5)
	ON_CBN_SELCHANGE(IDC_COMBO33, &DLG_LingXiu::OnCbnSelchangeCombo33)
END_MESSAGE_MAP()


// DLG_LingXiu 消息处理程序


void DLG_LingXiu::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	CString type, name, d, yinshu;
	CString ttype, tname, td;

	m_type.GetWindowTextW(type);
	m_name.GetWindowTextW(name);
	m_d.GetWindowTextW(d);
	m_yinshu.GetWindowTextW(yinshu);
	m_ttype.GetWindowTextW(ttype);
	m_tname.GetWindowTextW(tname);
	m_td.GetWindowTextW(td);

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
	if (yinshu.IsEmpty())
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

	pro->lingxiu(this);
	pro->baocunone(&dat);
}


void DLG_LingXiu::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码
	csh();
}


void DLG_LingXiu::OnBnClickedButton1()
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


void DLG_LingXiu::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;

	i = m_list.GetCurSel();
	m_list.DeleteString(i);
}


void DLG_LingXiu::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;

	i = m_ailist.GetCurSel();
	m_ailist.DeleteString(i);
}


void DLG_LingXiu::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码
	int i, j;
	CString str, temp, temp2;
	CString type;

	i = m_xitong.GetCurSel();
	m_xitong.GetWindowTextW(temp);
	j = m_xuanxiang.GetCurSel();
	m_xuanxiang.GetWindowTextW(temp2);
	m_shuzhi.GetWindowTextW(str);
	m_ai.GetWindowTextW(type);
	if (!type.IsEmpty())
	{
		str.Format(L"%d:%d:%s:%s:%s:%s", i, j, str, type, temp, temp2);
		m_ailist.InsertString(-1, str);
	}
}


void DLG_LingXiu::OnCbnSelchangeCombo33()
{
	// TODO: 在此添加控件通知处理程序代码
	int i;

	i = m_xitong.GetCurSel();
	m_xuanxiang.ResetContent();
	switch (i)
	{
	case 0:
		for (i = 1; i <= buildingnum; i++)
		{
			m_xuanxiang.AddString(building[i].name);
		}
		break;
	case 1:
		for (i = 1; i <= technum; i++)
		{
			m_xuanxiang.AddString(tech[i].name);
		}
		break;
	case 2:
		for (i = 1; i <= civicnum; i++)
		{
			m_xuanxiang.AddString(civic[i].name);
		}
		break;
	case 3:
		for (i = 0; i < 6; i++)
		{
			m_xuanxiang.AddString(yie[i]);
		}
		break;
	case 4:
		for (i = 1; i <= unitnum; i++)
		{
			m_xuanxiang.AddString(unit[i].name);
		}
		break;
	}
	m_xuanxiang.SetCurSel(0);
}
