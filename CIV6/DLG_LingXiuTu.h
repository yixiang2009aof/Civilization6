#pragma once


// DLG_JuZuo 对话框

class DLG_LingXiuTu : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_LingXiuTu)

public:
	DLG_LingXiuTu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_LingXiuTu();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG10 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
