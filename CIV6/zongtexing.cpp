// zongtexing.h : Czongtexing ���ʵ��



// Czongtexing ʵ��

// ���������� 2016��12��22��, 20:40

#include "stdafx.h"
#include "zongtexing.h"
IMPLEMENT_DYNAMIC(Czongtexing, CRecordset)

Czongtexing::Czongtexing(CDatabase* pdb)
	: CRecordset(pdb)
{
	m_ID = 0;
	m_type = L"";
	m_loc = L"";
	m_nFields = 3;
	m_nDefaultType = dynaset;
}
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
CString Czongtexing::GetDefaultConnect()
{
	return _T("DSN=civ6;DBQ=C:\\db.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Czongtexing::GetDefaultSQL()
{
	return _T("[zongtexing]");
}

void Czongtexing::DoFieldExchange(CFieldExchange* pFX)
{
	pFX->SetFieldType(CFieldExchange::outputColumn);
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
	RFX_Long(pFX, _T("[ID]"), m_ID);
	RFX_Text(pFX, _T("[type]"), m_type);
	RFX_Text(pFX, _T("[loc]"), m_loc);

}
/////////////////////////////////////////////////////////////////////////////
// Czongtexing ���

#ifdef _DEBUG
void Czongtexing::AssertValid() const
{
	CRecordset::AssertValid();
}

void Czongtexing::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


