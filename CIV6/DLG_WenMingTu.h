#pragma once


// DLG_ZiYuan 对话框

class DLG_WenMingTu : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_WenMingTu)

public:
	DLG_WenMingTu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_WenMingTu();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG9 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
