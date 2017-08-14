#pragma once

#include "CIV6Dlg.h"

#define MAXLENGTH 4084

struct table
{
	int id;//表序号
	int type;//类型（界面序号）
	int length;//数据长度
	char data[MAXLENGTH];//数据
	struct table * qian = NULL;//前一个链表指针
	struct table * hou = NULL;//后一个链表指针
};

struct jilu
{
	int leixing;//记录的数据类型
	//int type;//需要处理这个数据的序号（如建筑的编号）
	CString yuan;//需要处理这个数据的类型字符串
	CString str;//需要处理的数据
	struct jilu * next = NULL;//下一个记录
};
/*记录数据类型：
0：文明特色建筑
1：文明特色单位
2：领袖特色建筑
2：领袖特色单位
*/


struct xmljianzhu
{
	CString Buildings;//建筑
	CString BuildingReplaces;//替换建筑
	CString BuildingPrereqs;//前置建筑
	CString MutuallyExclusiveBuildings;//互斥建筑
	CString Building_YieldChanges;//建筑产出
	CString BuildingModifiers;//建筑特性
	CString Building_GreatPersonPoints;//建筑伟人点数
	CString Building_GreatWorks;//建筑巨作槽
	CString Building_RequiredFeatures;//建筑需求地貌
	CString Building_ValidFeatures;//建筑有效地貌
	CString Building_ValidTerrains;//建筑有效地形
};

struct xmlwenming
{
	CString Civilizations;//文明
	CString Traits;//效果
	CString CivilizationTraits;//文明效果
	CString CityNames;//城市名
	CString StartBiasResources;//关联资源
	CString StartBiasFeatures;//关联地貌
	CString StartBiasTerrains;//关联地形
	CString StartBiasRivers;//关联河流
	CString CivilizationCitizenNames;//文明姓名
	CString CivilizationInfo;//文明百科
};

struct xmllingxiu
{
	CString Leaders;//领袖
	CString LeaderQuotes;//领袖引述
	CString HistoricalAgendas;//历史议程
	CString CivilizationLeaders;//文明领袖
	CString LeaderTraits;//领袖特性
	CString AgendaPreferredLeaders;//首选议程
	CString Colors;//颜色
	CString PlayerColors;//玩家颜色
	CString AiListTypes;//AI类型
	CString AiLists;//AI列表
	CString AiFavoredItems;//AI喜好
};

struct xmlkejishizheng
{
	CString Technologies;//科技
	CString TechnologyPrereqs;//前置科技
	CString TechnologyQuotes;//科技引述
	CString TechnologyModifiers;//科技特性
	CString Civics;//市政
	CString CivicPrereqs;//前置市政
	CString CivicQuotes;//市政引述
	CString CivicModifiers;//市政特性
	CString Boosts;//提升
};

struct xmldanwei
{
	CString Units;//单位
	CString Tags;//标签
	CString TypeTags;//单位标签
	CString UnitUpgrades;//单位升级
	CString Unit_BuildingPrereqs;//单位前置建筑
	CString UnitAiInfos;//单位AI信息
	CString UnitAbilities;//单位能力
	CString UnitAbilityModifiers;//单位能力特性
	CString UnitReplaces;//替换单位
	CString UnitCaptures;//单位捕获
};

struct xmlzhengcezhengti
{
	CString Policies;//政策
	CString ObsoletePolicies;//过时政策
	CString PolicyModifiers;//政策特性
	CString Governments;//政体
	CString Government_SlotCounts;//政体槽位
	CString GovernmentModifiers;//政体特性
};

struct xmlxintiao
{
	CString Beliefs;//信条
	CString BeliefModifiers;//信条特性
	CString Religions;//宗教
};

