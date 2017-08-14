// building.h : Cbuilding 类的实现



// Cbuilding 实现

// 代码生成在 2016年12月17日, 10:32

#include "stdafx.h"
#include "building.h"
IMPLEMENT_DYNAMIC(Cbuilding, CRecordset)

Cbuilding::Cbuilding(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_type = L"";
	m_loc = L"";
	m_tech = L"";
	m_civic = L"";
	m_cost = 0;
	m_maxp = 0;
	m_maxw = 0;
	m_pdis = L"";
	m_house = 0;
	m_enter = 0;
	m_pur = L"";
	m_main = 0;
	m_range = 0;
	m_river = FALSE;
	m_advi = L"";
	m_trait = L"";
	m_nFields = 17;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString Cbuilding::GetDefaultConnect()
{
	return _T("DSN=civ6;DBQ=C:\\db.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Cbuilding::GetDefaultSQL()
{
	return _T("[building]");
}

void Cbuilding::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[type]"), m_type);
	RFX_Text(pFX, _T("[loc]"), m_loc);
	RFX_Text(pFX, _T("[tech]"), m_tech);
	RFX_Text(pFX, _T("[civic]"), m_civic);
	RFX_Long(pFX, _T("[cost]"), m_cost);
	RFX_Long(pFX, _T("[maxp]"), m_maxp);
	RFX_Long(pFX, _T("[maxw]"), m_maxw);
	RFX_Text(pFX, _T("[pdis]"), m_pdis);
	RFX_Long(pFX, _T("[house]"), m_house);
	RFX_Long(pFX, _T("[enter]"), m_enter);
	RFX_Text(pFX, _T("[pur]"), m_pur);
	RFX_Long(pFX, _T("[main]"), m_main);
	RFX_Long(pFX, _T("[range]"), m_range);
	RFX_Bool(pFX, _T("[river]"), m_river);
	RFX_Text(pFX, _T("[advi]"), m_advi);
	RFX_Text(pFX, _T("[trait]"), m_trait);

}
/////////////////////////////////////////////////////////////////////////////
// Cbuilding 诊断

#ifdef _DEBUG
void Cbuilding::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cbuilding::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


