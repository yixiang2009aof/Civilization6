// DLG_TiaoJian.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CIV6.h"
#include "DLG_TiaoJian.h"
#include "afxdialogex.h"
#include "v.h"


// DLG_TiaoJian �Ի���

IMPLEMENT_DYNAMIC(DLG_TiaoJian, CDialogEx)

DLG_TiaoJian::DLG_TiaoJian(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG13, pParent)
{

}

DLG_TiaoJian::~DLG_TiaoJian()
{
}

void DLG_TiaoJian::csh()
{
	m_type.SetWindowTextW(L"");
	m_miaoshu.SetWindowTextW(L"");
	m_leixing.SetCurSel(0);
	m_tj.SetCurSel(0);
	GetDlgItem(ARG1)->SetWindowTextW(L"�������ͣ�");
	GetDlgItem(ARG1)->ShowWindow(true);
	GetDlgItem(ARG2)->ShowWindow(false);
	GetDlgItem(ARG3)->ShowWindow(false);
	GetDlgItem(ARG4)->ShowWindow(false);
	GetDlgItem(ARG5)->ShowWindow(false);
	GetDlgItem(ARG6)->ShowWindow(false);
	GetDlgItem(ARG7)->ShowWindow(false);
	GetDlgItem(ARG8)->ShowWindow(false);
	m_arg1.ResetContent();
	m_arg1.AddString(L"��ԭ");
	m_arg1.AddString(L"��ԭ����");
	m_arg1.AddString(L"��ԭɽ��");
	m_arg1.AddString(L"ƽԭ");
	m_arg1.AddString(L"ƽԭ����");
	m_arg1.AddString(L"ƽԭɽ��");
	m_arg1.AddString(L"ɳĮ");
	m_arg1.AddString(L"ɳĮ����");
	m_arg1.AddString(L"ɳĮɽ��");
	m_arg1.AddString(L"����");
	m_arg1.AddString(L"��������");
	m_arg1.AddString(L"����ɽ��");
	m_arg1.AddString(L"ѩԭ");
	m_arg1.AddString(L"ѩԭ����");
	m_arg1.AddString(L"ѩԭɽ��");
	m_arg1.AddString(L"����");
	m_arg1.AddString(L"����");
	m_arg1.SetCurSel(0);
	m_arg1.ShowWindow(true);
	m_arg2.ShowWindow(false);
	m_arg3.ShowWindow(false);
	m_arg4.ShowWindow(false);
	m_arg5.ShowWindow(false);
	m_arg6.ShowWindow(false);
	m_arg7.ShowWindow(false);
	m_arg8.ShowWindow(false);
	arg1 = 71;
	arg2 = arg3 = arg4 = arg5 = arg6 = arg7 = arg8 = 0;
	strnum = xuhao = 0;
	number = 1;
	m_list.ResetContent();
}

void DLG_TiaoJian::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_type);
	DDX_Control(pDX, IDC_COMBO3, m_leixing);
	DDX_Control(pDX, IDC_EDIT2, m_miaoshu);
	DDX_Control(pDX, IDC_COMBO4, m_tj);
	DDX_Control(pDX, IDC_COMBO2, m_arg1);
	DDX_Control(pDX, IDC_COMBO5, m_arg2);
	DDX_Control(pDX, IDC_COMBO11, m_arg3);
	DDX_Control(pDX, IDC_COMBO12, m_arg4);
	DDX_Control(pDX, IDC_COMBO13, m_arg5);
	DDX_Control(pDX, IDC_COMBO14, m_arg6);
	DDX_Control(pDX, IDC_COMBO15, m_arg7);
	DDX_Control(pDX, IDC_COMBO16, m_arg8);
	DDX_Control(pDX, IDC_LIST2, m_list);
	DDX_Control(pDX, IDC_EDIT3, m_name);
}


BEGIN_MESSAGE_MAP(DLG_TiaoJian, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO4, &DLG_TiaoJian::OnCbnSelchangeCombo4)
	ON_BN_CLICKED(IDC_BUTTON2, &DLG_TiaoJian::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &DLG_TiaoJian::OnBnClickedButton3)
	ON_LBN_DBLCLK(IDC_LIST2, &DLG_TiaoJian::OnLbnDblclkList2)
	ON_BN_CLICKED(IDC_BUTTON5, &DLG_TiaoJian::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON4, &DLG_TiaoJian::OnBnClickedButton4)
