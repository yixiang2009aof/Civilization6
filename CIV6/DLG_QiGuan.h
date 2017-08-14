#pragma once
#include "afxwin.h"


// DLG_QiGuan 对话框

class DLG_QiGuan : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_QiGuan)

public:
	DLG_QiGuan(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_QiGuan();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_type;
	CEdit m_name;
	CEdit m_d;
	CEdit m_cost;
	CEdit m_yinyong;
	CComboBox m_advi;
	CComboBox m_tech;
	CComboBox m_civic;
	CComboBox m_dis;
	CComboBox m_res;
//	CButton m_tcaoyuan;
	CButton m_vt_caoyuan;
	CButton m_vt_pingyuan;
	CButton m_vt_shamo;
	CButton m_vt_dongtu;
	CButton m_vt_xueyuan;
	CButton m_vt_shanmai;
	CButton m_vt_qiuling;
//	CButton m_vt_hupo;
	CButton m_vt_haian;
	CButton m_vt_haiyang;
	CButton m_rf_shenlin;
	CButton m_rf_yulin;
	CButton m_rf_zhaoze;
	CButton m_rf_lvzhou;
	CButton m_rf_chongji;
	CButton m_rf_fubing;
	CButton m_vf_shenlin;
	CButton m_vf_yulin;
	CButton m_vf_zhaoze;
	CButton m_vf_lvzhou;
	CButton m_vf_chongji;
	CButton m_vf_fubing;
	CButton m_c1;
	CButton m_c2;
	CButton m_c3;
	CButton m_c4;
	CButton m_c5;
	CButton m_c6;
	CEdit m_food;
	CEdit m_channeng;
	CEdit m_gold;
	CEdit m_keyan;
	CEdit m_wenhua;
	CEdit m_xinyang;
	CComboBox m_tx;
	CComboBox m_tj;
	CButton m_w1;
	CButton m_w2;
	CButton m_w3;
	CButton m_w4;
	CButton m_w5;
	CButton m_w6;
	CButton m_w7;
	CButton m_w8;
	CButton m_w9;
	CButton m_j1;
	CButton m_j2;
	CButton m_j3;
	CButton m_j4;
	CButton m_j5;
	CButton m_j6;
	CEdit m_yuyan;
	CEdit m_junshi;
	CEdit m_haijun;
	CEdit m_kexue;
	CEdit m_gongcheng;
	CEdit m_shangren;
	CEdit m_wenxue;
	CEdit m_yishu;
	CEdit m_yinyue;
	CEdit m_wanneng;
	CEdit m_wenwu;
	CEdit m_yiwu;
	CEdit m_shuxie;
	CEdit m_meishu;
	CEdit m_yuequ;
	CButton m_xuanze;
	CButton m_linjinshanmai;
	CButton m_linjinludi;
	CButton m_chuangjianzongjiao;
	CButton m_baolei;
	CButton m_river;
	void csh();
	int xuanze;
	afx_msg void OnBnClickedCheck49();
	afx_msg void OnBnClickedCheck50();
	afx_msg void OnBnClickedCheck51();
	afx_msg void OnBnClickedCheck52();
	afx_msg void OnBnClickedCheck53();
	afx_msg void OnBnClickedCheck54();
	afx_msg void OnBnClickedCheck43();
	afx_msg void OnBnClickedCheck44();
	afx_msg void OnBnClickedCheck45();
	afx_msg void OnBnClickedCheck46();
	afx_msg void OnBnClickedCheck47();
	afx_msg void OnBnClickedCheck48();
	afx_msg void OnBnClickedCheck34();
	afx_msg void OnBnClickedCheck35();
	afx_msg void OnBnClickedCheck36();
	afx_msg void OnBnClickedCheck37();
	afx_msg void OnBnClickedCheck38();
	afx_msg void OnBnClickedCheck39();
	afx_msg void OnBnClickedCheck40();
	afx_msg void OnBnClickedCheck41();
	afx_msg void OnBnClickedCheck42();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
//	CButton m_xuanze2;
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
};
