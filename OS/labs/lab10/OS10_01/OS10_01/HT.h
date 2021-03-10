#pragma once
#include <Windows.h>

namespace HT    // HT API
{
	// API HT - программный интерфейс для доступа к НТ-хранилищу 
	//          НТ-хранилище предназначено для хранения данных в ОП в формате ключ/значение
	//          Персистестеность (сохранность) данных обеспечивается с помощью snapshot-менханизма 
	//          Create - создать  и открыть HT-хранилище для использования   
	//          Open   - открыть HT-хранилище для использования
	//          Insert - создать элемент данных
	//          Delete - удалить элемент данных    
	//          Get    - читать  элемент данных
	//          Update - изменить элемент данных
	//          Snap   - выпонить snapshot
	//          Close  - выполнить Snap и закрыть HT-хранилище для использования
	//          GetLastError - получить сообщение о последней ошибке


	struct HTHANDLE    // блок управления HT
	{
		HTHANDLE();
		HTHANDLE(int Capacity, int SecSnapshotInterval, int MaxKeyLength, int MaxPayloadLength, const wchar_t FileName[512]);
		int     Capacity = 20;               // емкость хранилища в количестве элементов 
		int     SecSnapshotInterval = 120;    // переодичность сохранения в сек. 
		int     MaxKeyLength = 64;           // максимальная длина ключа
		int     MaxPayloadLength = 64;       // максимальная длина данных
		wchar_t    FileName[512] = L"map.txt";          // имя файла 
		HANDLE  File = 0;                   // File HANDLE != 0, если файл открыт
		HANDLE  FileMapping = 0;            // Mapping File HANDLE != 0, если mapping создан  
		LPVOID  Addr = 0;                   // Addr != NULL, если mapview выполнен. Адрас з якога пачынаюцца элементы  
		char    LastErrorMessage[512] = "\0";  // сообщение об последней ошибке или 0x00  
		time_t  lastsnaptime = 0;           // дата последнего snap'a (time())  

		wchar_t mutexName[512];
		wchar_t fileMapName[512];
		wchar_t timerName[512];

		DWORD creatorPid;
		HANDLE hTimer;
		HANDLE hTimerThread;
	};

	struct Element   // элемент 
	{
		Element();
		Element(const void* key, int keylength);                                             // for Get
		Element(const void* key, int keylength, const void* payload, int  payloadlength);    // for Insert
		Element(Element* oldelement, const void* newpayload, int  newpayloadlength);         // for update
		void* key;                 // значение ключа 
		int             keylength;           // рахмер ключа
		void* payload;             // данные 
		int             payloadlength;       // размер данных
	};

	HTHANDLE* Create   //  создать HT             
	(
		int	  Capacity,					   // емкость хранилища
		int   SecSnapshotInterval,		   // переодичность сохранения в сек.
		int   MaxKeyLength,                // максимальный размер ключа
		int   MaxPayloadLength,            // максимальный размер данных
		const char  FileName[512]          // имя файла 
	); 	// != NULL успешное завершение  

	HTHANDLE* Open     //  открыть HT             
	(
		const char    FileName[512]         // имя файла 
	); 	// != NULL успешное завершение  

	BOOL Snap         // выполнить Snapshot
	(
		const HTHANDLE* hthandle           // управление HT (File, FileMapping)
	);


	BOOL Close        // Snap и закрыть HT  и  очистить HTHANDLE
	(
		const HTHANDLE* hthandle           // управление HT (File, FileMapping)
	);	//  == TRUE успешное завершение   


	BOOL Insert      // добавить элемент в хранилище
	(
		const HTHANDLE* hthandle,            // управление HT
		const Element* element              // элемент
	);	//  == TRUE успешное завершение 


	BOOL Delete      // удалить элемент в хранилище
	(
		const HTHANDLE* hthandle,            // управление HT (ключ)
		const Element* element              // элемент 
	);	//  == TRUE успешное завершение 

	Element* Get     //  читать элемент в хранилище
	(
		const HTHANDLE* hthandle,            // управление HT
		const Element* element              // элемент 
	); 	//  != NULL успешное завершение 

	int PrintAll     // print all elements aand return their count
	(
		HTHANDLE* ht           // управление HT
	); 	//  != NULL успешное завершение 


	BOOL Update     //  именить элемент в хранилище
	(
		const HTHANDLE* hthandle,            // управление HT
		const Element* oldelement,          // старый элемент (ключ, размер ключа)
		const void* newpayload,          // новые данные  
		int             newpayloadlength     // размер новых данных
	); 	//  != NULL успешное завершение 

	char* GetLastError1  // получить сообщение о последней ошибке
	(
		HTHANDLE* ht                         // управление HT
	);

	void print                               // распечатать элемент 
	(
		const Element* element              // элемент 
	);


};
