#pragma once
#include "afxwin.h"


// DLG_LingXiu 对话框

class DLG_LingXiu : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_LingXiu)

public:
	DLG_LingXiu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_LingXiu();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_type;
	CEdit m_name;
	CEdit m_d;
	CEdit m_yinshu;
//	CEdit m_tname;
	CEdit m_ttype;
	CEdit m_tname;
	CEdit m_td;
	CComboBox m_wenming;
	CComboBox m_yicheng;
	CComboBox m_wjianzhu;
	CComboBox m_wdanwei;
	CEdit m_zhong;
	CEdit m_zlv;
	CEdit m_zlan;
	CEdit m_ztou;
	CEdit m_fhong;
	CEdit m_flv;
	CEdit m_flan;
	CEdit m_ftou;
	CListBox m_list;
	CComboBox m_texing;
	CComboBox m_jianzhu;
	CEdit m_jianzhud;
	CComboBox m_danwei;
	CEdit m_danweid;
	CComboBox m_shouxuan;
	CEdit m_ai;
	CComboBox m_xitong;
	CComboBox m_xuanxiang;
	CEdit m_shuzhi;
	void csh();
	CListBox m_ailist;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnCbnSelchangeCombo33();
	CEdit m_shoudu;
};
