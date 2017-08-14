// DLG_QiGuan.cpp : 实现文件
//

#include "stdafx.h"
#include "CIV6.h"
#include "DLG_QiGuan.h"
#include "afxdialogex.h"
#include "v.h"


// DLG_QiGuan 对话框

IMPLEMENT_DYNAMIC(DLG_QiGuan, CDialogEx)

DLG_QiGuan::DLG_QiGuan(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

DLG_QiGuan::~DLG_QiGuan()
{
}

void DLG_QiGuan::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_type);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT3, m_d);
	DDX_Control(pDX, IDC_EDIT4, m_cost);
	DDX_Control(pDX, IDC_EDIT17, m_yinyong);
	DDX_Control(pDX, IDC_COMBO3, m_advi);
	DDX_Control(pDX, IDC_COMBO4, m_tech);
	DDX_Control(pDX, IDC_COMBO5, m_civic);
	DDX_Control(pDX, IDC_COMBO2, m_dis);
	DDX_Control(pDX, IDC_COMBO12, m_res);
	//  DDX_Control(pDX, IDC_CHECK24, m_tcaoyuan);
	DDX_Control(pDX, IDC_CHECK24, m_vt_caoyuan);
	DDX_Control(pDX, IDC_CHECK25, m_vt_pingyuan);
	DDX_Control(pDX, IDC_CHECK26, m_vt_shamo);
	DDX_Control(pDX, IDC_CHECK27, m_vt_dongtu);
	DDX_Control(pDX, IDC_CHECK28, m_vt_xueyuan);
	DDX_Control(pDX, IDC_CHECK29, m_vt_shanmai);
	DDX_Control(pDX, IDC_CHECK30, m_vt_qiuling);
	//DDX_Control(pDX, IDC_CHECK31, m_vt_hupo);
	DDX_Control(pDX, IDC_CHECK32, m_vt_haian);
	DDX_Control(pDX, IDC_CHECK33, m_vt_haiyang);
	DDX_Control(pDX, IDC_CHECK12, m_rf_shenlin);
	DDX_Control(pDX, IDC_CHECK13, m_rf_yulin);
	DDX_Control(pDX, IDC_CHECK14, m_rf_zhaoze);
	DDX_Control(pDX, IDC_CHECK15, m_rf_lvzhou);
	DDX_Control(pDX, IDC_CHECK16, m_rf_chongji);
	DDX_Control(pDX, IDC_CHECK17, m_rf_fubing);
	DDX_Control(pDX, IDC_CHECK18, m_vf_shenlin);
	DDX_Control(pDX, IDC_CHECK19, m_vf_yulin);
	DDX_Control(pDX, IDC_CHECK20, m_vf_zhaoze);
	DDX_Control(pDX, IDC_CHECK21, m_vf_lvzhou);
	DDX_Control(pDX, IDC_CHECK22, m_vf_chongji);
	DDX_Control(pDX, IDC_CHECK23, m_vf_fubing);
	DDX_Control(pDX, IDC_CHECK43, m_c1);
	DDX_Control(pDX, IDC_CHECK44, m_c2);
	DDX_Control(pDX, IDC_CHECK45, m_c3);
	DDX_Control(pDX, IDC_CHECK46, m_c4);
	DDX_Control(pDX, IDC_CHECK47, m_c5);
	DDX_Control(pDX, IDC_CHECK48, m_c6);
	DDX_Control(pDX, IDC_EDIT27, m_food);
	DDX_Control(pDX, IDC_EDIT28, m_channeng);
	DDX_Control(pDX, IDC_EDIT29, m_gold);
	DDX_Control(pDX, IDC_EDIT30, m_keyan);
	DDX_Control(pDX, IDC_EDIT31, m_wenhua);
	DDX_Control(pDX, IDC_EDIT32, m_xinyang);
	DDX_Control(pDX, IDC_COMBO7, m_tx);
	DDX_Control(pDX, IDC_COMBO8, m_tj);
	DDX_Control(pDX, IDC_CHECK34, m_w1);
	DDX_Control(pDX, IDC_CHECK35, m_w2);
	DDX_Control(pDX, IDC_CHECK36, m_w3);
	DDX_Control(pDX, IDC_CHECK37, m_w4);
	DDX_Control(pDX, IDC_CHECK38, m_w5);
	DDX_Control(pDX, IDC_CHECK39, m_w6);
	DDX_Control(pDX, IDC_CHECK40, m_w7);
	DDX_Control(pDX, IDC_CHECK41, m_w8);
	DDX_Control(pDX, IDC_CHECK42, m_w9);
	DDX_Control(pDX, IDC_CHECK49, m_j1);
	DDX_Control(pDX, IDC_CHECK50, m_j2);
	DDX_Control(pDX, IDC_CHECK51, m_j3);
	DDX_Control(pDX, IDC_CHECK52, m_j4);
	DDX_Control(pDX, IDC_CHECK53, m_j5);
	DDX_Control(pDX, IDC_CHECK54, m_j6);
	DDX_Control(pDX, IDC_EDIT18, m_yuyan);
	DDX_Control(pDX, IDC_EDIT19, m_junshi);
	DDX_Control(pDX, IDC_EDIT20, m_haijun);
	DDX_Control(pDX, IDC_EDIT21, m_kexue);
	DDX_Control(pDX, IDC_EDIT22, m_gongcheng);
	DDX_Control(pDX, IDC_EDIT23, m_shangren);
	DDX_Control(pDX, IDC_EDIT24, m_wenxue);
	DDX_Control(pDX, IDC_EDIT25, m_yishu);
	DDX_Control(pDX, IDC_EDIT26, m_yinyue);
	DDX_Control(pDX, IDC_EDIT33, m_wanneng);
	DDX_Control(pDX, IDC_EDIT34, m_wenwu);
	DDX_Control(pDX, IDC_EDIT35, m_yiwu);
	DDX_Control(pDX, IDC_EDIT36, m_shuxie);
	DDX_Control(pDX, IDC_EDIT37, m_meishu);
	DDX_Control(pDX, IDC_EDIT38, m_yuequ);
	DDX_Control(pDX, IDC_RADIO3, m_xuanze);
	DDX_Control(pDX, IDC_CHECK9, m_linjinshanmai);
	DDX_Control(pDX, IDC_CHECK10, m_linjinludi);
	DDX_Control(pDX, IDC_CHECK8, m_chuangjianzongjiao);
	DDX_Control(pDX, IDC_CHECK11, m_baolei);
	DDX_Control(pDX, IDC_CHECK1, m_river);
	//  DDX_Control(pDX, IDC_BUTTON1, m_xuanze2);
}

