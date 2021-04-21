#pragma once
#include "INTERFACE.h"
#include <objbase.h>
extern long g_lObjs;
extern long g_lLocks;

class OS12 : public IAdder, public IMultiplier
{
protected:
	// Reference count
	long          m_lRef;

public:
	OS12();
	~OS12();

public:
	// IUnknown
	STDMETHOD(QueryInterface(REFIID, void**));
	STDMETHOD_(ULONG, AddRef());
	STDMETHOD_(ULONG, Release());

	// IAdder
	STDMETHOD(Add(const double, const double, double*));
	STDMETHOD(Sub(const double, const double, double*));
	// IMultiplier
	STDMETHOD(Mul(const double, const double, double*));
	STDMETHOD(Div(const double, const double, double*));
};
