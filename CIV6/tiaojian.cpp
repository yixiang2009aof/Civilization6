// tiaojian.h : Ctiaojian ���ʵ��



// Ctiaojian ʵ��

// ���������� 2016��12��22��, 20:41

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
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
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
// Ctiaojian ���

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