END_MESSAGE_MAP()


// DLG_TiaoJian ��Ϣ�������


void DLG_TiaoJian::OnCbnSelchangeCombo4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i;
	/*switch (m_tj.GetCurSel())
	{
	default:
		break;
	}*/
	number = 0;
	i = m_tj.GetCurSel();

	if (arg1 = pro->canshu(GetDlgItem(ARG1), &m_arg1, tiaojian[i].arg1))
	{
		number++;
	}
	if (arg2 = pro->canshu(GetDlgItem(ARG2), &m_arg2, tiaojian[i].arg2))
	{
		number++;
	}
	if (arg3 = pro->canshu(GetDlgItem(ARG3), &m_arg3, tiaojian[i].arg3))
	{
		number++;
	}
	if (arg4 = pro->canshu(GetDlgItem(ARG4), &m_arg4, tiaojian[i].arg4))
	{
		number++;
	}
	if (arg5 = pro->canshu(GetDlgItem(ARG5), &m_arg5, tiaojian[i].arg5))
	{
		number++;
	}
	if (arg6 = pro->canshu(GetDlgItem(ARG6), &m_arg6, tiaojian[i].arg6))
	{
		number++;
	}
	if (arg7 = pro->canshu(GetDlgItem(ARG7), &m_arg7, tiaojian[i].arg7))
	{
		number++;
	}
	if (arg8 = pro->canshu(GetDlgItem(ARG8), &m_arg8, tiaojian[i].arg8))
	{
		number++;
	}
	pro->canshu(NULL, NULL, L"");//���ÿ�ѡ������Ϣ
}


void DLG_TiaoJian::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str, name, temp;
	CString strtemp1, strtemp2;
	static CString old;
	int i;

	m_name.GetWindowTextW(name);
	if (name.IsEmpty())
	{
		MessageBox(L"�������Ʋ���Ϊ�գ�");
		return;
	}
	if (!name.Compare(old))
	{
		MessageBox(L"�������Ʋ����ظ���");
		return;
	}
	m_tj.GetWindowTextW(temp);
	str.Format(L"%s:%s", name, temp);
	i = m_list.GetCount();
	if (i >= 20)
	{
		MessageBox(L"һ��������ֻ�������20������\r\n�����ж�ţ�ƣ�����ô���������ӷ�����");
		return;
	}
	argstrs[strnum] = L"";
	i = m_tj.GetCurSel();
	type[strnum] = i;
	old = name;
	
	if (arg1)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG1), &m_arg1, arg1).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>REQUIREMENT_%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg1], pro->fancanshu(GetDlgItem(ARG1), &m_arg1, arg1));
			argstrs[strnum] += temp;
		}
		GetDlgItem(ARG1)->GetWindowTextW(strtemp1);
		m_arg1.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg2)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG2), &m_arg2, arg2).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>REQUIREMENT_%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg2], pro->fancanshu(GetDlgItem(ARG2), &m_arg2, arg2));
			argstrs[strnum] += temp;
		}
		GetDlgItem(ARG2)->GetWindowTextW(strtemp1);
		m_arg2.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg3)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG3), &m_arg3, arg3).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>REQUIREMENT_%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg3], pro->fancanshu(GetDlgItem(ARG3), &m_arg3, arg3));
			argstrs[strnum] += temp;
		}
		GetDlgItem(ARG3)->GetWindowTextW(strtemp1);
		m_arg3.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg4)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG4), &m_arg4, arg4).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>REQUIREMENT_%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg4], pro->fancanshu(GetDlgItem(ARG4), &m_arg4, arg4));
			argstrs[strnum] += temp;
		}
		GetDlgItem(ARG4)->GetWindowTextW(strtemp1);
		m_arg4.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg5)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG5), &m_arg5, arg5).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>REQUIREMENT_%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg5], pro->fancanshu(GetDlgItem(ARG5), &m_arg5, arg5));
			argstrs[strnum] += temp;
		}
		GetDlgItem(ARG5)->GetWindowTextW(strtemp1);
		m_arg5.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg6)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG6), &m_arg6, arg6).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>REQUIREMENT_%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg6], pro->fancanshu(GetDlgItem(ARG6), &m_arg6, arg6));
			argstrs[strnum] += temp;
		}
		GetDlgItem(ARG6)->GetWindowTextW(strtemp1);
		m_arg6.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg7)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG7), &m_arg7, arg7).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>REQUIREMENT_%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg7], pro->fancanshu(GetDlgItem(ARG7), &m_arg7, arg7));
			argstrs[strnum] += temp;
		}
		GetDlgItem(ARG7)->GetWindowTextW(strtemp1);
		m_arg7.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg8)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG8), &m_arg8, arg8).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>REQUIREMENT_%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg8], pro->fancanshu(GetDlgItem(ARG8), &m_arg8, arg8));
			argstrs[strnum] += temp;
		}
		GetDlgItem(ARG8)->GetWindowTextW(strtemp1);
		m_arg8.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	pro->fancanshu(NULL, NULL, 0);

	xuhao = strnum;
	strnum++;
	m_list.InsertString(-1, str);
	//m_name.SetWindowTextW(L"");
}


