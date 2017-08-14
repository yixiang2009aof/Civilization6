#pragma once
#include "afxwin.h"


// DLG_JianZhu 对话框

class DLG_JianZhu : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_JianZhu)

public:
	DLG_JianZhu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_JianZhu();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_type;
	CEdit m_name;
	CEdit m_d;
	CEdit m_cost;
	CComboBox m_dis;
	CComboBox m_pur;
	CComboBox m_advi;
	CEdit m_house;
//	CEdit m_main;
	CEdit m_pmax;
	CEdit m_wmax;
	CEdit m_main;
	CEdit m_enter;
	CEdit m_range;
	CButton m_river;
	CComboBox m_pb;
	CComboBox m_tech;
	CComboBox m_civic;
	CComboBox m_tx;
	CComboBox m_tj;
	CEdit m_food;
	CEdit m_channeng;
	CEdit m_gold;
	CEdit m_keyan;
//	CEdit m_shizheng;
	CEdit m_wenhua;
	CEdit m_xinyang;
	afx_msg void OnBnClickedCheck2();
	CButton m_c1;
	CButton m_c2;
	CButton m_c3;
	CButton m_c4;
	CButton m_c5;
	CButton m_c6;
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck7();
	void csh();
	CComboBox m_tihuan;
	CComboBox m_huchi;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
