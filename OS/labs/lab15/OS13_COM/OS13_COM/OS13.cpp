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
	const wchar_t  FileName[512],      // имя файла 
	const wchar_t  HTUsersGroup[512],      // имя файла 
	HT::HTHANDLE** result
){
	*result = HT::Create(Capacity, SecSnapshotInterval, MaxKeyLength, MaxPayloadLength, FileName, HTUsersGroup);
	if (*result == NULL) {
		return E_FAIL;
	}
	return S_OK;
}

STDMETHODIMP OS13::Open(
	const wchar_t    FileName[512],         // имя файла 
	HT::HTHANDLE** result
) {
	HT::HTHANDLE* temp = HT::Open(FileName);
	if (temp == NULL)
		return E_FAIL;
	*result = temp;
	if (*result != NULL)
		return S_OK;
	else
		return E_FAIL;
}

STDMETHODIMP OS13::Open(
	const wchar_t    FileName[512],         // имя файла 
	const wchar_t    userName[512],         // имя файла 
	const wchar_t    password[512],         // имя файла 
	HT::HTHANDLE** result
) {
	HT::HTHANDLE* temp = HT::Open(FileName, userName, password);
	if (temp == NULL)
		return E_FAIL;
	*result = temp;
	if (*result != NULL)
		return S_OK;
	else
		return E_FAIL;
}

STDMETHODIMP OS13::OpenExist(
	const wchar_t    FileName[512],         // имя файла 
	HT::HTHANDLE** result
) {
	HT::HTHANDLE* temp = HT::OpenExist(FileName);
	if (temp == NULL)
		return E_FAIL;
	*result = temp;
	if (*result != NULL)
		return S_OK;
	else
		return E_FAIL;
}

STDMETHODIMP OS13::Close(
	HT::HTHANDLE** hthandle
) {
	bool isSuc =  HT::Close(*hthandle);
	if (isSuc)
		return S_OK;
	else
		return E_FAIL;
}

STDMETHODIMP OS13::Snap(
	HT::HTHANDLE** hthandle
) {
	if (HT::Snap(*hthandle))
		return S_OK;
	else
		return E_FAIL;
}

STDMETHODIMP OS13::Insert(
	HT::HTHANDLE** hthandle,            // управление HT
	HT::Element** element              // элемент
) {
	if (HT::Insert(*hthandle, *element))
		return S_OK;
	else
		return E_FAIL;
}

STDMETHODIMP OS13::Get(
	HT::Element** result,
	HT::HTHANDLE** hthandle,            // управление HT
	HT::Element** element              // элемент
) {
	HT::Element* temp = HT::Get(*hthandle, *element);
	if (temp == NULL)
		return E_FAIL;
	*result = temp;
	return S_OK;
}

STDMETHODIMP OS13::Delete(
	HT::HTHANDLE** hthandle,            // управление HT (ключ)
	HT::Element** element              // элемент 
) {
	if (HT::Delete(*hthandle, *element))
		return S_OK;
	else
		return E_FAIL;
}

STDMETHODIMP OS13::Update(
	HT::HTHANDLE** hthandle,            // управление HT
	HT::Element** oldelement,          // старый элемент (ключ, размер ключа)
	void** newpayload,          // новые данные  
	int*             newpayloadlength     // размер новых данных
) {
	if (HT::Update(*hthandle, *oldelement, *newpayload, *newpayloadlength))
		return S_OK;
	else
		return E_FAIL;
}

STDMETHODIMP OS13::GetLastErrorProg(
	std::string& error,
	HT::HTHANDLE** ht                         // управление HT
) {
	error = std::string(HT::GetLastErrorProg(*ht));
	return S_OK;
}

STDMETHODIMP OS13::CreateElement(
	std::string* key,
	HT::Element** el                         // управление HT
) {
	HT::Element* temp = new HT::Element((*key).c_str(), (*key).length() + 1);
	if (temp == NULL)
		return E_FAIL;
	*el = temp;
	return S_OK;
}
STDMETHODIMP OS13::CreateElement(
	std::string* key,
	std::string* payload,
	HT::Element** el			                  // управление HT
) {
	HT::Element* temp = new HT::Element((*key).c_str(), (*key).length() + 1, (*payload).c_str(), (*payload).length() + 1);
	if (temp == NULL)
		return E_FAIL;
	*el = temp;
	return S_OK;
	
}

STDMETHODIMP OS13::print(
	HT::Element** element              // элемент 
) {
	HT::print(*element);
	return S_OK;
}


