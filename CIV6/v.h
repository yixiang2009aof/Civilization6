#pragma once

#include "stdafx.h"
#include "project.h"
#include "building.h"
#include "tech.h"
#include "civic.h"
#include "zongtexing.h"
#include "zongtiaojian.h"
#include "texing.h"
#include "tiaojian.h"
#include "ziyuan.h"
#include "ability.h"
#include "jinsheng.h"
#include "unit.h"
#include "wenming.h"
#include "yicheng.h"
#include "tisheng.h"
#include "zhengce.h"


extern CString dis[];
extern CString yie[];
extern CString xt[];
extern CString zj[];
extern CString pur[];
extern CString advi[];
extern CString ter[];
extern CString fea[];
extern CString era[];
extern CString gov[];
extern CString gp[];
extern CString jz[];
extern CString jzc[];
extern CString ut[];
extern CString tag[];
extern CString ip[];
extern CString qiyuan[];
extern CString zhanlue[];
extern CString chuancheng[];
extern CString argstr[];
extern int tc[][8];

struct civ6
{
	int id;
	CString type;
	CString name;
};


struct civ666
{
	int id;
	CString type;
	CString name;
	CString arg1;
	CString arg2;
	CString arg3;
	CString arg4;
	CString arg5;
	CString arg6;
	CString arg7;
	CString arg8;
};

extern struct civ6 * building;
extern project * pro;
extern CFile dat;
extern int buildingnum;
extern struct civ6 * tech;
extern int technum;
extern struct civ6 * civic;
extern int civicnum;
extern struct civ666 * texing;
extern int texingnum;
extern struct civ666 * tiaojian;
extern int tiaojiannum;
extern struct civ6 * zongtexing;
extern int zongtexingnum;
extern struct civ6 * zongtiaojian;
extern int zongtiaojiannum;
extern struct civ6 * ziyuan;
extern int ziyuannum;
extern struct civ6 * ability;
extern int abilitynum;
extern struct civ6 * jinsheng;
extern int jinshengnum;
extern struct civ6 * unit;
extern int unitnum;
extern struct civ6 * wenming;
extern int wenmingnum;
extern struct civ6 * yicheng;
extern int yichengnum;
extern struct civ6 * tisheng;
extern int tishengnum;
extern struct civ6 * zhengce;
extern int zhengcenum;