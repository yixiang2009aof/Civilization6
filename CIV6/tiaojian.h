// tiaojian.h : Ctiaojian ������

#pragma once

// ���������� 2016��12��22��, 20:41

class Ctiaojian : public CRecordset
{
public:
	Ctiaojian(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Ctiaojian)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_ID;
	CStringW	m_type;
	CStringW	m_loc;
	CStringW	m_arg1;
	CStringW	m_arg2;
	CStringW	m_arg3;
	CStringW	m_arg4;
	CStringW	m_arg5;
	CStringW	m_arg6;
	CStringW	m_arg7;
	CStringW	m_arg8;

// ��д
	// �����ɵ��麯����д
	public:
	virtual CString GetDefaultConnect();	// Ĭ�������ַ���

	virtual CString GetDefaultSQL(); 	// ��¼����Ĭ�� SQL
	virtual void DoFieldExchange(CFieldExchange* pFX);	// RFX ֧��

// ʵ��
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

};


