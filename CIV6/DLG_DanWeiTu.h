#pragma once


// DLG_WeiRen 对话框

class DLG_DanWeiTu : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_DanWeiTu)

public:
	DLG_DanWeiTu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_DanWeiTu();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG11 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