void DLG_QiGuan::csh()
{
	m_type.SetWindowTextW(L"");
	m_name.SetWindowTextW(L"");
	m_d.SetWindowTextW(L"");
	m_cost.SetWindowTextW(L"0");
	m_yinyong.SetWindowTextW(L"");
	m_advi.SetCurSel(0);
	m_tech.SetCurSel(0);
	m_civic.SetCurSel(0);
	m_tx.SetCurSel(0);
	m_tj.SetCurSel(0);
	m_dis.SetCurSel(0);
	m_res.SetCurSel(0);
	m_tx.SetCurSel(0);
	m_tj.SetCurSel(0);
	m_vt_caoyuan.SetCheck(0);
	m_vt_pingyuan.SetCheck(0);
	m_vt_shamo.SetCheck(0);
	m_vt_dongtu.SetCheck(0);
	m_vt_xueyuan.SetCheck(0);
	m_vt_qiuling.SetCheck(0);
	//m_vt_hupo.SetCheck(0);
	m_vt_haian.SetCheck(0);
	m_vt_haiyang.SetCheck(0);
	m_vt_shanmai.SetCheck(0);
	m_rf_shenlin.SetCheck(0);
	m_rf_yulin.SetCheck(0);
	m_rf_zhaoze.SetCheck(0);
	m_rf_lvzhou.SetCheck(0);
	m_rf_chongji.SetCheck(0);
	m_rf_fubing.SetCheck(0);
	m_vf_shenlin.SetCheck(0);
	m_vf_yulin.SetCheck(0);
	m_vf_zhaoze.SetCheck(0);
	m_vf_lvzhou.SetCheck(0);
	m_vf_chongji.SetCheck(0);
	m_vf_fubing.SetCheck(0);
	m_linjinshanmai.SetCheck(0);
	m_linjinludi.SetCheck(0);
	m_chuangjianzongjiao.SetCheck(0);
	m_baolei.SetCheck(0);
	m_river.SetCheck(0);
	m_c1.SetCheck(0);
	m_c2.SetCheck(0);
	m_c3.SetCheck(0);
	m_c4.SetCheck(0);
	m_c5.SetCheck(0);
	m_c6.SetCheck(0);
	m_food.EnableWindow(false);
	m_channeng.EnableWindow(false);
	m_gold.EnableWindow(false);
	m_keyan.EnableWindow(false);
	m_wenhua.EnableWindow(false);
	m_xinyang.EnableWindow(false);
	m_food.SetWindowTextW(L"1");
	m_channeng.SetWindowTextW(L"1");
	m_gold.SetWindowTextW(L"1");
	m_keyan.SetWindowTextW(L"1");
	m_wenhua.SetWindowTextW(L"1");
	m_xinyang.SetWindowTextW(L"1");
	m_j1.SetCheck(0);
	m_j2.SetCheck(0);
	m_j3.SetCheck(0);
	m_j4.SetCheck(0);
	m_j5.SetCheck(0);
	m_j6.SetCheck(0);
	m_wanneng.EnableWindow(false);
	m_wenwu.EnableWindow(false);
	m_yiwu.EnableWindow(false);
	m_shuxie.EnableWindow(false);
	m_meishu.EnableWindow(false);
	m_yuequ.EnableWindow(false);
	m_wanneng.SetWindowTextW(L"1");
	m_wenwu.SetWindowTextW(L"1");
	m_yiwu.SetWindowTextW(L"1");
	m_shuxie.SetWindowTextW(L"1");
	m_meishu.SetWindowTextW(L"1");
	m_yuequ.SetWindowTextW(L"1");
	m_w1.SetCheck(0);
	m_w2.SetCheck(0);
	m_w3.SetCheck(0);
	m_w4.SetCheck(0);
	m_w5.SetCheck(0);
	m_w6.SetCheck(0);
	m_w7.SetCheck(0);
	m_w8.SetCheck(0);
	m_w9.SetCheck(0);
	m_yuyan.EnableWindow(false);
	m_junshi.EnableWindow(false);
	m_haijun.EnableWindow(false);
	m_kexue.EnableWindow(false);
	m_gongcheng.EnableWindow(false);
	m_shangren.EnableWindow(false);
	m_wenxue.EnableWindow(false);
	m_yishu.EnableWindow(false);
	m_yinyue.EnableWindow(false);
	m_yuyan.SetWindowTextW(L"1");
	m_junshi.SetWindowTextW(L"1");
	m_haijun.SetWindowTextW(L"1");
	m_kexue.SetWindowTextW(L"1");
	m_gongcheng.SetWindowTextW(L"1");
	m_shangren.SetWindowTextW(L"1");
	m_wenxue.SetWindowTextW(L"1");
	m_yishu.SetWindowTextW(L"1");
	m_yinyue.SetWindowTextW(L"1");
	m_xuanze.SetCheck(1);
}


