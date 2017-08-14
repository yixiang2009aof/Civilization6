#include "stdafx.h"
#include "project.h"
#include "v.h"
#include "resource.h"


project::project()
{
	number = 0;
	id = 0;
	root = NULL;
	p = NULL;
	jlroot = jlp = NULL;
	Type = L"";
	Modifiers = L"";
	ModifierArguments = L"";
	TraitModifiers = L"";
	RequirementSets = L"";
	RequirementSetRequirements = L"";
	RequirementArguments = L"";
	JianZhu.Buildings = L"";
	JianZhu.BuildingReplaces = L"";
	JianZhu.BuildingPrereqs = L"";
	JianZhu.MutuallyExclusiveBuildings = L"";
	JianZhu.Building_YieldChanges = L"";
	JianZhu.BuildingModifiers = L"";
	JianZhu.Building_GreatPersonPoints = L"";
	JianZhu.Building_GreatWorks = L"";
	JianZhu.Building_RequiredFeatures = L"";
	JianZhu.Building_ValidFeatures = L"";
	JianZhu.Building_ValidTerrains = L"";
	WenMing.CityNames = L"";
	WenMing.Civilizations = L"";
	WenMing.CivilizationTraits = L"";
	WenMing.StartBiasFeatures = L"";
	WenMing.StartBiasResources = L"";
	WenMing.StartBiasRivers = L"";
	WenMing.StartBiasTerrains = L"";
	WenMing.Traits = L"";
}


project::project(CFile * f)
{
	ULONGLONG length;
	struct table * temp;
	CString str;
	int pianyi, i, zhonglei;
	char * tt;

	number = 0;
	id = 0;
	root = NULL;
	p = NULL;
	jlroot = jlp = NULL;
	Type = L"";
	Modifiers = L"";
	ModifierArguments = L"";
	TraitModifiers = L"";
	RequirementSets = L"";
	RequirementSetRequirements = L"";
	RequirementArguments = L"";
	JianZhu.Buildings = L"";
	JianZhu.BuildingReplaces = L"";
	JianZhu.BuildingPrereqs = L"";
	JianZhu.MutuallyExclusiveBuildings = L"";
	JianZhu.Building_YieldChanges = L"";
	JianZhu.BuildingModifiers = L"";
	JianZhu.Building_GreatPersonPoints = L"";
	JianZhu.Building_GreatWorks = L"";
	JianZhu.Building_RequiredFeatures = L"";
	JianZhu.Building_ValidFeatures = L"";
	JianZhu.Building_ValidTerrains = L"";
	WenMing.CityNames = L"";
	WenMing.Civilizations = L"";
	WenMing.CivilizationTraits = L"";
	WenMing.StartBiasFeatures = L"";
	WenMing.StartBiasResources = L"";
	WenMing.StartBiasRivers = L"";
	WenMing.StartBiasTerrains = L"";
	WenMing.Traits = L"";

	length = f->GetLength() & 0xfffffffffffff000ULL;
	if (length > 0)
	{
		root = new struct table;
		p = root;
		f->Read(p, 4096);
		p->qian = p->hou = NULL;
		number++;
		id++;

		for (length -= 4096; length > 0; length -= 4096)
		{
			p->hou = new struct table;
			f->Read(p->hou, 4096);
			p->hou->qian = p;
			p = p->hou;
			p->hou = NULL;
			number++;
			id++;
		}
	}
	for (temp = root;temp;temp = temp->hou)
	{
		switch (temp->type)
		{
		case 0:
		case 1:
			pianyi = *((int *)(temp->data));
			str = (temp->data) + 4;
			pianyi += 8;
			buildingnum++;
			building[buildingnum].id = buildingnum;
			building[buildingnum].type = L"BUILDING_" + str;
			str = (temp->data) + pianyi;
			building[buildingnum].name = str;
			break;
		case 2:
			pianyi = *((int *)(temp->data));
			str = (temp->data) + 4;
			pianyi += 8;
			wenmingnum++;
			::wenming[wenmingnum].id = wenmingnum;
			::wenming[wenmingnum].type = L"CIVILIZATION_" + str;
			str = (temp->data) + pianyi;
			::wenming[wenmingnum].name = str;
			tt = (temp->data) + temp->length - 4;
			pianyi = *((int *)tt);
			tt -= pianyi;
			i = *((int *)tt);
			tt += 4;
			if (i)
			{
				jlp = jlroot;
				if (jlp)
				{
					while (jlp->next)
					{
						jlp = jlp->next;
					}
					jlp->next = new struct jilu;
					jlp = jlp->next;
				}
				else
				{
					jlroot = jlp = new struct jilu;
				}
				i = *((int *)tt);
				tt += 4;
				jlp->leixing = i;
				pianyi = *((int *)tt);
				tt += 4;
				jlp->yuan = tt;
				tt += pianyi;
				pianyi = *((int *)tt);
				tt += 4;
				jlp->str = tt;
				tt += pianyi;
			}
			i = *((int *)tt);
			tt += 4;
			if (i)
			{
				jlp = jlroot;
				if (jlp)
				{
					while (jlp->next)
					{
						jlp = jlp->next;
					}
					jlp->next = new struct jilu;
					jlp = jlp->next;
				}
				else
				{
					jlroot = jlp = new struct jilu;
				}
				i = *((int *)tt);
				tt += 4;
				jlp->leixing = i;
				pianyi = *((int *)tt);
				tt += 4;
				jlp->yuan = tt;
				tt += pianyi;
				pianyi = *((int *)tt);
				tt += 4;
				jlp->str = tt;
				tt += pianyi;
			}
			break;
		case 3:
			pianyi = *((int *)(temp->data));
			str = (temp->data) + 4;
			pianyi += 8;
			str = (temp->data) + pianyi;
			tt = (temp->data) + temp->length - 4;
			pianyi = *((int *)tt);
			tt -= pianyi;
			i = *((int *)tt);
			tt += 4;
			if (i)
			{
				jlp = jlroot;
				if (jlp)
				{
					while (jlp->next)
					{
						jlp = jlp->next;
					}
					jlp->next = new struct jilu;
					jlp = jlp->next;
				}
				else
				{
					jlroot = jlp = new struct jilu;
				}
				i = *((int *)tt);
				tt += 4;
				jlp->leixing = i;
				pianyi = *((int *)tt);
				tt += 4;
				jlp->yuan = tt;
				tt += pianyi;
				pianyi = *((int *)tt);
				tt += 4;
				jlp->str = tt;
				tt += pianyi;
			}
			i = *((int *)tt);
			tt += 4;
			if (i)
			{
				jlp = jlroot;
				if (jlp)
				{
					while (jlp->next)
					{
						jlp = jlp->next;
					}
					jlp->next = new struct jilu;
					jlp = jlp->next;
				}
				else
				{
					jlroot = jlp = new struct jilu;
				}
				i = *((int *)tt);
				tt += 4;
				jlp->leixing = i;
				pianyi = *((int *)tt);
				tt += 4;
				jlp->yuan = tt;
				tt += pianyi;
				pianyi = *((int *)tt);
				tt += 4;
				jlp->str = tt;
				tt += pianyi;
			}
			break;
		case 4:
			zhonglei = *((int *)(temp->data));
			pianyi = *((int *)(temp->data + 4));
			str = (temp->data) + 8;
			if (zhonglei == 0)
			{
				pianyi += 12;
				technum++;
				::tech[technum].id = technum;
				::tech[technum].type = L"TECH_" + str;
				str = (temp->data) + pianyi;
				::tech[technum].name = str;
			}
			else
			{
				pianyi += 12;
				civicnum++;
				::civic[civicnum].id = civicnum;
				::civic[civicnum].type = L"CIVIC_" + str;
				str = (temp->data) + pianyi;
				::civic[civicnum].name = str;
			}
			break;
		case 5:
			pianyi = *((int *)(temp->data));
			str = (temp->data) + 4;
			pianyi += 8;
			unitnum++;
			::unit[unitnum].id = unitnum;
			::unit[unitnum].type = L"UNIT_" + str;
			str = (temp->data) + pianyi;
			::unit[unitnum].name = str;
			break;
		case 6:
			zhonglei = *((int *)(temp->data));
			pianyi = *((int *)(temp->data+4));
			str = (temp->data) + 8;
			if (zhonglei == 0)
			{
				pianyi += 12;
				zhengcenum++;
				::zhengce[zhengcenum].id = zhengcenum;
				::zhengce[zhengcenum].type = L"POLICY_" + str;
				str = (temp->data) + pianyi;
				::zhengce[zhengcenum].name = str;
			}
			break;
		case 7:
			break;
		case 8:
			break;
		case 9:
			break;
		case 10:
			break;
		case 11:
			break;
		case 12:
			pianyi = *((int *)(temp->data));
			str = (temp->data) + 4;
			pianyi += 8;
			zongtiaojiannum++;
			zongtiaojian[zongtiaojiannum].id = zongtiaojiannum;
			zongtiaojian[zongtiaojiannum].type = str;
			str = (temp->data) + pianyi;
			zongtiaojian[zongtiaojiannum].name = str;
			break;
		case 13:
			pianyi = *((int *)(temp->data));
			str = (temp->data) + 4;
			pianyi += 8;
			zongtexingnum++;
			zongtexing[zongtexingnum].id = zongtexingnum;
			zongtexing[zongtexingnum].type = str;
			str = (temp->data) + pianyi;
			zongtexing[zongtexingnum].name = str;
			break;
		default:
			break;
		}
	}
	//p = NULL;
}


project::~project()
{
	if (root)
	{
		while (root->hou)
		{
			root = root->hou;
			delete root->qian;
		}
		delete root;
	}
	p = NULL;
	while (jlroot)
	{
		jlp = jlroot;
		jlroot = jlroot->next;
		delete jlp;
	}
	number = 0;
	id = 0;
}


void project::baocun(CFile * f)
{
	f->SeekToBegin();
	if (root)
	{
		for (p = root; p->hou; p = p->hou)
		{
			f->Write(p, 4096);
		}
		f->Write(p, 4096);
	}
}

void project::baocunone(CFile * f)
{
	int i;
	f->Seek(id << 12, CFile::begin);
	f->Write(p, 4096);
	pro->ck->shuaxin();
	
	i = pro->hou();
	if (i < 0)
	{
		pro->ck->m_hou.EnableWindow(false);
	}
	pro->ck->m_qian.EnableWindow(true);
}

void project::jianzhu(DLG_JianZhu * dhk)
{
	int i;
	char temp[4096];
	CString str, strtemp;
	int length;
	int max;
	char * tt;

	if (id == number)//��ǰָ��ָ�����һ������
	{
		if (p == NULL)
		{
			root = p = new struct table;
		}
		else
		{
			p->hou = new struct table;
			p->hou->qian = p;
			p = p->hou;
		}
		id = number++;
	}
	else
	{
		if (p->type != 0)
		{
			MessageBox(NULL, L"������һ����ťֱ���ð�ťΪ��ɫ�ٳ��Ըò�����", L"�α����", MB_OK);
			return;
		}
	}
	tt = p->data;
	p->length = 0;
	p->type = 0;
	p->id = id;
	max = MAXLENGTH;
	//Ӣ������
	dhk->m_type.GetWindowTextW(str);
	strtemp.Format(L"BUILDING_%s", str);
	if (buildingnum >= 1000)
	{
		MessageBox(NULL, L"����������������ɵĽ�����������������½����̻��ֶ���ӣ�", L"��������", MB_OK);
		return;
	}
	buildingnum++;
	building[buildingnum].type = strtemp;
	building[buildingnum].id = buildingnum;
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_name.GetWindowTextW(str);
	building[buildingnum].name = str;
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_d.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//���Ѳ���
	dhk->m_cost.GetWindowTextW(str);
	i = _ttoi(str);
	if (i != 1)
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//ǰ�ó���
	i = dhk->m_dis.GetCurSel();
	if (i)
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//�ɹ�����
	i = dhk->m_pur.GetCurSel();
	if (i)
	{
		*((int *)tt) = 2;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//��������
	i = dhk->m_advi.GetCurSel();
	if (i)
	{
		*((int *)tt) = 3;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//�滻����
	i = dhk->m_tihuan.GetCurSel();
	if (i)
	{
		*((int *)tt) = 4;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//����ס��
	dhk->m_house.GetWindowTextW(str);
	i = _ttoi(str);
	if (i)
	{
		*((int *)tt) = 5;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//�����˾�
	dhk->m_enter.GetWindowTextW(str);
	i = _ttoi(str);
	if (i)
	{
		*((int *)tt) = 6;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//�������
	dhk->m_pmax.GetWindowTextW(str);
	i = _ttoi(str);
	if (i != -1)
	{
		*((int *)tt) = 7;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//��������
	dhk->m_wmax.GetWindowTextW(str);
	i = _ttoi(str);
	if (i != -1)
	{
		*((int *)tt) = 8;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//ά������
	dhk->m_main.GetWindowTextW(str);
	i = _ttoi(str);
	if (i)
	{
		*((int *)tt) = 9;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//���䷶Χ
	dhk->m_range.GetWindowTextW(str);
	i = _ttoi(str);
	if (i)
	{
		*((int *)tt) = 10;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//ǰ�ý���
	i = dhk->m_pb.GetCurSel();
	if (i)
	{
		*((int *)tt) = 11;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//���⽨��
	i = dhk->m_huchi.GetCurSel();
	if (i)
	{
		*((int *)tt) = 12;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//ǰ�ÿƼ�
	i = dhk->m_tech.GetCurSel();
	if (i)
	{
		*((int *)tt) = 13;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//ǰ������
	i = dhk->m_civic.GetCurSel();
	if (i)
	{
		*((int *)tt) = 14;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//ʳ��
	if (dhk->m_c1.GetCheck())
	{
		dhk->m_food.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 15;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_c2.GetCheck())
	{
		dhk->m_channeng.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 16;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//���
	if (dhk->m_c3.GetCheck())
	{
		dhk->m_gold.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 17;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_c4.GetCheck())
	{
		dhk->m_keyan.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 18;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//�Ļ�
	if (dhk->m_c5.GetCheck())
	{
		dhk->m_wenhua.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 19;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_c6.GetCheck())
	{
		dhk->m_xinyang.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 20;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//��������
	i = dhk->m_tx.GetCurSel();
	if (i)
	{
		*((int *)tt) = 21;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//��������
	i = dhk->m_tj.GetCurSel();
	if (i)
	{
		*((int *)tt) = 22;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//��Ҫ�ٺ�
	if (dhk->m_river.GetCheck())
	{
		*((int *)tt) = 23;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	p->length = MAXLENGTH - max;
	ck->m_qian.EnableWindow(true);
	ck->m_delete.EnableWindow(true);
	ck->m_output.EnableWindow(true);
}

void project::fanjianzhu(DLG_JianZhu * dhk)
{
	int length, i;
	char * tt;
	CString str;

	length = p->length;
	tt = p->data;
	dhk->csh();

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_type.SetWindowTextW(str);

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_name.SetWindowTextW(str);

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_d.SetWindowTextW(str);

	while (length > 0)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		switch (i)
		{
		case 0:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_cost.SetWindowTextW(str);
			break;
		case 1:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_dis.SetCurSel(i);
			break;
		case 2:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_pur.SetCurSel(i);
			break;
		case 3:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_advi.SetCurSel(i);
			break;
		case 4:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_tihuan.SetCurSel(i);
			break;
		case 5:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_house.SetWindowTextW(str);
			break;
		case 6:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_enter.SetWindowTextW(str);
			break;
		case 7:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_pmax.SetWindowTextW(str);
			break;
		case 8:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_wmax.SetWindowTextW(str);
			break;
		case 9:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_main.SetWindowTextW(str);
			break;
		case 10:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_range.SetWindowTextW(str);
			break;
		case 11:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_pb.SetCurSel(i);
			break;
		case 12:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_huchi.SetCurSel(i);
			break;
		case 13:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_tech.SetCurSel(i);
			break;
		case 14:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_civic.SetCurSel(i);
			break;
		case 15:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_food.SetWindowTextW(str);
			dhk->m_food.EnableWindow(true);
			dhk->m_c1.SetCheck(true);
			break;
		case 16:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_channeng.SetWindowTextW(str);
			dhk->m_channeng.EnableWindow(true);
			dhk->m_c2.SetCheck(true);
			break;
		case 17:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_gold.SetWindowTextW(str);
			dhk->m_gold.EnableWindow(true);
			dhk->m_c3.SetCheck(true);
			break;
		case 18:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_keyan.SetWindowTextW(str);
			dhk->m_keyan.EnableWindow(true);
			dhk->m_c4.SetCheck(true);
			break;
		case 19:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_wenhua.SetWindowTextW(str);
			dhk->m_wenhua.EnableWindow(true);
			dhk->m_c5.SetCheck(true);
			break;
		case 20:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_xinyang.SetWindowTextW(str);
			dhk->m_xinyang.EnableWindow(true);
			dhk->m_c6.SetCheck(true);
			break;
		case 21:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_tx.SetCurSel(i);
			break;
		case 22:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_tj.SetCurSel(i);
			break;
		case 23:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_river.SetCheck(true);
			}
			break;
		}
	}
}

void project::shengjianzhu(char * tt, int length)
{
	CString str;
	CString strtemp;
	CString strtype;
	int i;

	JianZhu.Buildings += L"\t\t<Row";
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" BuildingType=\"BUILDING_%s\"", strtemp);
	strtype.Format(L"BUILDING_%s", strtemp);
	tt += i;
	length -= i;
	JianZhu.Buildings += str;
	str.Format(L"\t\t<Row Type=\"%s\" Kind=\"KIND_BUILDING\"/>\r\n", strtype);
	Type += str;

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Name=\"LOC_%s_NAME\"", strtype);
	tt += i;
	length -= i;
	JianZhu.Buildings += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Description=\"LOC_%s_DESCRIPTION\"", strtype);
	tt += i;
	length -= i;
	JianZhu.Buildings += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_DESCRIPTION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i != 0)
	{
		JianZhu.Buildings += L" Cost=\"1\"";
	}
	else
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" Cost=\"%d\"", i);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i != 1)
	{
		JianZhu.Buildings += L" PrereqDistrict=\"DISTRICT_CITY_CENTER\"";
	}
	else
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" PrereqDistrict=\"%s\"", dis[i]);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i != 2)
	{
		JianZhu.Buildings += L" PurchaseYield=\"YIELD_GOLD\"";
	}
	else
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" PurchaseYield=\"%s\"", pur[i]);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i != 3)
	{
		JianZhu.Buildings += L" AdvisorType=\"ADVISOR_CULTURE\"";
	}
	else
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" AdvisorType=\"%s\"", advi[i]);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 4)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row CivUniqueBuildingType=\"%s\" ReplacesBuildingType=\"%s\"/>\r\n", strtype, building[i].type);
		JianZhu.BuildingReplaces += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 5)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" Housing=\"%d\"", i);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 6)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" Entertainment=\"%d\"", i);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 7)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" MaxPlayerInstances=\"%d\"", i);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 8)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" MaxWorldInstances=\"%d\"", i);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 9)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" Maintenance=\"%d\"", i);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 10)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" RegionalRange=\"%d\"", i);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 11)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row Building=\"%s\" PrereqBuilding=\"%s\"/>\r\n", strtype, building[i].type);
		JianZhu.BuildingPrereqs += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 12)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row Building=\"%s\" MutuallyExclusiveBuilding=\"%s\"/>\r\n", strtype, building[i].type);
		JianZhu.MutuallyExclusiveBuildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 13)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" PrereqTech=\"%s\"", tech[i].type);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 14)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" PrereqCivic=\"%s\"", civic[i].type);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 15)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" YieldType=\"YIELD_FOOD\" YieldChange=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_YieldChanges += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 16)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" YieldType=\"YIELD_PRODUCTION\" YieldChange=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_YieldChanges += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 17)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" YieldType=\"YIELD_GOLD\" YieldChange=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_YieldChanges += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 18)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" YieldType=\"YIELD_SCIENCE\" YieldChange=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_YieldChanges += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 19)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" YieldType=\"YIELD_CULTURE\" YieldChange=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_YieldChanges += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 20)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" YieldType=\"YIELD_FAITH\" YieldChange=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_YieldChanges += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 21)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row>\r\n\t\t\t<BuildingType>%s</BuildingType>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t</Row>\r\n", strtype, zongtexing[i].type);
		JianZhu.BuildingModifiers += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 22)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 23)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		if (i)
		{
			str.Format(L" RequiresAdjacentRiver=\"true\"");
			JianZhu.Buildings += str;
		}
	}
	if (jlroot)
	{
		jlp = jlroot;
		while (jlp)
		{
			if ((jlp->leixing == 0) || (jlp->leixing == 2))
			{
				if (strtype.Compare(jlp->yuan))
				{
					jlp = jlp->next;
				}
				else
				{
					str.Format(L" TraitType=\"%s\"", jlp->str);
					JianZhu.Buildings += str;
					break;
				}
			}
			else
			{
				jlp = jlp->next;
			}
		}
	}
	JianZhu.Buildings += L"/>\r\n";
}

