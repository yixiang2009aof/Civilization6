#pragma once


// DLG_JuZuo �Ի���

class DLG_LingXiuTu : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_LingXiuTu)

public:
	DLG_LingXiuTu(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~DLG_LingXiuTu();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
