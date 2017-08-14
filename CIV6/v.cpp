#include "stdafx.h"
#include "v.h"


CString dis[] = {
	L"DISTRICT_CITY_CENTER",
	L"DISTRICT_HOLY_SITE",
	L"DISTRICT_CAMPUS",
	L"DISTRICT_ENCAMPMENT",
	L"DISTRICT_HARBOR",
	L"DISTRICT_COMMERCIAL_HUB",
	L"DISTRICT_ENTERTAINMENT_COMPLEX",
	L"DISTRICT_THEATER",
	L"DISTRICT_AQUEDUCT",
	L"DISTRICT_INDUSTRIAL_ZONE",
	L"DISTRICT_NEIGHBOURHOOD",
	L"DISTRICT_AERODROME",
	L"DISTRICT_SPACEPORT",
	L"DISTRICT_MBANZA",
	L"DISTRICT_LAVRA"
	L"DISTRICT_ACROPOLIS",
	L"DISTRICT_BATH",
	L"DISTRICT_HANSA"
	L"DISTRICT_STREET_CARNIVAL",
	L"DISTRICT_ROYAL_NAVY_DOCKYARD",
	L"DISTRICT_WONDER"
};

CString yie[] = {
	L"YIELD_FOOD",
	L"YIELD_PRODUCTION",
	L"YIELD_GOLD",
	L"YIELD_CULTURE",
	L"YIELD_SCIENCE",
	L"YIELD_FAITH"
};

CString xt[] = {
	L"BELIEF_CLASS_PANTHEON",
	L"BELIEF_CLASS_FOLLOWER",
	L"BELIEF_CLASS_WORSHIP",
	L"BELIEF_CLASS_FOUNDER",
	L"BELIEF_CLASS_ENHANCER"
};

CString zj[] = {
	L"Pa",
	L"Bu",
	L"Ca",
	L"Co",
	L"Hi",
	L"Is",
	L"Ju",
	L"Or",
	L"Pr",
	L"Sh",
	L"Si",
	L"Ta",
	L"Zo",
	L"01",
	L"02",
	L"03",
	L"04",
	L"05",
	L"06",
	L"07",
	L"08",
	L"09",
	L"10",
	L"11",
	L"12"
};

CString pur[] = {
	L"YIELD_GOLD",
	L"YIELD_FAITH"
};

CString advi[] = {
	L"ADVISOR_CULTURE",
	L"ADVISOR_CONQUEST",
	L"ADVISOR_GENERIC",
	L"ADVISOR_TECHNOLOGY",
	L"ADVISOR_RELIGIOUS"
};

CString ter[] = {
	L"TERRAIN_GRASS",
	L"TERRAIN_GRASS_HILLS",
	L"TERRAIN_GRASS_MOUNTAIN",
	L"TERRAIN_PLAINS",
	L"TERRAIN_PLAINS_HILLS",
	L"TERRAIN_PLAINS_MOUNTAIN",
	L"TERRAIN_DESERT",
	L"TERRAIN_DESERT_HILLS",
	L"TERRAIN_DESERT_MOUNTAIN",
	L"TERRAIN_TUNDRA",
	L"TERRAIN_TUNDRA_HILLS",
	L"TERRAIN_TUNDRA_MOUNTAIN",
	L"TERRAIN_SNOW",
	L"TERRAIN_SNOW_HILLS",
	L"TERRAIN_SNOW_MOUNTAIN",
	L"TERRAIN_COAST",
	L"TERRAIN_OCEAN"
};

CString fea[] = {
	L"FEATURE_FLOODPLAINS",
	L"FEATURE_ICE",
	L"FEATURE_JUNGLE",
	L"FEATURE_FOREST",
	L"FEATURE_OASIS",
	L"FEATURE_MARSH",
	L"FEATURE_BARRIER_REEF",
	L"FEATURE_CLIFFS_DOVER",
	L"FEATURE_CRATER_LAKE",
	L"FEATURE_DEAD_SEA",
	L"FEATURE_EVEREST",
	L"FEATURE_GALAPAGOS",
	L"FEATURE_KILIMANJARO",
	L"FEATURE_PANTANAL",
	L"FEATURE_PIOPIOTAHI",
	L"FEATURE_TORRES_DEL_PAINE",
	L"FEATURE_TSINGY",
	L"FEATURE_YOSEMITE",
	L"FEATURE_EYJAFJALLAJOKULL",
	L"FEATURE_LYSEFJORDEN",
	L"FEATURE_GIANTS_CAUSEWAY"
};

