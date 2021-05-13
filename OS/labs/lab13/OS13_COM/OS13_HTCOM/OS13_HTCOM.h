#pragma once
#include <Windows.h>
#include "INTERFACE.h"
#include <string>

namespace HTAPI    // HT API
{
	bool OpenConnection();
	bool CloseConnection();


	HT::HTHANDLE* Create   //  создать HT             
	(
		int	  Capacity,					   // емкость хранилища
		int   SecSnapshotInterval,		   // переодичность сохранения в сек.
		int   MaxKeyLength,                // максимальный размер ключа
		int   MaxPayloadLength,            // максимальный размер данных
		const wchar_t   FileName[512]          // имя файла 
	);

	HT::HTHANDLE* Open     //  открыть HT             
	(
		const wchar_t     FileName[512]         // имя файла 
	); 	// != NULL успешное завершение  

	HT::HTHANDLE* OpenExist     //  открыть HT             
	(
		const wchar_t     FileName[512]         // имя файла 
	); 	// != NULL успешное завершение  

	BOOL Snap         // выполнить Snapshot
	(
		HT::HTHANDLE* hthandle           // управление HT (File, FileMapping)
	);


	BOOL Close        // Snap и закрыть HT  и  очистить HT::HTHANDLE
	(
		HT::HTHANDLE* hthandle           // управление HT (File, FileMapping)
	);	//  == TRUE успешное завершение   


	BOOL Insert      // добавить элемент в хранилище
	(
		HT::HTHANDLE* hthandle,            // управление HT
		HT::Element** element              // элемент
	);	//  == TRUE успешное завершение 


	BOOL Delete      // удалить элемент в хранилище
	(
		HT::HTHANDLE* hthandle,            // управление HT (ключ)
		HT::Element* element              // элемент 
	);	//  == TRUE успешное завершение 

	HT::Element* Get     //  читать элемент в хранилище
	(
		HT::HTHANDLE* hthandle,            // управление HT
		HT::Element* element              // элемент 
	); 	//  != NULL успешное завершение 


	BOOL Update     //  именить элемент в хранилище
	(
		HT::HTHANDLE* hthandle,            // управление HT
		HT::Element* oldelement,          // старый элемент (ключ, размер ключа)
		void* newpayload,          // новые данные  
		int             newpayloadlength     // размер новых данных
	); 	//  != NULL успешное завершение 

	std::string GetLastErrorProg  // получить сообщение о последней ошибке
	(
		HT::HTHANDLE* ht                         // управление HT
	);


	HT::Element* CreateElement     //  читать элемент в хранилище
	(
		std::string* key         // элемент 
	); 	//  != NULL успешное завершение 

	HT::Element* CreateElement     //  читать элемент в хранилище
	(
		std::string* key,
		std::string* payload      // элемент 
	); 	//  != NULL успешное завершение 

	BOOL print  // получить сообщение о последней ошибке
	(
		HT::Element* oldelement                       // управление HT
	);

	wchar_t* GetWC(const char* c);

};