void project::qiguan(DLG_QiGuan * dhk)
{
	int i;
	char temp[4096];
	CString str, strtemp;
	int length;
	int max;
	char * tt;

	if (id == number)//��ǰָ��ָ�����һ������
	{
		if (p == NULL)
		{
			p = new struct table;
			if (root == NULL)
			{
				root = p;
			}
		}
		else
		{
			p->hou = new struct table;
			p->hou->qian = p;
			p = p->hou;
		}
		id = number++;
	}
	else
	{
		if (p->type != 1)
		{
			MessageBox(NULL, L"������һ����ťֱ���ð�ťΪ��ɫ�ٳ��Ըò�����", L"�α����", MB_OK);
			return;
		}
	}
	tt = p->data;
	p->length = 0;
	p->type = 1;
	p->id = id;
	max = MAXLENGTH;
	//Ӣ������
	dhk->m_type.GetWindowTextW(str);
	strtemp.Format(L"BUILDING_%s", str);
	if (buildingnum >= 1000)
	{
		MessageBox(NULL, L"����������������ɵĽ�����������������½����̻��ֶ���ӣ�", L"��������", MB_OK);
		return;
	}
	buildingnum++;
	building[buildingnum].type = strtemp;
	building[buildingnum].id = buildingnum;
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_name.GetWindowTextW(str);
	building[buildingnum].name = str;
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_d.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_yinyong.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//���Ѳ���
	dhk->m_cost.GetWindowTextW(str);
	i = _ttoi(str);
	if (i)
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//��������
	i = dhk->m_advi.GetCurSel();
	if (i)
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//ǰ�ÿƼ�
	i = dhk->m_tech.GetCurSel();
	if (i)
	{
		*((int *)tt) = 2;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//ǰ������
	i = dhk->m_civic.GetCurSel();
	if (i)
	{
		*((int *)tt) = 3;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//�ڽӳ���
	i = dhk->m_dis.GetCurSel();
	if (i)
	{
		*((int *)tt) = 4;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//�ڽ���Դ
	i = dhk->m_res.GetCurSel();
	if (i)
	{
		*((int *)tt) = 5;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//��Ч���β�ԭ
	if (dhk->m_vt_caoyuan.GetCheck())
	{
		*((int *)tt) = 6;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч����ƽԭ
	if (dhk->m_vt_pingyuan.GetCheck())
	{
		*((int *)tt) = 7;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч����ɳĮ
	if (dhk->m_vt_shamo.GetCheck())
	{
		*((int *)tt) = 8;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч���ζ���
	if (dhk->m_vt_dongtu.GetCheck())
	{
		*((int *)tt) = 9;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч����ѩԭ
	if (dhk->m_vt_xueyuan.GetCheck())
	{
		*((int *)tt) = 10;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч��������
	if (dhk->m_vt_qiuling.GetCheck())
	{
		*((int *)tt) = 11;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч���κ���
	/*if (dhk->m_vt_hupo.GetCheck())
	{
		*((int *)tt) = 12;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}*/
	//��Ч���κ���
	if (dhk->m_vt_haian.GetCheck())
	{
		*((int *)tt) = 13;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч���κ���
	if (dhk->m_vt_haiyang.GetCheck())
	{
		*((int *)tt) = 14;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч����ɽ��
	if (dhk->m_vt_shanmai.GetCheck())
	{
		*((int *)tt) = 15;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//�����ò����
	if (dhk->m_rf_shenlin.GetCheck())
	{
		*((int *)tt) = 16;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//�����ò����
	if (dhk->m_rf_yulin.GetCheck())
	{
		*((int *)tt) = 17;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//�����ò����
	if (dhk->m_rf_zhaoze.GetCheck())
	{
		*((int *)tt) = 18;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//�����ò����
	if (dhk->m_rf_lvzhou.GetCheck())
	{
		*((int *)tt) = 19;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//�����ò���ƽԭ
	if (dhk->m_rf_chongji.GetCheck())
	{
		*((int *)tt) = 20;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//�����ò����
	if (dhk->m_rf_fubing.GetCheck())
	{
		*((int *)tt) = 21;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч��ò����
	if (dhk->m_vf_shenlin.GetCheck())
	{
		*((int *)tt) = 22;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч��ò����
	if (dhk->m_vf_yulin.GetCheck())
	{
		*((int *)tt) = 23;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч��ò����
	if (dhk->m_vf_zhaoze.GetCheck())
	{
		*((int *)tt) = 24;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч��ò����
	if (dhk->m_vf_lvzhou.GetCheck())
	{
		*((int *)tt) = 25;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч��ò���ƽԭ
	if (dhk->m_vf_chongji.GetCheck())
	{
		*((int *)tt) = 26;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ч��ò����
	if (dhk->m_vf_fubing.GetCheck())
	{
		*((int *)tt) = 27;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//����
	if (dhk->m_j1.GetCheck())
	{
		dhk->m_wanneng.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 28;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_j2.GetCheck())
	{
		dhk->m_wenwu.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 29;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_j3.GetCheck())
	{
		dhk->m_yiwu.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 30;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//��д
	if (dhk->m_j4.GetCheck())
	{
		dhk->m_shuxie.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 31;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_j5.GetCheck())
	{
		dhk->m_meishu.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 32;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_j6.GetCheck())
	{
		dhk->m_yuequ.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 33;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//Ԥ��
	if (dhk->m_w1.GetCheck())
	{
		dhk->m_yuyan.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 34;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_w2.GetCheck())
	{
		dhk->m_junshi.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 35;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_w3.GetCheck())
	{
		dhk->m_haijun.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 36;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//��ѧ
	if (dhk->m_w4.GetCheck())
	{
		dhk->m_kexue.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 37;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_w5.GetCheck())
	{
		dhk->m_gongcheng.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 38;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_w6.GetCheck())
	{
		dhk->m_shangren.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 39;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//��ѧ
	if (dhk->m_w7.GetCheck())
	{
		dhk->m_wenxue.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 40;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_w8.GetCheck())
	{
		dhk->m_yishu.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 41;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_w9.GetCheck())
	{
		dhk->m_yinyue.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 42;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//ʳ��
	if (dhk->m_c1.GetCheck())
	{
		dhk->m_food.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 43;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_c2.GetCheck())
	{
		dhk->m_channeng.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 44;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//���
	if (dhk->m_c3.GetCheck())
	{
		dhk->m_gold.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 45;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_c4.GetCheck())
	{
		dhk->m_keyan.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 46;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//�Ļ�
	if (dhk->m_c5.GetCheck())
	{
		dhk->m_wenhua.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 47;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//����
	if (dhk->m_c6.GetCheck())
	{
		dhk->m_xinyang.GetWindowTextW(str);
		i = _ttoi(str);
		if (i)
		{
			*((int *)tt) = 48;
			tt += 4;
			max -= 4;
			*((int *)tt) = i;
			tt += 4;
			max -= 4;
		}
	}
	//�������
	i = dhk->m_tx.GetCurSel();
	if (i)
	{
		*((int *)tt) = 49;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//��������
	i = dhk->m_tj.GetCurSel();
	if (i)
	{
		*((int *)tt) = 50;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	//�ٽ�ɽ��
	if (dhk->m_linjinshanmai.GetCheck())
	{
		*((int *)tt) = 51;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//�ٽ�½��
	if (dhk->m_linjinludi.GetCheck())
	{
		*((int *)tt) = 52;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//�����ڽ�
	if (dhk->m_chuangjianzongjiao.GetCheck())
	{
		*((int *)tt) = 53;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ϊ����
	if (dhk->m_baolei.GetCheck())
	{
		*((int *)tt) = 54;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��Ҫ�ٺ�
	if (dhk->m_river.GetCheck())
	{
		*((int *)tt) = 55;
		tt += 4;
		max -= 4;
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	//��������
	i = dhk->xuanze;
	if (i > 0)
	{
		*((int *)tt) = 56;
		tt += 4;
		max -= 4;
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}

	p->length = MAXLENGTH - max;
	ck->m_qian.EnableWindow(true);
	ck->m_delete.EnableWindow(true);
	ck->m_output.EnableWindow(true);
}

void project::fanqiguan(DLG_QiGuan * dhk)
{
	int length, i;
	char * tt;
	CString str;

	length = p->length;
	tt = p->data;
	dhk->csh();

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_type.SetWindowTextW(str);

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_name.SetWindowTextW(str);

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_d.SetWindowTextW(str);

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_yinyong.SetWindowTextW(str);

	while (length > 0)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		switch (i)
		{
		case 0:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_cost.SetWindowTextW(str);
			break;
		case 1:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_advi.SetCurSel(i);
			break;
		case 2:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_tech.SetCurSel(i);
			break;
		case 3:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_civic.SetCurSel(i);
			break;
		case 4:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_dis.SetCurSel(i);
			break;
		case 5:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_res.SetCurSel(i);
			break;
		case 6:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vt_caoyuan.SetCheck(true);
			}
			break;
		case 7:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vt_pingyuan.SetCheck(true);
			}
			break;
		case 8:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vt_shamo.SetCheck(true);
			}
			break;
		case 9:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vt_dongtu.SetCheck(true);
			}
			break;
		case 10:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vt_xueyuan.SetCheck(true);
			}
			break;
		case 11:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vt_qiuling.SetCheck(true);
			}
			break;
		case 12:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			/*if (i)
			{
				dhk->m_vt_hupo.SetCheck(true);
			}*/
			break;
		case 13:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vt_haian.SetCheck(true);
			}
			break;
		case 14:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vt_haiyang.SetCheck(true);
			}
			break;
		case 15:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vt_shanmai.SetCheck(true);
			}
			break;
		case 16:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_rf_shenlin.SetCheck(true);
			}
			break;
		case 17:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_rf_yulin.SetCheck(true);
			}
			break;
		case 18:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_rf_zhaoze.SetCheck(true);
			}
			break;
		case 19:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_rf_lvzhou.SetCheck(true);
			}
			break;
		case 20:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_rf_chongji.SetCheck(true);
			}
			break;
		case 21:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_rf_fubing.SetCheck(true);
			}
			break;
		case 22:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vf_shenlin.SetCheck(true);
			}
			break;
		case 23:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vf_yulin.SetCheck(true);
			}
			break;
		case 24:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vf_zhaoze.SetCheck(true);
			}
			break;
		case 25:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vf_lvzhou.SetCheck(true);
			}
			break;
		case 26:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vf_chongji.SetCheck(true);
			}
			break;
		case 27:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_vf_fubing.SetCheck(true);
			}
			break;
		case 28:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_wanneng.SetWindowTextW(str);
			dhk->m_wanneng.EnableWindow(true);
			dhk->m_j1.SetCheck(true);
			break;
		case 29:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_wenwu.SetWindowTextW(str);
			dhk->m_wenwu.EnableWindow(true);
			dhk->m_j2.SetCheck(true);
			break;
		case 30:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_yiwu.SetWindowTextW(str);
			dhk->m_yiwu.EnableWindow(true);
			dhk->m_j3.SetCheck(true);
			break;
		case 31:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_shuxie.SetWindowTextW(str);
			dhk->m_shuxie.EnableWindow(true);
			dhk->m_j4.SetCheck(true);
			break;
		case 32:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_meishu.SetWindowTextW(str);
			dhk->m_meishu.EnableWindow(true);
			dhk->m_j5.SetCheck(true);
			break;
		case 33:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_yuequ.SetWindowTextW(str);
			dhk->m_yuequ.EnableWindow(true);
			dhk->m_j6.SetCheck(true);
			break;
		case 34:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_yuyan.SetWindowTextW(str);
			dhk->m_yuyan.EnableWindow(true);
			dhk->m_w1.SetCheck(true);
			break;
		case 35:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_junshi.SetWindowTextW(str);
			dhk->m_junshi.EnableWindow(true);
			dhk->m_w2.SetCheck(true);
			break;
		case 36:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_haijun.SetWindowTextW(str);
			dhk->m_haijun.EnableWindow(true);
			dhk->m_w3.SetCheck(true);
			break;
		case 37:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_kexue.SetWindowTextW(str);
			dhk->m_kexue.EnableWindow(true);
			dhk->m_w4.SetCheck(true);
			break;
		case 38:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_gongcheng.SetWindowTextW(str);
			dhk->m_gongcheng.EnableWindow(true);
			dhk->m_w5.SetCheck(true);
			break;
		case 39:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_shangren.SetWindowTextW(str);
			dhk->m_shangren.EnableWindow(true);
			dhk->m_w6.SetCheck(true);
			break;
		case 40:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_wenxue.SetWindowTextW(str);
			dhk->m_wenxue.EnableWindow(true);
			dhk->m_w7.SetCheck(true);
			break;
		case 41:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_yishu.SetWindowTextW(str);
			dhk->m_yishu.EnableWindow(true);
			dhk->m_w8.SetCheck(true);
			break;
		case 42:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_yinyue.SetWindowTextW(str);
			dhk->m_yinyue.EnableWindow(true);
			dhk->m_w9.SetCheck(true);
			break;
		case 43:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_food.SetWindowTextW(str);
			dhk->m_food.EnableWindow(true);
			dhk->m_c1.SetCheck(true);
			break;
		case 44:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_channeng.SetWindowTextW(str);
			dhk->m_channeng.EnableWindow(true);
			dhk->m_c2.SetCheck(true);
			break;
		case 45:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_gold.SetWindowTextW(str);
			dhk->m_gold.EnableWindow(true);
			dhk->m_c3.SetCheck(true);
			break;
		case 46:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_keyan.SetWindowTextW(str);
			dhk->m_keyan.EnableWindow(true);
			dhk->m_c4.SetCheck(true);
			break;
		case 47:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_wenhua.SetWindowTextW(str);
			dhk->m_wenhua.EnableWindow(true);
			dhk->m_c5.SetCheck(true);
			break;
		case 48:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str.Format(L"%d", i);
			dhk->m_xinyang.SetWindowTextW(str);
			dhk->m_xinyang.EnableWindow(true);
			dhk->m_c6.SetCheck(true);
			break;
		case 49:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_tx.SetCurSel(i);
			break;
		case 50:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->m_tj.SetCurSel(i);
			break;
		case 51:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_linjinshanmai.SetCheck(true);
			}
			break;
		case 52:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_linjinludi.SetCheck(true);
			}
			break;
		case 53:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_chuangjianzongjiao.SetCheck(true);
			}
			break;
		case 54:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_baolei.SetCheck(true);
			}
			break;
		case 55:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			if (i)
			{
				dhk->m_river.SetCheck(true);
			}
			break;
		case 56:
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			dhk->xuanze = i;
			if (i == 1)
			{
				((CButton*)(dhk->GetDlgItem(1042)))->SetCheck(1);
				((CButton*)(dhk->GetDlgItem(1043)))->SetCheck(0);
				((CButton*)(dhk->GetDlgItem(1044)))->SetCheck(0);
			}
			else
			{
				((CButton*)(dhk->GetDlgItem(1042)))->SetCheck(0);
				((CButton*)(dhk->GetDlgItem(1043)))->SetCheck(1);
				((CButton*)(dhk->GetDlgItem(1044)))->SetCheck(0);
			}
			break;
		}
	}
}

void project::shengqiguan(char * tt, int length)
{
	CString str;
	CString strtemp;
	CString strtype;
	int i;

	JianZhu.Buildings += L"\t\t<Row";
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" BuildingType=\"BUILDING_%s\"", strtemp);
	strtype.Format(L"BUILDING_%s", strtemp);
	tt += i;
	length -= i;
	JianZhu.Buildings += str;
	str.Format(L"\t\t<Row Type=\"%s\" Kind=\"KIND_BUILDING\"/>\r\n", strtype);
	Type += str;

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Name=\"LOC_%s_NAME\"", strtype);
	tt += i;
	length -= i;
	JianZhu.Buildings += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Description=\"LOC_%s_DESCRIPTION\"", strtype);
	tt += i;
	length -= i;
	JianZhu.Buildings += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_DESCRIPTION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Quote=\"LOC_%s_QUOTE\"", strtype);
	tt += i;
	length -= i;
	JianZhu.Buildings += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_QUOTE\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i != 0)
	{
		JianZhu.Buildings += L" Cost=\"1\"";
	}
	else
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" Cost=\"%d\"", i);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i != 1)
	{
		JianZhu.Buildings += L" AdvisorType=\"ADVISOR_CULTURE\"";
	}
	else
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" AdvisorType=\"%s\"", dis[i]);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 2)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" PrereqTech=\"%s\"", tech[i].type);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 3)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" PrereqCivic=\"%s\"", civic[i].type);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 4)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" AdjacentDistrict=\"%s\"", dis[i - 1]);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 5)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" AdjacentResource=\"%s\"", ziyuan[i - 1].type);
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	JianZhu.Buildings += L"MaxWorldInstances=\"1\" IsWonder=\"true\" RequiresPlacement=\"true\"";
	if (i == 6)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_GRASS\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 7)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_PLAINS\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 8)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_DESERT\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 9)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_TUNDRA\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 10)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_SNOW\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 11)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_GRASS_HILLS\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_PLAINS_HILLS\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_DESERT_HILLS\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_TUNDRA_HILLS\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_SNOW_HILLS\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 13)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_COAST\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 14)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_OCEAN\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 15)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_GRASS_MOUNTAIN\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_PLAINS_MOUNTAIN\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_DESERT_MOUNTAIN\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_TUNDRA_MOUNTAIN\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		str.Format(L"\t\t<Row BuildingType=\"%s\" TerrainType=\"TERRAIN_SNOW_MOUNTAIN\"/>\r\n", strtype);
		JianZhu.Building_ValidTerrains += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 16)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" FeatureType=\"FEATURE_FOREST\"/>\r\n", strtype);
		JianZhu.Building_RequiredFeatures += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 17)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" FeatureType=\"FEATURE_JUNGLE\"/>\r\n", strtype);
		JianZhu.Building_RequiredFeatures += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 18)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" FeatureType=\"FEATURE_MARSH\"/>\r\n", strtype);
		JianZhu.Building_RequiredFeatures += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 19)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" FeatureType=\"FEATURE_OASIS\"/>\r\n", strtype);
		JianZhu.Building_RequiredFeatures += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 20)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" FeatureType=\"FEATURE_FLOODPLAINS\"/>\r\n", strtype);
		JianZhu.Building_RequiredFeatures += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 21)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" FeatureType=\"FEATURE_ICE\"/>\r\n", strtype);
		JianZhu.Building_RequiredFeatures += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 22)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" FeatureType=\"FEATURE_FOREST\"/>\r\n", strtype);
		JianZhu.Building_ValidFeatures += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 23)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" FeatureType=\"FEATURE_JUNGLE\"/>\r\n", strtype);
		JianZhu.Building_ValidFeatures += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 24)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" FeatureType=\"FEATURE_MARSH\"/>\r\n", strtype);
		JianZhu.Building_ValidFeatures += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 25)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" FeatureType=\"FEATURE_OASIS\"/>\r\n", strtype);
		JianZhu.Building_ValidFeatures += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 26)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" FeatureType=\"FEATURE_FLOODPLAINS\"/>\r\n", strtype);
		JianZhu.Building_ValidFeatures += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 27)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" FeatureType=\"FEATURE_ICE\"/>\r\n", strtype);
		JianZhu.Building_ValidFeatures += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 28)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatWorkSlotType=\"GREATWORKSLOT_PALACE\" NumSlots=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatWorks += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 29)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatWorkSlotType=\"GREATWORKOBJECT_ARTIFACT\" NumSlots=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatWorks += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 30)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatWorkSlotType=\"GREATWORKSLOT_RELIC\" NumSlots=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatWorks += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 31)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatWorkSlotType=\"GREATWORKSLOT_WRITING\" NumSlots=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatWorks += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 32)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatWorkSlotType=\"GREATWORKSLOT_ART\" NumSlots=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatWorks += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 33)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatWorkSlotType=\"GREATWORKSLOT_MUSIC\" NumSlots=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatWorks += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 34)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatPersonClassType=\"GREAT_PERSON_CLASS_PROPHET\" PointsPerTurn=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatPersonPoints += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 35)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatPersonClassType=\"GREAT_PERSON_CLASS_GENERAL\" PointsPerTurn=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatPersonPoints += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 36)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatPersonClassType=\"GREAT_PERSON_CLASS_ADMIRAL\" PointsPerTurn=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatPersonPoints += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 37)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatPersonClassType=\"GREAT_PERSON_CLASS_SCIENTIST\" PointsPerTurn=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatPersonPoints += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 38)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatPersonClassType=\"GREAT_PERSON_CLASS_ENGINEER\" PointsPerTurn=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatPersonPoints += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 39)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatPersonClassType=\"GREAT_PERSON_CLASS_MERCHANT\" PointsPerTurn=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatPersonPoints += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 40)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatPersonClassType=\"GREAT_PERSON_CLASS_WRITER\" PointsPerTurn=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatPersonPoints += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 41)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatPersonClassType=\"GREAT_PERSON_CLASS_ARTIST\" PointsPerTurn=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatPersonPoints += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 42)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" GreatPersonClassType=\"GREAT_PERSON_CLASS_MUSICIAN\" PointsPerTurn=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_GreatPersonPoints += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 43)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" YieldType=\"YIELD_FOOD\" YieldChange=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_YieldChanges += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 44)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" YieldType=\"YIELD_PRODUCTION\" YieldChange=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_YieldChanges += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 45)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" YieldType=\"YIELD_GOLD\" YieldChange=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_YieldChanges += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 46)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" YieldType=\"YIELD_SCIENCE\" YieldChange=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_YieldChanges += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 47)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" YieldType=\"YIELD_CULTURE\" YieldChange=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_YieldChanges += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 48)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row BuildingType=\"%s\" YieldType=\"YIELD_FAITH\" YieldChange=\"%d\"/>\r\n", strtype, i);
		JianZhu.Building_YieldChanges += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 49)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t<Row>\r\n\t\t\t<BuildingType>%s</BuildingType>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t</Row>\r\n", strtype, zongtexing[i].type);
		JianZhu.BuildingModifiers += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 50)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 51)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" AdjacentToMountain=\"true\"");
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 52)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" MustBeAdjacentLand=\"true\"");
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 53)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" RequiresReligion=\"true\"");
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 54)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" GrantFortification=\"2\"");
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 55)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" RequiresRiver=\"true\"");
		JianZhu.Buildings += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (i == 56)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		if (i == 1)
		{
			str.Format(L" MustBeLake=\"true\"");
			JianZhu.Buildings += str;
		}
		else
		{
			str.Format(L" MustNotBeLake=\"true\"");
			JianZhu.Buildings += str;
		}
		i = *((int *)tt);
		tt += 4;
		length -= 4;
	}
	if (jlroot)
	{
		jlp = jlroot;
		while (jlp)
		{
			if ((jlp->leixing == 0) || (jlp->leixing == 2))
			{
				if (strtype.Compare(jlp->yuan))
				{
					jlp = jlp->next;
				}
				else
				{
					str.Format(L" TraitType==\"%s\"", jlp->str);
					JianZhu.Buildings += str;
					break;
				}
			}
			else
			{
				jlp = jlp->next;
			}
		}
	}
	JianZhu.Buildings += L"/>\r\n";
}

void project::wenming(DLG_WenMing * dhk)
{
	int i, j;
	char temp[4096];
	CString str;
	int length;
	int max;
	char * tt, * tt2;

	struct jilu * jz, *dw;//������󱣴��¼��
	jz = dw = NULL;

	if (id == number)//��ǰָ��ָ�����һ������
	{
		if (p == NULL)
		{
			root = p = new struct table;
		}
		else
		{
			p->hou = new struct table;
			p->hou->qian = p;
			p = p->hou;
		}
		id = number++;
	}
	else
	{
		if (p->type != 2)
		{
			MessageBox(NULL, L"������һ����ťֱ���ð�ťΪ��ɫ�ٳ��Ըò�����", L"�α����", MB_OK);
			return;
		}
	}
	tt = p->data;
	p->length = 0;
	p->type = 2;
	p->id = id;
	max = MAXLENGTH;
	//Ӣ������
	dhk->m_type.GetWindowTextW(str);
	if (wenmingnum >= 1000)
	{
		MessageBox(NULL, L"����������������ɵ��������������½����̻��ֶ���ӣ�", L"��������", MB_OK);
		return;
	}
	wenmingnum++;
	::wenming[wenmingnum].type = L"CIVILIZATION_" + str;
	::wenming[wenmingnum].id = wenmingnum;
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_name.GetWindowTextW(str);
	::wenming[wenmingnum].name = str;
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_d.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//������Դ
	i = dhk->m_qiyuan.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//����Ӣ��
	dhk->m_txtype.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_txname.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_txd.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ����
	i = dhk->m_jianzhu.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	if (i)
	{
		jlp = jlroot;
		if (jlp)
		{
			while (jlp->next)
			{
				jlp = jlp->next;
			}
			jlp->next = new struct jilu;
			jlp = jlp->next;
		}
		else
		{
			jlroot = jlp = new struct jilu;
		}
		jz = jlp;
		jlp->leixing = 0;
		jlp->yuan = building[i].type;
		jlp->str.Format(L"TRAIT_CIVILIZATION_%s", building[i].type);
	}
	//����˵��
	dhk->m_jianzhud.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ��λ
	i = dhk->m_danwei.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	if (i)
	{
		jlp = jlroot;
		if (jlp)
		{
			while (jlp->next)
			{
				jlp = jlp->next;
			}
			jlp->next = new struct jilu;
			jlp = jlp->next;
		}
		else
		{
			jlroot = jlp = new struct jilu;
		}
		dw = jlp;
		jlp->leixing = 1;
		jlp->yuan = unit[i].type;
		jlp->str.Format(L"TRAIT_CIVILIZATION_%s", unit[i].type);
	}
	//��λ˵��
	dhk->m_danweid.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//����
	j = dhk->m_list.GetCount();
	*((int *)tt) = j;
	tt += 4;
	max -= 4;
	for (i = 0; i < j; i++)
	{
		dhk->m_list.GetText(i, str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//20��������
	dhk->m_c1.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c2.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c3.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c4.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c5.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c6.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c7.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c8.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c9.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c10.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c11.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c12.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c13.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c14.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c15.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c16.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c17.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c18.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c19.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	dhk->m_c20.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	if (dhk->m_heliu.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		dhk->m_heliug.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//������Դ
	if (dhk->m_ziyuan.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		i = dhk->m_ziyuanc.GetCurSel();
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
		dhk->m_ziyuang.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//������ò
	if (dhk->m_dimao.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		i = dhk->m_dimaoc.GetCurSel();
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
		dhk->m_dimaog.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//��������
	if (dhk->m_dixing.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		i = dhk->m_dixingc.GetCurSel();
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
		dhk->m_dixingg.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}

	if (max < 0)
	{
		MessageBox(NULL, L"����ӵ����Թ������ڸ��ӣ��뾫������ԣ�", L"���Թ��ڸ���", MB_OK);
		return;
	}

	tt2 = tt;
	if (jz)
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		*((int *)tt) = jz->leixing;
		tt += 4;
		max -= 4;
		length = WideCharToMultiByte(CP_ACP, 0, jz->yuan, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
		length = WideCharToMultiByte(CP_ACP, 0, jz->str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	if (dw)
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		*((int *)tt) = dw->leixing;
		tt += 4;
		max -= 4;
		length = WideCharToMultiByte(CP_ACP, 0, dw->yuan, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
		length = WideCharToMultiByte(CP_ACP, 0, dw->str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	*((int *)tt) = tt - tt2;
	tt += 4;
	max -= 4;

	p->length = MAXLENGTH - max;
	ck->m_qian.EnableWindow(true);
	ck->m_delete.EnableWindow(true);
	ck->m_output.EnableWindow(true);
}

void project::fanwenming(DLG_WenMing * dhk)
{
	int length, i, j, k;
	char * tt;
	CString str;

	length = p->length;
	tt = p->data;
	dhk->csh();

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_type.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_name.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_d.SetWindowTextW(str);

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_qiyuan.SetCurSel(i);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_txtype.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_txname.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_txd.SetWindowTextW(str);

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_jianzhu.SetCurSel(i);
	if (i)//�жϼ�¼�����Ƿ��ж�Ӧ���ݣ�û���򴴽�
	{
		jlp = jlroot;
		while (jlp)
		{
			if ((jlp->leixing == 0) && !(jlp->yuan.Compare(building[i].type)))
			{
				break;
			}
			else
			{
				jlp = jlp->next;
			}
		}
		if (jlp == NULL)
		{
			jlp = jlroot;
			if (jlp)
			{
				while (jlp->next)
				{
					jlp = jlp->next;
				}
				jlp->next = new struct jilu;
				jlp = jlp->next;
			}
			else
			{
				jlroot = jlp = new struct jilu;
			}
			jlp->leixing = 0;
			jlp->yuan = building[i].type;
			jlp->str.Format(L"TRAIT_CIVILIZATION_%s", building[i].type);
		}
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_jianzhud.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_danwei.SetCurSel(i);
	if (i)//�жϼ�¼�����Ƿ��ж�Ӧ���ݣ�û���򴴽�
	{
		jlp = jlroot;
		while (jlp)
		{
			if ((jlp->leixing == 1) && !(jlp->yuan.Compare(unit[i].type)))
			{
				break;
			}
			else
			{
				jlp = jlp->next;
			}
		}
		if (jlp == NULL)
		{
			jlp = jlroot;
			if (jlp)
			{
				while (jlp->next)
				{
					jlp = jlp->next;
				}
				jlp->next = new struct jilu;
				jlp = jlp->next;
			}
			else
			{
				jlroot = jlp = new struct jilu;
			}
			jlp->leixing = 1;
			jlp->yuan = unit[i].type;
			jlp->str.Format(L"TRAIT_CIVILIZATION_%s", unit[i].type);
		}
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_danweid.SetWindowTextW(str);

	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (k = 0; k < j; k++)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_list.InsertString(-1, str);
	}
	//20��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c1.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c2.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c3.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c4.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c5.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c6.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c7.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c8.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c9.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c10.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c11.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c12.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c13.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c14.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c15.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c16.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c17.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c18.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c19.SetWindowTextW(str);
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_c20.SetWindowTextW(str);

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_heliu.SetCheck(1);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_heliug.SetWindowTextW(str);
		dhk->m_heliug.EnableWindow(true);
	}
	else
	{
		dhk->m_heliu.SetCheck(0);
		dhk->m_heliug.EnableWindow(false);
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_ziyuan.SetCheck(1);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		dhk->m_ziyuanc.SetCurSel(i);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_ziyuang.SetWindowTextW(str);
		dhk->m_ziyuanc.EnableWindow(true);
		dhk->m_ziyuang.EnableWindow(true);
	}
	else
	{
		dhk->m_ziyuan.SetCheck(0);
		dhk->m_ziyuanc.EnableWindow(false);
		dhk->m_ziyuang.EnableWindow(false);
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_dimao.SetCheck(1);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		dhk->m_dimaoc.SetCurSel(i);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_dimaog.SetWindowTextW(str);
		dhk->m_dimaoc.EnableWindow(true);
		dhk->m_dimaog.EnableWindow(true);
	}
	else
	{
		dhk->m_dimao.SetCheck(0);
		dhk->m_dimaoc.EnableWindow(false);
		dhk->m_dimaog.EnableWindow(false);
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_dixing.SetCheck(1);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		dhk->m_dixingc.SetCurSel(i);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_dixingg.SetWindowTextW(str);
		dhk->m_dixingc.EnableWindow(true);
		dhk->m_dixingg.EnableWindow(true);
	}
	else
	{
		dhk->m_dixing.SetCheck(0);
		dhk->m_dixingc.EnableWindow(false);
		dhk->m_dixingg.EnableWindow(false);
	}
}

void project::shengwenming(char * tt, int length)
{
	CString str, name;
	CString strtemp;
	CString strtype;
	CString strtype2;
	int i, j, cd;

	WenMing.Civilizations += L"\t\t<Row";
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" CivilizationType=\"CIVILIZATION_%s\"", strtemp);
	strtype.Format(L"CIVILIZATION_%s", strtemp);
	tt += i;
	length -= i;
	WenMing.Civilizations += str;
	str.Format(L"\t\t<Row Type=\"%s\" Kind=\"KIND_CIVILIZATION\"/>\r\n", strtype);
	Type += str;
	name = strtemp;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Name=\"LOC_%s_NAME\"", strtype);
	tt += i;
	length -= i;
	WenMing.Civilizations += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_ADJECTIVE\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	//�����Ͱٿ�
	for (i = 0; i < 10; i++)
	{
		str.Format(L"\t\t<Row CivilizationType=\"%s\" CitizenName=\"LOC_CITIZEN_%s_MALE_%d\"/>\r\n", strtype, name, i + 1);
		WenMing.CivilizationCitizenNames += str;
		str.Format(L"\t\t<Replace Tag=\"LOC_CITIZEN_%s_MALE_%d\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s����%d</Text>\r\n\t\t</Replace>\r\n", name, i + 1, strtemp, i + 1);
		Text += str;
	}
	for (i = 0; i < 10; i++)
	{
		str.Format(L"\t\t<Row CivilizationType=\"%s\" CitizenName=\"LOC_CITIZEN_%s_FEMALE_%d\" Female=\"true\"/>\r\n", strtype, name, i + 1);
		WenMing.CivilizationCitizenNames += str;
		str.Format(L"\t\t<Replace Tag=\"LOC_CITIZEN_%s_FEMALE_%d\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%sŮ��%d</Text>\r\n\t\t</Replace>\r\n", name, i + 1, strtemp, i + 1);
		Text += str;
	}
	for (i = 0; i < 10; i++)
	{
		str.Format(L"\t\t<Row CivilizationType=\"%s\" CitizenName=\"LOC_CITIZEN_%s_MODERN_MALE_%d\"  Modern=\"true\"/>\r\n", strtype, name, i + 1);
		WenMing.CivilizationCitizenNames += str;
		str.Format(L"\t\t<Replace Tag=\"LOC_CITIZEN_%s_MODERN_MALE_%d\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s�ִ�����%d</Text>\r\n\t\t</Replace>\r\n", name, i + 1, strtemp, i + 1);
		Text += str;
	}
	for (i = 0; i < 10; i++)
	{
		str.Format(L"\t\t<Row CivilizationType=\"%s\" CitizenName=\"LOC_CITIZEN_%s_MODERN_FEMALE_%d\"  Female=\"true\"  Modern=\"true\"/>\r\n", strtype, name, i + 1);
		WenMing.CivilizationCitizenNames += str;
		str.Format(L"\t\t<Replace Tag=\"LOC_CITIZEN_%s_MODERN_FEMALE_%d\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s�ִ�Ů��%d</Text>\r\n\t\t</Replace>\r\n", name, i + 1, strtemp, i + 1);
		Text += str;
	}
	str.Format(L"\t\t<Row CivilizationType=\"%s\" Header=\"LOC_CIVINFO_LOCATION\" Caption=\"LOC_CIVINFO_%s_LOCATION\" SortIndex=\"10\"/>\r\n", strtype, name);
	WenMing.CivilizationInfo += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_CIVINFO_%s_LOCATION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%sλ��</Text>\r\n\t\t</Replace>\r\n", name, strtemp);
	Text += str;
	str.Format(L"\t\t<Row CivilizationType=\"%s\" Header=\"LOC_CIVINFO_SIZE\" Caption=\"LOC_CIVINFO_%s_SIZE\" SortIndex=\"20\"/>\r\n", strtype, name);
	WenMing.CivilizationInfo += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_CIVINFO_%s_SIZE\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s��ģ</Text>\r\n\t\t</Replace>\r\n", name, strtemp);
	Text += str;
	str.Format(L"\t\t<Row CivilizationType=\"%s\" Header=\"LOC_CIVINFO_POPULATION\" Caption=\"LOC_CIVINFO_%s_POPULATION\" SortIndex=\"30\"/>\r\n", strtype, name);
	WenMing.CivilizationInfo += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_CIVINFO_%s_POPULATION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s�˿�</Text>\r\n\t\t</Replace>\r\n", name, strtemp);
	Text += str;
	str.Format(L"\t\t<Row CivilizationType=\"%s\" Header=\"LOC_CIVINFO_CAPITAL\" Caption=\"LOC_CIVINFO_%s_CAPITAL\" SortIndex=\"40\"/>\r\n", strtype, name);
	WenMing.CivilizationInfo += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_CIVINFO_%s_CAPITAL\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s�׶�</Text>\r\n\t\t</Replace>\r\n", name, strtemp);
	Text += str;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Description=\"LOC_%s_DESCRIPTION\"", strtype);
	tt += i;
	length -= i;
	WenMing.Civilizations += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_DESCRIPTION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	str.Format(L" Adjective=\"LOC_%s_ADJECTIVE\" StartingCivilizationLevelType=\"CIVILIZATION_LEVEL_FULL_CIV\" RandomCityNameDepth=\"10\"", strtype);
	WenMing.Civilizations += str;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str.Format(L" Ethnicity=\"%s\"/>\r\n", qiyuan[i]);
	WenMing.Civilizations += str;
	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L"\t\t<Row TraitType=\"TRAIT_%s\"", strtype);
	strtype2.Format(L"TRAIT_%s", strtype);
	tt += i;
	length -= i;
	WenMing.Traits += str;
	str.Format(L"\t\t<Row Type=\"%s\" Kind=\"KIND_TRAIT\"/>\r\n", strtype2);
	Type += str;
	str.Format(L"\t\t<Row CivilizationType=\"%s\" TraitType=\"%s\"/>\r\n", strtype, strtype2);
	WenMing.CivilizationTraits += str;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Name=\"LOC_%s_NAME\"", strtype2);
	tt += i;
	length -= i;
	WenMing.Traits += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype2, strtemp);
	Text += str;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Description=\"LOC_%s_DESCRIPTION\"/>\r\n", strtype2);
	tt += i;
	length -= i;
	WenMing.Traits += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_DESCRIPTION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype2, strtemp);
	Text += str;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row TraitType=\"TRAIT_CIVILIZATION_%s\" Name=\"LOC_TRAIT_CIVILIZATION_%s_NAME\"/>\r\n", building[i].type, building[i].type);
		WenMing.Traits += str;
		str.Format(L"\t\t<Row CivilizationType=\"%s\" TraitType=\"TRAIT_CIVILIZATION_%s\"/>\r\n", strtype, building[i].type);
		WenMing.CivilizationTraits += str;
		str.Format(L"\t\t<Row Type=\"TRAIT_CIVILIZATION_%s\" Kind=\"KIND_TRAIT\"/>\r\n", building[i].type);
		Type += str;
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += cd;
		length -= cd;
		str.Format(L"\t\t<Replace Tag=\"LOC_TRAIT_CIVILIZATION_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", building[i].type, strtemp);
		Text += str;
	}
	else
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row TraitType=\"TRAIT_CIVILIZATION_%s\" Name=\"LOC_TRAIT_CIVILIZATION_%s_NAME\"/>\r\n", unit[i].type, unit[i].type);
		WenMing.Traits += str;
		str.Format(L"\t\t<Row CivilizationType=\"%s\" TraitType=\"TRAIT_CIVILIZATION_%s\"/>\r\n", strtype, unit[i].type);
		WenMing.CivilizationTraits += str;
		str.Format(L"\t\t<Row Type=\"TRAIT_CIVILIZATION_%s\" Kind=\"KIND_TRAIT\"/>\r\n", unit[i].type);
		Type += str;
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += cd;
		length -= cd;
		str.Format(L"\t\t<Replace Tag=\"LOC_TRAIT_CIVILIZATION_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", unit[i].type, strtemp);
		Text += str;
	}
	else
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
	}
	//����
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (i = 0; i < j; i++)
	{
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L"%s", strtemp.Left(strtemp.Find(L":")));
		str.Format(L"\t\t<Row>\r\n\t\t\t<TraitType>%s</TraitType>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t</Row>\r\n", strtype2, zongtexing[_ttoi(str)].type);
		tt += cd;
		length -= cd;
		TraitModifiers += str;
	}
	//20������
	for (j = 0; j < 20; j++)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L"\t\t<Row CivilizationType=\"%s\" CityName=\"LOC_CITY_NAME_%s_%d\"/>\r\n", strtype, strtype, j + 1);
		WenMing.CityNames += str;
		str.Format(L"\t\t<Replace Tag=\"LOC_CITY_NAME_%s_%d\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, j + 1, strtemp);
		Text += str;
		tt += i;
		length -= i;
	}
	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		str.Format(L"\t\t<Row CivilizationType=\"%s\" Tier=\"%s\"/>\r\n", strtype, strtemp);
		WenMing.StartBiasRivers += str;
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		j = *((int *)tt);
		tt += 4;
		length -= 4;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		str.Format(L"\t\t<Row CivilizationType=\"%s\" ResourceType=\"%s\" Tier=\"%s\"/>\r\n", strtype, ziyuan[j + 1].type, strtemp);
		WenMing.StartBiasResources += str;
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		j = *((int *)tt);
		tt += 4;
		length -= 4;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		str.Format(L"\t\t<Row CivilizationType=\"%s\" FeatureType=\"%s\" Tier=\"%s\"/>\r\n", strtype, fea[j], strtemp);
		WenMing.StartBiasFeatures += str;
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		j = *((int *)tt);
		tt += 4;
		length -= 4;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		str.Format(L"\t\t<Row CivilizationType=\"%s\" TerrainType=\"%s\" Tier=\"%s\"/>\r\n", strtype, ter[j], strtemp);
		WenMing.StartBiasTerrains += str;
	}
}