class project
{
public:
	project();
	project(CFile * f);//根据文件指针读取数据创建链表
	~project();
	CCIV6Dlg * ck;//窗口句柄指针
	int number;//现有记录数量
	void baocun(CFile * f);//保存所有链表信息到一个文件中
	void baocunone(CFile * f);//保存本次操作信息
	void jianzhu(DLG_JianZhu * dhk);//将建筑界面信息制作成链表
	void fanjianzhu(DLG_JianZhu * dhk);//将链表中的数据还原到建筑界面中
	void shengjianzhu(char * tt, int length);//根据链表中的数据生成字符串
	void qiguan(DLG_QiGuan * dhk);//将奇观界面信息制作成链表
	void fanqiguan(DLG_QiGuan * dhk);//将链表中的数据还原到奇观界面中
	void shengqiguan(char * tt, int length);//根据链表中的数据生成字符串
	void wenming(DLG_WenMing * dhk);//将文明界面信息制作成链表
	void fanwenming(DLG_WenMing * dhk);//将链表中的数据还原到文明界面中
	void shengwenming(char * tt, int length);//根据链表中的数据生成字符串
	void lingxiu(DLG_LingXiu * dhk);//将领袖界面信息制作成链表
	void fanlingxiu(DLG_LingXiu * dhk);//将链表中的数据还原到领袖界面中
	void shenglingxiu(char * tt, int length);//根据链表中的数据生成字符串
	void keji(DLG_KeJi * dhk);//将科技界面信息制作成链表
	void fankeji(DLG_KeJi * dhk);//将链表中的数据还原到科技界面中
	void shengkeji(char * tt, int length);//根据链表中的数据生成字符串
	void danwei(DLG_DanWei * dhk);//将单位界面信息制作成链表
	void fandanwei(DLG_DanWei * dhk);//将链表中的数据还原到单位界面中
	void shengdanwei(char * tt, int length);//根据链表中的数据生成字符串
	void zhengce(DLG_ZhengCe * dhk);//将政策界面信息制作成链表
	void fanzhengce(DLG_ZhengCe * dhk);//将链表中的数据还原到政策界面中
	void shengzhengce(char * tt, int length);//根据链表中的数据生成字符串
	void xintiao(DLG_XinTiao * dhk);//将信条界面信息制作成链表
	void fanxintiao(DLG_XinTiao * dhk);//将链表中的数据还原到信条界面中
	void shengxintiao(char * tt, int length);//根据链表中的数据生成字符串
	void tiaojian(DLG_TiaoJian * dhk);//将条件界面信息制作成链表
	void fantiaojian(DLG_TiaoJian * dhk);//将链表中的数据还原到条件界面中
	void shengtiaojian(char * tt, int length);//根据链表中的数据生成字符串
	void texing(DLG_TeXing * dhk);//将特性界面信息制作成链表
	void fantexing(DLG_TeXing * dhk);//将链表中的数据还原到特性界面中
	void shengtexing(char * tt, int length);//根据链表中的数据生成字符串
	void xinjian(void);//新建信息，将链表指针移至末尾
	int shanchu(void);//删除当前指向链表
	int shengcheng(CString name, CString zuozhe, CString miaoshu, CString mulu, CString zhongwen);//根据链表生成DLC
	int canshu(CWnd * wenzi, CComboBox * shuju, CString canshu);//根据参数字符串修改控件，并返回编号
	CString fancanshu(CWnd * wenzi, CComboBox * shuju, int canshu);//根据编号和控件返回参数字符串
	int qian(void);//将链表指针前移一项，返回非0为成功，其中1表示还能继续前移，-1表示不能继续前移
	int hou(void);//将链表指针后移一项，返回1表示还能继续后移，-1表示已经移动到下一个链表项
private:
	int id;//当前记录
	struct table * root;//记录双向链表根指针
	struct table * p;//当前链表指针
	struct jilu * jlroot;//记录表的根节点指针
	struct jilu * jlp;//记录表当前指针
	CString Type;//类型
	CString Modifiers;//特性
	CString ModifierArguments;//特性参数
	CString ModifierStrings;//特性文字
	CString TraitModifiers;//效果特性
	CString Players;//玩家
	CString PlayerItems;//玩家物品
	CString RequirementSets;//条件集
	CString RequirementSetRequirements;//条件集条件
	CString Requirements;//条件
	CString RequirementArguments;//条件参数
	CString Text;//汉化文本
	struct xmljianzhu JianZhu;//建筑
	struct xmlwenming WenMing;//文明
	struct xmllingxiu LingXiu;//领袖
	struct xmlkejishizheng KeJiShiZheng;//科技市政
	struct xmldanwei DanWei;//单位
	struct xmlzhengcezhengti ZhengCeZhengTi;//政策政体
	struct xmlxintiao XinTiao;//信条
};

