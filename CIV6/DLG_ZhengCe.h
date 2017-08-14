#pragma once
#include "afxwin.h"


// DLG_ZhengCe 对话框

class DLG_ZhengCe : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_ZhengCe)

public:
	DLG_ZhengCe(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_ZhengCe();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_zhonglei;
	CEdit m_type;
	CEdit m_name;
	CEdit m_d;
	CComboBox m_qianzhi;
	CComboBox m_caowei;
	CComboBox m_guoshi;
	CComboBox m_texing;
	CListBox m_list;
	CEdit m_duan;
	CEdit m_chang;
	CEdit m_guyou;
	CEdit m_dishi;
	CEdit m_dianshu;
	CEdit m_yuzhi;
	CEdit m_shizhe;
	CComboBox m_chuancheng;
	CButton m_cjunshi;
	CButton m_cjingji;
	CButton m_cwaijiao;
	CButton m_ctongyong;
	CEdit m_junshi;
	CEdit m_jingji;
	CEdit m_waijiao;
	CEdit m_tongyong;
	int m_xuanze;
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	void csh();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck34();
	afx_msg void OnBnClickedCheck8();
	afx_msg void OnBnClickedCheck79();
};
