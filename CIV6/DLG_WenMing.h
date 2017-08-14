#pragma once
#include "afxwin.h"


// DLG_WenMing 对话框

class DLG_WenMing : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_WenMing)

public:
	DLG_WenMing(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_WenMing();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	void csh();
	CEdit m_type;
	CEdit m_name;
	CEdit m_d;
	CEdit m_txtype;
	CEdit m_txname;
	CEdit m_txd;
	CComboBox m_qiyuan;
	CComboBox m_jianzhu;
	CComboBox m_danwei;
	CComboBox m_texing;
	CListBox m_list;
	CEdit m_c1;
	CEdit m_c2;
	CEdit m_c3;
	CEdit m_c4;
	CEdit m_c5;
	CEdit m_c6;
	CEdit m_c7;
	CEdit m_c8;
	CEdit m_c9;
	CEdit m_c10;
	CEdit m_c11;
	CEdit m_c12;
	CEdit m_c14;
	CEdit m_c13;
	CEdit m_c15;
	CEdit m_c17;
	CEdit m_c16;
	CEdit m_c18;
	CEdit m_c19;
	CEdit m_c20;
	CButton m_heliu;
	CButton m_ziyuan;
	CButton m_dimao;
	CButton m_dixing;
	CComboBox m_ziyuanc;
	CComboBox m_dimaoc;
	CComboBox m_dixingc;
	CEdit m_heliug;
	CEdit m_ziyuang;
	CEdit m_dimaog;
	CEdit m_dixingg;
	afx_msg void OnBnClickedCheck9();
	afx_msg void OnBnClickedCheck10();
	afx_msg void OnBnClickedCheck11();
	afx_msg void OnBnClickedCheck55();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CEdit m_jianzhud;
	CEdit m_danweid;
};
