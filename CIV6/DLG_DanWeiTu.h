#pragma once


// DLG_WeiRen �Ի���

class DLG_DanWeiTu : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_DanWeiTu)

public:
	DLG_DanWeiTu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_DanWeiTu();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG11 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
