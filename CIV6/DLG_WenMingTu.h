#pragma once


// DLG_ZiYuan �Ի���

class DLG_WenMingTu : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_WenMingTu)

public:
	DLG_WenMingTu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_WenMingTu();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
