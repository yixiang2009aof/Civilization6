// building.h : Cbuilding 的声明

#pragma once

// 代码生成在 2016年12月17日, 10:32

class Cbuilding : public CRecordset
{
public:
	Cbuilding(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Cbuilding)

// 字段/参数数据

// 以下字符串类型(如果存在)反映数据库字段(ANSI 数据类型的 CStringA 和 Unicode
// 数据类型的 CStringW)的实际数据类型。
//  这是为防止 ODBC 驱动程序执行可能
// 不必要的转换。如果希望，可以将这些成员更改为
// CString 类型，ODBC 驱动程序将执行所有必要的转换。
// (注意: 必须使用 3.5 版或更高版本的 ODBC 驱动程序
// 以同时支持 Unicode 和这些转换)。

	long	m_ID;
	CStringW	m_type;	//类型
	CStringW	m_loc;	//名称（用于程序）
	CStringW	m_tech;	//前置科技
	CStringW	m_civic;	//前置市政
	long	m_cost;	//花费产能
	long	m_maxp;	//玩家最大数量
	long	m_maxw;	//世界最大数量
	CStringW	m_pdis;	//前置城区
	long	m_house;	//增加住房
	long	m_enter;	//增加宜居
	CStringW	m_pur;	//采购资源类型
	long	m_main;	//维护费
	long	m_range;	//区域辐射范围
	BOOL	m_river;	//城市需要临河
	CStringW	m_advi;	//顾问类型
	CStringW	m_trait;	//特性

// 重写
	// 向导生成的虚函数重写
	public:
	virtual CString GetDefaultConnect();	// 默认连接字符串

	virtual CString GetDefaultSQL(); 	// 记录集的默认 SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX 支持

// 实现
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


