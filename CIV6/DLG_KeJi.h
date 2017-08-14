#pragma once
#include "afxwin.h"


// DLG_KeJi 对话框

class DLG_KeJi : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_KeJi)

public:
	DLG_KeJi(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_KeJi();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_zhonglei;
	CEdit m_type;
	CEdit m_name;
	CEdit m_d;
	CEdit m_cost;
	CComboBox m_advi;
	CComboBox m_era;
	CEdit m_shu;
	CEdit m_yinshu;
	CComboBox m_kejishizheng;
	CComboBox m_boost;
	CComboBox m_texing;
//	CComboBox unit;
	CComboBox m_unit;
	CEdit m_num;
	CComboBox m_gailiang;
	CComboBox m_jianzhu;
	CComboBox m_ziyuan;
	CComboBox m_keji;
	CComboBox m_shizheng;
	CComboBox m_dis;
	int m_xuanze;
	void csh();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	CListBox m_blist;
	CListBox m_list;
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnCbnSelchangeCombo20();
	afx_msg void OnBnClickedButton5();
	CButton m_chongfu;
	CEdit m_yinshu2;
	CEdit m_miaoshu;
	CEdit m_miaoshu2;
};