CString era[] = {
	L"ERA_ANCIENT",
	L"ERA_CLASSICAL",
	L"ERA_MEDIEVAL",
	L"ERA_RENAISSANCE",
	L"ERA_INDUSTRIAL",
	L"ERA_MODERN",
	L"ERA_ATOMIC",
	L"ERA_INFORMATION"
};

CString gov[] = {
	L"SLOT_MILITARY",
	L"SLOT_ECONOMIC",
	L"SLOT_DIPLOMATIC",
	L"SLOT_WILDCARD"
};

CString gp[] = {
	L"GREAT_PERSON_CLASS_PROPHET",
	L"GREAT_PERSON_CLASS_GENERAL",
	L"GREAT_PERSON_CLASS_ADMIRAL",
	L"GREAT_PERSON_CLASS_SCIENTIST",
	L"GREAT_PERSON_CLASS_ENGINEER",
	L"GREAT_PERSON_CLASS_MERCHANT",
	L"GREAT_PERSON_CLASS_WRITER",
	L"GREAT_PERSON_CLASS_ARTIST",
	L"GREAT_PERSON_CLASS_MUSICIAN"
};

CString jz[] = {
	L"GREATWORKOBJECT_RELIC",
	L"GREATWORKOBJECT_SCULPTURE",
	L"GREATWORKOBJECT_ARTIFACT",
	L"GREATWORKOBJECT_PORTRAIT",
	L"GREATWORKOBJECT_LANDSCAPE",
	L"GREATWORKOBJECT_RELIGIOUS",
	L"GREATWORKOBJECT_MUSIC"
};

CString jzc[] = {
	L"GREATWORKSLOT_PALACE",
	L"GREATWORKSLOT_ARTIFACT",
	L"GREATWORKSLOT_RELIC",
	L"GREATWORKSLOT_WRITING",
	L"GREATWORKSLOT_ART",
	L"GREATWORKSLOT_MUSIC",
	L"GREATWORKSLOT_CATHEDRAL"
};

CString ut[] = {
	L"PROMOTION_CLASS_RECON",
	L"PROMOTION_CLASS_MELEE",
	L"PROMOTION_CLASS_RANGED",
	L"PROMOTION_CLASS_SIEGE",
	L"PROMOTION_CLASS_ANTI_CAVALRY",
	L"PROMOTION_CLASS_NAVAL_MELEE",
	L"PROMOTION_CLASS_NAVAL_RANGED",
	L"PROMOTION_CLASS_NAVAL_RAIDER",
	L"PROMOTION_CLASS_HEAVY_CAVALRY",
	L"PROMOTION_CLASS_LIGHT_CAVALRY",
	L"PROMOTION_CLASS_AIR_FIGHTER",
	L"PROMOTION_CLASS_AIR_BOMBER",
	L"PROMOTION_CLASS_NAVAL_CARRIER",
	L"PROMOTION_CLASS_SUPPORT",
	L"PROMOTION_CLASS_APOSTLE"
};

CString tag[] = {
	L"CLASS_LANDCIVILIAN",
	L"CLASS_RECON",
	L"CLASS_MELEE",
	L"CLASS_RANGED",
	L"CLASS_SIEGE",
	L"CLASS_HEAVY_CAVALRY",
	L"CLASS_LIGHT_CAVALRY",
	L"CLASS_RANGED_CAVALRY",
	L"CLASS_ANTI_CAVALRY",
	L"CLASS_HEAVY_CHARIOT",
	L"CLASS_LIGHT_CHARIOT",
	L"CLASS_BATTERING_RAM",
	L"CLASS_NAVAL_MELEE",
	L"CLASS_NAVAL_RANGED",
	L"CLASS_NAVAL_RAIDER",
	L"CLASS_NAVAL_CARRIER",
	L"CLASS_SIEGE_TOWER",
	L"CLASS_MEDIC",
	L"CLASS_TRADER",
	L"CLASS_RELIGIOUS",
	L"CLASS_INQUISITOR",
	L"CLASS_MISSIONARY",
	L"CLASS_OBSERVATION",
	L"CLASS_FORWARD_OBSERVER",
	L"CLASS_AIRCRAFT",
	L"CLASS_ARCHAEOLOGIST",
	L"CLASS_STEALTH",
	L"CLASS_REVEAL_STEALTH",
	L"CLASS_SPY",
	L"CLASS_LONGSHIP",
	L"CLASS_MELEE_BERSERKER",
	L"CLASS_CAPTURE_SHIPS",
	L"CLASS_CAPTURE_WORKER",
	L"CLASS_COSSACK",
	L"CLASS_REDCOAT",
	L"CLASS_ANTI_AIR",
	L"CLASS_VARU",
	L"CLASS_NAGAO",
	L"CLASS_CONQUISTADOR",
	L"CLASS_GARDE",
	L"CLASS_HOPLITE",
	L"CLASS_HELICOPTER",
	L"CLASS_UBOAT",
	L"CLASS_ROUGH_RIDER",
	L"CLASS_MUSTANG",
	L"CLASS_MAMLUK",
	L"CLASS_WAR_CART",
	L"CLASS_SAMURAI",
	//L"CLASS_PUSHBACK",
	L"CLASS_DIGGER"
};

