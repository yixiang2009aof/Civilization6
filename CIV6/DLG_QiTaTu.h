#pragma once


// DLG_ZiRanQiGuan 对话框

class DLG_QiTaTu : public CDialogEx
{
	DECLARE_DYNAMIC(DLG_QiTaTu)

public:
	DLG_QiTaTu(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~DLG_QiTaTu();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG12 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
