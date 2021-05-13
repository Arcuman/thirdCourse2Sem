#pragma once
#include "INTERFACE.h"
#include <objbase.h>
extern long g_lObjs;
extern long g_lLocks;

class OS13 : public IOS13
{
protected:
	// Reference count
	long          m_lRef;

public:
	OS13();
	~OS13();

public:
	// IUnknown
	STDMETHOD(QueryInterface(REFIID, void**));
	STDMETHOD_(ULONG, AddRef());
	STDMETHOD_(ULONG, Release());

	// IAdder
	STDMETHOD(Add(const double, const double, double*));
	STDMETHOD(Sub(const double, const double, double*));

	STDMETHOD(Create   //  ������� HT             
	(
		int	  Capacity,					   // ������� ���������
		int   SecSnapshotInterval,		   // ������������� ���������� � ���.
		int   MaxKeyLength,                // ������������ ������ �����
		int   MaxPayloadLength,            // ������������ ������ ������
		const wchar_t  FileName[512],          // ��� �����
		HT::HTHANDLE** result
	));

	STDMETHOD(Open     //  ������� HT             
	(
		const wchar_t    FileName[512],         // ��� ����� 
		HT::HTHANDLE** result
	)); 	// != NULL �������� ����������  

	STDMETHOD(OpenExist     //  ������� HT             
	(
		const wchar_t    FileName[512],         // ��� ����� 
		HT::HTHANDLE** result
	)); 	// != NULL �������� ���������� 

	STDMETHOD(Close     //  ������� HT             
	(
		HT::HTHANDLE** hthandle
	)); 	// != NULL �������� ����������

	STDMETHOD(Snap     //  ������� HT             
	(
		HT::HTHANDLE** hthandle
	)); 	// != NULL �������� ���������� 

	STDMETHOD(Insert     //  ������� HT             
	(
		HT::HTHANDLE** hthandle,            // ���������� HT
		HT::Element** element              // �������
	)); 	// != NULL �������� ����������

	STDMETHOD(Get     //  ������� HT             
	(
		HT::Element** result,
		HT::HTHANDLE** hthandle,            // ���������� HT
		HT::Element** element              // ������� 
	)); 	// != NULL �������� ����������

	STDMETHOD(Delete     //  ������� HT             
	(
		HT::HTHANDLE** hthandle,            // ���������� HT (����)
		HT::Element** element              // ������� 
	)); 	// != NULL �������� ����������

	STDMETHOD(Update     //  ������� HT             
	(
		HT::HTHANDLE** hthandle,            // ���������� HT
		HT::Element** oldelement,          // ������ ������� (����, ������ �����)
		void** newpayload,          // ����� ������  
		int*   newpayloadlength     // ������ ����� ������
	)); 	// != NULL �������� ����������

	STDMETHOD(GetLastErrorProg     //  ������� HT             
	(
		std::string& error,
		HT::HTHANDLE** ht                         // ���������� HT
	)); 	// != NULL �������� ����������

	STDMETHOD(CreateElement     //  ������� HT             
	(
		std::string* key,
		HT::Element** el                          // ���������� HT
	)); 	// != NULL �������� ����������

	STDMETHOD(CreateElement     //  ������� HT             
	(
		std::string* key,
		std::string* payload,
		HT::Element** el                         // ���������� HT
	)); 	// != NULL �������� ����������


	STDMETHOD(print     //  ������� HT             
	(
		HT::Element** element              // ������� 
	)); 	// != NULL �������� ����������

};
