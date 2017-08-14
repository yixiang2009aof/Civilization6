// building.h : Cbuilding ���ʵ��



// Cbuilding ʵ��

// ���������� 2016��12��17��, 10:32

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
//#error ��ȫ����: �����ַ������ܰ������롣
// �������ַ����п��ܰ������������/��������Ҫ
// ��Ϣ�����ڲ鿴��������ַ������ҵ������밲ȫ
// �йص�������Ƴ� #error��������Ҫ���������
// ��Ϊ������ʽ��ʹ���������û������֤��
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
// RFX_Text() �� RFX_Int() �������������
// ��Ա���������ͣ����������ݿ��ֶε����͡�
// ODBC �����Զ�����ֵת��Ϊ�����������
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
// Cbuilding ���

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


