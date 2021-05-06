#include "pch.h"
#include "ICom.h"
#include "SEQLOG.h"
#include "OS11_HTAPI.h"

extern ULONG g_Components;

OS13::OS13() :m_lRef(1) {
	SEQ;
	InterlockedIncrement((LONG*)&g_Components);
	LOG("OS12::Adder g_Components = ", g_Components);
};

OS13::~OS13() {
	SEQ;
	InterlockedDecrement((LONG*)&g_Components);
	LOG("OS12::~Adder g_Components = ", g_Components);
};

STDMETHODIMP OS13::QueryInterface(REFIID riid, void** ppv)
{
	SEQ;
	HRESULT rc = S_OK;
	*ppv = NULL;
	if (riid == IID_IUnknown)
		*ppv = (IOS13*)this;
	else if (riid == IID_IOS13)
		*ppv = (IOS13*)this;
	else rc = E_NOINTERFACE;

	if (rc == S_OK) this->AddRef();
	LOG("OS12::QueryInterface rc = ", rc);
	return rc;
};

STDMETHODIMP_(ULONG) OS13::AddRef(void) {
	SEQ;
	InterlockedIncrement((LONG*)&(this->m_lRef));
	LOG("OS12::AddRef m_lRef = ", this->m_lRef);
	return this->m_lRef;
};
STDMETHODIMP_(ULONG) OS13::Release(void) {
	SEQ;
	ULONG rc = this->m_lRef;
	if ((rc = InterlockedDecrement((LONG*)&(this->m_lRef))) == 0) delete this;
	LOG("OS12::Release rc = ", rc);
	return rc;
};

STDMETHODIMP OS13::Add(const double lOp1, const double lOp2, double* pResult)
{
	*pResult = lOp1 + lOp2;
	return S_OK;
}

STDMETHODIMP OS13::Sub(const double lOp1, const double lOp2, double* pResult)
{
	*pResult = lOp1 - lOp2;
	return S_OK;
}


STDMETHODIMP OS13::Create(
	int	  Capacity,					   // емкость хранилища
	int   SecSnapshotInterval,		   // переодичность сохранения в сек.
	int   MaxKeyLength,                // максимальный размер ключа
	int   MaxPayloadLength,            // максимальный размер данных
	const wchar_t  FileName[512],          // имя файла 
	HT::HTHANDLE** result
){
	*result = HT::Create(Capacity, SecSnapshotInterval, MaxKeyLength, MaxPayloadLength, FileName);
	std::cout << result;
	if (*result == NULL) {
		return E_FAIL;
	}
	return S_OK;
}