BEGIN_MESSAGE_MAP(DLG_QiGuan, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK49, &DLG_QiGuan::OnBnClickedCheck49)
	ON_BN_CLICKED(IDC_CHECK50, &DLG_QiGuan::OnBnClickedCheck50)
	ON_BN_CLICKED(IDC_CHECK51, &DLG_QiGuan::OnBnClickedCheck51)
	ON_BN_CLICKED(IDC_CHECK52, &DLG_QiGuan::OnBnClickedCheck52)
	ON_BN_CLICKED(IDC_CHECK53, &DLG_QiGuan::OnBnClickedCheck53)
	ON_BN_CLICKED(IDC_CHECK54, &DLG_QiGuan::OnBnClickedCheck54)
	ON_BN_CLICKED(IDC_CHECK43, &DLG_QiGuan::OnBnClickedCheck43)
	ON_BN_CLICKED(IDC_CHECK44, &DLG_QiGuan::OnBnClickedCheck44)
	ON_BN_CLICKED(IDC_CHECK45, &DLG_QiGuan::OnBnClickedCheck45)
	ON_BN_CLICKED(IDC_CHECK46, &DLG_QiGuan::OnBnClickedCheck46)
	ON_BN_CLICKED(IDC_CHECK47, &DLG_QiGuan::OnBnClickedCheck47)
	ON_BN_CLICKED(IDC_CHECK48, &DLG_QiGuan::OnBnClickedCheck48)
	ON_BN_CLICKED(IDC_CHECK34, &DLG_QiGuan::OnBnClickedCheck34)
	ON_BN_CLICKED(IDC_CHECK35, &DLG_QiGuan::OnBnClickedCheck35)
	ON_BN_CLICKED(IDC_CHECK36, &DLG_QiGuan::OnBnClickedCheck36)
	ON_BN_CLICKED(IDC_CHECK37, &DLG_QiGuan::OnBnClickedCheck37)
	ON_BN_CLICKED(IDC_CHECK38, &DLG_QiGuan::OnBnClickedCheck38)
	ON_BN_CLICKED(IDC_CHECK39, &DLG_QiGuan::OnBnClickedCheck39)
	ON_BN_CLICKED(IDC_CHECK40, &DLG_QiGuan::OnBnClickedCheck40)
	ON_BN_CLICKED(IDC_CHECK41, &DLG_QiGuan::OnBnClickedCheck41)
	ON_BN_CLICKED(IDC_CHECK42, &DLG_QiGuan::OnBnClickedCheck42)
	ON_BN_CLICKED(IDC_BUTTON2, &DLG_QiGuan::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &DLG_QiGuan::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_RADIO3, &DLG_QiGuan::OnBnClickedRadio3)
	ON_BN_CLICKED(IDC_RADIO1, &DLG_QiGuan::OnBnClickedRadio1)
	ON_BN_CLICKED(IDC_RADIO2, &DLG_QiGuan::OnBnClickedRadio2)
