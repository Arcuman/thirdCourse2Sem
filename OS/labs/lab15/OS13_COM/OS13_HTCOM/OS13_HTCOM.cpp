// OS13_HTCOM.cpp : Определяет функции для статической библиотеки.
//

#include "pch.h"
#include "framework.h"
#include "OS13_HTCOM.h"
#include "INTERFACE.h"


// TODO: Это пример библиотечной функции.
void fnOS13HTCOM()
{
}



namespace HTAPI    // HT API
{
	IOS13* pIOS13 = nullptr;
	IUnknown* pIUnknown = NULL;

	bool  HTAPI::OpenConnection() {
		CoInitialize(NULL);                        // инициализация библиотеки OLE32
		HRESULT hr0 = CoCreateInstance(CLSID_CA, NULL, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pIUnknown);
		if (SUCCEEDED(hr0))
		{
			std::cout << "CoCreateInstance succeeded" << std::endl;
			if (SUCCEEDED(pIUnknown->QueryInterface(IID_IOS13, (void**)&pIOS13)))
			{
				return true;
			}
		}
		return false;
	}

	bool  HTAPI::CloseConnection() {
		bool res = true;
		if (!SUCCEEDED(pIOS13->Release()))
			res = false;
		if (!SUCCEEDED(pIUnknown->Release()))
			res = false;
		CoFreeUnusedLibraries();
		return res;
	}

	HT::HTHANDLE* HTAPI::Create   //  создать HT             
	(
		int	  Capacity,					   // емкость хранилища
		int   SecSnapshotInterval,		   // переодичность сохранения в сек.
		int   MaxKeyLength,                // максимальный размер ключа
		int   MaxPayloadLength,            // максимальный размер данных
		const wchar_t  FileName[512],          // имя файла 
		const wchar_t  HTUsersGroup[512]          // имя файла 
	) {
		HT::HTHANDLE* pht;
		if (SUCCEEDED(pIOS13->Create(
			Capacity, SecSnapshotInterval, MaxKeyLength, MaxPayloadLength, FileName, HTUsersGroup, &pht))) {
			
			return pht;
		}
		else {
			return NULL;
		}
	}

	HT::HTHANDLE* HTAPI::Open     //  открыть HT             
	(
		const wchar_t   FileName[512]         // имя файла 
	) {
		HT::HTHANDLE* pht;
		if (SUCCEEDED(pIOS13->Open(FileName, &pht))) {
			return pht;
		}
		else {
			return NULL;
		}
	}

	HT::HTHANDLE* HTAPI::Open     //  открыть HT             
	(
		const wchar_t   FileName[512],         // имя файла 
		const wchar_t   userName[512],         // имя файла 
		const wchar_t   password[512]         // имя файла 
	) {
		HT::HTHANDLE* pht;
		if (SUCCEEDED(pIOS13->Open(FileName, userName, password, &pht))) {
			return pht;
		}
		else {
			return NULL;
		}
	}

	HT::HTHANDLE* HTAPI::OpenExist     //  открыть HT             
	(
		const wchar_t   FileName[512]         // имя файла 
	) {
		HT::HTHANDLE* pht;
		if (SUCCEEDED(pIOS13->OpenExist(FileName, &pht))) {
			return pht;
		}
		else {
			return NULL;
		}
	}

	BOOL Snap         // выполнить Snapshot
	(
		HT::HTHANDLE* hthandle           // управление HT (File, FileMapping)
	) {
		if (SUCCEEDED(pIOS13->Snap(&hthandle))) {
			return true;
		}
		else {
			return false;
		}
	}


	BOOL Close        // Snap и закрыть HT  и  очистить HT::HTHANDLE
	(
		HT::HTHANDLE* hthandle           // управление HT (File, FileMapping)
	) {
		if (SUCCEEDED(pIOS13->Close(&hthandle))) {
			return true;
		}
		else {
			return false;
		}
	}


	BOOL Insert      // добавить элемент в хранилище
	(
		HT::HTHANDLE* hthandle,            // управление HT
		HT::Element** element              // элемент
	) {
		if (SUCCEEDED(pIOS13->Insert(&hthandle, element))) {
			return true;
		}
		else {
			return false;
		}
	}


	BOOL Delete      // удалить элемент в хранилище
	(
		HT::HTHANDLE* hthandle,            // управление HT (ключ)
		HT::Element* element              // элемент 
	) {
		if (SUCCEEDED(pIOS13->Delete(&hthandle, &element))) {
			return true;
		}
		else {
			return false;
		}
	}

	HT::Element* Get     //  читать элемент в хранилище
	(
		HT::HTHANDLE* hthandle,            // управление HT
		HT::Element* element              // элемент 
	) {
		HT::Element* result;
		if (SUCCEEDED(pIOS13->Get(&result, &hthandle, &element))) {
			return result;
		}
		else {
			return NULL;
		}
	}



	BOOL Update     //  именить элемент в хранилище
	(
		HT::HTHANDLE* hthandle,            // управление HT
		HT::Element* oldelement,          // старый элемент (ключ, размер ключа)
		void* newpayload,          // новые данные  
		int             newpayloadlength     // размер новых данных
	) {
		if (SUCCEEDED(pIOS13->Update(&hthandle, &oldelement, &newpayload, &newpayloadlength))) {
			return true;
		}
		else {
			return false;
		}
	}

	std::string GetLastErrorProg  // получить сообщение о последней ошибке
	(
		HT::HTHANDLE* ht                         // управление HT
	) {
		std::string err;
		if (SUCCEEDED(pIOS13->GetLastErrorProg(err, &ht))) {
			return err;
		}
		else {
			return NULL;
		}
	}

	HT::Element* CreateElement     //  читать элемент в хранилище
	(
		std::string* key
	) {
		HT::Element* result;
		if (SUCCEEDED(pIOS13->CreateElement(&(*key), &result))) {
			return result;
		}
		else {
			return NULL;
		}
	}

	HT::Element* CreateElement     //  читать элемент в хранилище
	(
		std::string* key,
		std::string* payload
	) {
		HT::Element* result;
		if (SUCCEEDED(pIOS13->CreateElement(&(*key), &(*payload), &result))) {
			return result;
		}
		else {
			return NULL;
		}
	}

	BOOL print     //  читать элемент в хранилище
	(
		HT::Element* element
	) {
		if (SUCCEEDED(pIOS13->print(&element))) {
			return true;	
		}
		else {
			return false;
		}
	}

	wchar_t* GetWC(const char* c)
	{
		const size_t cSize = strlen(c) + 1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs(wc, c, cSize);

		return wc;
	}
};