CString ip[] = {
	L"IMPROVEMENT_BARBARIAN_CAMP",
	L"IMPROVEMENT_FARM",
	L"IMPROVEMENT_MINE",
	L"IMPROVEMENT_QUARRY",
	L"IMPROVEMENT_FISHING_BOATS",
	L"IMPROVEMENT_PASTURE",
	L"IMPROVEMENT_PLANTATION",
	L"IMPROVEMENT_CAMP",
	L"IMPROVEMENT_LUMBER_MILL",
	L"IMPROVEMENT_GOODY_HUT",
	L"IMPROVEMENT_OIL_WELL",
	L"IMPROVEMENT_OFFSHORE_OIL_RIG",
	L"IMPROVEMENT_FORT",
	L"IMPROVEMENT_AIRSTRIP",
	L"IMPROVEMENT_BEACH_RESORT",
	L"IMPROVEMENT_MISSILE_SILO",
	L"IMPROVEMENT_CHATEAU",
	L"IMPROVEMENT_COLOSSAL_HEAD",
	L"IMPROVEMENT_GREAT_WALL",
	L"IMPROVEMENT_KURGAN",
	L"IMPROVEMENT_MISSION",
	L"IMPROVEMENT_ROMAN_FORT",
	L"IMPROVEMENT_SPHINX",
	L"IMPROVEMENT_STEPWELL",
	L"IMPROVEMENT_ZIGGURAT"
};

CString qiyuan[] = {
	L"ETHNICITY_EURO",
	L"ETHNICITY_ASIAN",
	L"ETHNICITY_MEDIT",
	L"ETHNICITY_AFRICAN",
	L"ETHNICITY_SOUTHAM"
};

CString zhanlue[] = {
	L"RESOURCE_ALUMINUM",
	L"RESOURCE_COAL",
	L"RESOURCE_HORSES",
	L"RESOURCE_IRON",
	L"RESOURCE_NITER",
	L"RESOURCE_OIL",
	L"RESOURCE_URANIUM",
	L"RESOURCE_ANTIQUITY_SITE",
	L"RESOURCE_SHIPWRECK"
};

CString chuancheng[] = {
	L"NO_GOVERNMENTBONUS",
	L"GOVERNMENTBONUS_WONDER_CONSTRUCTION",
	L"GOVERNMENTBONUS_COMBAT_EXPERIENCE",
	L"GOVERNMENTBONUS_GREAT_PEOPLE",
	L"GOVERNMENTBONUS_ENVOYS",
	L"GOVERNMENTBONUS_FAITH_PURCHASES",
	L"GOVERNMENTBONUS_GOLD_PURCHASES",
	L"GOVERNMENTBONUS_UNIT_PRODUCTION",
	L"GOVERNMENTBONUS_OVERALL_PRODUCTION",
	L"GOVERNMENTBONUS_DISTRICT_PROJECTS"
};

