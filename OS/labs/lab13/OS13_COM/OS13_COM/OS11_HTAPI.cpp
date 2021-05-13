// MathLibrary.cpp : Defines the exported functions for the DLL.
#include "pch.h" // use stdafx.h in Visual Studio 2017 and earlier
#include <utility>
#include <limits.h>
#include "OS11_HTAPI.h"
#include <algorithm>
#include "SEQLOG.h"
extern HMODULE hmodule;
namespace HT {
	HANDLE Addr;

	int HashFunction(const Element* element, int size, int p);
	int Next_hash(int hash, int size, int p);
	DWORD WINAPI SnapShotCycle(HTHANDLE* ht);
	wchar_t* GenerateMutexName(const wchar_t* pathToHT);
	wchar_t* GenerateViewName(const wchar_t* pathToHT);
	BOOL CheckParmLength(HTHANDLE* ht, Element* element);
	BOOL CheckParmLength(HTHANDLE* ht, int payloadLength);

	const int DELETED = -1;
	Element* GetElementFromHT(HTHANDLE* ht, int n);
	BOOL SetElementToHT(HTHANDLE* ht, Element* element, int n);
	BOOL IsDeleted(Element* ptr);
	void SetDeletedFlag(Element* ptr);
	BOOL EqualElementKeys(Element* el1, Element* el2);
	void SetErrorMessage(HTHANDLE* ht, const char* message, int messageLen);
	void UpdateElement(HTHANDLE* ht, Element* el, void* newpayload, int newpayloadlength);

	Element::Element() {
		this->key = nullptr;
		this->keylength = NULL;
		this->payload = nullptr;
		this->payloadlength = NULL;
	}

	Element::Element(const void* key, int keylength) {
		Element();
		this->key = (void*)key;
		this->keylength = keylength;
	}

	Element::Element(const void* key, int keylength, const void* payload, int  payloadlength) {
		this->key = (void*)key;
		this->keylength = keylength;
		this->payload = (void*)payload;
		this->payloadlength = payloadlength;
	}
	Element::Element(Element* oldelement, const void* newpayload, int  newpayloadlength) {
		this->key = oldelement->key;
		this->keylength = oldelement->keylength;
		this->payload = (void*)payload;
		this->payloadlength = payloadlength;
	}

	HTHANDLE::HTHANDLE() {}
	HTHANDLE::HTHANDLE(
		int Capacity,
		int SecSnapshotInterval,
		int MaxKeyLength,
		int MaxPayloadLength,
		const wchar_t FileName[512]
	) {
		this->Capacity = Capacity;
		this->SecSnapshotInterval = SecSnapshotInterval;
		this->MaxKeyLength = MaxKeyLength;
		this->MaxPayloadLength = MaxPayloadLength;
		this->N = 0;
		memcpy(this->FileName, FileName, sizeof(this->FileName));
	}

