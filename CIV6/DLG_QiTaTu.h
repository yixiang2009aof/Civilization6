#pragma once


// DLG_ZiRanQiGuan �Ի���

class DLG_QiTaTu : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_QiTaTu)

public:
	DLG_QiTaTu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_QiTaTu();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
