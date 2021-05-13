#pragma once
#include <objbase.h>
#include "OS11_HTAPI.h"

#define FNAME L"Bor13.CA.COM"
#define VINDX L"Bor13.CA.1"
#define PRGID L"Bor13.CA"

// {C4574F65-719C-4584-B3FA-8093E188F323}
static const GUID CLSID_CA =
{ 0xc4574f65, 0x719c, 0x4584, { 0xb3, 0xfa, 0x80, 0x93, 0xe1, 0x88, 0xf3, 0x23 } };


// {2DD760A3-CB4E-4964-80A0-E0DF715C7184}
static const GUID IID_IOS13 =
{ 0x2dd760a3, 0xcb4e, 0x4964, { 0x80, 0xa0, 0xe0, 0xdf, 0x71, 0x5c, 0x71, 0x84 } };

interface IOS13 :IUnknown {
    STDMETHOD(Add(const double, const double, double*)) PURE;
    
	STDMETHOD(Sub(const double, const double, double*)) PURE;

	STDMETHOD(Create   //  создать HT             
	(
		int	  Capacity,					   // емкость хранилища
		int   SecSnapshotInterval,		   // переодичность сохранения в сек.
		int   MaxKeyLength,                // максимальный размер ключа
		int   MaxPayloadLength,            // максимальный размер данных
		const wchar_t  FileName[512],          // имя файла 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL успешное завершение  

	STDMETHOD(Open     //  открыть HT             
	(
		const wchar_t    FileName[512],         // имя файла 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL успешное завершение  

	STDMETHOD(Close     //  открыть HT             
	(
		HT::HTHANDLE** hthandle           // управление HT (File, FileMapping)
	)) PURE; 	// != NULL успешное завершение 

	STDMETHOD(OpenExist     //  открыть HT             
	(
		const wchar_t    FileName[512],         // имя файла 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL успешное завершение 

	STDMETHOD(Snap     //  открыть HT             
	(
		HT::HTHANDLE** hthandle
	)) PURE; 	// != NULL успешное завершение 

	STDMETHOD(Insert     //  открыть HT             
	(
		HT::HTHANDLE** hthandle,            // управление HT
		HT::Element** element              // элемент
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(Get     //  открыть HT             
	(
		HT::Element** result,
		HT::HTHANDLE** hthandle,            // управление HT
		HT::Element** element              // элемент 
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(Delete     //  открыть HT             
	(
		HT::HTHANDLE** hthandle,            // управление HT (ключ)
		HT::Element** element              // элемент 
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(Update     //  открыть HT             
	(
		HT::HTHANDLE** hthandle,            // управление HT
		HT::Element** oldelement,          // старый элемент (ключ, размер ключа)
		void** newpayload,          // новые данные  
		int*   newpayloadlength     // размер новых данных
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(GetLastErrorProg     //  открыть HT             
	(
		std::string& error,
		HT::HTHANDLE** ht                         // управление HT
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(CreateElement     //  открыть HT             
	(
		std::string* key,
		HT::Element** el                         // управление HT
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(CreateElement     //  открыть HT             
	(
		std::string* key,
		std::string* payload,
		HT::Element** el                         // управление HT
	)) PURE; 	// != NULL успешное завершение

	STDMETHOD(print     //  открыть HT             
	(
		HT::Element** element              // элемент 
	)) PURE; 	// != NULL успешное завершение
};

