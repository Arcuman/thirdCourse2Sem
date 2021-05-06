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
};
