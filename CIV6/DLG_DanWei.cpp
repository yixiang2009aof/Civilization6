// DLG_DanWei.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "CIV6.h"
#include "DLG_DanWei.h"
#include "afxdialogex.h"
#include "v.h"


// DLG_DanWei �Ի���

IMPLEMENT_DYNAMIC(DLG_DanWei, CDialogEx)

DLG_DanWei::DLG_DanWei(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

DLG_DanWei::~DLG_DanWei()
{
}

void DLG_DanWei::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_EDIT1, m_type);
	DDX_Control(pDX, IDC_EDIT17, m_cost);
	DDX_Control(pDX, IDC_EDIT2, m_name);
	DDX_Control(pDX, IDC_EDIT3, m_d);
	DDX_Control(pDX, IDC_COMBO3, m_advi);
	DDX_Control(pDX, IDC_EDIT4, m_move);
	DDX_Control(pDX, IDC_EDIT39, m_shiye);
	DDX_Control(pDX, IDC_COMBO5, m_leixing);
	DDX_Control(pDX, IDC_COMBO30, m_pur);
	DDX_Control(pDX, IDC_COMBO29, m_dis);
	DDX_Control(pDX, IDC_COMBO11, m_texing);
	DDX_Control(pDX, IDC_COMBO12, m_tag);
	DDX_Control(pDX, IDC_COMBO31, m_ziyuan);
	DDX_Control(pDX, IDC_COMBO28, m_build);
	DDX_Control(pDX, IDC_COMBO17, m_jinsheng);
	DDX_Control(pDX, IDC_COMBO20, m_tech);
	DDX_Control(pDX, IDC_COMBO24, m_civic);
	DDX_Control(pDX, IDC_COMBO25, m_renkou);
	DDX_Control(pDX, IDC_COMBO26, m_tihuan);
	DDX_Control(pDX, IDC_COMBO27, m_shengji);
	DDX_Control(pDX, IDC_LIST2, m_listtx);
	DDX_Control(pDX, IDC_LIST4, m_listtag);
	DDX_Control(pDX, IDC_CHECK2, m_xzhanli);
	DDX_Control(pDX, IDC_EDIT11, m_zhanli);
	DDX_Control(pDX, IDC_CHECK34, m_xyuanli);
	DDX_Control(pDX, IDC_EDIT18, m_yuanli);
	DDX_Control(pDX, IDC_EDIT43, m_shecheng);
	DDX_Control(pDX, IDC_CHECK3, m_xhongli);
	DDX_Control(pDX, IDC_EDIT12, m_hongli);
	DDX_Control(pDX, IDC_CHECK4, m_xhaoren);
	DDX_Control(pDX, IDC_EDIT13, m_haoren);
	DDX_Control(pDX, IDC_CHECK5, m_xjianci);
	DDX_Control(pDX, IDC_EDIT14, m_jianci);
	DDX_Control(pDX, IDC_CHECK6, m_xzongci);
	DDX_Control(pDX, IDC_CHECK7, m_xzongli);
	DDX_Control(pDX, IDC_EDIT15, m_zongci);
	DDX_Control(pDX, IDC_EDIT16, m_zongli);
	DDX_Control(pDX, IDC_CHECK56, m_schengshi);
	DDX_Control(pDX, IDC_CHECK57, m_sfuyin);
	DDX_Control(pDX, IDC_CHECK58, m_sshenxun);
	DDX_Control(pDX, IDC_CHECK59, m_syiji);
	DDX_Control(pDX, IDC_CHECK60, m_sbuhuo);
	DDX_Control(pDX, IDC_CHECK61, m_smanzu);
	DDX_Control(pDX, IDC_CHECK62, m_sleijia);
	DDX_Control(pDX, IDC_CHECK63, m_sjinsheng);
	DDX_Control(pDX, IDC_CHECK64, m_ayimin);
	DDX_Control(pDX, IDC_CHECK65, m_agongren);
	DDX_Control(pDX, IDC_CHECK66, m_ashangren);
	DDX_Control(pDX, IDC_CHECK67, m_apingmin);
	DDX_Control(pDX, IDC_CHECK68, m_atansuo);
	DDX_Control(pDX, IDC_CHECK69, m_ajinzhan);
	DDX_Control(pDX, IDC_CHECK70, m_ayuancheng);
	DDX_Control(pDX, IDC_CHECK71, m_agongcheng);
	DDX_Control(pDX, IDC_CHECK72, m_aqibing);
	DDX_Control(pDX, IDC_CHECK73, m_azhiyuan);
	DDX_Control(pDX, IDC_CHECK74, m_ahewu);
	DDX_Control(pDX, IDC_CHECK75, m_aweiren);
	DDX_Control(pDX, IDC_CHECK76, m_xshecheng);
	DDX_Control(pDX, IDC_EDIT57, m_feiyong);
	DDX_Control(pDX, IDC_EDIT58, m_fangkong);
	DDX_Control(pDX, IDC_CHECK33, m_xfangkong);
	//  DDX_Control(pDX, IDC_CHECK77, m_beibu);
	DDX_Control(pDX, IDC_CHECK77, m_sbeibu);
	DDX_Control(pDX, IDC_EDIT59, m_shuoming);
}