CString argstr[] = {
	L"",//0
	L"AbilityType",//1
	L"Access",
	L"Action",
	L"AddedGovernmentSlotType",
	L"Amount",
	L"Bonus",
	L"BonusRate",
	L"BonusType",
	L"BoostsWonders",
	L"BuildingType",
	L"Bypass",
	L"CanAttack",
	L"CanCapture",
	L"CanMove",
	L"CanRaid",
	L"CivicType",
	L"Converts",
	L"ConvertsCity",
	L"Corps",
	L"DefenseValue",
	L"Discount",
	L"DistrictType",
	L"Domain",
	L"DomainType",
	L"Domestic",
	L"Enable",
	L"EndEraType",
	L"Enemy",
	L"EraType",
	L"EscortMobility",
	L"Exert",
	L"Extract",
	L"Favored",
	L"FeatureType",
	L"Founder",
	L"ForceRetreat",
	L"GovernmentSlotType",
	L"GreatPersonClass",
	L"GreatWorkObjectType",
	L"GreatWorkSlotType",//40
	L"HasBonus",
	L"Hidden",
	L"Ignore",
	L"ImprovementType",
	L"Intercontinental",
	L"MaxDistance",
	L"MechanicName",
	L"MinDistance",
	L"ModifierId",
	L"Multiplier",
	L"MustReplaceImprovement",
	L"NoReduction",
	L"Offense",
	L"OnlyWhenDefeatedEarlierEraUnit",
	L"Overall",
	L"Percent",
	L"PercentDefeatedStrength",
	L"PromotionType",
	L"Range",
	L"RelicUponDeath",
	L"ReplacedGovernmentSlotType",
	L"ResourceType",
	L"ScalingFactor",
	L"SeeHidden",
	L"Source",
	L"SourceType",
	L"StartEraType",
	L"Tag",
	L"TechnologyType",
	L"TechType",
	L"TerrainType",
	L"UnitDomain",
	L"UnitPromotionClass",
	L"UnitPromotionClassType",
	L"UnitType",
	L"Valid",
	L"YieldBasedOnAppeal",
	L"YieldType",
	L"OperationType",
	L"ReductionPercent",//80
	L"Description",//描述
	L"DiplomaticYieldSource",//外交情况
	L"ImprovedRouteLevel",//道路等级
	L"MaxPercent",//最大比例
	L"NoPenalties",//没有惩罚
	L"RequiredAppeal",//魅力需求
	L"TurnsActive",//有效回合
	L"YieldChange"//产出变动
};

int tc[][8] = {//分别表示单位类型、数量、改良设施、建筑类型、资源类型、研究科技、研究市政、城区类型的有无
	{ 1,0,0,0,0,0,0,0 },//1
	{ 1,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0 },
	{ 1,1,0,0,0,0,0,0 },//10
	{ 0,0,0,0,0,1,0,0 },
	{ 0,0,1,0,1,0,0,0 },
	{ 1,1,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,1 },
	{ 0,1,0,0,0,0,0,0 },
	{ 1,1,0,0,0,0,0,0 },
	{ 0,1,0,1,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 1,1,0,0,0,0,0,0 },//20
	{ 0,1,0,0,0,0,0,1 },
	{ 0,1,2,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 1,1,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },//30
	{ 0,1,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,1,0 },//40
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,1,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,1 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 1,0,0,0,0,0,0,0 },//50
	{ 0,0,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,0,0,0,0,0,0,0 },
	{ 0,1,0,0,0,0,0,0 },
	{ 0,1,0,0,1,0,0,0 },//59
};

project * pro = NULL;
CFile dat;
struct civ6 * building = NULL;
int buildingnum = 0;
struct civ6 * tech = NULL;
int technum = 0;
struct civ6 * civic = NULL;
int civicnum = 0;
struct civ666 * texing = NULL;
int texingnum = 0;
struct civ666 * tiaojian = NULL;
int tiaojiannum = 0;
struct civ6 * zongtexing = NULL;
int zongtexingnum = 0;
struct civ6 * zongtiaojian = NULL;
int zongtiaojiannum = 0;
struct civ6 * ziyuan = NULL;
int ziyuannum = 0;
struct civ6 * ability = NULL;
int abilitynum = 0;
struct civ6 * jinsheng = NULL;
int jinshengnum = 0;
struct civ6 * unit = NULL;
int unitnum = 0;
struct civ6 * wenming = NULL;
int wenmingnum = 0;
struct civ6 * yicheng = NULL;
int yichengnum = 0;
struct civ6 * tisheng = NULL;
int tishengnum = 0;
struct civ6 * zhengce = NULL;
int zhengcenum = 0;