void project::lingxiu(DLG_LingXiu * dhk)
{
	int i, j;
	char temp[4096];
	CString str;
	int length;
	int max;
	char * tt, *tt2;

	struct jilu * jz, *dw;//������󱣴��¼��
	jz = dw = NULL;

	if (id == number)//��ǰָ��ָ�����һ������
	{
		if (p == NULL)
		{
			root = p = new struct table;
		}
		else
		{
			p->hou = new struct table;
			p->hou->qian = p;
			p = p->hou;
		}
		id = number++;
	}
	else
	{
		if (p->type != 3)
		{
			MessageBox(NULL, L"������һ����ťֱ���ð�ťΪ��ɫ�ٳ��Ըò�����", L"�α����", MB_OK);
			return;
		}
	}
	tt = p->data;
	p->length = 0;
	p->type = 3;
	p->id = id;
	max = MAXLENGTH;
	//Ӣ������
	dhk->m_type.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_name.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_d.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_yinshu.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//����Ӣ��
	dhk->m_ttype.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_tname.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_td.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	i = dhk->m_wenming.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//�׶�
	dhk->m_shoudu.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//�������
	i = dhk->m_yicheng.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��ѡ���
	i = dhk->m_shouxuan.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��������
	i = dhk->m_wjianzhu.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//������λ
	i = dhk->m_wdanwei.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��ɫ��
	dhk->m_zhong.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ��
	dhk->m_zlv.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ��
	dhk->m_zlan.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ͸��
	dhk->m_ztou.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ��
	dhk->m_fhong.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ��
	dhk->m_flv.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ��
	dhk->m_flan.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ͸��
	dhk->m_ftou.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ����
	i = dhk->m_jianzhu.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	if (i)
	{
		jlp = jlroot;
		if (jlp)
		{
			while (jlp->next)
			{
				jlp = jlp->next;
			}
			jlp->next = new struct jilu;
			jlp = jlp->next;
		}
		else
		{
			jlroot = jlp = new struct jilu;
		}
		jz = jlp;
		jlp->leixing = 2;
		jlp->yuan = building[i].type;
		jlp->str.Format(L"TRAIT_LEADER_%s", building[i].type);
	}
	//����˵��
	dhk->m_jianzhud.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ��λ
	i = dhk->m_danwei.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	if (i)
	{
		jlp = jlroot;
		if (jlp)
		{
			while (jlp->next)
			{
				jlp = jlp->next;
			}
			jlp->next = new struct jilu;
			jlp = jlp->next;
		}
		else
		{
			jlroot = jlp = new struct jilu;
		}
		dw = jlp;
		jlp->leixing = 3;
		jlp->yuan = unit[i].type;
		jlp->str.Format(L"TRAIT_LEADER_%s", unit[i].type);
	}
	//��λ˵��
	dhk->m_danweid.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//����AI
	j = dhk->m_ailist.GetCount();
	*((int *)tt) = j;
	tt += 4;
	max -= 4;
	for (i = 0; i < j; i++)
	{
		dhk->m_ailist.GetText(i, str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//����
	j = dhk->m_list.GetCount();
	*((int *)tt) = j;
	tt += 4;
	max -= 4;
	for (i = 0; i < j; i++)
	{
		dhk->m_list.GetText(i, str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}

	if (max < 0)
	{
		MessageBox(NULL, L"����ӵ����Թ������ڸ��ӣ��뾫������ԣ�", L"���Թ��ڸ���", MB_OK);
		return;
	}

	tt2 = tt;
	if (jz)
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		*((int *)tt) = jz->leixing;
		tt += 4;
		max -= 4;
		length = WideCharToMultiByte(CP_ACP, 0, jz->yuan, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
		length = WideCharToMultiByte(CP_ACP, 0, jz->str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	if (dw)
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		*((int *)tt) = dw->leixing;
		tt += 4;
		max -= 4;
		length = WideCharToMultiByte(CP_ACP, 0, dw->yuan, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
		length = WideCharToMultiByte(CP_ACP, 0, dw->str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	*((int *)tt) = tt - tt2;
	tt += 4;
	max -= 4;

	p->length = MAXLENGTH - max;
	ck->m_qian.EnableWindow(true);
	ck->m_delete.EnableWindow(true);
	ck->m_output.EnableWindow(true);
}

void project::fanlingxiu(DLG_LingXiu * dhk)
{
	int length, i, j, k;
	char * tt;
	CString str;

	length = p->length;
	tt = p->data;
	dhk->csh();

	//Ӣ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_type.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_name.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_d.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_yinshu.SetWindowTextW(str);
	//����Ӣ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_ttype.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_tname.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_td.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_wenming.SetCurSel(i);
	//�׶�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_shoudu.SetWindowTextW(str);
	//�������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_yicheng.SetCurSel(i);
	//��ѡ���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_shouxuan.SetCurSel(i);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_wjianzhu.SetCurSel(i);
	//������λ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_wdanwei.SetCurSel(i);
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_zhong.SetWindowTextW(str);
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_zlv.SetWindowTextW(str);
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_zlan.SetWindowTextW(str);
	//��ɫ͸��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_ztou.SetWindowTextW(str);
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_fhong.SetWindowTextW(str);
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_flv.SetWindowTextW(str);
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_flan.SetWindowTextW(str);
	//��ɫ͸��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_ftou.SetWindowTextW(str);
	//��ɫ����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_jianzhu.SetCurSel(i);
	if (i)//�жϼ�¼�����Ƿ��ж�Ӧ���ݣ�û���򴴽�
	{
		jlp = jlroot;
		while (jlp)
		{
			if ((jlp->leixing == 2) && !(jlp->yuan.Compare(building[i].type)))
			{
				break;
			}
			else
			{
				jlp = jlp->next;
			}
		}
		if (jlp == NULL)
		{
			jlp = jlroot;
			if (jlp)
			{
				while (jlp->next)
				{
					jlp = jlp->next;
				}
				jlp->next = new struct jilu;
				jlp = jlp->next;
			}
			else
			{
				jlroot = jlp = new struct jilu;
			}
			jlp->leixing = 2;
			jlp->yuan = building[i].type;
			jlp->str.Format(L"TRAIT_LEADER_%s", building[i].type);
		}
	}
	//����˵��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_jianzhud.SetWindowTextW(str);
	//��ɫ��λ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_danwei.SetCurSel(i);
	if (i)//�жϼ�¼�����Ƿ��ж�Ӧ���ݣ�û���򴴽�
	{
		jlp = jlroot;
		while (jlp)
		{
			if ((jlp->leixing == 3) && !(jlp->yuan.Compare(unit[i].type)))
			{
				break;
			}
			else
			{
				jlp = jlp->next;
			}
		}
		if (jlp == NULL)
		{
			jlp = jlroot;
			if (jlp)
			{
				while (jlp->next)
				{
					jlp = jlp->next;
				}
				jlp->next = new struct jilu;
				jlp = jlp->next;
			}
			else
			{
				jlroot = jlp = new struct jilu;
			}
			jlp->leixing = 3;
			jlp->yuan = unit[i].type;
			jlp->str.Format(L"TRAIT_LEADER_%s", unit[i].type);
		}
	}
	//��λ˵��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_danweid.SetWindowTextW(str);
	//����AI
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (k = 0; k < j; k++)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_ailist.InsertString(-1, str);
	}
	//����
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (k = 0; k < j; k++)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_list.InsertString(-1, str);
	}
}

void project::shenglingxiu(char * tt, int length)
{
	CString str, str2, shuzhi;
	CString strtemp;
	CString strtype;
	CString strtype2;
	//CString strtype3;
	int i, j, k, cd, jishu, wm;

	//Ӣ������
	LingXiu.Leaders += L"\t\t<Row";
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" LeaderType=\"LEADER_%s\"", strtemp);
	strtype.Format(L"LEADER_%s", strtemp);
	strtype2.Format(L"TRAIT_LEADER_%s", strtemp);
	tt += i;
	length -= i;
	LingXiu.Leaders += str;
	str.Format(L"\t\t<Row Type=\"%s\" Kind=\"KIND_LEADER\"/>\r\n", strtype);
	Type += str;
	str.Format(L"\t\t<Row Type=\"%s\" Kind=\"KIND_TRAIT\"/>\r\n", strtype2);
	Type += str;
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Name=\"LOC_%s_NAME\" InheritFrom=\"LEADER_DEFAULT\" SceneLayers=\"4\"/>\r\n", strtype);
	tt += i;
	length -= i;
	LingXiu.Leaders += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	//str.Format(L" Description=\"LOC_%s_DESCRIPTION\"", strtype);
	tt += i;
	length -= i;
	//LingXiu.Leaders += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_LOADING_INFO_%s\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L"\t\t<Row LeaderType=\"%s\" Quote=\"LOC_%s_QUOTE\"/>\r\n", strtype, strtype);
	tt += i;
	length -= i;
	LingXiu.LeaderQuotes += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_QUOTE\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	//����Ӣ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L"\t\t<Row LeaderType=\"%s\" TraitType=\"%s\"/>\r\n", strtype, strtype2);
	//strtype3.Format(L"TRAIT_%s", strtype);
	tt += i;
	length -= i;
	LingXiu.LeaderTraits += str;
	str.Format(L"\t\t<Row TraitType=\"%s\" Name=\"LOC_%s_NAME\" Description=\"LOC_%s_DESCRIPTION\"/>\r\n", strtype2, strtype2, strtype2);
	WenMing.Traits += str;
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype2, strtemp);
	Text += str;
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_DESCRIPTION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype2, strtemp);
	Text += str;
	//��������
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	wm = j;
	//�׶�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	str.Format(L"\t\t<Row CivilizationType=\"%s\" LeaderType=\"%s\" CapitalName=\"LOC_CITY_NAME_%s\"/>\r\n", ::wenming[j + 1].type, strtype, strtype);
	LingXiu.CivilizationLeaders += str;
	str.Format(L"\t\t<Row CivilizationType=\"%s\" CityName=\"LOC_CITY_NAME_%s\"/>\r\n", ::wenming[j + 1].type, strtype);
	WenMing.CityNames += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_CITY_NAME_%s\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	str.Format(L"\t\t<Row CivilizationType=\"%s\" LeaderType=\"%s\" CivilizationName=\"LOC_%s_NAME\" CivilizationIcon=\"ICON_%s\" LeaderName=\"LOC_%s_NAME\" LeaderIcon=\"ICON_LEADER_DEFAULT\"", ::wenming[j + 1].type, strtype, ::wenming[j + 1].type, ::wenming[j + 1].type, strtype);
	Players += str;
	str.Format(L" CivilizationAbilityName=\"LOC_TRAIT_%s_NAME\" CivilizationAbilityDescription=\"LOC_TRAIT_%s_DESCRIPTION\" CivilizationAbilityIcon=\"ICON_%s\" LeaderAbilityName=\"LOC_%s_NAME\" LeaderAbilityDescription=\"LOC_%s_DESCRIPTION\" LeaderAbilityIcon=\"ICON_LEADER_DEFAULT\"/>\r\n", ::wenming[j + 1].type, ::wenming[j + 1].type, ::wenming[j + 1].type, strtype2, strtype2);
	Players += str;
	//�������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str.Format(L"\t\t<Row LeaderType=\"%s\" AgendaType=\"%s\"/>\r\n", strtype, ::yicheng[i + 1].type);
	LingXiu.HistoricalAgendas += str;
	//��ѡ���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row LeaderType=\"%s\" AgendaType=\"%s\"/>\r\n", strtype, ::yicheng[i].type);
		LingXiu.AgendaPreferredLeaders += str;
	}
	//��������
	jishu = 1;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row CivilizationType=\"%s\" LeaderType=\"%s\" Type=\"%s\" Icon=\"ICON_%s\" Name=\"LOC_%s_NAME\" Description=\"LOC_%s_DESCRIPTION\" SortIndex=\"%d\"/>\r\n", ::wenming[j + 1].type, strtype, ::building[i].type, ::building[i].type, ::building[i].type, ::building[i].type, jishu * 10);
		PlayerItems += str;
		jishu++;
	}
	//������λ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row CivilizationType=\"%s\" LeaderType=\"%s\" Type=\"%s\" Icon=\"ICON_%s\" Name=\"LOC_%s_NAME\" Description=\"LOC_%s_DESCRIPTION\" SortIndex=\"%d\"/>\r\n", ::wenming[j + 1].type, strtype, ::unit[i].type, ::unit[i].type, ::unit[i].type, ::unit[i].type, jishu * 10);
		PlayerItems += str;
		jishu++;
	}
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	str.Format(L"\t\t<Row>\r\n\t\t\t<Type>COLOR_PLAYER_%s_PRIMARY</Type>\r\n\t\t\t<Color>%s,", strtype, strtemp);
	LingXiu.Colors += str;
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	str.Format(L"%s,", strtemp);
	LingXiu.Colors += str;
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	str.Format(L"%s,", strtemp);
	LingXiu.Colors += str;
	//��ɫ͸��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	str.Format(L"%s</Color>\r\n\t\t</Row>\r\n", strtemp);
	LingXiu.Colors += str;
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	str.Format(L"\t\t<Row>\r\n\t\t\t<Type>COLOR_PLAYER_%s_SECONDARY</Type>\r\n\t\t\t<Color>%s,", strtype, strtemp);
	LingXiu.Colors += str;
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	str.Format(L"%s,", strtemp);
	LingXiu.Colors += str;
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	str.Format(L"%s,", strtemp);
	LingXiu.Colors += str;
	//��ɫ͸��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	str.Format(L"%s</Color>\r\n\t\t</Row>\r\n", strtemp);
	LingXiu.Colors += str;
	str.Format(L"\t\t<Row Type=\"%s\" Usage=\"Unique\" PrimaryColor=\"COLOR_PLAYER_%s_PRIMARY\" SecondaryColor=\"COLOR_PLAYER_%s_SECONDARY\" TextColor=\"COLOR_PLAYER_WHITE_TEXT\"/>\r\n", strtype, strtype, strtype);
	LingXiu.PlayerColors += str;
	//��ɫ����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row TraitType=\"TRAIT_LEADER_%s\" Name=\"LOC_TRAIT_LEADER_%s_NAME\"/>\r\n", building[i].type, building[i].type);
		WenMing.Traits += str;
		str.Format(L"\t\t<Row LeaderType=\"%s\" TraitType=\"TRAIT_LEADER_%s\"/>\r\n", strtype, building[i].type);
		LingXiu.LeaderTraits += str;
		str.Format(L"\t\t<Row Type=\"TRAIT_LEADER_%s\" Kind=\"KIND_TRAIT\"/>\r\n", building[i].type);
		Type += str;
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += cd;
		length -= cd;
		str.Format(L"\t\t<Replace Tag=\"LOC_TRAIT_LEADER_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", building[i].type, strtemp);
		Text += str;
		str.Format(L"\t\t<Row CivilizationType=\"%s\" LeaderType=\"%s\" Type=\"%s\" Icon=\"ICON_%s\" Name=\"LOC_%s_NAME\" Description=\"LOC_%s_DESCRIPTION\" SortIndex=\"%d\"/>\r\n", ::wenming[wm + 1].type, strtype, ::building[i].type, ::building[i].type, ::building[i].type, ::building[i].type, jishu * 10);
		PlayerItems += str;
		jishu++;
	}
	else
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
	}
	//��ɫ��λ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row TraitType=\"TRAIT_LEADER_%s\" Name=\"LOC_TRAIT_LEADER_%s_NAME\"/>\r\n", unit[i].type, unit[i].type);
		WenMing.Traits += str;
		str.Format(L"\t\t<Row LeaderType=\"%s\" TraitType=\"TRAIT_LEADER_%s\"/>\r\n", strtype, unit[i].type);
		LingXiu.LeaderTraits += str;
		str.Format(L"\t\t<Row Type=\"TRAIT_LEADER_%s\" Kind=\"KIND_TRAIT\"/>\r\n", unit[i].type);
		Type += str;
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += cd;
		length -= cd;
		str.Format(L"\t\t<Replace Tag=\"LOC_TRAIT_LEADER_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", unit[i].type, strtemp);
		Text += str;
		str.Format(L"\t\t<Row CivilizationType=\"%s\" LeaderType=\"%s\" Type=\"%s\" Icon=\"ICON_%s\" Name=\"LOC_%s_NAME\" Description=\"LOC_%s_DESCRIPTION\" SortIndex=\"%d\"/>\r\n", ::wenming[wm + 1].type, strtype, ::unit[i].type, ::unit[i].type, ::unit[i].type, ::unit[i].type, jishu * 10);
		PlayerItems += str;
	}
	else
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
	}
	//����AI
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (i = 0; i < j; i++)
	{
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += cd;
		length -= cd;
		str.Format(L"%s", strtemp.Left(strtemp.Find(L":")));
		switch (_ttoi(str))
		{
		case 0:
			str2 = strtemp.Right(strtemp.GetLength() - strtemp.Find(L":") - 1);
			str.Format(L"%s", str2.Left(str2.Find(L":")));
			k = _ttoi(str);
			str2 = str2.Right(str2.GetLength() - str2.Find(L":") - 1);
			shuzhi.Format(L"%s", str2.Left(str2.Find(L":")));
			str2 = str2.Right(str2.GetLength() - str2.Find(L":") - 1);
			strtemp.Format(L"%s", str2.Left(str2.Find(L":")));
			str.Format(L"\t\t<Row ListType=\"%s\"/>\r\n", strtemp);
			LingXiu.AiListTypes += str;
			str.Format(L"\t\t<Row ListType=\"%s\" LeaderType=\"%s\" System=\"Buildings\"/>\r\n", strtemp, strtype);
			LingXiu.AiLists += str;
			str.Format(L"\t\t<Row ListType=\"%s\" Item=\"%s\"/>\r\n", strtemp, ::building[k + 1].type);
			LingXiu.AiFavoredItems += str;
			break;
		case 1:
			str2 = strtemp.Right(strtemp.GetLength() - strtemp.Find(L":") - 1);
			str.Format(L"%s", str2.Left(str2.Find(L":")));
			k = _ttoi(str);
			str2 = str2.Right(str2.GetLength() - str2.Find(L":") - 1);
			shuzhi.Format(L"%s", str2.Left(str2.Find(L":")));
			str2 = str2.Right(str2.GetLength() - str2.Find(L":") - 1);
			strtemp.Format(L"%s", str2.Left(str2.Find(L":")));
			str.Format(L"\t\t<Row ListType=\"%s\"/>\r\n", strtemp);
			LingXiu.AiListTypes += str;
			str.Format(L"\t\t<Row ListType=\"%s\" LeaderType=\"%s\" System=\"Technologies\"/>\r\n", strtemp, strtype);
			LingXiu.AiLists += str;
			str.Format(L"\t\t<Row ListType=\"%s\" Item=\"%s\"/>\r\n", strtemp, ::tech[k + 1].type);
			LingXiu.AiFavoredItems += str;
			break;
		case 2:
			str2 = strtemp.Right(strtemp.GetLength() - strtemp.Find(L":") - 1);
			str.Format(L"%s", str2.Left(str2.Find(L":")));
			k = _ttoi(str);
			str2 = str2.Right(str2.GetLength() - str2.Find(L":") - 1);
			shuzhi.Format(L"%s", str2.Left(str2.Find(L":")));
			str2 = str2.Right(str2.GetLength() - str2.Find(L":") - 1);
			strtemp.Format(L"%s", str2.Left(str2.Find(L":")));
			str.Format(L"\t\t<Row ListType=\"%s\"/>\r\n", strtemp);
			LingXiu.AiListTypes += str;
			str.Format(L"\t\t<Row ListType=\"%s\" LeaderType=\"%s\" System=\"Civics\"/>\r\n", strtemp, strtype);
			LingXiu.AiLists += str;
			str.Format(L"\t\t<Row ListType=\"%s\" Item=\"%s\"/>\r\n", strtemp, ::civic[k + 1].type);
			LingXiu.AiFavoredItems += str;
			break;
		case 3:
			str2 = strtemp.Right(strtemp.GetLength() - strtemp.Find(L":") - 1);
			str.Format(L"%s", str2.Left(str2.Find(L":")));
			k = _ttoi(str);
			str2 = str2.Right(str2.GetLength() - str2.Find(L":") - 1);
			shuzhi.Format(L"%s", str2.Left(str2.Find(L":")));
			str2 = str2.Right(str2.GetLength() - str2.Find(L":") - 1);
			strtemp.Format(L"%s", str2.Left(str2.Find(L":")));
			str.Format(L"\t\t<Row ListType=\"%s\"/>\r\n", strtemp);
			LingXiu.AiListTypes += str;
			str.Format(L"\t\t<Row ListType=\"%s\" LeaderType=\"%s\" System=\"Yields\"/>\r\n", strtemp, strtype);
			LingXiu.AiLists += str;
			str.Format(L"\t\t<Row ListType=\"%s\" Item=\"%s\" Value=\"%s\"/>\r\n", strtemp, ::yie[k], shuzhi);
			LingXiu.AiFavoredItems += str;
			break;
		case 4:
			str2 = strtemp.Right(strtemp.GetLength() - strtemp.Find(L":") - 1);
			str.Format(L"%s", str2.Left(str2.Find(L":")));
			k = _ttoi(str);
			str2 = str2.Right(str2.GetLength() - str2.Find(L":") - 1);
			shuzhi.Format(L"%s", str2.Left(str2.Find(L":")));
			str2 = str2.Right(str2.GetLength() - str2.Find(L":") - 1);
			strtemp.Format(L"%s", str2.Left(str2.Find(L":")));
			str.Format(L"\t\t<Row ListType=\"%s\"/>\r\n", strtemp);
			LingXiu.AiListTypes += str;
			str.Format(L"\t\t<Row ListType=\"%s\" LeaderType=\"%s\" System=\"Units\"/>\r\n", strtemp, strtype);
			LingXiu.AiLists += str;
			str.Format(L"\t\t<Row ListType=\"%s\" Item=\"%s\" Value=\"%s\"/>\r\n", strtemp, ::unit[k + 1].type, shuzhi);
			LingXiu.AiFavoredItems += str;
			break;
		}
	}
	//����
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (i = 0; i < j; i++)
	{
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L"%s", strtemp.Left(strtemp.Find(L":")));
		str.Format(L"\t\t<Row>\r\n\t\t\t<TraitType>%s</TraitType>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t</Row>\r\n", strtype2, zongtexing[_ttoi(str)].type);
		tt += cd;
		length -= cd;
		TraitModifiers += str;
	}
}