void DLG_DanWei::csh()
{
	m_type.SetWindowTextW(L"");
	m_name.SetWindowTextW(L"");
	m_d.SetWindowTextW(L"");
	m_shuoming.SetWindowTextW(L"");
	m_cost.SetWindowTextW(L"30");
	m_move.SetWindowTextW(L"2");
	m_feiyong.SetWindowTextW(L"1");
	m_shiye.SetWindowTextW(L"2");
	m_zhanli.SetWindowTextW(L"30");
	m_yuanli.SetWindowTextW(L"30");
	m_shecheng.SetWindowTextW(L"2");
	m_hongli.SetWindowTextW(L"30");
	m_haoren.SetWindowTextW(L"1");
	m_jianci.SetWindowTextW(L"3");
	m_zongci.SetWindowTextW(L"3");
	m_zongli.SetWindowTextW(L"30");
	m_fangkong.SetWindowTextW(L"30");
	m_dis.SetCurSel(0);
	m_pur.SetCurSel(0);
	m_advi.SetCurSel(0);
	m_leixing.SetCurSel(0);
	m_ziyuan.SetCurSel(0);
	m_build.SetCurSel(0);
	m_shengji.SetCurSel(0);
	m_tihuan.SetCurSel(0);
	m_jinsheng.SetCurSel(0);
	m_tech.SetCurSel(0);
	m_civic.SetCurSel(0);
	m_renkou.SetCurSel(0);
	m_texing.SetCurSel(0);
	m_tag.ResetContent();
	m_tag.AddString(L"½��ƽ��");
	m_tag.AddString(L"���");
	m_tag.AddString(L"��ս");
	m_tag.AddString(L"Զ��");
	m_tag.AddString(L"��ը");
	m_tag.AddString(L"�����");
	m_tag.AddString(L"�����");
	m_tag.AddString(L"������");
	m_tag.AddString(L"�����");
	m_tag.AddString(L"��ս��");
	m_tag.AddString(L"��ս��");
	m_tag.AddString(L"�ƳǴ�");
	m_tag.AddString(L"������ս");
	m_tag.AddString(L"����Զ��");
	m_tag.AddString(L"��������");
	m_tag.AddString(L"��ĸ");
	m_tag.AddString(L"������");
	m_tag.AddString(L"ҽ��");
	m_tag.AddString(L"����");
	m_tag.AddString(L"�ڽ�");
	m_tag.AddString(L"���й�");
	m_tag.AddString(L"����ʿ");
	m_tag.AddString(L"�۲�");
	m_tag.AddString(L"ǰհ�۲�");
	m_tag.AddString(L"˫���");
	m_tag.AddString(L"����ѧ��");
	m_tag.AddString(L"����");
	m_tag.AddString(L"��ʾ����");
	m_tag.AddString(L"���");
	m_tag.AddString(L"����");
	m_tag.AddString(L"��սʿ");
	m_tag.AddString(L"����ֻ");
	m_tag.AddString(L"������");
	m_tag.AddString(L"���������");
	m_tag.AddString(L"������");
	m_tag.AddString(L"����");
	m_tag.AddString(L"ս��");
	m_tag.AddString(L"��ķ����");
	m_tag.AddString(L"������");
	m_tag.AddString(L"�۹�����");
	m_tag.AddString(L"��װ����");
	m_tag.AddString(L"ֱ����");
	m_tag.AddString(L"U��Ǳͧ");
	m_tag.AddString(L"ç���");
	m_tag.AddString(L"P51");
	m_tag.AddString(L"ū����");
	m_tag.AddString(L"ս��");
	m_tag.AddString(L"��ʿ");
	m_tag.AddString(L"��");
	m_tag.SetCurSel(0);
	m_zhanli.EnableWindow(false);
	m_yuanli.EnableWindow(false);
	m_hongli.EnableWindow(false);
	m_shecheng.EnableWindow(false);
	m_haoren.EnableWindow(false);
	m_jianci.EnableWindow(false);
	m_zongci.EnableWindow(false);
	m_zongli.EnableWindow(false);
	m_fangkong.EnableWindow(false);
	m_xzhanli.SetCheck(0);
	m_xyuanli.SetCheck(0);
	m_xhongli.SetCheck(0);
	m_xhaoren.SetCheck(0);
	m_xjianci.SetCheck(0);
	m_xzongci.SetCheck(0);
	m_xzongli.SetCheck(0);
	m_xfangkong.SetCheck(0);
	m_schengshi.SetCheck(0);
	m_sfuyin.SetCheck(0);
	m_sshenxun.SetCheck(0);
	m_syiji.SetCheck(0);
	m_sbuhuo.SetCheck(0);
	m_sbeibu.SetCheck(0);
	m_smanzu.SetCheck(0);
	m_sleijia.SetCheck(0);
	m_sjinsheng.SetCheck(0);
	m_ayimin.SetCheck(0);
	m_agongren.SetCheck(0);
	m_ashangren.SetCheck(0);
	m_apingmin.SetCheck(0);
	m_atansuo.SetCheck(0);
	m_ajinzhan.SetCheck(0);
	m_ayuancheng.SetCheck(0);
	m_agongcheng.SetCheck(0);
	m_aqibing.SetCheck(0);
	m_azhiyuan.SetCheck(0);
	m_ahewu.SetCheck(0);
	m_aweiren.SetCheck(0);
	m_listtx.ResetContent();
	m_listtag.ResetContent();
}