void DLG_TiaoJian::OnBnClickedButton3()
{
	int i;
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (MessageBox(L"ȷ��Ҫ����������ɾ����ѡ������", NULL, MB_YESNO) == IDYES)
	{
		i = m_list.GetCurSel();
		m_list.DeleteString(i);
		strnum--;
		if (xuhao > i)
		{
			xuhao--;
		}
		if (xuhao >= strnum)
		{
			xuhao = strnum - 1;
		}
		for (;i < strnum;i++)
		{
			argstrs[i] = argstrs[i + 1];
		}
		argstrs[i] = L"";
	}
}


void DLG_TiaoJian::OnLbnDblclkList2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i, pianyi;
	CString str, temp1, temp2;
	CComboBox * tt[8];
	CComboBox ** ttt = tt;

	i = m_list.GetCurSel();
	xuhao = i;
	i = type[i];
	m_tj.SetCurSel(i);
	arg1 = pro->canshu(GetDlgItem(ARG1), &m_arg1, tiaojian[i].arg1);
	arg2 = pro->canshu(GetDlgItem(ARG2), &m_arg2, tiaojian[i].arg2);
	arg3 = pro->canshu(GetDlgItem(ARG3), &m_arg3, tiaojian[i].arg3);
	arg4 = pro->canshu(GetDlgItem(ARG4), &m_arg4, tiaojian[i].arg4);
	arg5 = pro->canshu(GetDlgItem(ARG5), &m_arg5, tiaojian[i].arg5);
	arg6 = pro->canshu(GetDlgItem(ARG6), &m_arg6, tiaojian[i].arg6);
	arg7 = pro->canshu(GetDlgItem(ARG7), &m_arg7, tiaojian[i].arg7);
	arg8 = pro->canshu(GetDlgItem(ARG8), &m_arg8, tiaojian[i].arg8);
	pro->canshu(NULL, NULL, L"");//���ÿ�ѡ������Ϣ

	tt[0] = &m_arg1;
	tt[1] = &m_arg2;
	tt[2] = &m_arg3;
	tt[3] = &m_arg4;
	tt[4] = &m_arg5;
	tt[5] = &m_arg6;
	tt[6] = &m_arg7;
	tt[7] = &m_arg8;
	i = m_list.GetCurSel();
	//pianyi = m_list.GetTextLen(i);
	m_list.GetText(i, str);//.GetBuffer(pianyi));
	//str.ReleaseBuffer();
	pianyi = str.Find(L"��");
	while (pianyi >= 0)
	{
		pianyi++;
		str = str.Right(str.GetLength() - pianyi);
		pianyi = str.Find(L"-");
		if (pianyi >= 0)
		{
			temp1 = str.Left(pianyi);
		}
		else
		{
			temp1 = str;
		}
		(*ttt)->GetWindowTextW(temp2);
		if (!temp2.Compare(L"*"))
		{
			ttt++;
		}
		(*ttt)->SetWindowTextW(temp1);
		if (pianyi < 0)
		{
			break;
		}
		else
		{
			pianyi = str.Find(L"��");
		}
	}
}


