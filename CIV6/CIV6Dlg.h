
// CIV6Dlg.h : 头文件
//

#pragma once
#include "afxcmn.h"
#include "DLG_JianZhu.h"
#include "DLG_QiGuan.h"
#include "DLG_WenMing.h"
#include "DLG_LingXiu.h"
#include "DLG_KeJi.h"
#include "DLG_DanWei.h"
#include "DLG_ZhengCe.h"
#include "DLG_XinTiao.h"
#include "DLG_WenMingTu.h"
#include "DLG_LingXiuTu.h"
#include "DLG_DanWeiTu.h"
#include "DLG_QiTaTu.h"
#include "DLG_TiaoJian.h"
#include "DLG_TeXing.h"
#include "afxwin.h"
#include "afxeditbrowsectrl.h"


// CCIV6Dlg 对话框
class CCIV6Dlg : public CDialogEx
{
// 构造
public:
	CCIV6Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CIV6_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	void csh();
	void shuaxin();
	void xuanxiang(CComboBox * box, int num, struct civ6 * shuju);
	void xuanxiangwu(CComboBox * box, int num, struct civ666 * shuju);
	void xuanxiangwu(CComboBox * box, int num, struct civ6 * shuju);
	CTabCtrl m_tab;
	DLG_JianZhu m_JianZhu;
	DLG_QiGuan m_QiGuan;
	DLG_WenMing m_WenMing;
	DLG_LingXiu m_LingXiu;
	DLG_KeJi m_KeJi;
	DLG_DanWei m_DanWei;
	DLG_ZhengCe m_ZhengCe;
	DLG_XinTiao m_XinTiao;
	DLG_WenMingTu m_ZiYuan;
	DLG_LingXiuTu m_JuZuo;
	DLG_DanWeiTu m_WeiRen;
	DLG_QiTaTu m_ZiRanQiGuan;
	DLG_TiaoJian m_TiaoJian;
	DLG_TeXing m_TeXing;
	afx_msg void OnTcnSelchangeTab1(NMHDR *pNMHDR, LRESULT *pResult);
	afx_msg void OnDestroy();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	CButton m_qian;
	CButton m_hou;
	CButton m_delete;
	CButton m_output;
	CEdit m_name;
	CEdit m_zuozhe;
	CEdit m_miaoshu;
	CMFCEditBrowseCtrl m_mulu;
	afx_msg void OnDropFiles(HDROP hDropInfo);
	CEdit m_zhongwen;
};
