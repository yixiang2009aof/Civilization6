#pragma once
#include "afxwin.h"


// DLG_TiaoJian �Ի���

class DLG_TiaoJian : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_TiaoJian)

public:
	DLG_TiaoJian(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_TiaoJian();
	void csh();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG13 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	CEdit m_type;
	CComboBox m_leixing;
	CEdit m_miaoshu;
	CComboBox m_tj;
	CComboBox m_arg1;
	CComboBox m_arg2;
	CComboBox m_arg3;
	CComboBox m_arg4;
	CComboBox m_arg5;
	CComboBox m_arg6;
	CComboBox m_arg7;
	CComboBox m_arg8;
	CListBox m_list;
	int number;//��Ч��������
	int arg1;
	int arg2;
	int arg3;
	int arg4;
	int arg5;
	int arg6;
	int arg7;
	int arg8;
	CString argstrs[20];//ÿ�������ַ���
	int type[20];//ÿ������������
	int strnum;//�����ַ�������
	int xuhao;//��ǰ�ַ���λ��
	afx_msg void OnCbnSelchangeCombo4();
	afx_msg void OnBnClickedButton2();
	CEdit m_name;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnLbnDblclkList2();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton4();
};
