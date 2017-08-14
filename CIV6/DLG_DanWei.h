#pragma once
#include "afxwin.h"


// DLG_DanWei 对话框

class DLG_DanWei : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_DanWei)

public:
	DLG_DanWei(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_DanWei();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_type;
	CEdit m_cost;
	CEdit m_name;
	CEdit m_d;
	CComboBox m_advi;
	CEdit m_move;
	CEdit m_shiye;
	CComboBox m_leixing;
	CComboBox m_pur;
	CComboBox m_dis;
	CComboBox m_texing;
	CComboBox m_tag;
	CComboBox m_ziyuan;
	CComboBox m_build;
	CComboBox m_jinsheng;
	CComboBox m_tech;
	CComboBox m_civic;
	CComboBox m_renkou;
	CComboBox m_tihuan;
	CComboBox m_shengji;
	CListBox m_listtx;
	CListBox m_listtag;
	CButton m_xzhanli;
	CEdit m_zhanli;
	CButton m_xyuanli;
	CEdit m_yuanli;
	CEdit m_shecheng;
	CButton m_xhongli;
	CEdit m_hongli;
	CButton m_xhaoren;
	CEdit m_haoren;
	CButton m_xjianci;
	CEdit m_jianci;
	CButton m_xzongci;
	CButton m_xzongli;
	CEdit m_zongci;
	CEdit m_zongli;
	CButton m_schengshi;
	CButton m_sfuyin;
	CButton m_sshenxun;
	CButton m_syiji;
	CButton m_sbuhuo;
	CButton m_smanzu;
	CButton m_sleijia;
	CButton m_sjinsheng;
	CButton m_ayimin;
	CButton m_agongren;
	CButton m_ashangren;
	CButton m_apingmin;
	CButton m_atansuo;
	CButton m_ajinzhan;
	CButton m_ayuancheng;
	CButton m_agongcheng;
	CButton m_aqibing;
	CButton m_azhiyuan;
	CButton m_ahewu;
	CButton m_aweiren;
	void csh();
	afx_msg void OnBnClickedCheck2();
	afx_msg void OnBnClickedCheck34();
	afx_msg void OnBnClickedCheck3();
	afx_msg void OnBnClickedCheck4();
	afx_msg void OnBnClickedCheck5();
	afx_msg void OnBnClickedCheck6();
	afx_msg void OnBnClickedCheck7();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	CButton m_xshecheng;
	afx_msg void OnBnClickedCheck76();
	CEdit m_feiyong;
	CEdit m_fangkong;
	CButton m_xfangkong;
	afx_msg void OnBnClickedCheck33();
//	CButton m_beibu;
	CButton m_sbeibu;
	CEdit m_shuoming;
};
