#pragma once
#include <objbase.h>
#include "OS11_HTAPI.h"

#define FNAME L"Lab15.CA.COM"
#define VINDX L"Lab15.CA.1"
#define PRGID L"Lab15.CA"

// {2F07B277-8FBA-4F7F-AD11-28B8C7A9B84B}
static const GUID CLSID_CA =
{ 0x2f07b277, 0x8fba, 0x4f7f, { 0xad, 0x11, 0x28, 0xb8, 0xc7, 0xa9, 0xb8, 0x4b } };


// {4FF4FCD4-2082-4F0E-A0C5-A9898582241F}
static const GUID IID_IOS13 =
{ 0x4ff4fcd4, 0x2082, 0x4f0e, { 0xa0, 0xc5, 0xa9, 0x89, 0x85, 0x82, 0x24, 0x1f } };


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
		const wchar_t  HTUsersGroup[512],          // имя файла 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL успешное завершение  

	STDMETHOD(Open     //  открыть HT             
	(
		const wchar_t    FileName[512],         // имя файла 
		HT::HTHANDLE** result
	)) PURE; 	// != NULL успешное завершение 

	STDMETHOD(Open     //  открыть HT             
	(
		const wchar_t    FileName[512],         // имя файла 
		const wchar_t    userName[512],         // имя файла 
		const wchar_t    password[512],         // имя файла 
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