END_MESSAGE_MAP()


// DLG_QiGuan 消息处理程序


void DLG_QiGuan::OnBnClickedCheck49()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_j1.GetCheck())
	{
		m_wanneng.EnableWindow(true);
	}
	else
	{
		m_wanneng.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck50()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_j2.GetCheck())
	{
		m_wenwu.EnableWindow(true);
	}
	else
	{
		m_wenwu.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck51()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_j3.GetCheck())
	{
		m_yiwu.EnableWindow(true);
	}
	else
	{
		m_yiwu.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck52()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_j4.GetCheck())
	{
		m_shuxie.EnableWindow(true);
	}
	else
	{
		m_shuxie.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck53()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_j5.GetCheck())
	{
		m_meishu.EnableWindow(true);
	}
	else
	{
		m_meishu.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck54()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_j6.GetCheck())
	{
		m_yuequ.EnableWindow(true);
	}
	else
	{
		m_yuequ.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck43()
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


void DLG_QiGuan::OnBnClickedCheck44()
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


void DLG_QiGuan::OnBnClickedCheck45()
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


void DLG_QiGuan::OnBnClickedCheck46()
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


void DLG_QiGuan::OnBnClickedCheck47()
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


void DLG_QiGuan::OnBnClickedCheck48()
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


void DLG_QiGuan::OnBnClickedCheck34()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_w1.GetCheck())
	{
		m_yuyan.EnableWindow(true);
	}
	else
	{
		m_yuyan.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck35()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_w2.GetCheck())
	{
		m_junshi.EnableWindow(true);
	}
	else
	{
		m_junshi.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck36()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_w3.GetCheck())
	{
		m_haijun.EnableWindow(true);
	}
	else
	{
		m_haijun.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck37()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_w4.GetCheck())
	{
		m_kexue.EnableWindow(true);
	}
	else
	{
		m_kexue.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck38()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_w5.GetCheck())
	{
		m_gongcheng.EnableWindow(true);
	}
	else
	{
		m_gongcheng.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck39()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_w6.GetCheck())
	{
		m_shangren.EnableWindow(true);
	}
	else
	{
		m_shangren.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck40()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_w7.GetCheck())
	{
		m_wenxue.EnableWindow(true);
	}
	else
	{
		m_wenxue.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck41()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_w8.GetCheck())
	{
		m_yishu.EnableWindow(true);
	}
	else
	{
		m_yishu.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedCheck42()
{
	// TODO: 在此添加控件通知处理程序代码
	if (m_w9.GetCheck())
	{
		m_yinyue.EnableWindow(true);
	}
	else
	{
		m_yinyue.EnableWindow(false);
	}
}


void DLG_QiGuan::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	csh();
}


void DLG_QiGuan::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString type, name, d, cost, yinshu;

	m_type.GetWindowTextW(type);
	m_name.GetWindowTextW(name);
	m_d.GetWindowTextW(d);
	m_cost.GetWindowTextW(cost);
	m_yinyong.GetWindowTextW(yinshu);

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
	if (yinshu.IsEmpty())
	{
		MessageBox(L"请将相关数据填写完整");
		return;
	}

	pro->qiguan(this);
	pro->baocunone(&dat);
}


void DLG_QiGuan::OnBnClickedRadio3()
{
	// TODO: 在此添加控件通知处理程序代码
	xuanze = 0;
}


void DLG_QiGuan::OnBnClickedRadio1()
{
	// TODO: 在此添加控件通知处理程序代码
	xuanze = 1;
}


void DLG_QiGuan::OnBnClickedRadio2()
{
	// TODO: 在此添加控件通知处理程序代码
	xuanze = 2;
}
