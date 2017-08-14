// building.h : Cbuilding ������

#pragma once

// ���������� 2016��12��17��, 10:32

class Cbuilding : public CRecordset
{
public:
	Cbuilding(CDatabase* pDatabase = NULL);
	DECLARE_DYNAMIC(Cbuilding)

// �ֶ�/��������

// �����ַ�������(�������)��ӳ���ݿ��ֶ�(ANSI �������͵� CStringA �� Unicode
// �������͵� CStringW)��ʵ���������͡�
//  ����Ϊ��ֹ ODBC ��������ִ�п���
// ����Ҫ��ת�������ϣ�������Խ���Щ��Ա����Ϊ
// CString ���ͣ�ODBC ��������ִ�����б�Ҫ��ת����
// (ע��: ����ʹ�� 3.5 �����߰汾�� ODBC ��������
// ��ͬʱ֧�� Unicode ����Щת��)��

	long	m_ID;
	CStringW	m_type;	//����
	CStringW	m_loc;	//���ƣ����ڳ���
	CStringW	m_tech;	//ǰ�ÿƼ�
	CStringW	m_civic;	//ǰ������
	long	m_cost;	//���Ѳ���
	long	m_maxp;	//����������
	long	m_maxw;	//�����������
	CStringW	m_pdis;	//ǰ�ó���
	long	m_house;	//����ס��
	long	m_enter;	//�����˾�
	CStringW	m_pur;	//�ɹ���Դ����
	long	m_main;	//ά����
	long	m_range;	//������䷶Χ
	BOOL	m_river;	//������Ҫ�ٺ�
	CStringW	m_advi;	//��������
	CStringW	m_trait;	//����

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


