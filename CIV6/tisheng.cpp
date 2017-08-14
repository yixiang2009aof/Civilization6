// tisheng.h : Ctisheng ���ʵ��



// Ctisheng ʵ��

// ���������� 2017��6��14��, 20:30

#include "stdafx.h"
#include "tisheng.h"
IMPLEMENT_DYNAMIC(Ctisheng, CRecordset)

Ctisheng::Ctisheng(CDatabase* pdb)
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
CString Ctisheng::GetDefaultConnect()
{
	return _T("DSN=civ6;DBQ=C:\\db.accdb;DriverId=25;FIL=MS Access;MaxBufferSize=2048;PageTimeout=5;UID=admin;");
}

CString Ctisheng::GetDefaultSQL()
{
	return _T("[tisheng]");
}

void Ctisheng::DoFieldExchange(CFieldExchange* pFX)
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
// Ctisheng ���

#ifdef _DEBUG
void Ctisheng::AssertValid() const
{
	CRecordset::AssertValid();
}

void Ctisheng::Dump(CDumpContext& dc) const
{
	CRecordset::Dump(dc);
}
#endif //_DEBUG


