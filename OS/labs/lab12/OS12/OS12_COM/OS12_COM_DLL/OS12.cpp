#include "pch.h"
#include "ICom.h"
#include "SEQLOG.h"

extern ULONG g_Components;

OS12::OS12() :m_lRef(1) {
	SEQ;
	InterlockedIncrement((LONG*)&g_Components);
	LOG("OS12::Adder g_Components = ", g_Components);
};

OS12::~OS12() {
	SEQ;
	InterlockedDecrement((LONG*)&g_Components);
	LOG("OS12::~Adder g_Components = ", g_Components);
};

STDMETHODIMP OS12::QueryInterface(REFIID riid, void** ppv)
{
	SEQ;
	HRESULT rc = S_OK;
	*ppv = NULL;
	if (riid == IID_IUnknown)
		*ppv = (IAdder*)this;
	else if (riid == IID_IAdder)
		*ppv = (IAdder*)this;
	else if (riid == IID_IMultiplier)
		*ppv = (IMultiplier*)this;
	else rc = E_NOINTERFACE;

	if (rc == S_OK) this->AddRef();
	LOG("OS12::QueryInterface rc = ", rc);
	return rc;
};

STDMETHODIMP_(ULONG) OS12::AddRef(void) {
	SEQ;
	InterlockedIncrement((LONG*)&(this->m_lRef));
	LOG("OS12::AddRef m_lRef = ", this->m_lRef);
	return this->m_lRef;
};
STDMETHODIMP_(ULONG) OS12::Release(void) {
	SEQ;
	ULONG rc = this->m_lRef;
	if ((rc = InterlockedDecrement((LONG*)&(this->m_lRef))) == 0) delete this;
	LOG("OS12::Release rc = ", rc);
	return rc;
};

STDMETHODIMP OS12::Add(const double lOp1, const double lOp2, double* pResult)
{
	*pResult = lOp1 + lOp2;
	return S_OK;
}

STDMETHODIMP OS12::Sub(const double lOp1, const double lOp2, double* pResult)
{
	*pResult = lOp1 - lOp2;
	return S_OK;
}

STDMETHODIMP OS12::Mul(const double lOp1, const double lOp2, double* pResult)
{
	*pResult = lOp1 * lOp2;
	return S_OK;
}

STDMETHODIMP OS12::Div(const double lOp1, const double lOp2, double* pResult)
{
	*pResult = lOp1 / lOp2;
	return S_OK;
}