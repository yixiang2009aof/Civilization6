// tiaojian.h : Ctiaojian 类的实现



// Ctiaojian 实现

// 代码生成在 2016年12月22日, 20:41

#include "stdafx.h"
#include "tiaojian.h"
IMPLEMENT_DYNAMIC(Ctiaojian, CRecordset)

Ctiaojian::Ctiaojian(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_type = L"";
	m_loc = L"";
	m_arg1 = L"";
	m_arg2 = L"";
	m_arg3 = L"";
	m_arg4 = L"";
	m_arg5 = L"";
	m_arg6 = L"";
	m_arg7 = L"";
	m_arg8 = L"";
	m_nFields = 11;
	m_nDefaultType = dynaset;
}
//#error 安全问题: 连接字符串可能包含密码。
// 此连接字符串中可能包含明文密码和/或其他重要
// 信息。请在查看完此连接字符串并找到所有与安全
// 有关的问题后移除 #error。可能需要将此密码存
// 储为其他格式或使用其他的用户身份验证。
CString Ctiaojian::GetDefaultConnect()
{
	return _T("DSN=civ6;DBQ=C:\\db.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Ctiaojian::GetDefaultSQL()
{
	return _T("[tiaojian]");
}

void Ctiaojian::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() 和 RFX_Int() 这类宏依赖的是
// 成员变量的类型，而不是数据库字段的类型。
// ODBC 尝试自动将列值转换为所请求的类型
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[type]"), m_type);
	RFX_Text(pFX, _T("[loc]"), m_loc);
	RFX_Text(pFX, _T("[arg1]"), m_arg1);
	RFX_Text(pFX, _T("[arg2]"), m_arg2);
	RFX_Text(pFX, _T("[arg3]"), m_arg3);
	RFX_Text(pFX, _T("[arg4]"), m_arg4);
	RFX_Text(pFX, _T("[arg5]"), m_arg5);
	RFX_Text(pFX, _T("[arg6]"), m_arg6);
	RFX_Text(pFX, _T("[arg7]"), m_arg7);
	RFX_Text(pFX, _T("[arg8]"), m_arg8);

}
/////////////////////////////////////////////////////////////////////////////
// Ctiaojian 诊断

#ifdef _DEBUG
void Ctiaojian::AssertValid() const
{
	CRecordset::AssertValid();
}

void Ctiaojian::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