void DLG_TiaoJian::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString str, name, temp;
	CString strtemp1, strtemp2;
	int i, pianyi;

	i = m_list.GetCurSel();
	if (i < 0)
	{
		MessageBox(L"��˫����Ҫ�޸ĵ����������޸���ɺ��ٵ���޸İ�ť��");
		return;
	}
	m_list.GetText(i, str);
	pianyi = str.Find(L":");
	name = str.Left(pianyi);
	m_tj.GetWindowTextW(temp);
	str.Format(L"%s:%s", name, temp);
	argstrs[xuhao] = L"";
	i = m_tj.GetCurSel();
	type[xuhao] = i;

	if (arg1)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG1), &m_arg1, arg1).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg1], pro->fancanshu(GetDlgItem(ARG1), &m_arg1, arg1));
			argstrs[xuhao] += temp;
		}
		GetDlgItem(ARG1)->GetWindowTextW(strtemp1);
		m_arg1.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg2)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG2), &m_arg2, arg2).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg2], pro->fancanshu(GetDlgItem(ARG2), &m_arg2, arg2));
			argstrs[xuhao] += temp;
		}
		GetDlgItem(ARG2)->GetWindowTextW(strtemp1);
		m_arg2.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg3)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG3), &m_arg3, arg3).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg3], pro->fancanshu(GetDlgItem(ARG3), &m_arg3, arg3));
			argstrs[xuhao] += temp;
		}
		GetDlgItem(ARG3)->GetWindowTextW(strtemp1);
		m_arg3.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg4)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG4), &m_arg4, arg4).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg4], pro->fancanshu(GetDlgItem(ARG4), &m_arg4, arg4));
			argstrs[xuhao] += temp;
		}
		GetDlgItem(ARG4)->GetWindowTextW(strtemp1);
		m_arg4.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg5)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG5), &m_arg5, arg5).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg5], pro->fancanshu(GetDlgItem(ARG5), &m_arg5, arg5));
			argstrs[xuhao] += temp;
		}
		GetDlgItem(ARG5)->GetWindowTextW(strtemp1);
		m_arg5.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg6)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG6), &m_arg6, arg6).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg6], pro->fancanshu(GetDlgItem(ARG6), &m_arg6, arg6));
			argstrs[xuhao] += temp;
		}
		GetDlgItem(ARG6)->GetWindowTextW(strtemp1);
		m_arg6.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg7)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG7), &m_arg7, arg7).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg7], pro->fancanshu(GetDlgItem(ARG7), &m_arg7, arg7));
			argstrs[xuhao] += temp;
		}
		GetDlgItem(ARG7)->GetWindowTextW(strtemp1);
		m_arg7.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	if (arg8)
	{
		if (!(pro->fancanshu(GetDlgItem(ARG8), &m_arg8, arg8).IsEmpty()))//�����ַ���Ϊ��˵����Ч��û��ѡ��Ŀ�ѡ����
		{
			temp.Format(L"\t\t<Row>\r\n\t\t\t<RequirementId>%s</RequirementId>\r\n\t\t\t<Name>%s</Name>\r\n\t\t\t<Value>%s</Value>\r\n\t\t</Row>\r\n", name, argstr[arg8], pro->fancanshu(GetDlgItem(ARG8), &m_arg8, arg8));
			argstrs[xuhao] += temp;
		}
		GetDlgItem(ARG8)->GetWindowTextW(strtemp1);
		m_arg8.GetWindowTextW(strtemp2);
		temp.Format(L"-%s%s", strtemp1, strtemp2);
		str += temp;
	}
	i = m_list.GetCurSel();
	m_list.DeleteString(i);
	m_list.InsertString(i, str);
}


void DLG_TiaoJian::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString type;

	m_type.GetWindowTextW(type);

	if (type.IsEmpty())
	{
		MessageBox(L"�뽫���������д����");
		return;
	}

	pro->tiaojian(this);
	pro->baocunone(&dat);
}
