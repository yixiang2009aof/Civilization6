// ziyuan.h : Cziyuan ���ʵ��



// Cziyuan ʵ��

// ���������� 2016��12��25��, 22:52

#include "stdafx.h"
#include "ziyuan.h"
IMPLEMENT_DYNAMIC(Cziyuan, CRecordset)

Cziyuan::Cziyuan(CDatabase* pdb)
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
CString Cziyuan::GetDefaultConnect()
{
	return _T("DSN=civ6;DBQ=C:\\db.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Cziyuan::GetDefaultSQL()
{
	return _T("[ziyuan]");
}

void Cziyuan::DoFieldExchange(CFieldExchange* pFX)
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
// Cziyuan ���

#ifdef _DEBUG
void Cziyuan::AssertValid() const
{
	CRecordset::AssertValid();
}

void Cziyuan::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