void project::keji(DLG_KeJi * dhk)
{
	int i, j;
	char temp[4096];
	CString str;
	int length;
	int max;
	char * tt;
	
	if (id == number)//��ǰָ��ָ�����һ������
	{
		if (p == NULL)
		{
			root = p = new struct table;
		}
		else
		{
			p->hou = new struct table;
			p->hou->qian = p;
			p = p->hou;
		}
		id = number++;
	}
	else
	{
		if (p->type != 4)
		{
			MessageBox(NULL, L"������һ����ťֱ���ð�ťΪ��ɫ�ٳ��Ըò�����", L"�α����", MB_OK);
			return;
		}
	}
	tt = p->data;
	p->length = 0;
	p->type = 4;
	p->id = id;
	max = MAXLENGTH;

	//����
	i = dhk->m_xuanze;
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//Ӣ������
	dhk->m_type.GetWindowTextW(str);
	if (dhk->m_xuanze)
	{
		if (civicnum >= 1000)
		{
			MessageBox(NULL, L"����������������ɵ��������������½����̻��ֶ���ӣ�", L"��������", MB_OK);
			return;
		}
		civicnum++;
		::civic[civicnum].type = L"CIVIC_" + str;
		::civic[civicnum].id = civicnum;
	}
	else
	{
		if (technum >= 1000)
		{
			MessageBox(NULL, L"����������������ɵĿƼ����������½����̻��ֶ���ӣ�", L"��������", MB_OK);
			return;
		}
		technum++;
		::tech[technum].type = L"TECH_" + str;
		::tech[technum].id = technum;
	}
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_name.GetWindowTextW(str);
	if (dhk->m_xuanze)
	{
		::civic[civicnum].name = str;
	}
	else
	{
		::tech[technum].name = str;
	}
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_d.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɻ���
	dhk->m_cost.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	i = dhk->m_advi.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//����ʱ��
	i = dhk->m_era.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��λ��
	dhk->m_shu.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������1
	dhk->m_yinshu.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������2
	dhk->m_yinshu2.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;

	//��������
	i = dhk->m_boost.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��λ����
	i = dhk->m_unit.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//������ֵ
	dhk->m_num.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//������ʩ
	i = dhk->m_gailiang.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��������
	i = dhk->m_jianzhu.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��Դ����
	i = dhk->m_ziyuan.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//�о��Ƽ�
	i = dhk->m_keji.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//�о�����
	i = dhk->m_shizheng.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��������
	i = dhk->m_dis.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��������
	dhk->m_miaoshu.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//�������
	dhk->m_miaoshu2.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//ǰ�ÿƼ�����
	j = dhk->m_blist.GetCount();
	*((int *)tt) = j;
	tt += 4;
	max -= 4;
	for (i = 0; i < j; i++)
	{
		dhk->m_blist.GetText(i, str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//����
	j = dhk->m_list.GetCount();
	*((int *)tt) = j;
	tt += 4;
	max -= 4;
	for (i = 0; i < j; i++)
	{
		dhk->m_list.GetText(i, str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//�ظ��о�
	if (dhk->m_chongfu.GetCheck())
	{
		i = 1;
	}
	else
	{
		i = 0;
	}
	*((int *)tt) = i;
	tt += 4;
	max -= 4;

	p->length = MAXLENGTH - max;
	ck->m_qian.EnableWindow(true);
	ck->m_delete.EnableWindow(true);
	ck->m_output.EnableWindow(true);
}

void project::fankeji(DLG_KeJi * dhk)
{
	int length, i, j, k;
	char * tt;
	CString str;

	length = p->length;
	tt = p->data;
	dhk->csh();

	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_zhonglei.SetCheck(0);
		((CButton *)(dhk->GetDlgItem(IDC_RADIO2)))->SetCheck(1);
		dhk->m_xuanze = 1;
	}
	else
	{
		dhk->m_zhonglei.SetCheck(1);
		((CButton *)(dhk->GetDlgItem(IDC_RADIO2)))->SetCheck(0);
		dhk->m_xuanze = 0;
	}
	//Ӣ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_type.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_name.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_d.SetWindowTextW(str);
	//��ɻ���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_cost.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_advi.SetCurSel(i);
	//����ʱ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_era.SetCurSel(i);
	//��λ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_shu.SetWindowTextW(str);
	//��������1
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_yinshu.SetWindowTextW(str);
	//��������2
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_yinshu2.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_boost.SetCurSel(i);
	//��λ����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_unit.SetCurSel(i);
	//������ֵ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_num.SetWindowTextW(str);
	//������ʩ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_gailiang.SetCurSel(i);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_jianzhu.SetCurSel(i);
	//��Դ����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_ziyuan.SetCurSel(i);
	//�о��Ƽ�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_keji.SetCurSel(i);
	//�о�����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_shizheng.SetCurSel(i);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_dis.SetCurSel(i);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_miaoshu.SetWindowTextW(str);
	//�������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_miaoshu2.SetWindowTextW(str);
	//ǰ�ÿƼ�����
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (k = 0; k < j; k++)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_blist.InsertString(-1, str);
	}
	//����
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (k = 0; k < j; k++)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_list.InsertString(-1, str);
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_chongfu.SetCheck(1);
	}
	else
	{
		dhk->m_chongfu.SetCheck(0);
	}
}

void project::shengkeji(char * tt, int length)
{
	CString str;
	CString strtemp;
	CString strtype;
	CString kjsz;
	CString kjsz2;
	CString kjsz3;
	int i, j, k, cd;

	k = *((int *)tt);
	tt += 4;
	length -= 4;
	//Ӣ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	kjsz.Format(L"%s", !k ? L"Technology" : L"Civic");
	kjsz2.Format(L"%s", !k ? L"Tech" : L"Civic");
	kjsz3.Format(L"%s", !k ? L"TECH" : L"CIVIC");
	str.Format(L"\t\t<Row %sType=\"%s_%s\"", kjsz, kjsz3, strtemp);
	strtype.Format(L"%s_%s", kjsz3, strtemp);
	tt += i;
	length -= i;
	k ? KeJiShiZheng.Civics += str : KeJiShiZheng.Technologies += str;
	str.Format(L"\t\t<Row Type=\"%s\" Kind=\"KIND_%s\"/>\r\n", strtype, kjsz3);
	Type += str;
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Name=\"LOC_%s_NAME\"", strtype);
	tt += i;
	length -= i;
	k ? KeJiShiZheng.Civics += str : KeJiShiZheng.Technologies += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Description=\"LOC_%s_DESCRIPTION\"", strtype);
	tt += i;
	length -= i;
	k ? KeJiShiZheng.Civics += str : KeJiShiZheng.Technologies += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_DESCRIPTION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	//��ɻ���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Cost=\"%s\"", strtemp);
	tt += i;
	length -= i;
	k ? KeJiShiZheng.Civics += str : KeJiShiZheng.Technologies += str;
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str.Format(L" AdvisorType=\"%s\"", advi[i]);
	k ? KeJiShiZheng.Civics += str : KeJiShiZheng.Technologies += str;
	//����ʱ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str.Format(L" EraType=\"%s\"", era[i]);
	k ? KeJiShiZheng.Civics += str : KeJiShiZheng.Technologies += str;
	//��λ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" UITreeRow=\"%s\"", strtemp);
	tt += i;
	length -= i;
	k ? KeJiShiZheng.Civics += str : KeJiShiZheng.Technologies += str;
	//��������1
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L"\t\t<Row %sType=\"%s\" Quote=\"LOC_%s_QUOTE_1\"/>\r\n", kjsz, strtype, strtype);
	tt += i;
	length -= i;
	k ? KeJiShiZheng.CivicQuotes += str : KeJiShiZheng.TechnologyQuotes += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_QUOTE_1\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	//��������2
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L"\t\t<Row %sType=\"%s\" Quote=\"LOC_%s_QUOTE_2\"/>\r\n", kjsz, strtype, strtype);
	tt += i;
	length -= i;
	k ? KeJiShiZheng.CivicQuotes += str : KeJiShiZheng.TechnologyQuotes += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_QUOTE_2\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	//��������
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	str.Format(L"\t\t<Row %sType=\"%s\" Boost=\"50\" TriggerDescription=\"LOC_BOOST_TRIGGER_%s\" TriggerLongDescription=\"LOC_BOOST_TRIGGER_LONGDESC_%s\" BoostClass=\"%s\"", kjsz, strtype, strtype, strtype, tisheng[j + 1].type);
	KeJiShiZheng.Boosts += str;
	//��λ����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (tc[j][0])
	{
		str.Format(L" Unit1Type=\"%s\"", unit[i + 1].type);
		KeJiShiZheng.Boosts += str;
	}
	//������ֵ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	if (tc[j][1])
	{
		str.Format(L" NumItems=\"%s\"", strtemp);
		KeJiShiZheng.Boosts += str;
	}
	//������ʩ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (tc[j][2])
	{
		str.Format(L" ImprovementType=\"%s\"", ip[i]);
		KeJiShiZheng.Boosts += str;
		if ((tc[j][2] >= 2) && (i >= 1) && (i <= 11) && (i != 9))
		{
			KeJiShiZheng.Boosts += L" RequiresResource=\"true\"";
		}
		else
		{
			KeJiShiZheng.Boosts += L" RequiresResource=\"false\"";
		}
	}
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (tc[j][3])
	{
		str.Format(L" BuildingType=\"%s\"", building[i + 1].type);
		KeJiShiZheng.Boosts += str;
	}
	//��Դ����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (tc[j][4])
	{
		str.Format(L" ResourceType=\"%s\"", ziyuan[i + 1].type);
		KeJiShiZheng.Boosts += str;
	}
	//�о��Ƽ�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (tc[j][5])
	{
		str.Format(L" BoostingTechType=\"%s\"", tech[i + 1].type);
		KeJiShiZheng.Boosts += str;
	}
	//�о�����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (tc[j][6])
	{
		str.Format(L" BoostingCivicType=\"%s\"", civic[i + 1].type);
		KeJiShiZheng.Boosts += str;
	}
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (tc[j][7])
	{
		str.Format(L" DistrictType=\"%s\"", dis[i]);
		KeJiShiZheng.Boosts += str;
	}
	KeJiShiZheng.Boosts += L"/>\r\n";
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	str.Format(L"\t\t<Replace Tag=\"LOC_BOOST_TRIGGER_%s\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	//�������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	str.Format(L"\t\t<Replace Tag=\"LOC_BOOST_TRIGGER_LONGDESC_%s\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	//ǰ�ÿƼ�����
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (i = 0; i < j; i++)
	{
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L"%s", strtemp.Left(strtemp.Find(L":")));
		str.Format(L"\t\t<Row %s=\"%s\" Prereq%s=\"%s\"/>\r\n", kjsz, strtype, kjsz2, k ? civic[_ttoi(str)].type : tech[_ttoi(str)].type);
		tt += cd;
		length -= cd;
		k ? KeJiShiZheng.CivicPrereqs += str : KeJiShiZheng.TechnologyPrereqs += str;
	}
	//����
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (i = 0; i < j; i++)
	{
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L"%s", strtemp.Left(strtemp.Find(L":")));
		str.Format(L"\t\t<Row>\r\n\t\t\t<%sType>%s</%sType>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t</Row>\r\n", kjsz, strtype, kjsz, zongtexing[_ttoi(str)].type);
		tt += cd;
		length -= cd;
		k ? KeJiShiZheng.CivicModifiers += str : KeJiShiZheng.TechnologyModifiers += str;
	}
	//�ظ��о�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		k ? KeJiShiZheng.Civics += L" Repeatable=\"true\"" : KeJiShiZheng.Technologies += L" Repeatable=\"true\"";
	}
	k ? KeJiShiZheng.Civics += L"/>\r\n" : KeJiShiZheng.Technologies += L"/>\r\n";
}

void project::danwei(DLG_DanWei * dhk)
{
	int i, j;
	char temp[4096];
	CString str;
	int length;
	int max;
	char * tt;

	if (id == number)//��ǰָ��ָ�����һ������
	{
		if (p == NULL)
		{
			root = p = new struct table;
		}
		else
		{
			p->hou = new struct table;
			p->hou->qian = p;
			p = p->hou;
		}
		id = number++;
	}
	else
	{
		if (p->type != 5)
		{
			MessageBox(NULL, L"������һ����ťֱ���ð�ťΪ��ɫ�ٳ��Ըò�����", L"�α����", MB_OK);
			return;
		}
	}
	tt = p->data;
	p->length = 0;
	p->type = 5;
	p->id = id;
	max = MAXLENGTH;

	//Ӣ������
	dhk->m_type.GetWindowTextW(str);
	if (unitnum >= 1000)
	{
		MessageBox(NULL, L"����������������ɵĵ�λ���������½����̻��ֶ���ӣ�", L"��������", MB_OK);
		return;
	}
	unitnum++;
	::unit[unitnum].type = L"UNIT_" + str;
	::unit[unitnum].id = unitnum;
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_name.GetWindowTextW(str);
	::unit[unitnum].name = str;
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_d.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//�����ƶ�
	dhk->m_move.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɻ���
	dhk->m_cost.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//������Ұ
	dhk->m_shiye.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//ά������
	dhk->m_feiyong.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	i = dhk->m_advi.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��λ����
	i = dhk->m_leixing.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//�ɹ�����
	i = dhk->m_pur.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//ս����Դ
	i = dhk->m_ziyuan.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��������
	i = dhk->m_jinsheng.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//ǰ�ÿƼ�
	i = dhk->m_tech.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//ǰ������
	i = dhk->m_civic.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//ǰ���˿�
	i = dhk->m_renkou.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//�滻��λ
	i = dhk->m_tihuan.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//������λ
	i = dhk->m_shengji.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//ǰ�ý���
	i = dhk->m_build.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//ǰ�ó���
	i = dhk->m_dis.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//ս����
	if (dhk->m_xzhanli.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		dhk->m_zhanli.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//Զ��ս����
	if (dhk->m_xyuanli.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		dhk->m_yuanli.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//���
	if (dhk->m_xshecheng.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		dhk->m_shecheng.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//��ը������
	if (dhk->m_xhongli.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		dhk->m_hongli.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//����ս����
	if (dhk->m_xfangkong.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		dhk->m_fangkong.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//�����˿�
	if (dhk->m_xhaoren.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		dhk->m_haoren.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//�������
	if (dhk->m_xjianci.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		dhk->m_jianci.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//�ڽ̴�������
	if (dhk->m_xzongci.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		dhk->m_zongci.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//�ڽ�ս����
	if (dhk->m_xzongli.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		dhk->m_zongli.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//��������
	if (dhk->m_schengshi.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//��������
	if (dhk->m_sfuyin.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//������Ѷ
	if (dhk->m_sshenxun.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//�ھ��ż�
	if (dhk->m_syiji.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//�ܹ�����
	if (dhk->m_sbuhuo.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//�ܹ�������
	if (dhk->m_sbeibu.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//��������
	if (dhk->m_smanzu.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//�ɱ��ۼ�
	if (dhk->m_sleijia.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//�������
	if (dhk->m_sjinsheng.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//����
	if (dhk->m_ayimin.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//����
	if (dhk->m_agongren.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//����
	if (dhk->m_ashangren.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//ƽ��
	if (dhk->m_apingmin.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//̽��
	if (dhk->m_atansuo.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//��ս
	if (dhk->m_ajinzhan.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//Զ��
	if (dhk->m_ayuancheng.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//����
	if (dhk->m_agongcheng.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//���
	if (dhk->m_aqibing.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//֧Ԯ
	if (dhk->m_azhiyuan.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//����
	if (dhk->m_ahewu.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//ΰ��
	if (dhk->m_aweiren.GetCheck())
	{
		*((int *)tt) = 1;
	}
	else
	{
		*((int *)tt) = 0;
	}
	tt += 4;
	max -= 4;
	//����
	j = dhk->m_listtx.GetCount();
	*((int *)tt) = j;
	tt += 4;
	max -= 4;
	for (i = 0; i < j; i++)
	{
		dhk->m_listtx.GetText(i, str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//����˵��
	dhk->m_shuoming.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ǩ
	j = dhk->m_listtag.GetCount();
	*((int *)tt) = j;
	tt += 4;
	max -= 4;
	for (i = 0; i < j; i++)
	{
		dhk->m_listtag.GetText(i, str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}

	p->length = MAXLENGTH - max;
	ck->m_qian.EnableWindow(true);
	ck->m_delete.EnableWindow(true);
	ck->m_output.EnableWindow(true);
}

void project::fandanwei(DLG_DanWei * dhk)
{
	int length, i, j, k;
	char * tt;
	CString str;

	length = p->length;
	tt = p->data;
	dhk->csh();
	//Ӣ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_type.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_name.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_d.SetWindowTextW(str);
	//�����ƶ�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_move.SetWindowTextW(str);
	//��ɻ���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_cost.SetWindowTextW(str);
	//������Ұ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_shiye.SetWindowTextW(str);
	//ά������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_feiyong.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_advi.SetCurSel(i);
	//��λ����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_leixing.SetCurSel(i);
	//�ɹ�����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_pur.SetCurSel(i);
	//ս����Դ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_ziyuan.SetCurSel(i);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_jinsheng.SetCurSel(i);
	//ǰ�ÿƼ�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_tech.SetCurSel(i);
	//ǰ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_civic.SetCurSel(i);
	//ǰ���˿�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_renkou.SetCurSel(i);
	//�滻��λ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_tihuan.SetCurSel(i);
	//������λ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_shengji.SetCurSel(i);
	//ǰ�ý���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_build.SetCurSel(i);
	//ǰ�ó���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_dis.SetCurSel(i);
	//ս����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_xzhanli.SetCheck(1);
		dhk->m_zhanli.EnableWindow(true);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_zhanli.SetWindowTextW(str);
	}
	else
	{
		dhk->m_xzhanli.SetCheck(0);
		dhk->m_zhanli.EnableWindow(false);
	}
	//Զ��ս����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_xyuanli.SetCheck(1);
		dhk->m_yuanli.EnableWindow(true);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_yuanli.SetWindowTextW(str);
	}
	else
	{
		dhk->m_xyuanli.SetCheck(0);
		dhk->m_yuanli.EnableWindow(false);
	}
	//���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_xshecheng.SetCheck(1);
		dhk->m_shecheng.EnableWindow(true);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_shecheng.SetWindowTextW(str);
	}
	else
	{
		dhk->m_xshecheng.SetCheck(0);
		dhk->m_shecheng.EnableWindow(false);
	}
	//��ը������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_xhongli.SetCheck(1);
		dhk->m_hongli.EnableWindow(true);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_hongli.SetWindowTextW(str);
	}
	else
	{
		dhk->m_xhongli.SetCheck(0);
		dhk->m_hongli.EnableWindow(false);
	}
	//����ս����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_xfangkong.SetCheck(1);
		dhk->m_fangkong.EnableWindow(true);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_fangkong.SetWindowTextW(str);
	}
	else
	{
		dhk->m_xfangkong.SetCheck(0);
		dhk->m_fangkong.EnableWindow(false);
	}
	//�����˿�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_xhaoren.SetCheck(1);
		dhk->m_haoren.EnableWindow(true);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_haoren.SetWindowTextW(str);
	}
	else
	{
		dhk->m_xhaoren.SetCheck(0);
		dhk->m_haoren.EnableWindow(false);
	}
	//�������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_xjianci.SetCheck(1);
		dhk->m_jianci.EnableWindow(true);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_jianci.SetWindowTextW(str);
	}
	else
	{
		dhk->m_xjianci.SetCheck(0);
		dhk->m_jianci.EnableWindow(false);
	}
	//�ڽ̴���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_xzongci.SetCheck(1);
		dhk->m_zongci.EnableWindow(true);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_zongci.SetWindowTextW(str);
	}
	else
	{
		dhk->m_xzongci.SetCheck(0);
		dhk->m_zongci.EnableWindow(false);
	}
	//�ڽ�ս����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_xzongli.SetCheck(1);
		dhk->m_zongli.EnableWindow(true);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_zongli.SetWindowTextW(str);
	}
	else
	{
		dhk->m_xzongli.SetCheck(0);
		dhk->m_zongli.EnableWindow(false);
	}
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_schengshi.SetCheck(1);
	}
	else
	{
		dhk->m_schengshi.SetCheck(0);
	}
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_sfuyin.SetCheck(1);
	}
	else
	{
		dhk->m_sfuyin.SetCheck(0);
	}
	//������Ѷ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_sshenxun.SetCheck(1);
	}
	else
	{
		dhk->m_sshenxun.SetCheck(0);
	}
	//�ھ��ż�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_syiji.SetCheck(1);
	}
	else
	{
		dhk->m_syiji.SetCheck(0);
	}
	//�ܹ�����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_sbuhuo.SetCheck(1);
	}
	else
	{
		dhk->m_sbuhuo.SetCheck(0);
	}
	//�ܹ�������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_sbeibu.SetCheck(1);
	}
	else
	{
		dhk->m_sbeibu.SetCheck(0);
	}
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_smanzu.SetCheck(1);
	}
	else
	{
		dhk->m_smanzu.SetCheck(0);
	}
	//�ɱ��ۼ�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_sleijia.SetCheck(1);
	}
	else
	{
		dhk->m_sleijia.SetCheck(0);
	}
	//�������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_sjinsheng.SetCheck(1);
	}
	else
	{
		dhk->m_sjinsheng.SetCheck(0);
	}
	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_ayimin.SetCheck(1);
	}
	else
	{
		dhk->m_ayimin.SetCheck(0);
	}
	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_agongren.SetCheck(1);
	}
	else
	{
		dhk->m_agongren.SetCheck(0);
	}
	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_ashangren.SetCheck(1);
	}
	else
	{
		dhk->m_ashangren.SetCheck(0);
	}
	//ƽ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_apingmin.SetCheck(1);
	}
	else
	{
		dhk->m_apingmin.SetCheck(0);
	}
	//̽��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_atansuo.SetCheck(1);
	}
	else
	{
		dhk->m_atansuo.SetCheck(0);
	}
	//��ս
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_ajinzhan.SetCheck(1);
	}
	else
	{
		dhk->m_ajinzhan.SetCheck(0);
	}
	//Զ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_ayuancheng.SetCheck(1);
	}
	else
	{
		dhk->m_ayuancheng.SetCheck(0);
	}
	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_agongcheng.SetCheck(1);
	}
	else
	{
		dhk->m_agongcheng.SetCheck(0);
	}
	//���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_aqibing.SetCheck(1);
	}
	else
	{
		dhk->m_aqibing.SetCheck(0);
	}
	//֧Ԯ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_azhiyuan.SetCheck(1);
	}
	else
	{
		dhk->m_azhiyuan.SetCheck(0);
	}
	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_ahewu.SetCheck(1);
	}
	else
	{
		dhk->m_ahewu.SetCheck(0);
	}
	//ΰ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_aweiren.SetCheck(1);
	}
	else
	{
		dhk->m_aweiren.SetCheck(0);
	}
	//����
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (k = 0; k < j; k++)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_listtx.InsertString(-1, str);
	}
	//����˵��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_shuoming.SetWindowTextW(str);
	//��ǩ
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (k = 0; k < j; k++)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_listtag.InsertString(-1, str);
	}
}