BEGIN_MESSAGE_MAP(DLG_DanWei, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK2, &DLG_DanWei::OnBnClickedCheck2)
	ON_BN_CLICKED(IDC_CHECK34, &DLG_DanWei::OnBnClickedCheck34)
	ON_BN_CLICKED(IDC_CHECK3, &DLG_DanWei::OnBnClickedCheck3)
	ON_BN_CLICKED(IDC_CHECK4, &DLG_DanWei::OnBnClickedCheck4)
	ON_BN_CLICKED(IDC_CHECK5, &DLG_DanWei::OnBnClickedCheck5)
	ON_BN_CLICKED(IDC_CHECK6, &DLG_DanWei::OnBnClickedCheck6)
	ON_BN_CLICKED(IDC_CHECK7, &DLG_DanWei::OnBnClickedCheck7)
	ON_BN_CLICKED(IDC_BUTTON1, &DLG_DanWei::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &DLG_DanWei::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON9, &DLG_DanWei::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON5, &DLG_DanWei::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON3, &DLG_DanWei::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON4, &DLG_DanWei::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_CHECK76, &DLG_DanWei::OnBnClickedCheck76)
	ON_BN_CLICKED(IDC_CHECK33, &DLG_DanWei::OnBnClickedCheck33)
END_MESSAGE_MAP()


