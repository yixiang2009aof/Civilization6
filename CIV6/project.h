#pragma once

#include "CIV6Dlg.h"

#define MAXLENGTH 4084

struct table
{
	int id;//�����
	int type;//���ͣ�������ţ�
	int length;//���ݳ���
	char data[MAXLENGTH];//����
	struct table * qian = NULL;//ǰһ������ָ��
	struct table * hou = NULL;//��һ������ָ��
};

struct jilu
{
	int leixing;//��¼����������
	//int type;//��Ҫ����������ݵ���ţ��罨���ı�ţ�
	CString yuan;//��Ҫ����������ݵ������ַ���
	CString str;//��Ҫ���������
	struct jilu * next = NULL;//��һ����¼
};
/*��¼�������ͣ�
0��������ɫ����
1��������ɫ��λ
2��������ɫ����
2��������ɫ��λ
*/


struct xmljianzhu
{
	CString Buildings;//����
	CString BuildingReplaces;//�滻����
	CString BuildingPrereqs;//ǰ�ý���
	CString MutuallyExclusiveBuildings;//���⽨��
	CString Building_YieldChanges;//��������
	CString BuildingModifiers;//��������
	CString Building_GreatPersonPoints;//����ΰ�˵���
	CString Building_GreatWorks;//����������
	CString Building_RequiredFeatures;//���������ò
	CString Building_ValidFeatures;//������Ч��ò
	CString Building_ValidTerrains;//������Ч����
};

struct xmlwenming
{
	CString Civilizations;//����
	CString Traits;//Ч��
	CString CivilizationTraits;//����Ч��
	CString CityNames;//������
	CString StartBiasResources;//������Դ
	CString StartBiasFeatures;//������ò
	CString StartBiasTerrains;//��������
	CString StartBiasRivers;//��������
	CString CivilizationCitizenNames;//��������
	CString CivilizationInfo;//�����ٿ�
};

struct xmllingxiu
{
	CString Leaders;//����
	CString LeaderQuotes;//��������
	CString HistoricalAgendas;//��ʷ���
	CString CivilizationLeaders;//��������
	CString LeaderTraits;//��������
	CString AgendaPreferredLeaders;//��ѡ���
	CString Colors;//��ɫ
	CString PlayerColors;//�����ɫ
	CString AiListTypes;//AI����
	CString AiLists;//AI�б�
	CString AiFavoredItems;//AIϲ��
};

struct xmlkejishizheng
{
	CString Technologies;//�Ƽ�
	CString TechnologyPrereqs;//ǰ�ÿƼ�
	CString TechnologyQuotes;//�Ƽ�����
	CString TechnologyModifiers;//�Ƽ�����
	CString Civics;//����
	CString CivicPrereqs;//ǰ������
	CString CivicQuotes;//��������
	CString CivicModifiers;//��������
	CString Boosts;//����
};

struct xmldanwei
{
	CString Units;//��λ
	CString Tags;//��ǩ
	CString TypeTags;//��λ��ǩ
	CString UnitUpgrades;//��λ����
	CString Unit_BuildingPrereqs;//��λǰ�ý���
	CString UnitAiInfos;//��λAI��Ϣ
	CString UnitAbilities;//��λ����
	CString UnitAbilityModifiers;//��λ��������
	CString UnitReplaces;//�滻��λ
	CString UnitCaptures;//��λ����
};

struct xmlzhengcezhengti
{
	CString Policies;//����
	CString ObsoletePolicies;//��ʱ����
	CString PolicyModifiers;//��������
	CString Governments;//����
	CString Government_SlotCounts;//�����λ
	CString GovernmentModifiers;//��������
};

struct xmlxintiao
{
	CString Beliefs;//����
	CString BeliefModifiers;//��������
	CString Religions;//�ڽ�
};