void project::shengdanwei(char * tt, int length)
{
	CString str;
	CString strtemp;
	CString strtype;
	CString strtype2;
	CString strtype3;
	int i, j, cd;

	//Ӣ������
	DanWei.Units += L"\t\t<Row";
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" UnitType=\"UNIT_%s\"", strtemp);
	strtype.Format(L"UNIT_%s", strtemp);
	strtype2.Format(L"ABILITY_%s", strtemp);
	strtype3.Format(L"CLASS_%s", strtemp);
	tt += i;
	length -= i;
	DanWei.Units += str;
	str.Format(L"\t\t<Row Type=\"%s\" Kind=\"KIND_UNIT\"/>\r\n", strtype);
	Type += str;
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Name=\"LOC_%s_NAME\"", strtype);
	tt += i;
	length -= i;
	DanWei.Units += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Description=\"LOC_%s_DESCRIPTION\"", strtype);
	tt += i;
	length -= i;
	DanWei.Units += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_DESCRIPTION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	//�����ƶ�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" BaseMoves=\"%s\"", strtemp);
	tt += i;
	length -= i;
	DanWei.Units += str;
	//��ɻ���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Cost=\"%s\"", strtemp);
	tt += i;
	length -= i;
	DanWei.Units += str;
	//������Ұ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" BaseSightRange=\"%s\"", strtemp);
	tt += i;
	length -= i;
	DanWei.Units += str;
	//ά������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Maintenance=\"%s\"", strtemp);
	tt += i;
	length -= i;
	DanWei.Units += str;
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str.Format(L" AdvisorType=\"%s\"", advi[i]);
	DanWei.Units += str;
	//��λ����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	switch (i)
	{
	case 0:
	default:
		str.Format(L" Domain=\"DOMAIN_LAND\" FormationClass=\"FORMATION_CLASS_CIVILIAN\"");
		break;
	case 1:
		str.Format(L" Domain=\"DOMAIN_LAND\" FormationClass=\"FORMATION_CLASS_LAND_COMBAT\"");
		break;
	case 2:
		str.Format(L" Domain=\"DOMAIN_SEA\" FormationClass=\"FORMATION_CLASS_NAVAL\" PseudoYieldType=\"PSEUDOYIELD_UNIT_NAVAL_COMBAT\"");
		break;
	case 3:
		str.Format(L" Domain=\"DOMAIN_SEA\" FormationClass=\"PROMOTION_CLASS_NAVAL\" PseudoYieldType=\"PSEUDOYIELD_UNIT_NAVAL_COMBAT\" AirSlots=\"2\"");
		break;
	case 4:
		str.Format(L" Domain=\"DOMAIN_AIR\" FormationClass=\"FORMATION_CLASS_AIR\" PseudoYieldType=\"PSEUDOYIELD_UNIT_AIR_COMBAT\" IgnoreMoves=\"true\" CanTargetAir=\"TRUE\" Stackable=\"TRUE\"");
		break;
	case 5:
		str.Format(L" Domain=\"DOMAIN_AIR\" FormationClass=\"FORMATION_CLASS_AIR\" PseudoYieldType=\"PSEUDOYIELD_UNIT_AIR_COMBAT\" IgnoreMoves=\"true\" CanTargetAir=\"TRUE\" Stackable=\"TRUE\"");
		break;
	case 6:
		str.Format(L" Domain=\"DOMAIN_LAND\" FormationClass=\"FORMATION_CLASS_SUPPORT\"");
		break;
	case 7:
		str.Format(L" Domain=\"DOMAIN_AIR\" FormationClass=\"FORMATION_CLASS_SUPPORT\" IgnoreMoves=\"true\"");
		break;
	}
	DanWei.Units += str;
	//�ɹ�����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L" PurchaseYield=\"%s\"", pur[i - 1]);
		DanWei.Units += str;
	}
	//ս����Դ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L" StrategicResource=\"%s\"", ziyuan[i].type);
		DanWei.Units += str;
	}
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L" PromotionClass=\"%s\"", ut[i - 1]);
		DanWei.Units += str;
	}
	//ǰ�ÿƼ�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L" PrereqTech=\"%s\"", tech[i].type);
		DanWei.Units += str;
	}
	//ǰ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L" PrereqCivic=\"%s\"", civic[i].type);
		DanWei.Units += str;
	}
	//ǰ���˿�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L" PrereqPopulation=\"%d\"", i);
		DanWei.Units += str;
	}
	//�滻��λ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row CivUniqueUnitType=\"%s\" ReplacesUnitType=\"%s\"/>\r\n", strtype, unit[i].type);
		DanWei.UnitReplaces += str;
	}
	//������λ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row Unit=\"%s\" UpgradeUnit=\"%s\"/>\r\n", strtype, unit[i].type);
		DanWei.UnitUpgrades += str;
	}
	//ǰ�ý���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row Unit=\"%s\" PrereqBuilding=\"%s\"/>\r\n", strtype, building[i].type);
		DanWei.Unit_BuildingPrereqs += str;
	}
	//ǰ�ó���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L" PrereqDistrict=\"%s\"", dis[i]);
		DanWei.Units += str;
	}
	//ս����
	j = 0;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" Combat=\"%s\"", strtemp);
		tt += i;
		length -= i;
		DanWei.Units += str;
		j = 1;
	}
	//Զ��ս����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" RangedCombat=\"%s\"", strtemp);
		tt += i;
		length -= i;
		DanWei.Units += str;
	}
	//���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" Range=\"%s\"", strtemp);
		tt += i;
		length -= i;
		DanWei.Units += str;
		j = 0;
	}
	if (j)
	{
		str.Format(L" ZoneOfControl=\"true\"");
	}
	else
	{
		str.Format(L" ZoneOfControl=\"false\"");
	}
	DanWei.Units += str;
	//��ը������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" Bombard=\"%s\"", strtemp);
		tt += i;
		length -= i;
		DanWei.Units += str;
	}
	//����ս����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" AntiAirCombat=\"%s\"", strtemp);
		tt += i;
		length -= i;
		DanWei.Units += str;
	}
	//�����˿�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" PopulationCost=\"%s\"", strtemp);
		tt += i;
		length -= i;
		DanWei.Units += str;
	}
	//�������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" BuildCharges=\"%s\"", strtemp);
		tt += i;
		length -= i;
		DanWei.Units += str;
	}
	//�ڽ̴�������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" SpreadCharges=\"%s\"", strtemp);
		tt += i;
		length -= i;
		DanWei.Units += str;
	}
	//�ڽ�ս����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" ReligiousStrength=\"%s\"", strtemp);
		tt += i;
		length -= i;
		DanWei.Units += str;
	}
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L" FoundCity=\"true\"");
		DanWei.Units += str;
	}
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L" EvangelizeBelief=\"true\"");
		DanWei.Units += str;
	}
	//������Ѷ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L" LaunchInquisition=\"true\"");
		DanWei.Units += str;
	}
	//�ھ��ż�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L" ExtractsArtifacts=\"true\"");
		DanWei.Units += str;
	}
	//�ܹ�����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (!i)
	{
		str.Format(L" CanCapture=\"false\"");
		DanWei.Units += str;
	}
	//�ܹ�������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row CapturedUnitType=\"%s\" BecomesUnitType=\"%s\"/>\r\n", strtype, strtype);
		DanWei.UnitCaptures += str;
	}
	//�������壨ȡ����
	j = 0;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		j = 1;
	}
	//�ɱ��ۼ�
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		if (j)
		{
			str.Format(L" CostProgressionModel=\"COST_PROGRESSION_PREVIOUS_COPIES\" CostProgressionParam1=\"20\"");
		}
		else
		{
			str.Format(L" CostProgressionModel=\"COST_PROGRESSION_PREVIOUS_COPIES\" CostProgressionParam1=\"4\"");
		}
		DanWei.Units += str;
	}
	//�������������ֻ�ܲɹ���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L" MustPurchase=\"true\"");
		DanWei.Units += str;
	}
	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row UnitType=\"%s\" AiType=\"UNITAI_SETTLE\"/>\r\n",strtype);
		DanWei.UnitAiInfos += str;
	}
	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row UnitType=\"%s\" AiType=\"UNITAI_BUILD\"/>\r\n", strtype);
		DanWei.UnitAiInfos += str;
	}
	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row UnitType=\"%s\" AiType=\"UNITTYPE_TRADE\"/>\r\n", strtype);
		DanWei.UnitAiInfos += str;
	}
	//ƽ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row UnitType=\"%s\" AiType=\"UNITTYPE_CIVILIAN\"/>\r\n", strtype);
		DanWei.UnitAiInfos += str;
	}
	//̽��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row UnitType=\"%s\" AiType=\"UNITAI_EXPLORE\"/>\r\n", strtype);
		DanWei.UnitAiInfos += str;
	}
	//��ս
	j = 0;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row UnitType=\"%s\" AiType=\"UNITTYPE_MELEE\"/>\r\n", strtype);
		DanWei.UnitAiInfos += str;
		j = 1;
	}
	//Զ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row UnitType=\"%s\" AiType=\"UNITTYPE_RANGED\"/>\r\n", strtype);
		DanWei.UnitAiInfos += str;
		j = 1;
	}
	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row UnitType=\"%s\" AiType=\"UNITTYPE_SIEGE\"/>\r\n", strtype);
		DanWei.UnitAiInfos += str;
		j = 1;
	}
	//���
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row UnitType=\"%s\" AiType=\"UNITTYPE_CAVALRY\"/>\r\n", strtype);
		DanWei.UnitAiInfos += str;
		j = 1;
	}
	//֧Ԯ
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row UnitType=\"%s\" AiType=\"UNITTYPE_SIEGE_SUPPORT\"/>\r\n", strtype);
		DanWei.UnitAiInfos += str;
	}
	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row UnitType=\"%s\" AiType=\"UNITTYPE_NUCLEAR\"/>\r\n", strtype);
		DanWei.UnitAiInfos += str;
		str.Format(L" WMDCapable=\"true\"");
		DanWei.Units += str;
	}
	//ΰ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		str.Format(L"\t\t<Row UnitType=\"%s\" AiType=\"UNITTYPE_CIVILIAN_LEADER\"/>\r\n", strtype);
		DanWei.UnitAiInfos += str;
	}
	if (j)
	{
		str.Format(L"\t\t<Row UnitType=\"%s\" AiType=\"UNITAI_COMBAT\"/>\r\n", strtype);
		DanWei.UnitAiInfos += str;
	}
	//��ɫ����
	if (jlroot)
	{
		jlp = jlroot;
		while (jlp)
		{
			if ((jlp->leixing == 1) || (jlp->leixing == 3))
			{
				if (strtype.Compare(jlp->yuan))
				{
					jlp = jlp->next;
				}
				else
				{
					str.Format(L" TraitType=\"%s\"", jlp->str);
					DanWei.Units += str;
					break;
				}
			}
			else
			{
				jlp = jlp->next;
			}
		}
	}
	DanWei.Units += L"/>\r\n";
	//����
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	if (j)
	{
		str.Format(L"\t\t<Row Type=\"%s\" Kind=\"KIND_ABILITY\"/>\r\n", strtype2);
		Type += str;
		str.Format(L"\t\t<Row Tag=\"%s\" Vocabulary=\"ABILITY_CLASS\"/>\r\n", strtype3);
		DanWei.Tags += str;
		str.Format(L"\t\t<Row Type=\"%s\" Tag=\"%s\"/>\r\n", strtype2, strtype3);
		DanWei.TypeTags += str;
		str.Format(L"\t\t<Row Type=\"%s\" Tag=\"%s\"/>\r\n", strtype, strtype3);
		DanWei.TypeTags += str;
	}
	for (i = 0; i < j; i++)
	{
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L"%s", strtemp.Left(strtemp.Find(L":")));
		str.Format(L"\t\t<Row>\r\n\t\t\t<UnitAbilityType>%s</UnitAbilityType>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t</Row>\r\n", strtype2, zongtexing[_ttoi(str)].type);
		tt += cd;
		length -= cd;
		DanWei.UnitAbilityModifiers += str;
	}
	//����˵��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L"\t\t<Row UnitAbilityType=\"%s\" Name=\"LOC_%s_NAME\" Description=\"LOC_%s_DESCRIPTION\"/>\r\n", strtype2, strtype2, strtype2);
	tt += i;
	length -= i;
	DanWei.UnitAbilities += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype2, strtemp.Left(strtemp.Find(L":")));
	Text += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_DESCRIPTION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype2, strtemp.Right(strtemp.GetLength() - strtemp.Find(L":") - 1));
	Text += str;
	//��ǩ
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (i = 0; i < j; i++)
	{
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L"%s", strtemp.Left(strtemp.Find(L":")));
		str.Format(L"\t\t<Row Type=\"%s\" Tag=\"%s\"/>\r\n", strtype, tag[_ttoi(str)]);
		tt += cd;
		length -= cd;
		DanWei.TypeTags += str;
	}
}

void project::zhengce(DLG_ZhengCe * dhk)
{
	int i, j;
	char temp[4096];
	CString str;
	int length;
	int max;
	char * tt;

	if (id == number)//��ǰָ��ָ�����һ������
	{
		if (p == NULL)
		{
			root = p = new struct table;
		}
		else
		{
			p->hou = new struct table;
			p->hou->qian = p;
			p = p->hou;
		}
		id = number++;
	}
	else
	{
		if (p->type != 6)
		{
			MessageBox(NULL, L"������һ����ťֱ���ð�ťΪ��ɫ�ٳ��Ըò�����", L"�α����", MB_OK);
			return;
		}
	}
	tt = p->data;
	p->length = 0;
	p->type = 6;
	p->id = id;
	max = MAXLENGTH;

	//����
	i = dhk->m_xuanze;
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//Ӣ������
	dhk->m_type.GetWindowTextW(str);
	if (dhk->m_xuanze==0)
	{
		if (zhengcenum >= 1000)
		{
			MessageBox(NULL, L"����������������ɵ��������������½����̻��ֶ���ӣ�", L"��������", MB_OK);
			return;
		}
		zhengcenum++;
		::zhengce[zhengcenum].type = L"POLICY_" + str;
		::zhengce[zhengcenum].id = zhengcenum;
	}
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_name.GetWindowTextW(str);
	if (dhk->m_xuanze==0)
	{
		::zhengce[zhengcenum].name = str;
	}
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//ǰ������
	i = dhk->m_qianzhi.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	if (dhk->m_xuanze==0)
	{
		//��������
		dhk->m_d.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
		//��λ����
		i = dhk->m_caowei.GetCurSel();
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
		//��ʱ����
		i = dhk->m_guoshi.GetCurSel();
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
	}
	else
	{
		//������
		dhk->m_duan.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
		//������
		dhk->m_chang.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
		//��������
		dhk->m_guyou.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
		//������Ӷ�
		dhk->m_dishi.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
		//Ӱ��������
		dhk->m_dianshu.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
		//Ӱ������ֵ
		dhk->m_yuzhi.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
		//���ʹ����
		dhk->m_shizhe.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
		//��������
		i = dhk->m_chuancheng.GetCurSel();
		*((int *)tt) = i;
		tt += 4;
		max -= 4;
		//���²�λ
		if (dhk->m_cjunshi.GetCheck())
		{
			*((int *)tt) = 1;
			tt += 4;
			max -= 4;
			dhk->m_junshi.GetWindowTextW(str);
			length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
			*((int *)tt) = length;
			tt += 4;
			max -= 4;
			strcpy_s(tt, max, temp);
			tt += length;
			max -= length;
		}
		else
		{
			*((int *)tt) = 0;
			tt += 4;
			max -= 4;
		}
		//���ò�λ
		if (dhk->m_cjingji.GetCheck())
		{
			*((int *)tt) = 1;
			tt += 4;
			max -= 4;
			dhk->m_jingji.GetWindowTextW(str);
			length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
			*((int *)tt) = length;
			tt += 4;
			max -= 4;
			strcpy_s(tt, max, temp);
			tt += length;
			max -= length;
		}
		else
		{
			*((int *)tt) = 0;
			tt += 4;
			max -= 4;
		}
		//�⽻��λ
		if (dhk->m_cwaijiao.GetCheck())
		{
			*((int *)tt) = 1;
			tt += 4;
			max -= 4;
			dhk->m_waijiao.GetWindowTextW(str);
			length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
			*((int *)tt) = length;
			tt += 4;
			max -= 4;
			strcpy_s(tt, max, temp);
			tt += length;
			max -= length;
		}
		else
		{
			*((int *)tt) = 0;
			tt += 4;
			max -= 4;
		}
		//ͨ�ò�λ
		if (dhk->m_ctongyong.GetCheck())
		{
			*((int *)tt) = 1;
			tt += 4;
			max -= 4;
			dhk->m_tongyong.GetWindowTextW(str);
			length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
			*((int *)tt) = length;
			tt += 4;
			max -= 4;
			strcpy_s(tt, max, temp);
			tt += length;
			max -= length;
		}
		else
		{
			*((int *)tt) = 0;
			tt += 4;
			max -= 4;
		}
	}
	//����
	j = dhk->m_list.GetCount();
	*((int *)tt) = j;
	tt += 4;
	max -= 4;
	for (i = 0; i < j; i++)
	{
		dhk->m_list.GetText(i, str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}

	p->length = MAXLENGTH - max;
	ck->m_qian.EnableWindow(true);
	ck->m_delete.EnableWindow(true);
	ck->m_output.EnableWindow(true);
}

void project::fanzhengce(DLG_ZhengCe * dhk)
{
	int length, i, j, k;
	char * tt;
	CString str;

	length = p->length;
	tt = p->data;
	dhk->csh();

	//����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_zhonglei.SetCheck(0);
		((CButton *)(dhk->GetDlgItem(IDC_RADIO2)))->SetCheck(1);
		dhk->m_xuanze = 1;
	}
	else
	{
		dhk->m_zhonglei.SetCheck(1);
		((CButton *)(dhk->GetDlgItem(IDC_RADIO2)))->SetCheck(0);
		dhk->m_xuanze = 0;
	}
	//Ӣ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_type.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_name.SetWindowTextW(str);
	//ǰ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_qianzhi.SetCurSel(i);
	if (dhk->m_xuanze==0)
	{
		//��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_d.SetWindowTextW(str);
		//��λ����
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		dhk->m_caowei.SetCurSel(i);
		//��ʱ����
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		dhk->m_guoshi.SetCurSel(i);
	}
	else
	{
		//������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_duan.SetWindowTextW(str);
		//������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_chang.SetWindowTextW(str);
		//��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_guyou.SetWindowTextW(str);
		//������Ӷ�
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_dishi.SetWindowTextW(str);
		//Ӱ��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_dianshu.SetWindowTextW(str);
		//Ӱ������ֵ
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_yuzhi.SetWindowTextW(str);
		//���ʹ����
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_shizhe.SetWindowTextW(str);
		//��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		dhk->m_chuancheng.SetCurSel(i);
		//���²�λ
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		if (i)
		{
			dhk->m_cjunshi.SetCheck(1);
			dhk->m_junshi.EnableWindow(true);
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str = tt;
			tt += i;
			length -= i;
			dhk->m_junshi.SetWindowTextW(str);
		}
		else
		{
			dhk->m_cjunshi.SetCheck(0);
			dhk->m_junshi.EnableWindow(false);
		}
		//���ò�λ
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		if (i)
		{
			dhk->m_cjingji.SetCheck(1);
			dhk->m_jingji.EnableWindow(true);
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str = tt;
			tt += i;
			length -= i;
			dhk->m_jingji.SetWindowTextW(str);
		}
		else
		{
			dhk->m_cjingji.SetCheck(0);
			dhk->m_jingji.EnableWindow(false);
		}
		//�⽻��λ
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		if (i)
		{
			dhk->m_cwaijiao.SetCheck(1);
			dhk->m_waijiao.EnableWindow(true);
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str = tt;
			tt += i;
			length -= i;
			dhk->m_waijiao.SetWindowTextW(str);
		}
		else
		{
			dhk->m_cwaijiao.SetCheck(0);
			dhk->m_waijiao.EnableWindow(false);
		}
		//ͨ�ò�λ
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		if (i)
		{
			dhk->m_ctongyong.SetCheck(1);
			dhk->m_tongyong.EnableWindow(true);
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			str = tt;
			tt += i;
			length -= i;
			dhk->m_tongyong.SetWindowTextW(str);
		}
		else
		{
			dhk->m_ctongyong.SetCheck(0);
			dhk->m_tongyong.EnableWindow(false);
		}
	}
	//����
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (k = 0; k < j; k++)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_list.InsertString(-1, str);
	}
}

void project::shengzhengce(char * tt, int length)
{
	CString str;
	CString strtemp;
	CString strtype;
	CString ztzc;
	CString ztzc2;
	int i, j, k, cd;

	k = *((int *)tt);
	tt += 4;
	length -= 4;
	//Ӣ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	ztzc.Format(L"%s", !k ? L"Policy" : L"Government");
	ztzc2.Format(L"%s", !k ? L"POLICY" : L"GOVERNMENT");
	str.Format(L"\t\t<Row %sType=\"%s_%s\"", ztzc, ztzc2, strtemp);
	strtype.Format(L"%s_%s", ztzc2, strtemp);
	tt += i;
	length -= i;
	k ? ZhengCeZhengTi.Governments += str : ZhengCeZhengTi.Policies += str;
	str.Format(L"\t\t<Row Type=\"%s\" Kind=\"KIND_%s\"/>\r\n", strtype, ztzc2);
	Type += str;
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	str.Format(L" Name=\"LOC_%s_NAME\"", strtype);
	tt += i;
	length -= i;
	k ? ZhengCeZhengTi.Governments += str : ZhengCeZhengTi.Policies += str;
	str.Format(L"\t\t<Replace Tag=\"LOC_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
	Text += str;
	//ǰ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str.Format(L" PrereqCivic=\"%s\"", ::civic[i + 1].type);
	k ? ZhengCeZhengTi.Governments += str : ZhengCeZhengTi.Policies += str;
	if (k == 0)
	{
		//��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" Description=\"LOC_%s_DESCRIPTION\"", strtype);
		tt += i;
		length -= i;
		ZhengCeZhengTi.Policies += str;
		str.Format(L"\t\t<Replace Tag=\"LOC_%s_DESCRIPTION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
		Text += str;
		//��λ����
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" GovernmentSlotType=\"%s\"/>\r\n", gov[i]);
		ZhengCeZhengTi.Policies += str;
		//��ʱ����
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		if (i)
		{
			str.Format(L"\t\t<Row PolicyType=\"%s\" ObsoletePolicy=\"%s\"/>\r\n", strtype, ::zhengce[i].type);
			ZhengCeZhengTi.ObsoletePolicies += str;
		}
	}
	else
	{
		//������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" AccumulatedBonusShortDesc=\"LOC_GOVT_ACCUMULATED_BONUS_BRIEF_%s\"", strtype);
		tt += i;
		length -= i;
		ZhengCeZhengTi.Governments += str;
		str.Format(L"\t\t<Replace Tag=\"LOC_GOVT_ACCUMULATED_BONUS_BRIEF_%s\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
		Text += str;
		//������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" AccumulatedBonusDesc=\"LOC_GOVT_ACCUMULATED_BONUS_%s\"", strtype);
		tt += i;
		length -= i;
		ZhengCeZhengTi.Governments += str;
		str.Format(L"\t\t<Replace Tag=\"LOC_GOVT_ACCUMULATED_BONUS_%s\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
		Text += str;
		//��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" InherentBonusDesc=\"LOC_GOVT_INHERENT_BONUS_%s\"", strtype);
		tt += i;
		length -= i;
		ZhengCeZhengTi.Governments += str;
		str.Format(L"\t\t<Replace Tag=\"LOC_GOVT_INHERENT_BONUS_%s\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
		Text += str;
		//������Ӷ�
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" OtherGovernmentIntolerance=\"-%s\"", strtemp);
		tt += i;
		length -= i;
		ZhengCeZhengTi.Governments += str;
		//Ӱ��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" InfluencePointsPerTurn=\"%s\"", strtemp);
		tt += i;
		length -= i;
		ZhengCeZhengTi.Governments += str;
		//Ӱ������ֵ
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" InfluencePointsThreshold=\"%s\"", strtemp);
		tt += i;
		length -= i;
		ZhengCeZhengTi.Governments += str;
		//���ʹ����
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" InfluenceTokensPerThreshold=\"%s\"", strtemp);
		tt += i;
		length -= i;
		ZhengCeZhengTi.Governments += str;
		//��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" BonusType=\"%s\"", ::chuancheng[i]);
		ZhengCeZhengTi.Governments += str;
		ZhengCeZhengTi.Governments += L"/>\r\n";
		//���²�λ
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		if (i)
		{
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			strtemp = tt;
			str.Format(L"\t\t<Row GovernmentType=\"%s\" GovernmentSlotType=\"SLOT_MILITARY\" NumSlots=\"%s\"/>\r\n", strtype, strtemp);
			tt += i;
			length -= i;
			ZhengCeZhengTi.Government_SlotCounts += str;
		}
		//���ò�λ
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		if (i)
		{
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			strtemp = tt;
			str.Format(L"\t\t<Row GovernmentType=\"%s\" GovernmentSlotType=\"SLOT_ECONOMIC\" NumSlots=\"%s\"/>\r\n", strtype, strtemp);
			tt += i;
			length -= i;
			ZhengCeZhengTi.Government_SlotCounts += str;
		}
		//�⽻��λ
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		if (i)
		{
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			strtemp = tt;
			str.Format(L"\t\t<Row GovernmentType=\"%s\" GovernmentSlotType=\"SLOT_DIPLOMATIC\" NumSlots=\"%s\"/>\r\n", strtype, strtemp);
			tt += i;
			length -= i;
			ZhengCeZhengTi.Government_SlotCounts += str;
		}
		//ͨ�ò�λ
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		if (i)
		{
			i = *((int *)tt);
			tt += 4;
			length -= 4;
			strtemp = tt;
			str.Format(L"\t\t<Row GovernmentType=\"%s\" GovernmentSlotType=\"SLOT_WILDCARD\" NumSlots=\"%s\"/>\r\n", strtype, strtemp);
			tt += i;
			length -= i;
			ZhengCeZhengTi.Government_SlotCounts += str;
		}
	}
	//����
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (i = 0; i < j; i++)
	{
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L"%s", strtemp.Left(strtemp.Find(L":")));
		str.Format(L"\t\t<Row>\r\n\t\t\t<%sType>%s</%sType>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t</Row>\r\n", ztzc, strtype, ztzc, zongtexing[_ttoi(str)].type);
		tt += cd;
		length -= cd;
		k ? ZhengCeZhengTi.GovernmentModifiers += str : ZhengCeZhengTi.PolicyModifiers += str;
	}
}

void project::xintiao(DLG_XinTiao * dhk)
{
	int i, j;
	char temp[4096];
	CString str;
	int length;
	int max;
	char * tt;

	if (id == number)//��ǰָ��ָ�����һ������
	{
		if (p == NULL)
		{
			root = p = new struct table;
		}
		else
		{
			p->hou = new struct table;
			p->hou->qian = p;
			p = p->hou;
		}
		id = number++;
	}
	else
	{
		if (p->type != 7)
		{
			MessageBox(NULL, L"������һ����ťֱ���ð�ťΪ��ɫ�ٳ��Ըò�����", L"�α����", MB_OK);
			return;
		}
	}
	tt = p->data;
	p->length = 0;
	p->type = 7;
	p->id = id;
	max = MAXLENGTH;

	//Ӣ������
	dhk->m_type.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_name.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_d.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	i = dhk->m_xintiao.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//Ӣ������2
	dhk->m_type2.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������2
	dhk->m_name2.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������2
	dhk->m_d2.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//ͼ������
	i = dhk->m_tubiao.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//�����
	i = dhk->m_shendian.GetCheck();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��Ҫ������
	i = dhk->m_mingming.GetCheck();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��ɫ��
	dhk->m_hong.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ��
	dhk->m_lv.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ��
	dhk->m_lan.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��ɫ͸��
	dhk->m_tou.GetWindowTextW(str);
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//����
	j = dhk->m_list.GetCount();
	*((int *)tt) = j;
	tt += 4;
	max -= 4;
	for (i = 0; i < j; i++)
	{
		dhk->m_list.GetText(i, str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}

	p->length = MAXLENGTH - max;
	ck->m_qian.EnableWindow(true);
	ck->m_delete.EnableWindow(true);
	ck->m_output.EnableWindow(true);
}

void project::fanxintiao(DLG_XinTiao * dhk)
{
	int length, i, j, k;
	char * tt;
	CString str;

	length = p->length;
	tt = p->data;
	dhk->csh();
	//Ӣ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_type.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_name.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_d.SetWindowTextW(str);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_xintiao.SetCurSel(i);
	//Ӣ������2
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_type2.SetWindowTextW(str);
	//��������2
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_name2.SetWindowTextW(str);
	//��������2
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_d2.SetWindowTextW(str);
	//ͼ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_tubiao.SetCurSel(i);
	//�����
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_shendian.SetCheck(i);
	//��Ҫ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_mingming.SetCheck(i);
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_hong.SetWindowTextW(str);
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_lv.SetWindowTextW(str);
	//��ɫ��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_lan.SetWindowTextW(str);
	//��ɫ͸��
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_tou.SetWindowTextW(str);
	//����
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (k = 0; k < j; k++)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_list.InsertString(-1, str);
	}
}