// DLG_DanWei ��Ϣ�������


void DLG_DanWei::OnBnClickedCheck2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_xzhanli.GetCheck())
	{
		m_zhanli.EnableWindow(true);
	}
	else
	{
		m_zhanli.EnableWindow(false);
	}
}


void DLG_DanWei::OnBnClickedCheck34()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_xyuanli.GetCheck())
	{
		m_yuanli.EnableWindow(true);
	}
	else
	{
		m_yuanli.EnableWindow(false);
	}
}


void DLG_DanWei::OnBnClickedCheck3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_xhongli.GetCheck())
	{
		m_hongli.EnableWindow(true);
	}
	else
	{
		m_hongli.EnableWindow(false);
	}
}


void DLG_DanWei::OnBnClickedCheck4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_xhaoren.GetCheck())
	{
		m_haoren.EnableWindow(true);
	}
	else
	{
		m_haoren.EnableWindow(false);
	}
}


void DLG_DanWei::OnBnClickedCheck5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_xjianci.GetCheck())
	{
		m_jianci.EnableWindow(true);
	}
	else
	{
		m_jianci.EnableWindow(false);
	}
}


void DLG_DanWei::OnBnClickedCheck6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_xzongci.GetCheck())
	{
		m_zongci.EnableWindow(true);
	}
	else
	{
		m_zongci.EnableWindow(false);
	}
}


void DLG_DanWei::OnBnClickedCheck7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_xzongli.GetCheck())
	{
		m_zongli.EnableWindow(true);
	}
	else
	{
		m_zongli.EnableWindow(false);
	}
}


void DLG_DanWei::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i;
	CString str, temp;

	i = m_texing.GetCurSel();
	m_texing.GetWindowTextW(temp);
	if (i)
	{
		str.Format(L"%d:%s", i, temp);
		m_listtx.InsertString(-1, str);
	}
}


void DLG_DanWei::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i;

	i = m_listtx.GetCurSel();
	m_listtx.DeleteString(i);
}


void DLG_DanWei::OnBnClickedButton9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	csh();
}


void DLG_DanWei::OnBnClickedButton5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CString type, name, d, cost;
	CString yd, sy, wh;

	m_type.GetWindowTextW(type);
	m_name.GetWindowTextW(name);
	m_d.GetWindowTextW(d);
	m_cost.GetWindowTextW(cost);
	m_move.GetWindowTextW(yd);
	m_shiye.GetWindowTextW(sy);
	m_feiyong.GetWindowTextW(wh);

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
	if (cost.IsEmpty())
	{
		MessageBox(L"�뽫���������д����");
		return;
	}
	if (yd.IsEmpty())
	{
		MessageBox(L"�뽫���������д����");
		return;
	}
	if (sy.IsEmpty())
	{
		MessageBox(L"�뽫���������д����");
		return;
	}
	if (wh.IsEmpty())
	{
		MessageBox(L"�뽫���������д����");
		return;
	}

	pro->danwei(this);
	pro->baocunone(&dat);
}


void DLG_DanWei::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i;
	CString str, temp;

	i = m_tag.GetCurSel();
	m_tag.GetWindowTextW(temp);
	if (i >= 0)
	{
		str.Format(L"%d:%s", i, temp);
		m_listtag.InsertString(-1, str);
	}
}


void DLG_DanWei::OnBnClickedButton4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	int i;

	i = m_listtag.GetCurSel();
	m_listtag.DeleteString(i);
}


void DLG_DanWei::OnBnClickedCheck76()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_xshecheng.GetCheck())
	{
		m_shecheng.EnableWindow(true);
	}
	else
	{
		m_shecheng.EnableWindow(false);
	}
}


void DLG_DanWei::OnBnClickedCheck33()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	if (m_xfangkong.GetCheck())
	{
		m_fangkong.EnableWindow(true);
	}
	else
	{
		m_fangkong.EnableWindow(false);
	}
}