class project
{
public:
	project();
	project(CFile * f);//�����ļ�ָ���ȡ���ݴ�������
	~project();
	CCIV6Dlg * ck;//���ھ��ָ��
	int number;//���м�¼����
	void baocun(CFile * f);//��������������Ϣ��һ���ļ���
	void baocunone(CFile * f);//���汾�β�����Ϣ
	void jianzhu(DLG_JianZhu * dhk);//������������Ϣ����������
	void fanjianzhu(DLG_JianZhu * dhk);//�������е����ݻ�ԭ������������
	void shengjianzhu(char * tt, int length);//���������е����������ַ���
	void qiguan(DLG_QiGuan * dhk);//����۽�����Ϣ����������
	void fanqiguan(DLG_QiGuan * dhk);//�������е����ݻ�ԭ����۽�����
	void shengqiguan(char * tt, int length);//���������е����������ַ���
	void wenming(DLG_WenMing * dhk);//������������Ϣ����������
	void fanwenming(DLG_WenMing * dhk);//�������е����ݻ�ԭ������������
	void shengwenming(char * tt, int length);//���������е����������ַ���
	void lingxiu(DLG_LingXiu * dhk);//�����������Ϣ����������
	void fanlingxiu(DLG_LingXiu * dhk);//�������е����ݻ�ԭ�����������
	void shenglingxiu(char * tt, int length);//���������е����������ַ���
	void keji(DLG_KeJi * dhk);//���Ƽ�������Ϣ����������
	void fankeji(DLG_KeJi * dhk);//�������е����ݻ�ԭ���Ƽ�������
	void shengkeji(char * tt, int length);//���������е����������ַ���
	void danwei(DLG_DanWei * dhk);//����λ������Ϣ����������
	void fandanwei(DLG_DanWei * dhk);//�������е����ݻ�ԭ����λ������
	void shengdanwei(char * tt, int length);//���������е����������ַ���
	void zhengce(DLG_ZhengCe * dhk);//�����߽�����Ϣ����������
	void fanzhengce(DLG_ZhengCe * dhk);//�������е����ݻ�ԭ�����߽�����
	void shengzhengce(char * tt, int length);//���������е����������ַ���
	void xintiao(DLG_XinTiao * dhk);//������������Ϣ����������
	void fanxintiao(DLG_XinTiao * dhk);//�������е����ݻ�ԭ������������
	void shengxintiao(char * tt, int length);//���������е����������ַ���
	void tiaojian(DLG_TiaoJian * dhk);//������������Ϣ����������
	void fantiaojian(DLG_TiaoJian * dhk);//�������е����ݻ�ԭ������������
	void shengtiaojian(char * tt, int length);//���������е����������ַ���
	void texing(DLG_TeXing * dhk);//�����Խ�����Ϣ����������
	void fantexing(DLG_TeXing * dhk);//�������е����ݻ�ԭ�����Խ�����
	void shengtexing(char * tt, int length);//���������е����������ַ���
	void xinjian(void);//�½���Ϣ��������ָ������ĩβ
	int shanchu(void);//ɾ����ǰָ������
	int shengcheng(CString name, CString zuozhe, CString miaoshu, CString mulu, CString zhongwen);//������������DLC
	int canshu(CWnd * wenzi, CComboBox * shuju, CString canshu);//���ݲ����ַ����޸Ŀؼ��������ر��
	CString fancanshu(CWnd * wenzi, CComboBox * shuju, int canshu);//���ݱ�źͿؼ����ز����ַ���
	int qian(void);//������ָ��ǰ��һ����ط�0Ϊ�ɹ�������1��ʾ���ܼ���ǰ�ƣ�-1��ʾ���ܼ���ǰ��
	int hou(void);//������ָ�����һ�����1��ʾ���ܼ������ƣ�-1��ʾ�Ѿ��ƶ�����һ��������
private:
	int id;//��ǰ��¼
	struct table * root;//��¼˫�������ָ��
	struct table * p;//��ǰ����ָ��
	struct jilu * jlroot;//��¼��ĸ��ڵ�ָ��
	struct jilu * jlp;//��¼��ǰָ��
	CString Type;//����
	CString Modifiers;//����
	CString ModifierArguments;//���Բ���
	CString ModifierStrings;//��������
	CString TraitModifiers;//Ч������
	CString Players;//���
	CString PlayerItems;//�����Ʒ
	CString RequirementSets;//������
	CString RequirementSetRequirements;//����������
	CString Requirements;//����
	CString RequirementArguments;//��������
	CString Text;//�����ı�
	struct xmljianzhu JianZhu;//����
	struct xmlwenming WenMing;//����
	struct xmllingxiu LingXiu;//����
	struct xmlkejishizheng KeJiShiZheng;//�Ƽ�����
	struct xmldanwei DanWei;//��λ
	struct xmlzhengcezhengti ZhengCeZhengTi;//��������
	struct xmlxintiao XinTiao;//����
};

