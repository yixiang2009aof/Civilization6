// DLG_ZhengTi.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CIV6.h"
#include "DLG_XinTiao.h"
#include "afxdialogex.h"
#include "v.h"


// DLG_ZhengTi �Ի���

IMPLEMENT_DYNAMIC(DLG_XinTiao, CDialogEx)

DLG_XinTiao::DLG_XinTiao(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG8, pParent)
{

}

DLG_XinTiao::~DLG_XinTiao()
{
}

void DLG_XinTiao::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_type);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT3, m_d);
	DDX_Control(pDX, IDC_EDIT4, m_type2);
	DDX_Control(pDX, IDC_EDIT17, m_name2);
	DDX_Control(pDX, IDC_EDIT39, m_d2);
	//  DDX_Control(pDX, IDC_COMBO5, m_xingtiao);
	DDX_Control(pDX, IDC_COMBO32, m_texing);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_COMBO11, m_tubiao);
	DDX_Control(pDX, IDC_CHECK1, m_shendian);
	DDX_Control(pDX, IDC_CHECK80, m_mingming);
	DDX_Control(pDX, IDC_EDIT6, m_hong);
	DDX_Control(pDX, IDC_EDIT8, m_lv);
	DDX_Control(pDX, IDC_EDIT66, m_lan);
	DDX_Control(pDX, IDC_EDIT10, m_tou);
	DDX_Control(pDX, IDC_COMBO5, m_xintiao);
}

void DLG_XinTiao::csh()
{
	m_type.SetWindowTextW(L"");
	m_name.SetWindowTextW(L"");
	m_d.SetWindowTextW(L"");
	m_type2.SetWindowTextW(L"");
	m_name2.SetWindowTextW(L"");
	m_d2.SetWindowTextW(L"");
	m_hong.SetWindowTextW(L"0");
	m_lv.SetWindowTextW(L"0");
	m_lan.SetWindowTextW(L"0");
	m_tou.SetWindowTextW(L"255");
	m_xintiao.SetCurSel(0);
	m_texing.SetCurSel(0);
	m_tubiao.ResetContent();
	m_tubiao.AddString(L"�����");
	m_tubiao.AddString(L"���");
	m_tubiao.AddString(L"������");
	m_tubiao.AddString(L"���˼��");
	m_tubiao.AddString(L"ӡ�Ƚ�");
	m_tubiao.AddString(L"��˹����");
	m_tubiao.AddString(L"��̫��");
	m_tubiao.AddString(L"������");
	m_tubiao.AddString(L"�½�");
	m_tubiao.AddString(L"�����");
	m_tubiao.AddString(L"���˽�");
	m_tubiao.AddString(L"����");
	m_tubiao.AddString(L"�ݻ��");
	m_tubiao.AddString(L"��������1");
	m_tubiao.AddString(L"��������2");
	m_tubiao.AddString(L"��������3");
	m_tubiao.AddString(L"��������4");
	m_tubiao.AddString(L"��������5");
	m_tubiao.AddString(L"��������6");
	m_tubiao.AddString(L"��������7");
	m_tubiao.AddString(L"��������8");
	m_tubiao.AddString(L"��������9");
	m_tubiao.AddString(L"��������10");
	m_tubiao.AddString(L"��������11");
	m_tubiao.AddString(L"��������12");
	m_tubiao.SetCurSel(0);
	m_shendian.SetCheck(0);
	m_mingming.SetCheck(0);
	m_list.ResetContent();
}


BEGIN_MESSAGE_MAP(DLG_XinTiao, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON4, &DLG_XinTiao::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &DLG_XinTiao::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON2, &DLG_XinTiao::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &DLG_XinTiao::OnBnClickedButton1)
END_MESSAGE_MAP()


// DLG_ZhengTi ��Ϣ�������


void DLG_XinTiao::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	csh();
}


void DLG_XinTiao::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString type, name, d;

	m_type.GetWindowTextW(type);
	m_name.GetWindowTextW(name);
	m_d.GetWindowTextW(d);

	if (type.IsEmpty())
	{
		m_type2.GetWindowTextW(type);
		m_name2.GetWindowTextW(name);
		m_d2.GetWindowTextW(d);
	}
	if (type.IsEmpty())
	{
		MessageBox(L"�뽫���������д����");
		return;
	}
	if (name.IsEmpty())
	{
		MessageBox(L"�뽫���������д����");
		return;
	}
	if (d.IsEmpty())
	{
		MessageBox(L"�뽫���������д����");
		return;
	}

	pro->xintiao(this);
	pro->baocunone(&dat);
}


void DLG_XinTiao::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i;

	i = m_list.GetCurSel();
	m_list.DeleteString(i);
}


void DLG_XinTiao::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i;
	CString str, temp;

	i = m_texing.GetCurSel();
	m_texing.GetWindowTextW(temp);
	if (i)
	{
		str.Format(L"%d:%s", i, temp);
		m_list.InsertString(-1, str);
	}
}
