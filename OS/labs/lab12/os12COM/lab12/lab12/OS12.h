#pragma once
#include <objbase.h>
#include <iostream>
#include "INTERFACE.h"

class OS12 :public IAdder, public IMultiplier
{
public:
	OS12();
	~OS12();


	virtual HRESULT STDMETHODCALLTYPE QueryInterface(REFIID riid, void** ppv);
	virtual ULONG STDMETHODCALLTYPE AddRef(void);
	virtual ULONG STDMETHODCALLTYPE Release(void);


	virtual HRESULT  STDMETHODCALLTYPE Add(
		const double x,
		const double y,
		double& z
	);
	virtual HRESULT STDMETHODCALLTYPE Sub(
		const double x,
		const double y,
		double& z
	);

	virtual HRESULT STDMETHODCALLTYPE Mul(
		const double x,
		const double y,
		double& z
	);
	virtual HRESULT STDMETHODCALLTYPE Div(
		const double x,
		const double y,
		double& z
	);

private:
	volatile ULONG m_Ref;
};
