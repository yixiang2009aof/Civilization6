#pragma once
#include "afxwin.h"


// DLG_ZhengTi 对话框

class DLG_XinTiao : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_XinTiao)

public:
	DLG_XinTiao(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_XinTiao();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG8 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_type;
	CEdit m_name;
	CEdit m_d;
	CEdit m_type2;
	CEdit m_name2;
	CEdit m_d2;
//	CComboBox m_xingtiao;
	CComboBox m_texing;
	CListBox m_list;
	CComboBox m_tubiao;
	CButton m_shendian;
	CButton m_mingming;
	CEdit m_hong;
	CEdit m_lv;
	CEdit m_lan;
	CEdit m_tou;
	void csh();
	CComboBox m_xintiao;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