void project::shengxintiao(char * tt, int length)
{
	CString str;
	CString strtemp;
	CString strtype;
	int i, j, cd;

	//Ӣ������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	tt += i;
	length -= i;
	if (strtemp.IsEmpty())//��������Ϊ���������ڽ�
	{
		//��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		//��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		//��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		//Ӣ������2
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		str.Format(L"\t\t<Row>\r\n\t\t\t<ReligionType>RELIGION_%s</ReligionType>\r\n", strtemp);
		strtype.Format(L"RELIGION_%s", strtemp);
		XinTiao.Religions += str;
		str.Format(L"\t\t<Row Type=\"%s\" Kind=\"KIND_RELIGION\"/>\r\n", strtype);
		Type += str;
		//��������2
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L"\t\t\t<Name>LOC_%s_NAME</Name>\r\n", strtype);
		tt += i;
		length -= i;
		XinTiao.Religions += str;
		str.Format(L"\t\t<Replace Tag=\"LOC_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
		Text += str;
		//��������2
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		//ͼ������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t\t<IconString>%s</IconString>\r\n", ::zj[i]);
		XinTiao.Religions += str;
		//�����
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		if (i)
		{
			str.Format(L"\t\t\t<Pantheon>true</Pantheon>\r\n");
			XinTiao.Religions += str;
		}
		//��Ҫ������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L"\t\t\t<Pantheon>%s</Pantheon>\r\n", i ? L"true" : L"false");
		XinTiao.Religions += str;
		//��ɫ��
		str.Format(L"\t\t\t<Color>COLOR_%s</Color>\r\n\t\t</Row>\r\n", strtype);
		XinTiao.Religions += str;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L"\t\t<Row>\r\n\t\t\t<Type>COLOR_%s</Type>\r\n\t\t\t<Color>%s,", strtype, strtemp);
		tt += i;
		length -= i;
		LingXiu.Colors += str;
		//��ɫ��
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L"%s,", strtemp);
		tt += i;
		length -= i;
		LingXiu.Colors += str;
		//��ɫ��
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L"%s,", strtemp);
		tt += i;
		length -= i;
		LingXiu.Colors += str;
		//��ɫ͸��
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L"%s</Color>\r\n\t\t</Row>\r\n", strtemp);
		tt += i;
		length -= i;
		LingXiu.Colors += str;
		//����
		j = *((int *)tt);
		tt += 4;
		length -= 4;
		for (i = 0; i < j; i++)
		{
			cd = *((int *)tt);
			tt += 4;
			length -= 4;
			strtemp = tt;
			tt += cd;
			length -= cd;
		}
	}
	else
	{
		str.Format(L"\t\t<Row BeliefType=\"BELIEF_%s\"", strtemp, strtemp, strtemp);
		strtype.Format(L"BELIEF_%s", strtemp);
		XinTiao.Beliefs += str;
		str.Format(L"\t\t<Row Type=\"%s\" Kind=\"KIND_BELIEF\"/>\r\n", strtype);
		Type += str;
		//��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" Name=\"LOC_%s_NAME\"", strtype);
		tt += i;
		length -= i;
		XinTiao.Beliefs += str;
		str.Format(L"\t\t<Replace Tag=\"LOC_%s_NAME\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
		Text += str;
		//��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		str.Format(L" Description=\"LOC_%s_DESCRIPTION\"", strtype);
		tt += i;
		length -= i;
		XinTiao.Beliefs += str;
		str.Format(L"\t\t<Replace Tag=\"LOC_%s_DESCRIPTION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype, strtemp);
		Text += str;
		//��������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str.Format(L" BeliefClassType=\"%s\"/>\r\n", ::xt[i]);
		XinTiao.Beliefs += str;
		//Ӣ������2
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		//��������2
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		//��������2
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		//ͼ������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		//�����
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		//��Ҫ������
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		//��ɫ��
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		//��ɫ��
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		//��ɫ��
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		//��ɫ͸��
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += i;
		length -= i;
		//����
		j = *((int *)tt);
		tt += 4;
		length -= 4;
		for (i = 0; i < j; i++)
		{
			cd = *((int *)tt);
			tt += 4;
			length -= 4;
			strtemp = tt;
			str.Format(L"%s", strtemp.Left(strtemp.Find(L":")));
			str.Format(L"\t\t<Row>\r\n\t\t\t<BeliefType>%s</BeliefType>\r\n\t\t\t<ModifierId>%s</ModifierId>\r\n\t\t</Row>\r\n", strtype, zongtexing[_ttoi(str)].type);
			tt += cd;
			length -= cd;
			XinTiao.BeliefModifiers += str;
		}
	}
}

void project::tiaojian(DLG_TiaoJian * dhk)
{
	int i, j;
	char temp[4096];
	CString str;
	int length;
	int max;
	char * tt;

	if (id == number)//��ǰָ��ָ�����һ������
	{
		if (p == NULL)
		{
			p = new struct table;
			if (root == NULL)
			{
				root = p;
			}
		}
		else
		{
			p->hou = new struct table;
			p->hou->qian = p;
			p = p->hou;
		}
		id = number++;
	}
	else
	{
		if (p->type != 12)
		{
			MessageBox(NULL, L"������һ����ťֱ���ð�ťΪ��ɫ�ٳ��Ըò�����", L"�α����", MB_OK);
			return;
		}
	}
	tt = p->data;
	p->length = 0;
	p->type = 12;
	p->id = id;
	max = MAXLENGTH;
	//Ӣ������
	dhk->m_type.GetWindowTextW(str);
	if (zongtiaojiannum >= 1000)
	{
		MessageBox(NULL, L"����������������ɵ��������������½����̻��ֶ���ӣ�", L"��������", MB_OK);
		return;
	}
	zongtiaojiannum++;
	zongtiaojian[zongtiaojiannum].type = str;
	zongtiaojian[zongtiaojiannum].id = zongtiaojiannum;
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_miaoshu.GetWindowTextW(str);
	zongtiaojian[zongtiaojiannum].name = str;
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//����������
	i = dhk->m_leixing.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//�����ַ���
	*((int *)tt) = dhk->strnum;
	tt += 4;
	max -= 4;
	for (i = 0;i < dhk->strnum;i++)
	{
		*((int *)tt) = dhk->type[i];
		tt += 4;
		max -= 4;
		length = WideCharToMultiByte(CP_ACP, 0, dhk->argstrs[i], -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//�ؼ���ʾ�ַ���
	j = dhk->m_list.GetCount();
	*((int *)tt) = j;
	tt += 4;
	max -= 4;
	for (i = 0;i < j;i++)
	{
		dhk->m_list.GetText(i, str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	if (max < 0)
	{
		MessageBox(NULL, L"����ӵ������������ڸ��ӣ��뾫������ԣ�", L"�������ڸ���", MB_OK);
		return;
	}
	p->length = MAXLENGTH - max;
	ck->m_qian.EnableWindow(true);
	ck->m_delete.EnableWindow(true);
	ck->m_output.EnableWindow(true);
}

void project::fantiaojian(DLG_TiaoJian * dhk)
{
	int length, i, j, k;
	char * tt;
	CString str;

	length = p->length;
	tt = p->data;
	dhk->csh();

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_type.SetWindowTextW(str);

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_miaoshu.SetWindowTextW(str);

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_leixing.SetCurSel(i);

	dhk->strnum = *((int *)tt);
	tt += 4;
	length -= 4;
	for (i = 0;i < dhk->strnum;i++)
	{
		dhk->type[i] = *((int *)tt);
		tt += 4;
		length -= 4;
		j = *((int *)tt);
		tt += 4;
		length -= 4;
		dhk->argstrs[i] = tt;
		tt += j;
		length -= j;
	}
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_list.ResetContent();
	for (i = 0;i < j;i++)
	{
		k = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += k;
		length -= k;
		dhk->m_list.InsertString(-1, str);
	}
}

void project::shengtiaojian(char * tt, int length)
{
	CString str;
	CString strtemp;
	CString strtype;
	int i, j, k, cd;

	RequirementSets += L"\t\t<Row>\r\n";
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	strtype.Format(L"\t\t\t<RequirementSetId>%s</RequirementSetId>\r\n", strtemp);
	tt += i;
	length -= i;
	RequirementSets += strtype;

	cd = *((int *)tt);
	tt += 4;
	length -= 4;
	tt += cd;
	length -= cd;
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		RequirementSets += L"\t\t\t<RequirementSetType>REQUIREMENTSET_TEST_ANY</RequirementSetType>\r\n\t\t</Row>\r\n";
	}
	else
	{
		RequirementSets += L"\t\t\t<RequirementSetType>REQUIREMENTSET_TEST_ALL</RequirementSetType>\r\n\t\t</Row>\r\n";
	}

	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (i = 0;i < j;i++)
	{
		k = *((int *)tt);
		tt += 4;
		length -= 4;
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		RequirementArguments += strtemp;
		tt += cd;
		length -= cd;
		str.Format(L"\t\t<Row>\r\n%s%s</RequirementId>\r\n\t\t</Row>\r\n", strtype, strtemp.Mid(9, strtemp.Find(L"</RequirementId>") - 9));
		RequirementSetRequirements += str;
		str.Format(L"\t\t<Row>\r\n%s</RequirementId>\r\n", strtemp.Mid(9, strtemp.Find(L"</RequirementId>") - 9));
		Requirements += str;
		str.Format(L"\t\t\t<RequirementType>%s</RequirementType>\r\n\t\t</Row>\r\n", ::tiaojian[k].type);
		Requirements += str;
	}
}

void project::texing(DLG_TeXing * dhk)
{
	int i;
	char temp[4096];
	CString str;
	int length;
	int max;
	char * tt;

	if (id == number)//��ǰָ��ָ�����һ������
	{
		if (p == NULL)
		{
			p = new struct table;
			if (root == NULL)
			{
				root = p;
			}
		}
		else
		{
			p->hou = new struct table;
			p->hou->qian = p;
			p = p->hou;
		}
		id = number++;
	}
	else
	{
		if (p->type != 13)
		{
			MessageBox(NULL, L"������һ����ťֱ���ð�ťΪ��ɫ�ٳ��Ըò�����", L"�α����", MB_OK);
			return;
		}
	}
	tt = p->data;
	p->length = 0;
	p->type = 13;
	p->id = id;
	max = MAXLENGTH;

	//Ӣ������
	dhk->m_type.GetWindowTextW(str);
	if (zongtexingnum >= 1000)
	{
		MessageBox(NULL, L"����������������ɵĽ������������½����̻��ֶ���ӣ�", L"��������", MB_OK);
		return;
	}
	zongtexingnum++;
	zongtexing[zongtexingnum].type = str;
	zongtexing[zongtexingnum].id = zongtexingnum;
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	dhk->m_miaoshu.GetWindowTextW(str);
	zongtexing[zongtexingnum].name = str;
	length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;
	//��������
	i = dhk->m_tiaojian.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//��������
	if (dhk->m_xwenzi.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		dhk->m_wenzi.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//��������
	i = dhk->m_texing.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;
	//ӵ��������
	i = dhk->m_yongyou.GetCurSel();
	*((int *)tt) = i;
	tt += 4;
	max -= 4;

	*((int *)tt) = dhk->number;
	tt += 4;
	max -= 4;
	//����1
	if (dhk->number > 0)
	{
		*((int *)tt) = dhk->arg1;
		tt += 4;
		max -= 4;
		dhk->m_arg1.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//����2
	if (dhk->number > 1)
	{
		*((int *)tt) = dhk->arg2;
		tt += 4;
		max -= 4;
		dhk->m_arg2.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//����3
	if (dhk->number > 2)
	{
		*((int *)tt) = dhk->arg3;
		tt += 4;
		max -= 4;
		dhk->m_arg3.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//����4
	if (dhk->number > 3)
	{
		*((int *)tt) = dhk->arg4;
		tt += 4;
		max -= 4;
		dhk->m_arg4.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//����5
	if (dhk->number > 4)
	{
		*((int *)tt) = dhk->arg5;
		tt += 4;
		max -= 4;
		dhk->m_arg5.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//����6
	if (dhk->number > 5)
	{
		*((int *)tt) = dhk->arg6;
		tt += 4;
		max -= 4;
		dhk->m_arg6.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//����7
	if (dhk->number > 6)
	{
		*((int *)tt) = dhk->arg7;
		tt += 4;
		max -= 4;
		dhk->m_arg7.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//����8
	if (dhk->number > 7)
	{
		*((int *)tt) = dhk->arg8;
		tt += 4;
		max -= 4;
		dhk->m_arg8.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	//Ч����פ
	if (dhk->m_f1.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//����һ��
	if (dhk->m_f2.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	//���Ӳ���
	if (dhk->m_f3.GetCheck())
	{
		*((int *)tt) = 1;
		tt += 4;
		max -= 4;
		dhk->m_fujia.GetWindowTextW(str);
		length = WideCharToMultiByte(CP_ACP, 0, str, -1, temp, sizeof(temp), NULL, NULL);
		*((int *)tt) = length;
		tt += 4;
		max -= 4;
		strcpy_s(tt, max, temp);
		tt += length;
		max -= length;
	}
	else
	{
		*((int *)tt) = 0;
		tt += 4;
		max -= 4;
	}
	length = WideCharToMultiByte(CP_ACP, 0, dhk->argstr, -1, temp, sizeof(temp), NULL, NULL);
	*((int *)tt) = length;
	tt += 4;
	max -= 4;
	strcpy_s(tt, max, temp);
	tt += length;
	max -= length;

	p->length = MAXLENGTH - max;
	ck->m_qian.EnableWindow(true);
	ck->m_delete.EnableWindow(true);
	ck->m_output.EnableWindow(true);
}

void project::fantexing(DLG_TeXing * dhk)
{
	int length, i;
	char * tt;
	CString str;

	length = p->length;
	tt = p->data;
	dhk->csh();

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_type.SetWindowTextW(str);

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += i;
	length -= i;
	dhk->m_miaoshu.SetWindowTextW(str);

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_tiaojian.SetCurSel(i);
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_xwenzi.SetCheck(1);
		dhk->m_wenzi.EnableWindow(true);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_wenzi.SetWindowTextW(str);
	}

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_texing.SetCurSel(i);
	dhk->OnCbnSelchangeCombo4();

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->m_yongyou.SetCurSel(i);
	dhk->number = *((int *)tt);
	tt += 4;
	length -= 4;

	if (dhk->number > 0)
	{
		dhk->arg1 = *((int *)tt);
		tt += 4;
		length -= 4;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_arg1.SetWindowTextW(str);
	}
	if (dhk->number > 1)
	{
		dhk->arg2 = *((int *)tt);
		tt += 4;
		length -= 4;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_arg2.SetWindowTextW(str);
	}
	if (dhk->number > 2)
	{
		dhk->arg3 = *((int *)tt);
		tt += 4;
		length -= 4;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_arg3.SetWindowTextW(str);
	}
	if (dhk->number > 3)
	{
		dhk->arg4 = *((int *)tt);
		tt += 4;
		length -= 4;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_arg4.SetWindowTextW(str);
	}
	if (dhk->number > 4)
	{
		dhk->arg5 = *((int *)tt);
		tt += 4;
		length -= 4;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_arg5.SetWindowTextW(str);
	}
	if (dhk->number > 5)
	{
		dhk->arg6 = *((int *)tt);
		tt += 4;
		length -= 4;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_arg6.SetWindowTextW(str);
	}
	if (dhk->number > 6)
	{
		dhk->arg7 = *((int *)tt);
		tt += 4;
		length -= 4;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_arg7.SetWindowTextW(str);
	}
	if (dhk->number > 7)
	{
		dhk->arg8 = *((int *)tt);
		tt += 4;
		length -= 4;
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_arg8.SetWindowTextW(str);
	}

	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_f1.SetCheck(1);
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_f2.SetCheck(1);
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		dhk->m_f3.SetCheck(1);
		dhk->m_fujia.EnableWindow(true);
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += i;
		length -= i;
		dhk->m_fujia.SetWindowTextW(str);
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	dhk->argstr = tt;
	tt += i;
	length -= i;
}

void project::shengtexing(char * tt, int length)
{
	CString str;
	CString strtemp;
	CString strtype;
	CString strtype2;
	int i, j, cd;

	//Ӣ������
	Modifiers += L"\t\t<Row>\r\n";
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	strtemp = tt;
	strtype2 = strtemp;
	strtype.Format(L"\t\t\t<ModifierId>%s</ModifierId>\r\n", strtemp);
	tt += i;
	length -= i;
	Modifiers += strtype;
	//��������
	cd = *((int *)tt);
	tt += 4;
	length -= 4;
	tt += cd;
	length -= cd;
	//��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	//��������
	cd = *((int *)tt);
	tt += 4;
	length -= 4;
	if (cd)
	{
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		strtemp = tt;
		tt += cd;
		length -= cd;
		strtype.Format(L"\t\t<Row ModifierId=\"%s\" Context=\"Preview\" Text=\"LOC_ABILITY_%s_DESCRIPTION\"/>\r\n", strtype2, strtype2);
		ModifierStrings += strtype;
		str.Format(L"\t\t<Replace Tag=\"LOC_ABILITY_%s_DESCRIPTION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", strtype2, strtemp);
		Text += str;
	}
	//��������
	j = *((int *)tt);
	tt += 4;
	length -= 4;
	strtype.Format(L"\t\t\t<ModifierType>%s</ModifierType>\r\n", ::texing[j].type);
	Modifiers += strtype;
	if (i)
	{
		strtype.Format(L"\t\t\t<SubjectRequirementSetId>%s</SubjectRequirementSetId>\r\n", zongtiaojian[i].type);
		Modifiers += strtype;
	}
	//ӵ��������
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	switch (i)
	{
	case 1:
		Modifiers += L"\t\t\t<OwnerRequirementSetId>REQUIREMENTS_UNIT_LAND_DOMAIN</OwnerRequirementSetId>\r\n";
		break;
	case 2:
		Modifiers += L"\t\t\t<OwnerRequirementSetId>REQUIREMENTS_UNIT_SEA_DOMAIN</OwnerRequirementSetId>\r\n";
		break;
	case 3:
		Modifiers += L"\t\t\t<OwnerRequirementSetId>ON_TURN_STARTED</OwnerRequirementSetId>\r\n";
		break;
	case 4:
		Modifiers += L"\t\t\t<OwnerRequirementSetId>PLAYER_IS_HUMAN</OwnerRequirementSetId>\r\n";
		break;
	case 5:
		Modifiers += L"\t\t\t<OwnerRequirementSetId>PLAYER_IS_HIGH_DIFFICULTY_AI</OwnerRequirementSetId>\r\n";
		break;
	case 6:
		Modifiers += L"\t\t\t<OwnerRequirementSetId>PLAYER_IS_LOW_DIFFICULTY_HUMAN</OwnerRequirementSetId>\r\n";
		break;
	default:
		break;
	}

	j = *((int *)tt);
	tt += 4;
	length -= 4;
	for (; j > 0; j--)
	{
		i = *((int *)tt);
		tt += 4;
		length -= 4;
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		tt += cd;
		length -= cd;
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		Modifiers += L"\t\t\t<Permanent>true</Permanent>\r\n";
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		Modifiers += L"\t\t\t<RunOnce>true</RunOnce>\r\n";
	}
	i = *((int *)tt);
	tt += 4;
	length -= 4;
	if (i)
	{
		cd = *((int *)tt);
		tt += 4;
		length -= 4;
		str = tt;
		tt += cd;
		length -= cd;
		strtype.Format(L"\t\t\t<Extra>%s</Extra>\r\n", str);
		Modifiers += strtype;
	}
	Modifiers += L"\t\t</Row>\r\n";

	cd = *((int *)tt);
	tt += 4;
	length -= 4;
	str = tt;
	tt += cd;
	length -= cd;
	ModifierArguments += str;
}

void project::xinjian(void)
{
	while (id < number)
	{
		p = p->hou;
		id++;
	}
}

int project::shanchu(void)
{
	struct table * temp;

	if (p)
	{
		if (p->qian)
		{
			if (p->hou)
			{
				number--;
				p->qian->hou = p->hou;
				p->hou->qian = p->qian;
				temp = p;
				p = p->hou;
				delete temp;
			}
			else
			{
				number--;
				id--;
				p = p->qian;
				delete p->hou;
				p->hou = NULL;
			}
		}
		else
		{
			if (p->hou)
			{
				root = p->hou;
				number--;
				id = 0;
				p->hou->qian = NULL;
				delete p;
				p = root;
			}
			else
			{
				id = number = 0;
				delete p;
				root = p = NULL;
				ck->m_hou.EnableWindow(false);
			}
		}
	}
	else
	{
		return 0;
	}

	return 1;
}

int project::shengcheng(CString name1, CString zuozhe, CString miaoshu, CString mulu, CString zhongwen)
{
	struct table * temp;
	CString dir1, dir2;// , dir3;
	CFile mod, text, f;
	int length;
	char * tt;
	CString str, strtemp;
	CString name = L"DLC_name";

	if (root)
	{
		for (temp = root; temp; temp = temp->hou)
		{
			length = temp->length;
			tt = temp->data;
			switch (temp->type)
			{
			case 0:
				shengjianzhu(tt, length);
				break;
			case 1:
				shengqiguan(tt, length);
				break;
			case 2:
				shengwenming(tt, length);
				break;
			case 3:
				shenglingxiu(tt, length);
				break;
			case 4:
				shengkeji(tt, length);
				break;
			case 5:
				shengdanwei(tt, length);
				break;
			case 6:
				shengzhengce(tt, length);
				break;
			case 7:
				shengxintiao(tt, length);
				break;
			case 8:
				break;
			case 9:
				break;
			case 10:
				break;
			case 11:
				break;
			case 12:
				shengtiaojian(tt, length);
				break;
			case 13:
				shengtexing(tt, length);
				break;
			}
		}

		if (!name1.IsEmpty())
		{
			name = name1;
		}
		dir1 = mulu + L"\\DLC\\" + name;
		dir2 = mulu + L"\\DLC\\" + name + L"\\Data";
		//dir3 = mulu + L"\\Base\\Assets\\Text\\";
		if (!PathIsDirectory(mulu + L"\\DLC"))
		{
			CreateDirectory(mulu + L"\\DLC", NULL);
		}
		if (!PathIsDirectory(dir1))
		{
			CreateDirectory(dir1, NULL);
		}
		if (!PathIsDirectory(dir2))
		{
			CreateDirectory(dir2, NULL);
		}
		/*if (!PathIsDirectory(mulu + L"\\Base"))
		{
			CreateDirectory(mulu + L"\\Base", NULL);
		}
		if (!PathIsDirectory(mulu + L"\\Base\\Assets"))
		{
			CreateDirectory(mulu + L"\\Base\\Assets", NULL);
		}
		if (!PathIsDirectory(mulu + L"\\Base\\Assets\\Text"))
		{
			CreateDirectory(mulu + L"\\Base\\Assets\\Text", NULL);
		}*/
		/*if (!PathIsDirectory(mulu + L"\\Base\\Assets\\Text\\Translations"))
		{
			CreateDirectory(mulu + L"\\Base\\Assets\\Text\\Translations", NULL);
		}*/
		dir1 += L"\\";
		dir2 += L"\\";

		mod.Open(dir1 + name + L".modinfo", CFile::modeCreate | CFile::modeWrite);
		str.Format(L"<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n\
<Mod id=\"12345678-90AB-CDFF-FFDC-BA0987654321\" version=\"1.0.1\">\r\n\t<Properties>\r\n\
\t\t<Name>LOC_%s</Name>\r\n\t\t<Teaser>LOC_%s_TEASER</Teaser>\r\n\
\t\t<Description>LOC_%s_DESCRIPTION</Description>\r\n\
\t\t<Authors>LOC_%s_AUTHORS</Authors>\r\n\
\t\t<ShowInBrowser>AlwaysShow</ShowInBrowser>\r\n\
\t\t<EnabledByDefault>1</EnabledByDefault>\r\n\
\t\t<EnabledAtStartup>1</EnabledAtStartup>\r\n\
\t</Properties>\r\n\t<InGameActions>\r\n\
\t\t<UpdateDatabase id=\"%s_GAMEPLAY_DATA\">\r\n\
\t\t\t<File>Data/%s_GameplayData.xml</File>\r\n\
\t\t</UpdateDatabase>\r\n\t\t<UpdateText id=\"%s_Text\">\r\n\
\t\t\t<File>Data/%s_zh_Hans_CN.xml</File>\r\n\t\t</UpdateText>\r\n\
\t</InGameActions>\r\n\t<FrontEndActions>\r\n\t\t<UpdateDatabase id=\"%s_CONFIG_DATA\">\r\n\
\t\t\t<File>Data/%s_ConfigData.xml</File>\r\n\
\t\t</UpdateDatabase>\r\n\t\t<UpdateText id=\"%s_CONFIG_Text\">\r\n\
\t\t\t<File>Data/%s_zh_Hans_CN.xml</File>\r\n\t\t</UpdateText>\r\n\t</FrontEndActions>\r\n\
\t<Files>\r\n\t\t<File>Data/%s_GameplayData.xml</File>\r\n\
\t\t<File>Data/%s_ConfigData.xml</File>\r\n\t\t<File>Data/%s_zh_Hans_CN.xml</File>\r\n\t</Files>\r\n</Mod>\r\n", \
name, name, name, name, name, name, name, name, name, name, name, name, name, name, name);
		strtemp.Format(L"\t\t<Replace Tag=\"LOC_%s\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", name, zhongwen);
		Text += strtemp;
		strtemp.Format(L"\t\t<Replace Tag=\"LOC_%s_AUTHORS\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", name, zuozhe);
		Text += strtemp;
		strtemp.Format(L"\t\t<Replace Tag=\"LOC_%s_TEASER\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", name, miaoshu);
		Text += strtemp;
		strtemp.Format(L"\t\t<Replace Tag=\"LOC_%s_DESCRIPTION\" Language=\"zh_Hans_CN\">\r\n\t\t\t<Text>%s</Text>\r\n\t\t</Replace>\r\n", name, miaoshu);
		Text += strtemp;
		length = str.GetLength() + 1;
		tt = new char[2 * length + 1];
		length = WideCharToMultiByte(CP_UTF8, 0, str, -1, tt, 2 * length + 1, NULL, NULL);
		mod.Write(tt, length);
		mod.Close();
		delete[] tt;

		text.Open(dir2 + name + L"_zh_Hans_CN.xml", CFile::modeCreate | CFile::modeWrite);
		str = L"<?xml version=\"1.0\" encoding=\"utf-8\"?>\r\n<GameData>\r\n\t<LocalizedText>\r\n";
		str += Text;
		str += L"\t</LocalizedText>\r\n</GameData>\r\n";
		length = str.GetLength() + 1;
		tt = new char[2 * length + 1];
		length = WideCharToMultiByte(CP_UTF8, 0, str, -1, tt, 2 * length + 1, NULL, NULL);
		text.Write(tt, length);
		text.Close();
		delete[] tt;

		f.Open(dir2 + name + L"_GameplayData.xml", CFile::modeCreate | CFile::modeWrite);
		str = L"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n";
		str += L"<GameInfo>\r\n";
		Type = L"\t<Types>\r\n" + Type + L"\t</Types>\r\n\r\n";
		str += Type;
		if (Modifiers.GetLength() > 0)
		{
			Modifiers = L"\t<Modifiers>\r\n" + Modifiers + L"\t</Modifiers>\r\n\r\n";
			str += Modifiers;
		}
		if (ModifierArguments.GetLength() > 0)
		{
			ModifierArguments = L"\t<ModifierArguments>\r\n" + ModifierArguments + L"\t</ModifierArguments>\r\n\r\n";
			str += ModifierArguments;
		}
		if (ModifierStrings.GetLength() > 0)
		{
			ModifierStrings = L"\t<ModifierStrings>\r\n" + ModifierStrings + L"\t</ModifierStrings>\r\n\r\n";
			str += ModifierStrings;
		}
		if (TraitModifiers.GetLength() > 0)
		{
			TraitModifiers = L"\t<TraitModifiers>\r\n" + TraitModifiers + L"\t</TraitModifiers>\r\n\r\n";
			str += TraitModifiers;
		}
		if (RequirementSets.GetLength() > 0)
		{
			RequirementSets = L"\t<RequirementSets>\r\n" + RequirementSets + L"\t</RequirementSets>\r\n\r\n";
			str += RequirementSets;
		}
		if (RequirementSetRequirements.GetLength() > 0)
		{
			RequirementSetRequirements = L"\t<RequirementSetRequirements>\r\n" + RequirementSetRequirements + L"\t</RequirementSetRequirements>\r\n\r\n";
			str += RequirementSetRequirements;
		}
		if (Requirements.GetLength() > 0)
		{
			Requirements = L"\t<Requirements>\r\n" + Requirements + L"\t</Requirements>\r\n\r\n";
			str += Requirements;
		}
		if (RequirementArguments.GetLength() > 0)
		{
			RequirementArguments = L"\t<RequirementArguments>\r\n" + RequirementArguments + L"\t</RequirementArguments>\r\n\r\n";
			str += RequirementArguments;
		}

		if (JianZhu.Buildings.GetLength() > 0)
		{
			JianZhu.Buildings = L"\t<Buildings>\r\n" + JianZhu.Buildings + L"\t</Buildings>\r\n\r\n";
			str += JianZhu.Buildings;
		}
		if (JianZhu.BuildingReplaces.GetLength() > 0)
		{
			JianZhu.BuildingReplaces = L"\t<BuildingReplaces>\r\n" + JianZhu.BuildingReplaces + L"\t</BuildingReplaces>\r\n\r\n";
			str += JianZhu.BuildingReplaces;
		}
		if (JianZhu.BuildingPrereqs.GetLength() > 0)
		{
			JianZhu.BuildingPrereqs = L"\t<BuildingPrereqs>\r\n" + JianZhu.BuildingPrereqs + L"\t</BuildingPrereqs>\r\n\r\n";
			str += JianZhu.BuildingPrereqs;
		}
		if (JianZhu.MutuallyExclusiveBuildings.GetLength() > 0)
		{
			JianZhu.MutuallyExclusiveBuildings = L"\t<MutuallyExclusiveBuildings>\r\n" + JianZhu.MutuallyExclusiveBuildings + L"\t</MutuallyExclusiveBuildings>\r\n\r\n";
			str += JianZhu.MutuallyExclusiveBuildings;
		}
		if (JianZhu.Building_YieldChanges.GetLength() > 0)
		{
			JianZhu.Building_YieldChanges = L"\t<Building_YieldChanges>\r\n" + JianZhu.Building_YieldChanges + L"\t</Building_YieldChanges>\r\n\r\n";
			str += JianZhu.Building_YieldChanges;
		}
		if (JianZhu.BuildingModifiers.GetLength() > 0)
		{
			JianZhu.BuildingModifiers = L"\t<BuildingModifiers>\r\n" + JianZhu.BuildingModifiers + L"\t</BuildingModifiers>\r\n\r\n";
			str += JianZhu.BuildingModifiers;
		}
		if (JianZhu.Building_GreatPersonPoints.GetLength() > 0)
		{
			JianZhu.Building_GreatPersonPoints = L"\t<Building_GreatPersonPoints>\r\n" + JianZhu.Building_GreatPersonPoints + L"\t</Building_GreatPersonPoints>\r\n\r\n";
			str += JianZhu.Building_GreatPersonPoints;
		}
		if (JianZhu.Building_GreatWorks.GetLength() > 0)
		{
			JianZhu.Building_GreatWorks = L"\t<Building_GreatWorks>\r\n" + JianZhu.Building_GreatWorks + L"\t</Building_GreatWorks>\r\n\r\n";
			str += JianZhu.Building_GreatWorks;
		}
		if (JianZhu.Building_RequiredFeatures.GetLength() > 0)
		{
			JianZhu.Building_RequiredFeatures = L"\t<Building_RequiredFeatures>\r\n" + JianZhu.Building_RequiredFeatures + L"\t</Building_RequiredFeatures>\r\n\r\n";
			str += JianZhu.Building_RequiredFeatures;
		}
		if (JianZhu.Building_ValidFeatures.GetLength() > 0)
		{
			JianZhu.Building_ValidFeatures = L"\t<Building_ValidFeatures>\r\n" + JianZhu.Building_ValidFeatures + L"\t</Building_ValidFeatures>\r\n\r\n";
			str += JianZhu.Building_ValidFeatures;
		}
		if (JianZhu.Building_ValidTerrains.GetLength() > 0)
		{
			JianZhu.Building_ValidTerrains = L"\t<Building_ValidTerrains>\r\n" + JianZhu.Building_ValidTerrains + L"\t</Building_ValidTerrains>\r\n\r\n";
			str += JianZhu.Building_ValidTerrains;
		}

		if (WenMing.Civilizations.GetLength() > 0)
		{
			WenMing.Civilizations = L"\t<Civilizations>\r\n" + WenMing.Civilizations + L"\t</Civilizations>\r\n\r\n";
			str += WenMing.Civilizations;
		}
		if (WenMing.Traits.GetLength() > 0)
		{
			WenMing.Traits = L"\t<Traits>\r\n" + WenMing.Traits + L"\t</Traits>\r\n\r\n";
			str += WenMing.Traits;
		}
		if (WenMing.CivilizationTraits.GetLength() > 0)
		{
			WenMing.CivilizationTraits = L"\t<CivilizationTraits>\r\n" + WenMing.CivilizationTraits + L"\t</CivilizationTraits>\r\n\r\n";
			str += WenMing.CivilizationTraits;
		}
		if (WenMing.CityNames.GetLength() > 0)
		{
			WenMing.CityNames = L"\t<CityNames>\r\n" + WenMing.CityNames + L"\t</CityNames>\r\n\r\n";
			str += WenMing.CityNames;
		}
		if (WenMing.StartBiasResources.GetLength() > 0)
		{
			WenMing.StartBiasResources = L"\t<StartBiasResources>\r\n" + WenMing.StartBiasResources + L"\t</StartBiasResources>\r\n\r\n";
			str += WenMing.StartBiasResources;
		}
		if (WenMing.StartBiasFeatures.GetLength() > 0)
		{
			WenMing.StartBiasFeatures = L"\t<StartBiasFeatures>\r\n" + WenMing.StartBiasFeatures + L"\t</StartBiasFeatures>\r\n\r\n";
			str += WenMing.StartBiasFeatures;
		}
		if (WenMing.StartBiasTerrains.GetLength() > 0)
		{
			WenMing.StartBiasTerrains = L"\t<StartBiasTerrains>\r\n" + WenMing.StartBiasTerrains + L"\t</StartBiasTerrains>\r\n\r\n";
			str += WenMing.StartBiasTerrains;
		}
		if (WenMing.StartBiasRivers.GetLength() > 0)
		{
			WenMing.StartBiasRivers = L"\t<StartBiasRivers>\r\n" + WenMing.StartBiasRivers + L"\t</StartBiasRivers>\r\n\r\n";
			str += WenMing.StartBiasRivers;
		}
		if (WenMing.CivilizationCitizenNames.GetLength() > 0)
		{
			WenMing.CivilizationCitizenNames = L"\t<CivilizationCitizenNames>\r\n" + WenMing.CivilizationCitizenNames + L"\t</CivilizationCitizenNames>\r\n\r\n";
			str += WenMing.CivilizationCitizenNames;
		}
		if (WenMing.CivilizationInfo.GetLength() > 0)
		{
			WenMing.CivilizationInfo = L"\t<CivilizationInfo>\r\n" + WenMing.CivilizationInfo + L"\t</CivilizationInfo>\r\n\r\n";
			str += WenMing.CivilizationInfo;
		}

		if (LingXiu.Leaders.GetLength() > 0)
		{
			LingXiu.Leaders = L"\t<Leaders>\r\n" + LingXiu.Leaders + L"\t</Leaders>\r\n\r\n";
			str += LingXiu.Leaders;
		}
		if (LingXiu.LeaderQuotes.GetLength() > 0)
		{
			LingXiu.LeaderQuotes = L"\t<LeaderQuotes>\r\n" + LingXiu.LeaderQuotes + L"\t</LeaderQuotes>\r\n\r\n";
			str += LingXiu.LeaderQuotes;
		}
		if (LingXiu.HistoricalAgendas.GetLength() > 0)
		{
			LingXiu.HistoricalAgendas = L"\t<HistoricalAgendas>\r\n" + LingXiu.HistoricalAgendas + L"\t</HistoricalAgendas>\r\n\r\n";
			str += LingXiu.HistoricalAgendas;
		}
		if (LingXiu.CivilizationLeaders.GetLength() > 0)
		{
			LingXiu.CivilizationLeaders = L"\t<CivilizationLeaders>\r\n" + LingXiu.CivilizationLeaders + L"\t</CivilizationLeaders>\r\n\r\n";
			str += LingXiu.CivilizationLeaders;
		}
		if (LingXiu.LeaderTraits.GetLength() > 0)
		{
			LingXiu.LeaderTraits = L"\t<LeaderTraits>\r\n" + LingXiu.LeaderTraits + L"\t</LeaderTraits>\r\n\r\n";
			str += LingXiu.LeaderTraits;
		}
		if (LingXiu.AgendaPreferredLeaders.GetLength() > 0)
		{
			LingXiu.AgendaPreferredLeaders = L"\t<AgendaPreferredLeaders>\r\n" + LingXiu.AgendaPreferredLeaders + L"\t</AgendaPreferredLeaders>\r\n\r\n";
			str += LingXiu.AgendaPreferredLeaders;
		}
		if (LingXiu.Colors.GetLength() > 0)
		{
			LingXiu.Colors = L"\t<Colors>\r\n" + LingXiu.Colors + L"\t</Colors>\r\n\r\n";
			str += LingXiu.Colors;
		}
		if (LingXiu.PlayerColors.GetLength() > 0)
		{
			LingXiu.PlayerColors = L"\t<PlayerColors>\r\n" + LingXiu.PlayerColors + L"\t</PlayerColors>\r\n\r\n";
			str += LingXiu.PlayerColors;
		}
		if (LingXiu.AiListTypes.GetLength() > 0)
		{
			LingXiu.AiListTypes = L"\t<AiListTypes>\r\n" + LingXiu.AiListTypes + L"\t</AiListTypes>\r\n\r\n";
			str += LingXiu.AiListTypes;
		}
		if (LingXiu.AiLists.GetLength() > 0)
		{
			LingXiu.AiLists = L"\t<AiLists>\r\n" + LingXiu.AiLists + L"\t</AiLists>\r\n\r\n";
			str += LingXiu.AiLists;
		}
		if (LingXiu.AiFavoredItems.GetLength() > 0)
		{
			LingXiu.AiFavoredItems = L"\t<AiFavoredItems>\r\n" + LingXiu.AiFavoredItems + L"\t</AiFavoredItems>\r\n\r\n";
			str += LingXiu.AiFavoredItems;
		}

		if (KeJiShiZheng.Technologies.GetLength() > 0)
		{
			KeJiShiZheng.Technologies = L"\t<Technologies>\r\n" + KeJiShiZheng.Technologies + L"\t</Technologies>\r\n\r\n";
			str += KeJiShiZheng.Technologies;
		}
		if (KeJiShiZheng.TechnologyPrereqs.GetLength() > 0)
		{
			KeJiShiZheng.TechnologyPrereqs = L"\t<TechnologyPrereqs>\r\n" + KeJiShiZheng.TechnologyPrereqs + L"\t</TechnologyPrereqs>\r\n\r\n";
			str += KeJiShiZheng.TechnologyPrereqs;
		}
		if (KeJiShiZheng.TechnologyQuotes.GetLength() > 0)
		{
			KeJiShiZheng.TechnologyQuotes = L"\t<TechnologyQuotes>\r\n" + KeJiShiZheng.TechnologyQuotes + L"\t</TechnologyQuotes>\r\n\r\n";
			str += KeJiShiZheng.TechnologyQuotes;
		}
		if (KeJiShiZheng.TechnologyModifiers.GetLength() > 0)
		{
			KeJiShiZheng.TechnologyModifiers = L"\t<TechnologyModifiers>\r\n" + KeJiShiZheng.TechnologyModifiers + L"\t</TechnologyModifiers>\r\n\r\n";
			str += KeJiShiZheng.TechnologyModifiers;
		}
		if (KeJiShiZheng.Civics.GetLength() > 0)
		{
			KeJiShiZheng.Civics = L"\t<Civics>\r\n" + KeJiShiZheng.Civics + L"\t</Civics>\r\n\r\n";
			str += KeJiShiZheng.Civics;
		}
		if (KeJiShiZheng.CivicPrereqs.GetLength() > 0)
		{
			KeJiShiZheng.CivicPrereqs = L"\t<CivicPrereqs>\r\n" + KeJiShiZheng.CivicPrereqs + L"\t</CivicPrereqs>\r\n\r\n";
			str += KeJiShiZheng.CivicPrereqs;
		}
		if (KeJiShiZheng.CivicQuotes.GetLength() > 0)
		{
			KeJiShiZheng.CivicQuotes = L"\t<CivicQuotes>\r\n" + KeJiShiZheng.CivicQuotes + L"\t</CivicQuotes>\r\n\r\n";
			str += KeJiShiZheng.CivicQuotes;
		}
		if (KeJiShiZheng.CivicModifiers.GetLength() > 0)
		{
			KeJiShiZheng.CivicModifiers = L"\t<CivicModifiers>\r\n" + KeJiShiZheng.CivicModifiers + L"\t</CivicModifiers>\r\n\r\n";
			str += KeJiShiZheng.CivicModifiers;
		}
		if (KeJiShiZheng.Boosts.GetLength() > 0)
		{
			KeJiShiZheng.Boosts = L"\t<Boosts>\r\n" + KeJiShiZheng.Boosts + L"\t</Boosts>\r\n\r\n";
			str += KeJiShiZheng.Boosts;
		}

		if (DanWei.Units.GetLength() > 0)
		{
			DanWei.Units = L"\t<Units>\r\n" + DanWei.Units + L"\t</Units>\r\n\r\n";
			str += DanWei.Units;
		}
		if (DanWei.Tags.GetLength() > 0)
		{
			DanWei.Tags = L"\t<Tags>\r\n" + DanWei.Tags + L"\t</Tags>\r\n\r\n";
			str += DanWei.Tags;
		}
		if (DanWei.TypeTags.GetLength() > 0)
		{
			DanWei.TypeTags = L"\t<TypeTags>\r\n" + DanWei.TypeTags + L"\t</TypeTags>\r\n\r\n";
			str += DanWei.TypeTags;
		}
		if (DanWei.UnitUpgrades.GetLength() > 0)
		{
			DanWei.UnitUpgrades = L"\t<UnitUpgrades>\r\n" + DanWei.UnitUpgrades + L"\t</UnitUpgrades>\r\n\r\n";
			str += DanWei.UnitUpgrades;
		}
		if (DanWei.Unit_BuildingPrereqs.GetLength() > 0)
		{
			DanWei.Unit_BuildingPrereqs = L"\t<Unit_BuildingPrereqs>\r\n" + DanWei.Unit_BuildingPrereqs + L"\t</Unit_BuildingPrereqs>\r\n\r\n";
			str += DanWei.Unit_BuildingPrereqs;
		}
		if (DanWei.UnitAiInfos.GetLength() > 0)
		{
			DanWei.UnitAiInfos = L"\t<UnitAiInfos>\r\n" + DanWei.UnitAiInfos + L"\t</UnitAiInfos>\r\n\r\n";
			str += DanWei.UnitAiInfos;
		}
		if (DanWei.UnitAbilities.GetLength() > 0)
		{
			DanWei.UnitAbilities = L"\t<UnitAbilities>\r\n" + DanWei.UnitAbilities + L"\t</UnitAbilities>\r\n\r\n";
			str += DanWei.UnitAbilities;
		}
		if (DanWei.UnitAbilityModifiers.GetLength() > 0)
		{
			DanWei.UnitAbilityModifiers = L"\t<UnitAbilityModifiers>\r\n" + DanWei.UnitAbilityModifiers + L"\t</UnitAbilityModifiers>\r\n\r\n";
			str += DanWei.UnitAbilityModifiers;
		}
		if (DanWei.UnitReplaces.GetLength() > 0)
		{
			DanWei.UnitReplaces = L"\t<UnitReplaces>\r\n" + DanWei.UnitReplaces + L"\t</UnitReplaces>\r\n\r\n";
			str += DanWei.UnitReplaces;
		}
		if (DanWei.UnitCaptures.GetLength() > 0)
		{
			DanWei.UnitCaptures = L"\t<UnitCaptures>\r\n" + DanWei.UnitCaptures + L"\t</UnitCaptures>\r\n\r\n";
			str += DanWei.UnitCaptures;
		}

		if (ZhengCeZhengTi.Policies.GetLength() > 0)
		{
			ZhengCeZhengTi.Policies = L"\t<Policies>\r\n" + ZhengCeZhengTi.Policies + L"\t</Policies>\r\n\r\n";
			str += ZhengCeZhengTi.Policies;
		}
		if (ZhengCeZhengTi.ObsoletePolicies.GetLength() > 0)
		{
			ZhengCeZhengTi.ObsoletePolicies = L"\t<ObsoletePolicies>\r\n" + ZhengCeZhengTi.ObsoletePolicies + L"\t</ObsoletePolicies>\r\n\r\n";
			str += ZhengCeZhengTi.ObsoletePolicies;
		}
		if (ZhengCeZhengTi.PolicyModifiers.GetLength() > 0)
		{
			ZhengCeZhengTi.PolicyModifiers = L"\t<PolicyModifiers>\r\n" + ZhengCeZhengTi.PolicyModifiers + L"\t</PolicyModifiers>\r\n\r\n";
			str += ZhengCeZhengTi.PolicyModifiers;
		}
		if (ZhengCeZhengTi.Governments.GetLength() > 0)
		{
			ZhengCeZhengTi.Governments = L"\t<Governments>\r\n" + ZhengCeZhengTi.Governments + L"\t</Governments>\r\n\r\n";
			str += ZhengCeZhengTi.Governments;
		}
		if (ZhengCeZhengTi.Government_SlotCounts.GetLength() > 0)
		{
			ZhengCeZhengTi.Government_SlotCounts = L"\t<Government_SlotCounts>\r\n" + ZhengCeZhengTi.Government_SlotCounts + L"\t</Government_SlotCounts>\r\n\r\n";
			str += ZhengCeZhengTi.Government_SlotCounts;
		}
		if (ZhengCeZhengTi.GovernmentModifiers.GetLength() > 0)
		{
			ZhengCeZhengTi.GovernmentModifiers = L"\t<GovernmentModifiers>\r\n" + ZhengCeZhengTi.GovernmentModifiers + L"\t</GovernmentModifiers>\r\n\r\n";
			str += ZhengCeZhengTi.GovernmentModifiers;
		}

		if (XinTiao.Beliefs.GetLength() > 0)
		{
			XinTiao.Beliefs = L"\t<Beliefs>\r\n" + XinTiao.Beliefs + L"\t</Beliefs>\r\n\r\n";
			str += XinTiao.Beliefs;
		}
		if (XinTiao.BeliefModifiers.GetLength() > 0)
		{
			XinTiao.BeliefModifiers = L"\t<BeliefModifiers>\r\n" + XinTiao.BeliefModifiers + L"\t</BeliefModifiers>\r\n\r\n";
			str += XinTiao.BeliefModifiers;
		}
		if (XinTiao.Religions.GetLength() > 0)
		{
			XinTiao.Religions = L"\t<Religions>\r\n" + XinTiao.Religions + L"\t</Religions>\r\n\r\n";
			str += XinTiao.Religions;
		}

		str += L"</GameInfo>\r\n";
		length = str.GetLength() + 1;
		tt = new char[2 * length + 1];
		length = WideCharToMultiByte(CP_UTF8, 0, str, -1, tt, 2 * length + 1, NULL, NULL);
		f.Write(tt, length);
		f.Close();
		delete[] tt;

		f.Open(dir2 + name + L"_ConfigData.xml", CFile::modeCreate | CFile::modeWrite);
		str = L"<?xml version=\"1.0\" encoding=\"UTF-8\"?>\r\n";
		str += L"<GameInfo>\r\n";
		if (Players.GetLength() > 0)
		{
			Players = L"\t<Players>\r\n" + Players + L"\t</Players>\r\n\r\n";
			str += Players;
		}
		if (PlayerItems.GetLength() > 0)
		{
			PlayerItems = L"\t<PlayerItems>\r\n" + PlayerItems + L"\t</PlayerItems>\r\n\r\n";
			str += PlayerItems;
		}
		str += L"</GameInfo>\r\n";
		length = str.GetLength() + 1;
		tt = new char[2 * length + 1];
		length = WideCharToMultiByte(CP_UTF8, 0, str, -1, tt, 2 * length + 1, NULL, NULL);
		f.Write(tt, length);
		f.Close();
		delete[] tt;
	}
	else
	{
		return 0;
	}

	return 1;
}

int project::canshu(CWnd * wenzi, CComboBox * shuju, CString canshu)
{
	char temp[1024];
	int length, i, j;
	static bool kexuan = false;

	if ((wenzi == NULL) && (shuju == NULL))
	{
		kexuan = false;
		return 0;
	}
	if (canshu.GetLength() < 1)
	{
		wenzi->ShowWindow(false);
		shuju->ShowWindow(false);
		return 0;
	}
	length = WideCharToMultiByte(CP_UTF8, 0, canshu, -1, temp, sizeof(temp), NULL, NULL);
	shuju->ResetContent();
	if (kexuan)
	{
		shuju->AddString(L"��");
	}

	switch (*((unsigned short *)temp))
	{
	case 0x6241:
		wenzi->SetWindowTextW(L"�������ͣ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		for (i = 0; i < abilitynum; i++)
		{
			shuju->AddString(ability[i].name);
		}
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 1;
	case 0x6341:
		if (temp[2] == 'c')
		{
			wenzi->SetWindowTextW(L"�Ƿ�����");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 2;
		}
		else
		{
			wenzi->SetWindowTextW(L"�ж���");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"λ�ñ��Ӱ����Ȩ");
			shuju->AddString(L"��������������ս��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 3;
		}
	case 0x6441:
		wenzi->SetWindowTextW(L"���߲�λ��");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"�������߲�");
		shuju->AddString(L"�������߲�");
		shuju->AddString(L"�⽻���߲�");
		shuju->AddString(L"ͨ�����߲�");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 4;
	case 0x6d41:
		wenzi->SetWindowTextW(L"��ֵ��");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 5;
	case 0x6f42:
		if (length <= 5)
		{
			wenzi->SetWindowTextW(L"����������");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 6;
		}
		else if (temp[5] == 'R')
		{
			wenzi->SetWindowTextW(L"�����ٶȣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 7;
		}
		else if (temp[5] == 'T')
		{
			wenzi->SetWindowTextW(L"�������ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"�޽���ۼ���");
			shuju->AddString(L"��λս������ӳ�");
			shuju->AddString(L"ΰ�˵����ӳ�");
			shuju->AddString(L"Ӱ������������");
			shuju->AddString(L"�����������ļ���");
			shuju->AddString(L"��ҹ������ļ���");
			shuju->AddString(L"ѵ����λʱ��������");
			shuju->AddString(L"������������");
			shuju->AddString(L"������Ŀ��������");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 8;
		}
		else
		{
			wenzi->SetWindowTextW(L"������ۣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 9;
		}
	case 0x7542:
		wenzi->SetWindowTextW(L"�������ͣ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		for (j = 1;j <= buildingnum;j++)
		{
			shuju->AddString(building[j].name);
		}
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 10;
	case 0x7942:
		wenzi->SetWindowTextW(L"֧Ԯ��λ��");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"��");
		shuju->AddString(L"��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 11;
	case 0x6143:
		switch (temp[3])
		{
		case 'A':
			wenzi->SetWindowTextW(L"�ܹ�������");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 12;
		case 'C':
			wenzi->SetWindowTextW(L"�ܹ�����");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 13;
		case 'M':
			wenzi->SetWindowTextW(L"�ܹ��ƶ���");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 14;
		case 'R':
			wenzi->SetWindowTextW(L"�ܹ�Ϯ����");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 15;
		}
	case 0x6943:
		wenzi->SetWindowTextW(L"�������ͣ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		for (j = 1;j <= civicnum;j++)
		{
			shuju->AddString(civic[j].name);
		}
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 16;
	case 0x6f43:
		if (temp[2] == 'r')
		{
			wenzi->SetWindowTextW(L"���ż���");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 19;
		}
		else if (length <= 8)
		{
			wenzi->SetWindowTextW(L"ת�����壺");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 17;
		}
		else
		{
			wenzi->SetWindowTextW(L"ת���ڽ̣�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 18;
		}
	case 0x6544:
		if (temp[2] == 'f')
		{
			wenzi->SetWindowTextW(L"�������£�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 20;
		}
		else
		{
			wenzi->SetWindowTextW(L"�������֣�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 81;
		}
	case 0x6944:
		if (temp[2] == 'p')
		{
			wenzi->SetWindowTextW(L"�⽻״����");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"����ս");
			shuju->AddString(L"��ų���");
			shuju->AddString(L"����ͻϮս��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 82;
		}
		else if (temp[3] == 'c')
		{
			wenzi->SetWindowTextW(L"�ۿۣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 21;
		}
		else
		{
			wenzi->SetWindowTextW(L"�������ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"������");
			shuju->AddString(L"ʥ��");
			shuju->AddString(L"ѧԺ");
			shuju->AddString(L"���»���");
			shuju->AddString(L"�ۿ�");
			shuju->AddString(L"��ҵ����");
			shuju->AddString(L"��������");
			shuju->AddString(L"��Ժ�㳡");
			shuju->AddString(L"��ˮ��");
			shuju->AddString(L"��ҵ��");
			shuju->AddString(L"����");
			shuju->AddString(L"����");
			shuju->AddString(L"�����");
			shuju->AddString(L"ķ����");
			shuju->AddString(L"�޵�Ժ");
			shuju->AddString(L"����");
			shuju->AddString(L"����ԡ��");
			shuju->AddString(L"�����̻�");
			shuju->AddString(L"��ü��껪");
			shuju->AddString(L"�ʼҾ���");
			shuju->AddString(L"�������");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 22;
		}
	case 0x6f44:
		if (length <= 6)
		{
			wenzi->SetWindowTextW(L"��λ���ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"½�ص�λ");
			shuju->AddString(L"����λ");
			shuju->AddString(L"���е�λ");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 23;
		}
		else if (temp[3] == 'a')
		{
			wenzi->SetWindowTextW(L"��λ���ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"½�ص�λ");
			shuju->AddString(L"����λ");
			shuju->AddString(L"���е�λ");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 24;
		}
		else
		{
			wenzi->SetWindowTextW(L"���޹��ڣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 25;
		}
	case 0x6e45:
		if (temp[2] == 'a')
		{
			wenzi->SetWindowTextW(L"�Ƿ�����");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 26;
		}
		else if (temp[2] == 'd')
		{
			wenzi->SetWindowTextW(L"����ʱ����");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"Զ��ʱ��");
			shuju->AddString(L"�ŵ�ʱ��");
			shuju->AddString(L"�й�ʱ��");
			shuju->AddString(L"����ʱ��");
			shuju->AddString(L"��ҵʱ��");
			shuju->AddString(L"����ʱ��");
			shuju->AddString(L"ԭ��ʱ��");
			shuju->AddString(L"��Ϣʱ��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 27;
		}
		else
		{
			wenzi->SetWindowTextW(L"�Ƿ���ˣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 28;
		}
	case 0x7245:
		wenzi->SetWindowTextW(L"ʱ�����ͣ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"Զ��ʱ��");
		shuju->AddString(L"�ŵ�ʱ��");
		shuju->AddString(L"�й�ʱ��");
		shuju->AddString(L"����ʱ��");
		shuju->AddString(L"��ҵʱ��");
		shuju->AddString(L"����ʱ��");
		shuju->AddString(L"ԭ��ʱ��");
		shuju->AddString(L"��Ϣʱ��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 29;
	case 0x7345:
		wenzi->SetWindowTextW(L"����ƶ���");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"��");
		shuju->AddString(L"��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 30;
	case 0x7845:
		if (temp[2] == 'e')
		{
			wenzi->SetWindowTextW(L"��������");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 31;
		}
		else
		{
			wenzi->SetWindowTextW(L"��ȡ���");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 32;
		}
	case 0x6146:
		wenzi->SetWindowTextW(L"�Ƿ�ϲ����");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"��");
		shuju->AddString(L"��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 33;
	case 0x6546:
		wenzi->SetWindowTextW(L"��ò���ͣ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"���ƽԭ");
		shuju->AddString(L"����");
		shuju->AddString(L"����");
		shuju->AddString(L"ɭ��");
		shuju->AddString(L"����");
		shuju->AddString(L"����");
		shuju->AddString(L"�󱤽�");
		shuju->AddString(L"������");
		shuju->AddString(L"��ɽ�ں�");
		shuju->AddString(L"����");
		shuju->AddString(L"���������");
		shuju->AddString(L"��������˹Ⱥ��");
		shuju->AddString(L"����������ɽ");
		shuju->AddString(L"�����ɶ�ʪ��");
		shuju->AddString(L"�׷�Ͽ��");
		shuju->AddString(L"���׵����");
		shuju->AddString(L"�ټ��±�������");
		shuju->AddString(L"Լ���׵�");
		shuju->AddString(L"���ŷ�����ɽ");
		shuju->AddString(L"��ɪϿ��");
		shuju->AddString(L"����֮·");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 34;
	case 0x6f46:
		if (temp[2] == 'u')
		{
			wenzi->SetWindowTextW(L"�����ڽ̣�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 35;
		}
		else
		{
			wenzi->SetWindowTextW(L"ǿ���ƶ���");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 36;
		}
	case 0x6f47:
		wenzi->SetWindowTextW(L"���߲�λ��");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"�������߲�");
		shuju->AddString(L"�������߲�");
		shuju->AddString(L"�⽻���߲�");
		shuju->AddString(L"ͨ�����߲�");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 37;
	case 0x7247:
		if (temp[10] == 'n')
		{
			wenzi->SetWindowTextW(L"ΰ�����ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��Ԥ�Լ�");
			shuju->AddString(L"����¼�");
			shuju->AddString(L"�����Ͻ�");
			shuju->AddString(L"���ѧ��");
			shuju->AddString(L"�󹤳�ʦ");
			shuju->AddString(L"������");
			shuju->AddString(L"������");
			shuju->AddString(L"��������");
			shuju->AddString(L"�����ּ�");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 38;
		}
		else if (temp[10] == 'b')
		{
			wenzi->SetWindowTextW(L"�������ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"����");
			shuju->AddString(L"����");
			shuju->AddString(L"����");
			shuju->AddString(L"Ф��");
			shuju->AddString(L"�羰");
			shuju->AddString(L"�ڽ�");
			shuju->AddString(L"����");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 39;
		}
		else
		{
			wenzi->SetWindowTextW(L"�����ۣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"���ܲ�");
			shuju->AddString(L"�����");
			shuju->AddString(L"�����");
			shuju->AddString(L"��д��");
			shuju->AddString(L"������");
			shuju->AddString(L"������");
			shuju->AddString(L"�ڽ�������");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 40;
		}
	case 0x6148:
		wenzi->SetWindowTextW(L"���������");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"��");
		shuju->AddString(L"��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 41;
	case 0x6948:
		wenzi->SetWindowTextW(L"�������Σ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"��");
		shuju->AddString(L"��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 42;
	case 0x6749:
		wenzi->SetWindowTextW(L"�Ƿ���ӣ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"��");
		shuju->AddString(L"��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 43;
	case 0x6d49:
		if (temp[7] == 'm')
		{
			wenzi->SetWindowTextW(L"������ʩ��");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"����Ӫ��");
			shuju->AddString(L"ũ��");
			shuju->AddString(L"��");
			shuju->AddString(L"��ʯ��");
			shuju->AddString(L"�洬");
			shuju->AddString(L"����");
			shuju->AddString(L"��ֲ԰");
			shuju->AddString(L"�Գ�");
			shuju->AddString(L"�����ׯ");
			shuju->AddString(L"�;�");
			shuju->AddString(L"�������");
			shuju->AddString(L"Ҫ��");
			shuju->AddString(L"�����ȼ���");
			shuju->AddString(L"�������侮");
			shuju->AddString(L"ׯ԰");
			shuju->AddString(L"��ʯͷ��");
			shuju->AddString(L"����");
			shuju->AddString(L"�ض�");
			shuju->AddString(L"���̻�");
			shuju->AddString(L"����Ҫ��");
			shuju->AddString(L"ʨ��������");
			shuju->AddString(L"���ݾ�");
			shuju->AddString(L"ͨ����");
			shuju->AddString(L"�Ǳ�");
			shuju->AddString(L"�޵�Ժ");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 44;
		}
		else
		{
			wenzi->SetWindowTextW(L"��·������");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 83;
		}
	case 0x6e49:
		wenzi->SetWindowTextW(L"��Ҫ�޼ʣ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"��");
		shuju->AddString(L"��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 45;
	case 0x614d:
		if (temp[3] == 'D')
		{
			wenzi->SetWindowTextW(L"�����룺");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 46;
		}
		else
		{
			wenzi->SetWindowTextW(L"��������");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 84;
		}
	case 0x654d:
		wenzi->SetWindowTextW(L"�������ͣ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"���ɿ����ż�");
		shuju->AddString(L"���ɺ����ż�");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 47;
	case 0x694d:
		wenzi->SetWindowTextW(L"��С���룺");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 48;
	case 0x6f4d:
		wenzi->SetWindowTextW(L"�������ͣ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		for (j = 1;j <= zongtexingnum;j++)
		{
			shuju->AddString(zongtexing[j].name);
		}
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 49;
	case 0x754d:
		if (temp[2] == 'l')
		{
			wenzi->SetWindowTextW(L"�ٷֱȣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 50;
		}
		else
		{
			wenzi->SetWindowTextW(L"�滻������");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 51;
		}
	case 0x6f4e:
		if (temp[2] == 'R')
		{
			wenzi->SetWindowTextW(L"ս��������");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 52;
		}
		else
		{
			wenzi->SetWindowTextW(L"û�гͷ���");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 85;
		}
	case 0x664f:
		wenzi->SetWindowTextW(L"�Ƿ������");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"��");
		shuju->AddString(L"��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 53;
	case 0x6e4f:
		wenzi->SetWindowTextW(L"����ʱ����");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"��");
		shuju->AddString(L"��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 54;
	case 0x764f:
		wenzi->SetWindowTextW(L"���������");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"��");
		shuju->AddString(L"��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 55;
	case 0x6550:
		if (length <= 7)
		{
			wenzi->SetWindowTextW(L"�ٷֱȣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 56;
		}
		else
		{
			wenzi->SetWindowTextW(L"����ս�ȣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 57;
		}
	case 0x7250:
		wenzi->SetWindowTextW(L"�������ͣ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		for (j = 1;j <= jinshengnum;j++)
		{
			shuju->AddString(jinsheng[j].name);
		}
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 58;
	case 0x6152:
		wenzi->SetWindowTextW(L"��Χ��");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 59;
	case 0x6552:
		if (temp[2] == 'l')
		{
			wenzi->SetWindowTextW(L"�������");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 60;
		}
		else if(temp[2] == 'p')
		{
			wenzi->SetWindowTextW(L"�滻���ۣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"�������߲�");
			shuju->AddString(L"�������߲�");
			shuju->AddString(L"�⽻���߲�");
			shuju->AddString(L"ͨ�����߲�");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 61;
		}
		else if (temp[2] == 'd')
		{
			wenzi->SetWindowTextW(L"���ٱ�����");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 80;
		}
		else if(temp[2] == 's')
		{
			wenzi->SetWindowTextW(L"��Դ���ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			for (j = 1;j <= ziyuannum;j++)
			{
				shuju->AddString(ziyuan[j].name);
			}
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 62;
		}
		else
		{
			wenzi->SetWindowTextW(L"��������");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 86;
		}
	case 0x6353:
		wenzi->SetWindowTextW(L"���ű�����");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 63;
	case 0x6553:
		wenzi->SetWindowTextW(L"�������Σ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"��");
		shuju->AddString(L"��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 64;
	case 0x6f53:
		if (length <= 6)
		{
			wenzi->SetWindowTextW(L"�ܼ��ȣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"����");
			shuju->AddString(L"�Ƽ�");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 65;
		}
		else
		{
			wenzi->SetWindowTextW(L"�ܼ���Χ��");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��Ů��");
			shuju->AddString(L"������������");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 66;
		}
	case 0x7453:
		wenzi->SetWindowTextW(L"��ʼʱ����");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"Զ��ʱ��");
		shuju->AddString(L"�ŵ�ʱ��");
		shuju->AddString(L"�й�ʱ��");
		shuju->AddString(L"����ʱ��");
		shuju->AddString(L"��ҵʱ��");
		shuju->AddString(L"����ʱ��");
		shuju->AddString(L"ԭ��ʱ��");
		shuju->AddString(L"��Ϣʱ��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 67;
	case 0x6154:
		wenzi->SetWindowTextW(L"��λ��ǩ��");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"��鵥λ");
		shuju->AddString(L"��ս��λ");
		shuju->AddString(L"Զ�̵�λ");
		shuju->AddString(L"���ǵ�λ");
		shuju->AddString(L"�����");
		shuju->AddString(L"�����");
		shuju->AddString(L"������");
		shuju->AddString(L"�����");
		shuju->AddString(L"��ս��");
		shuju->AddString(L"��ս��");
		shuju->AddString(L"�����");
		shuju->AddString(L"������ս");
		shuju->AddString(L"����Զ��");
		shuju->AddString(L"��������");
		shuju->AddString(L"����ĸ��");
		shuju->AddString(L"������");
		shuju->AddString(L"ҽ��");
		shuju->AddString(L"����");
		shuju->AddString(L"�ڽ̵�λ");
		shuju->AddString(L"����");
		shuju->AddString(L"����ʿ");
		shuju->AddString(L"�۲�����");
		shuju->AddString(L"ǰ���۲�");
		shuju->AddString(L"������");
		shuju->AddString(L"����ѧ��");
		shuju->AddString(L"����");
		shuju->AddString(L"������");
		shuju->AddString(L"���");
		shuju->AddString(L"����");
		shuju->AddString(L"��սʿ");
		shuju->AddString(L"����ֻ");
		shuju->AddString(L"������");
		shuju->AddString(L"���������");
		shuju->AddString(L"������");
		shuju->AddString(L"���յ�λ");
		shuju->AddString(L"ӡ��ս��");
		shuju->AddString(L"��ķ����");
		shuju->AddString(L"������");
		shuju->AddString(L"������");
		shuju->AddString(L"��װ����");
		shuju->AddString(L"ֱ����");
		shuju->AddString(L"U��Ǳͧ");
		shuju->AddString(L"�������");
		shuju->AddString(L"Ұ��ս����");
		shuju->AddString(L"����³��");
		shuju->AddString(L"������ս��");
		shuju->AddString(L"�ձ���ʿ");
		shuju->AddString(L"�ӳ����");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 68;
	case 0x6554:
		if (temp[4] == 'n')
		{
			wenzi->SetWindowTextW(L"�Ƽ����ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			for (j = 1;j <= technum;j++)
			{
				shuju->AddString(tech[j].name);
			}
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 69;
		}
		else if (temp[4] == 'T')
		{
			wenzi->SetWindowTextW(L"�Ƽ����ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			for (j = 1;j <= technum;j++)
			{
				shuju->AddString(tech[j].name);
			}
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 70;
		}
		else
		{
			wenzi->SetWindowTextW(L"�������ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��ԭ");
			shuju->AddString(L"��ԭ����");
			shuju->AddString(L"��ԭɽ��");
			shuju->AddString(L"ƽԭ");
			shuju->AddString(L"ƽԭ����");
			shuju->AddString(L"ƽԭɽ��");
			shuju->AddString(L"ɳĮ");
			shuju->AddString(L"ɳĮ����");
			shuju->AddString(L"ɳĮɽ��");
			shuju->AddString(L"����");
			shuju->AddString(L"��������");
			shuju->AddString(L"����ɽ��");
			shuju->AddString(L"ѩԭ");
			shuju->AddString(L"ѩԭ����");
			shuju->AddString(L"ѩԭɽ��");
			shuju->AddString(L"����");
			shuju->AddString(L"����");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 71;
		}
	case 0x7554:
		wenzi->SetWindowTextW(L"��Ч�غϣ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 87;
	case 0x6e55:
		if (temp[4] == 'D')
		{
			wenzi->SetWindowTextW(L"��λ���ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"½�ص�λ");
			shuju->AddString(L"����λ");
			shuju->AddString(L"���е�λ");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 72;
		}
		else if (temp[4] == 'P')
		{
			wenzi->SetWindowTextW(L"��λ���ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��ս��λ");
			shuju->AddString(L"Զ�̵�λ");
			shuju->AddString(L"�������λ");
			shuju->AddString(L"������ս��λ");
			shuju->AddString(L"����Զ�̵�λ");
			shuju->AddString(L"�������ӵ�λ");
			shuju->AddString(L"�������λ");
			shuju->AddString(L"�������λ");
			shuju->AddString(L"�վ�ս����λ");
			shuju->AddString(L"�վ���ը��λ");
			shuju->AddString(L"֧Ԯ��λ");
			shuju->AddString(L"����ĸ��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			if (length <= 18)
			{
				return 73;
			}
			else
			{
				return 74;
			}
		}
		else
		{
			wenzi->SetWindowTextW(L"��λ���ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			for (j = 1;j <= unitnum;j++)
			{
				shuju->AddString(unit[j].name);
			}
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 75;
		}
	case 0x6156:
		wenzi->SetWindowTextW(L"�Ƿ���Ч��");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"��");
		shuju->AddString(L"��");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 76;
	case 0x6959:
		if (temp[5] == 'B')
		{
			wenzi->SetWindowTextW(L"����������");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"��");
			shuju->AddString(L"��");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 77;
		}
		else if (temp[5] == 'T')
		{
			wenzi->SetWindowTextW(L"�������ͣ�");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->AddString(L"ʳ��");
			shuju->AddString(L"����");
			shuju->AddString(L"���");
			shuju->AddString(L"�Ļ�");
			shuju->AddString(L"����");
			shuju->AddString(L"����");
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 78;
		}
		else
		{
			wenzi->SetWindowTextW(L"�����䶯��");
			wenzi->ShowWindow(true);
			//shuju->ResetContent();
			shuju->SetCurSel(0);
			shuju->ShowWindow(true);
			return 88;
		}
	case 0x704f:
		wenzi->SetWindowTextW(L"�ж����ͣ�");
		wenzi->ShowWindow(true);
		//shuju->ResetContent();
		shuju->AddString(L"�ƻ��������");
		shuju->AddString(L"��ȡ��ϢԴ");
		shuju->AddString(L"��ȡ����");
		shuju->AddString(L"��ļ�λ���Ա");
		shuju->AddString(L"�ƻ�����");
		shuju->AddString(L"��ȡ�ʽ�");
		shuju->AddString(L"��ȡ�Ƽ�");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		return 79;
	default:
		wenzi->ShowWindow(false);
		//shuju->ResetContent();
		shuju->AddString(L"���²���Ϊ��ѡ����������ѡ��һ");
		shuju->SetCurSel(0);
		shuju->ShowWindow(true);
		kexuan = true;
		return -1;
	}

	wenzi->ShowWindow(false);
	shuju->ShowWindow(false);
	return 0;
}

CString project::fancanshu(CWnd * wenzi, CComboBox * shuju, int canshu)
{
	int i;
	CString str;
	static bool kexuan = false;

	if ((wenzi == NULL) && (shuju == NULL))
	{
		kexuan = false;
		return L"";
	}
	i = shuju->GetCurSel();
	shuju->GetWindowTextW(str);
	if (!str.Compare(L"��"))
	{
		if (!i)
		{
			return L"";
		}
		else
		{
			i--;
		}
	}
	if (canshu < 0)
	{
		kexuan = true;
		return L"";
	}
	if (kexuan)
	{
		i--;
	}
	switch (canshu)
	{
	case 0:
		return L"";
	default:
		//i = shuju->GetCurSel();
		if (i)
		{
			return L"false";
		}
		else
		{
			return L"true";
		}
	case 1:
		//i = shuju->GetCurSel();
		return ability[i + 1].type;
	case 3:
		//i = shuju->GetCurSel();
		if (i)
		{
			return L"DIPLOACTION_DECLARE_WAR_MINOR_CIV";
		}
		else
		{
			return L"DIPLOACTION_GRANT_INFLUENCE_TOKEN";
		}
	case 4:
	case 37:
	case 61:
		//i = shuju->GetCurSel();
		return gov[i];
	case 5:
	case 6:
	case 7:
	case 20:
	case 21:
	case 46:
	case 48:
	case 50:
	case 56:
	case 57:
	case 59:
	case 63:
	case 80:
	case 81:
	case 83:
	case 84:
	case 86:
	case 87:
	case 88:
		shuju->GetWindowTextW(str);
		return str;
	case 8:
		//i = shuju->GetCurSel();
		switch (i)
		{
		case 0:
		default:
			return L"GOVERNMENTBONUS_WONDER_CONSTRUCTION";
		case 1:
			return L"GOVERNMENTBONUS_COMBAT_EXPERIENCE";
		case 2:
			return L"GOVERNMENTBONUS_GREAT_PEOPLE";
		case 3:
			return L"GOVERNMENTBONUS_ENVOYS";
		case 4:
			return L"GOVERNMENTBONUS_FAITH_PURCHASES";
		case 5:
			return L"GOVERNMENTBONUS_GOLD_PURCHASES";
		case 6:
			return L"GOVERNMENTBONUS_UNIT_PRODUCTION";
		case 7:
			return L"GOVERNMENTBONUS_OVERALL_PRODUCTION";
		case 8:
			return L"GOVERNMENTBONUS_DISTRICT_PROJECTS";
		}
	case 10:
		//i = shuju->GetCurSel();
		return building[i + 1].type;
	case 16:
		//i = shuju->GetCurSel();
		return civic[i + 1].type;
	case 22:
		//i = shuju->GetCurSel();
		return dis[i];
	case 23:
	case 24:
	case 72:
		//i = shuju->GetCurSel();
		switch (i)
		{
		case 0:
		default:
			return L"DOMAIN_LAND";
		case 1:
			return L"DOMAIN_SEA";
		case 2:
			return L"DOMAIN_AIR";
		}
	case 27:
	case 29:
	case 67:
		//i = shuju->GetCurSel();
		return era[i];
	case 34:
		//i = shuju->GetCurSel();
		return fea[i];
	case 38:
		//i = shuju->GetCurSel();
		return fea[i];
	case 39:
		//i = shuju->GetCurSel();
		return jz[i];
	case 40:
		//i = shuju->GetCurSel();
		return jzc[i];
	case 44:
		//i = shuju->GetCurSel();
		return ip[i];
	case 47:
		//i = shuju->GetCurSel();
		if (i)
		{
			return L"GenerateSeaAntiquities";
		}
		else
		{
			return L"GenerateLandAntiquities";
		}
	case 49:
		//i = shuju->GetCurSel();
		return zongtexing[i + 1].type;
	case 58:
		//i = shuju->GetCurSel();
		return jinsheng[i + 1].type;
	case 62:
		//i = shuju->GetCurSel();
		return ziyuan[i + 1].type;
	case 65:
		//i = shuju->GetCurSel();
		if (i)
		{
			return L"SOURCE_TECH";
		}
		else
		{
			return L"SOURCE_TRAIT";
		}
	case 66:
		//i = shuju->GetCurSel();
		if (i)
		{
			return L"DIPLO_SOURCE_ALL_NAMES";
		}
		else
		{
			return L"DIPLO_SOURCE_FEMALE_ONLY";
		}
	case 68:
		//i = shuju->GetCurSel();
		return tag[i];
	case 69:
	case 70:
		//i = shuju->GetCurSel();
		return tech[i + 1].type;
	case 71:
		//i = shuju->GetCurSel();
		return ter[i];
	case 73:
	case 74:
		//i = shuju->GetCurSel();
		return ut[i];
	case 75:
		//i = shuju->GetCurSel();
		return unit[i + 1].type;
	case 78:
		//i = shuju->GetCurSel();
		return yie[i];
	case 79:
		//i = shuju->GetCurSel();
		switch (i)
		{
		case 0:
		default:
			return L"UNITOPERATION_SPY_DISRUPT_ROCKETRY";
		case 1:
			return L"UNITOPERATION_SPY_GAIN_SOURCES";
		case 2:
			return L"UNITOPERATION_SPY_GREAT_WORK_HEIST";
		case 3:
			return L"UNITOPERATION_SPY_RECRUIT_PARTISANS";
		case 4:
			return L"UNITOPERATION_SPY_SABOTAGE_PRODUCTION";
		case 5:
			return L"UNITOPERATION_SPY_SIPHON_FUNDS";
		case 6:
			return L"UNITOPERATION_SPY_STEAL_TECH_BOOST";
		}
	case 82:
		if (i == 0)
		{
			return L"WAR_DECLARATION_RECEIVED";
		}
		else if (i == 1)
		{
			return L"LIBERATION";
		}
		else
		{
			return L"SURPRISE_WAR_INITIATED";
		}
	}
}

int project::qian(void)
{
	int r;

	if (id != number)
	{
		p = p->qian;
	}
	id--;
	if (p->qian)
	{
		r = 1;
	}
	else
	{
		r = -1;
	}

	ck->m_tab.SetCurSel(p->type);
	switch (p->type)
	{
	case 0:
	default:
		fanjianzhu(&(ck->m_JianZhu));
		ck->m_JianZhu.ShowWindow(SW_SHOW);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 1:
		fanqiguan(&(ck->m_QiGuan));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_SHOW);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 2:
		fanwenming(&(ck->m_WenMing));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_SHOW);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 3:
		fanlingxiu(&(ck->m_LingXiu));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_SHOW);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 4:
		fankeji(&(ck->m_KeJi));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_SHOW);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 5:
		fandanwei(&(ck->m_DanWei));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_SHOW);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 6:
		fanzhengce(&(ck->m_ZhengCe));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_SHOW);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 7:
		fanxintiao(&(ck->m_XinTiao));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_SHOW);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 8:
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_SHOW);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 9:
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_SHOW);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 10:
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_SHOW);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 11:
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_SHOW);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 12:
		fantiaojian(&(ck->m_TiaoJian));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_SHOW);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 13:
		fantexing(&(ck->m_TeXing));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_SHOW);
		break;
	}
	//ck->PostMessage(TCN_SELCHANGE);
	//SendMessage(ck->GetSafeHwnd(), TCN_SELCHANGE, 0, 0);

	return r;
}

int project::hou(void)
{
	int r;

	if (p->hou)
	{
		p = p->hou;
		id++;
		r = 1;
	}
	else
	{
		id++;
		return -1;
	}

	ck->m_tab.SetCurSel(p->type);
	switch (p->type)
	{
	case 0:
	default:
		fanjianzhu(&(ck->m_JianZhu));
		ck->m_JianZhu.ShowWindow(SW_SHOW);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 1:
		fanqiguan(&(ck->m_QiGuan));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_SHOW);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 2:
		fanwenming(&(ck->m_WenMing));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_SHOW);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 3:
		fanlingxiu(&(ck->m_LingXiu));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_SHOW);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 4:
		fankeji(&(ck->m_KeJi));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_SHOW);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 5:
		fandanwei(&(ck->m_DanWei));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_SHOW);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 6:
		fanzhengce(&(ck->m_ZhengCe));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_SHOW);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 7:
		fanxintiao(&(ck->m_XinTiao));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_SHOW);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 8:
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_SHOW);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 9:
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_SHOW);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 10:
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_SHOW);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 11:
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_SHOW);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 12:
		fantiaojian(&(ck->m_TiaoJian));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_SHOW);
		ck->m_TeXing.ShowWindow(SW_HIDE);
		break;
	case 13:
		fantexing(&(ck->m_TeXing));
		ck->m_JianZhu.ShowWindow(SW_HIDE);
		ck->m_QiGuan.ShowWindow(SW_HIDE);
		ck->m_WenMing.ShowWindow(SW_HIDE);
		ck->m_LingXiu.ShowWindow(SW_HIDE);
		ck->m_KeJi.ShowWindow(SW_HIDE);
		ck->m_DanWei.ShowWindow(SW_HIDE);
		ck->m_ZhengCe.ShowWindow(SW_HIDE);
		ck->m_XinTiao.ShowWindow(SW_HIDE);
		ck->m_ZiYuan.ShowWindow(SW_HIDE);
		ck->m_JuZuo.ShowWindow(SW_HIDE);
		ck->m_WeiRen.ShowWindow(SW_HIDE);
		ck->m_ZiRanQiGuan.ShowWindow(SW_HIDE);
		ck->m_TiaoJian.ShowWindow(SW_HIDE);
		ck->m_TeXing.ShowWindow(SW_SHOW);
		break;
	}

	return r;
}