	HTHANDLE* Create(
		int	  Capacity,					   // емкость хранилища
		int   SecSnapshotInterval,		   // переодичность сохранения в сек.
		int   MaxKeyLength,                // максимальный размер ключа
		int   MaxPayloadLength,            // максимальный размер данных
		const wchar_t  FileName[512]          // имя файла 
	) {
		HANDLE hf = CreateFile(
			FileName,//path
			GENERIC_WRITE | GENERIC_READ,
			NULL,//режим совместного пользования
			NULL,// атрибуты защиты
			CREATE_NEW,// создание 
			FILE_ATTRIBUTE_NORMAL,//атрибуты и флаги
			NULL//файл атрибутов
		);
		if (hf == INVALID_HANDLE_VALUE) 
			return NULL;
		DWORD HTsize = sizeof(HTHANDLE) + Capacity * (MaxKeyLength + MaxPayloadLength + 2 * sizeof(int));
		HANDLE hm = CreateFileMapping(
			hf,
			NULL,
			PAGE_READWRITE,
			0, HTsize, NULL);
		if (!hm)
			return NULL;
		std::cout << "Open FileMapping: " << hm << std::endl;

		LPVOID lp = MapViewOfFile(
			hm,
			FILE_MAP_ALL_ACCESS | FILE_MAP_READ | FILE_MAP_WRITE,
			0, 0, 0);
		if (!lp)return NULL;
		std::cout << "Open MapViewOfFile: " << lp << std::endl;


		ZeroMemory(lp, HTsize);
		HTHANDLE* ht = new(lp) HTHANDLE(
			Capacity,
			SecSnapshotInterval,
			MaxKeyLength,
			MaxPayloadLength,
			FileName);
		std::cout << "Create ht: " << std::endl;
		ht->File = hf;
		ht->FileMapping = hm;
		ht->Addr = lp;
		ht->lastsnaptime = time(NULL);
		ht->Mutex = CreateMutex(
			NULL,
			FALSE,
			GenerateMutexName(FileName));//MAX_PATH LIMIT
		std::cout << "Create Mutex: " << std::endl;

		std::cout << "Open Mutex: " << ht->Mutex << std::endl;
		DWORD SnapShotThread = NULL;
		if (!(ht->SnapshotThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)SnapShotCycle, ht, 0, &SnapShotThread))) return NULL;
		return ht;
	}

	HTHANDLE* Open(const wchar_t FileName[512]) {
		HANDLE hf = CreateFile(
			FileName,//path
			GENERIC_WRITE | GENERIC_READ,
			FILE_SHARE_READ | FILE_SHARE_WRITE | FILE_SHARE_DELETE,//режим совместного пользования
			NULL,// атрибуты защиты
			OPEN_EXISTING,//  открытие
			FILE_ATTRIBUTE_NORMAL,//атрибуты и флаги
			NULL//файл атрибутов
		);
		if (hf == INVALID_HANDLE_VALUE)
		{
			std::cout << _Post_equals_last_error_::GetLastError();
			return NULL;
		}
		HANDLE hm = CreateFileMapping(//создать объект ядра 
			hf,
			NULL,
			PAGE_READWRITE,
			0, 0, L"name");
		if (!hm)return NULL;
		std::cout << "Open FileMapping: " << hm << std::endl;
		LPVOID lp = MapViewOfFile(
			hm,
			FILE_MAP_ALL_ACCESS | FILE_MAP_READ | FILE_MAP_WRITE,
			0, 0, 0);
		Addr = lp;
		if (!lp) {
			return NULL;
		}
		std::cout << "Open MapViewOfFile: " << lp << std::endl;

		HTHANDLE* ht = (HTHANDLE*)lp;
		ht->File = hf;
		ht->FileMapping = hm;
		ht->Addr = lp;
		ht->Mutex = CreateMutex(
			NULL,
			FALSE,
			L"mutex");

		DWORD SnapShotThread = NULL;
		if (!(ht->SnapshotThread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)SnapShotCycle, ht, 0, &SnapShotThread))) return NULL;
		return ht;
	}

	HTHANDLE* OpenExist(const wchar_t FileName[512]) {
		HANDLE hm;
		HANDLE mutex = CreateMutex(
			NULL,
			FALSE, L"mutex");
		WaitForSingleObject(mutex, INFINITE);
		std::cout << _Post_equals_last_error_::GetLastError();
		//hm = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"name");
		hm = OpenFileMapping(FILE_MAP_ALL_ACCESS, FALSE, L"name");
		std::cout << _Post_equals_last_error_::GetLastError();
		if (!hm)return NULL;

		LPVOID lp = MapViewOfFile(
			hm,
			FILE_MAP_ALL_ACCESS | FILE_MAP_READ | FILE_MAP_WRITE,
			0, 0, 0);
		Addr = lp;
		std::cout << _Post_equals_last_error_::GetLastError();
		if (!lp)return NULL;
		ReleaseMutex(mutex);
		HTHANDLE* ht = (HTHANDLE*)lp;
		ht->FileMapping = hm;
		ht->Addr = lp;
		ht->Mutex = mutex;
		return ht;
	}

	BOOL Snap(HTHANDLE* hthandle) {
		std::cout << "-----SNAPSHOT WAIT-----" << std::endl;
		WaitForSingleObject(hthandle->Mutex, INFINITE);
		if (!FlushViewOfFile(Addr, NULL)) {
			SetErrorMessage(hthandle, "Snapshot error", 15);
			ReleaseMutex(hthandle->Mutex);
			return FALSE;
		}
		std::cout << "-----SNAPSHOT-----" << std::endl;
		hthandle->lastsnaptime = time(NULL);
		ReleaseMutex(hthandle->Mutex);
		return TRUE;
	}

	BOOL Close(const HTHANDLE* hthandle) {
		HANDLE mapping, file, mutex, addr;

		memcpy(&mapping, &hthandle->FileMapping, sizeof(HANDLE));
		memcpy(&file, &hthandle->File, sizeof(HANDLE));
		memcpy(&mutex, &hthandle->Mutex, sizeof(HANDLE));
		TerminateThread(hthandle->SnapshotThread, 0);
		if (!CloseHandle(mapping))return FALSE;
		if (!CloseHandle(file))return FALSE;
		if (!CloseHandle(mutex))return FALSE;
		return TRUE;
	}
	BOOL CloseExist(const HTHANDLE* hthandle) {
		if (!UnmapViewOfFile(hthandle->Addr))
		{
			return FALSE;
		}
		return TRUE;
	}

	BOOL Insert      // добавить элемент в хранилище
	(
		HTHANDLE* hthandle,            // управление HT
		Element* element              // элемент
	) {
		if (!CheckParmLength(hthandle, element))
			return FALSE;
		WaitForSingleObject(hthandle->Mutex, INFINITE);
		bool inserted = false;
		if (hthandle->N != hthandle->Capacity)
		{
			for (int i = 0, j = HashFunction(element, hthandle->Capacity, 0);
				i != hthandle->Capacity && !inserted;  j = Next_hash(j, hthandle->Capacity, ++i)) {
				Element* elFromHT = GetElementFromHT(hthandle, j);
				if (elFromHT!= NULL && !IsDeleted(elFromHT)) {
					if (EqualElementKeys(elFromHT, element)) {
						SetErrorMessage(hthandle, "Key exists\n", 12);
						ReleaseMutex(hthandle->Mutex);
						return FALSE;
					}
				}
				SetElementToHT(hthandle, element, j);
				hthandle->N++;
				inserted = true;

			}
		}
		ReleaseMutex(hthandle->Mutex);
		return inserted;
	}

	Element* Get     //  читать элемент в хранилище
	(
		HTHANDLE* hthandle,            // управление HT
		Element* element              // элемент 
	) 	//  != NULL успешное завершение 
	{
		if (!CheckParmLength(hthandle, element))
			return NULL;
		WaitForSingleObject(hthandle->Mutex, INFINITE);

		int indexInHT = -1;
		bool found = false;
		if (hthandle->N != 0)
			for (int i = 0, j = HashFunction(element, hthandle->Capacity, 0);
				GetElementFromHT(hthandle, j) != NULL && i != hthandle->Capacity && !found;
				j = Next_hash(j, hthandle->Capacity, ++i)) {
			Element* elFromHT = GetElementFromHT(hthandle, j);
			if (!IsDeleted(elFromHT)) {
				if (EqualElementKeys(elFromHT, element)) {
					indexInHT = j; found = true;
				}
			}
		}
		if (indexInHT < 0) {
			SetErrorMessage(hthandle, "Not found key\n", 15);
			ReleaseMutex(hthandle->Mutex);
			return NULL;
		}
		ReleaseMutex(hthandle->Mutex);
		return GetElementFromHT(hthandle, indexInHT);
	}

	BOOL Delete      // удалить элемент в хранилище
	(
		HTHANDLE* hthandle,            // управление HT (ключ)
		Element* element              // элемент 
	)	//  == TRUE успешное завершение 
	{
		if (!CheckParmLength(hthandle, element))
			return FALSE;
		WaitForSingleObject(hthandle->Mutex, INFINITE);
		int indexInHT = -1;
		bool deleted = false;
		if (hthandle->N != 0)
			for (int i = 0, j = HashFunction(element, hthandle->Capacity, 0);
				GetElementFromHT(hthandle, j) != NULL && i != hthandle->Capacity && !deleted;
				j = Next_hash(j, hthandle->Capacity, ++i)) {
			Element* elFromHT = GetElementFromHT(hthandle, j);
			if (!IsDeleted(elFromHT)) {
				if (EqualElementKeys(elFromHT, element)) {
					indexInHT = j; deleted = true;
				}
			}
		}
		if (indexInHT < 0) {
			SetErrorMessage(hthandle, "Not found key\n", 15);
			ReleaseMutex(hthandle->Mutex);
			return FALSE;
		}

		SetDeletedFlag(GetElementFromHT(hthandle, indexInHT));
		hthandle->N--;
		ReleaseMutex(hthandle->Mutex);
		return TRUE;
	}

	BOOL Update     //  именить элемент в хранилище
	(
		HTHANDLE* hthandle,            // управление HT
		Element* oldelement,          // старый элемент (ключ, размер ключа)
		void* newpayload,          // новые данные  
		int             newpayloadlength     // размер новых данных
	) {
		if (!CheckParmLength(hthandle, oldelement) || !CheckParmLength(hthandle, newpayloadlength))
			return FALSE;
		WaitForSingleObject(hthandle->Mutex, INFINITE);
		int indexInHT = -1;
		bool updated = false;
		if (hthandle->N != 0)
			for (int i = 0, j = HashFunction(oldelement, hthandle->Capacity, 0);
				GetElementFromHT(hthandle, j) != NULL && i != hthandle->Capacity && !updated;
				j = Next_hash(j, hthandle->Capacity, ++i)) {
			Element* elFromHT = GetElementFromHT(hthandle, j);
			if (!IsDeleted(elFromHT)) {
				if (EqualElementKeys(elFromHT, oldelement)) {
					indexInHT = j; updated = true;
				}
			}
		}
		if (indexInHT < 0) {
			SetErrorMessage(hthandle, "Not found key\n", 15);
			ReleaseMutex(hthandle->Mutex);
			return FALSE;
		}

		UpdateElement(hthandle, GetElementFromHT(hthandle, indexInHT), newpayload, newpayloadlength);
		ReleaseMutex(hthandle->Mutex);
		return TRUE;
	}

	char* GetLastErrorProg(HTHANDLE* ht) {
		return ht->LastErrorMessage;
	}

	void print(const Element* element) {
		char* key = (char*)element->key;
		std::cout << std::right << std::setfill('=') << std::setw(30) << '|' << std::endl;
		std::cout << std::left << std::setfill(' ') << std::setw(10) << "KEY";
		for (int i = 0; i < element->keylength; i++) {
			std::cout << key[i];
		}
		std::cout << std::left << std::setfill(' ') << std::setw(10) << "\nVALUE";
		char* payload = (char*)element->payload;
		for (int i = 0; i < element->payloadlength; i++) {
			std::cout << payload[i];
		}
		std::cout << std::endl;
		std::cout << std::right << std::setfill('=') << std::setw(30) << '|' << std::endl;
	}

	Element* GetElementFromHT(HTHANDLE* ht, int n) {
		void* elementsAddr = ht + 1;
		int defaultElementSize = ht->MaxKeyLength + ht->MaxPayloadLength + 2 * sizeof(int);
		void* elementAddr = (char*)elementsAddr + defaultElementSize * n;

		Element* element = new Element();
		element->key = elementAddr;
		element->keylength = *(int*)((char*)elementAddr + ht->MaxKeyLength);
		element->payload = ((char*)elementAddr + ht->MaxKeyLength + sizeof(int));
		element->payloadlength = *(int*)((char*)elementAddr + ht->MaxKeyLength + sizeof(int) + ht->MaxPayloadLength);
		if (element->keylength == 0) {
			delete element;
			return NULL;
		}
		return element;
	}

	BOOL SetElementToHT(HTHANDLE* ht, Element* element, int n) {
		void* elementsAddr = ht + 1;
		int defaultElementSize = ht->MaxKeyLength + ht->MaxPayloadLength + 2 * sizeof(int);
		void* elementAddr = (char*)elementsAddr + defaultElementSize * n;

		memcpy(elementAddr, element->key, element->keylength);
		memcpy(((char*)elementAddr + ht->MaxKeyLength), &element->keylength, sizeof(int));
		memcpy(((char*)elementAddr + ht->MaxKeyLength + sizeof(int)), element->payload, element->payloadlength);
		memcpy(((char*)elementAddr + ht->MaxKeyLength + sizeof(int) + ht->MaxPayloadLength), &element->payloadlength, sizeof(int));
		return TRUE;
	}

	BOOL IsDeleted(Element* ptr) {
		if (*(int*)ptr->key == -1) {
			return TRUE;
		}
		return FALSE;
	}

	BOOL EqualElementKeys(Element* el1, Element* el2) {
		// print(el1);
		// print(el2);
		return !memcmp(el1->key, el2->key, el2->keylength) ? TRUE : FALSE;
	}

	void SetErrorMessage(HTHANDLE* ht, const char* message, int messageLen) {
		char* err = (char*)message;
		memcpy(ht->LastErrorMessage, err, messageLen);
	}

	void SetDeletedFlag(Element* ptr) {
		memcpy(ptr->key, &DELETED, sizeof(DELETED));
	}

	void UpdateElement(HTHANDLE* ht, Element* el, void* newpayload, int newpayloadlength) {
		ZeroMemory(el->payload, ht->MaxPayloadLength + sizeof(int));
		memcpy(el->payload, newpayload, newpayloadlength);
		memcpy((char*)el->payload + ht->MaxPayloadLength, &newpayloadlength, sizeof(int));
	}

	int HashFunction(const Element* element, int size, int p)    //Хеш-функция
	{
		char* arrKeyBytes = new char[element->keylength];
		memcpy(arrKeyBytes, element->key, element->keylength);
		int sumBytes = 0;
		for (int i = 0; i < element->keylength; i++) {
			sumBytes += arrKeyBytes[i];
		}
		delete[] arrKeyBytes;
		return (p + sumBytes) % size;
	}
	int Next_hash(int hash, int size, int p)
	{
		return (hash + 5 * p + 3 * p * p) % size;
	}

	DWORD WINAPI SnapShotCycle(HTHANDLE* ht) {
		while (true)
		{
			if (ht) {
				if (time(NULL) >= ht->lastsnaptime + ht->SecSnapshotInterval)
				{
					WaitForSingleObject(ht->Mutex, INFINITE);
					if (!FlushViewOfFile(Addr, NULL)) {
						SetErrorMessage(ht, "Snapshot error", 15);
						return FALSE;
					}
					ht->lastsnaptime = time(NULL);
					std::cout << "----SNAPSHOT in Thread----" << std::endl;
					SEQ;
					LOG("----SNAPSHOT in File----", hmodule);

					ReleaseMutex(ht->Mutex);
				}
			}
			else
				break;
		}
		return TRUE;
	}

	wchar_t* GenerateMutexName(const wchar_t* pathToHT) {
		std::wstring s(pathToHT);
		std::wstring mutexName;
		s.erase(std::remove(s.begin(), s.end(), '\\'), s.end());
		std::wcout << s;
		return (wchar_t*)s.c_str();
	}
	wchar_t* GenerateViewName(const wchar_t* pathToHT) {
		std::wstring s(pathToHT);
		std::wstring mutexName;
		s.erase(std::remove(s.begin(), s.end(), '\\'), s.end());
		std::wcout << s;
		return (wchar_t*)s.c_str();
	}

	BOOL CheckParmLength(HTHANDLE* ht, Element* element) {
		if (element->keylength > ht->MaxKeyLength) {
			SetErrorMessage(ht, "KeyLength > maxKeyLength\n", strlen("KeyLength > maxKeyLength\n") + 1);
			return FALSE;
		}
		if (element->payloadlength > ht->MaxPayloadLength) {
			SetErrorMessage(ht, "PayloadLength > maxPayloadLength\n", strlen("PayloadLength > maxPayloadLength\n") + 1);
			return FALSE;
		}
		return TRUE;
	}

	BOOL CheckParmLength(HTHANDLE* ht, int payloadLength) {
		if (payloadLength > ht->MaxPayloadLength) {
			SetErrorMessage(ht, "PayloadLength > maxPayloadLength\n", strlen("PayloadLength > maxPayloadLength\n") + 1);
			return FALSE;
		}
		return TRUE;
	}
}