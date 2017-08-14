#pragma once
#include "afxwin.h"


// DLG_TeXing 对话框

class DLG_TeXing : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_TeXing)

public:
	DLG_TeXing(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_TeXing();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG14 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_type;
	CComboBox m_tiaojian;
	CEdit m_miaoshu;
	CEdit m_fujia;
	CButton m_f1;
	CButton m_f2;
	CButton m_f3;
	CComboBox m_yongyou;
	CComboBox m_texing;
	CComboBox m_arg1;
	CComboBox m_arg2;
	CComboBox m_arg3;
	CComboBox m_arg4;
	CComboBox m_arg5;
	CComboBox m_arg6;
	CComboBox m_arg7;
	CComboBox m_arg8;
	int arg1;
	int arg2;
	int arg3;
	int arg4;
	int arg5;
	int arg6;
	int arg7;
	int arg8;
	int number;
	CString argstr;
	void csh();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton2();
//	CButton m_p;
	CButton m_xwenzi;
	CEdit m_wenzi;
	afx_msg void OnBnClickedCheck78();
};
