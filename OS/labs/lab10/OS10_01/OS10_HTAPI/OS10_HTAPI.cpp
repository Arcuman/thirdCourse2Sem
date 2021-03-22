#include "pch.h"
#include <Windows.h>
#include <iostream>
#include "OS10_HTAPI.h"
typedef unsigned char byte;

#define FULL_ELEMENT_SIZE (sizeof(Element) + htHandle->MaxKeyLength + htHandle->MaxPayloadLength)

using namespace std;

namespace HT
{
	// HTHANDLE Constructors
	HTHANDLE::HTHANDLE() {}
	HTHANDLE::HTHANDLE(int Capacity, int SecSnapshotInterval, int MaxKeyLength, int MaxPayloadLength, const wchar_t FileName[512])
	{
		this->Capacity = Capacity;
		this->CurrentCapacity = 0;
		this->SecSnapshotInterval = SecSnapshotInterval;
		this->MaxKeyLength = MaxKeyLength;
		this->MaxPayloadLength = MaxPayloadLength;
		wcscpy_s(this->FileName, _countof(this->FileName), FileName);
	}


	// Element Constructors
	Element::Element() {}
	Element::Element(const void* Key, int KeyLength)
	{
		this->KeyLength = KeyLength;
		this->Key = (void*)Key;
	}
	Element::Element(const void* Key, int KeyLength, const void* Payload, int PayloadLength)
	{
		this->KeyLength = KeyLength;
		this->Key = (void*)Key;
		this->PayloadLength = PayloadLength;
		this->Payload = (void*)Payload;
	}
	Element::Element(Element* OldElement, const void* NewPayload, int NewPayloadLegth)
	{
		this->PayloadLength = NewPayloadLegth;
		this->Payload = (void*)NewPayload;
		this->KeyLength = OldElement->KeyLength;
		this->Key = OldElement->Key;
	}


	// Helpers
	void CorrectAddresses(HTHANDLE* htHandle)
	{
		//указатель на адресс в памяти
		byte* pointer = (byte*)htHandle->Addr;
		//итерируемся по всем вставленным объектам
		for (int i = 0; i < htHandle->CurrentCapacity; i++)
		{
			byte* currentPointer = pointer + (FULL_ELEMENT_SIZE * i);
			Element* currentElement = (Element*)currentPointer;
			//указатель на ключ
			currentElement->Key = currentPointer + sizeof(Element);
			//указатель на данные
			currentElement->Payload = currentPointer + sizeof(Element) + htHandle->MaxKeyLength;
		}
	}

	const wchar_t* GetWC(const char* c)
	{
		const size_t cSize = strlen(c) + 1;
		wchar_t* wc = new wchar_t[cSize];
		mbstowcs(wc, c, cSize);

		return wc;
	}

	void SetLastErrorMsg(HTHANDLE* ht, string msg)
	{
		strcpy_s(ht->LastErrorMessage, msg.length() + 1, msg.c_str());
	}

	DWORD WINAPI IntervalSnap(LPVOID htHandle);


	// CRUD Functions
	HTHANDLE* Create(int Capacity, int SecSnapshotInterval, int MaxKeyLength, int MaxPayloadLength, const wchar_t FileName[512])
	{
		HTHANDLE* hashTable = new HTHANDLE(Capacity, SecSnapshotInterval, MaxKeyLength, MaxPayloadLength, FileName);
		HANDLE hFile = NULL;
		HANDLE hMap = NULL;
		HANDLE hMutex = NULL;
		DWORD htSize = sizeof(HTHANDLE) + Capacity * (sizeof(Element) + MaxKeyLength + MaxPayloadLength);
		// File path
		experimental::filesystem::path path(FileName);

		try
		{
			hFile = CreateFile(FileName, GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile == NULL)
			{
				throw "File creation error";
			}

			hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, htSize, NULL);
			if (hMap == NULL)
			{
				throw "File Mapping creation error";
			}

			LPVOID lp = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, htSize);
			if (lp == NULL)
			{
				throw "File Mapping View error";
			}

			HTHANDLE* mappedHashTable = new(lp) HTHANDLE(Capacity, SecSnapshotInterval, MaxKeyLength, MaxPayloadLength, FileName);

			hMutex = CreateMutex(NULL, FALSE, path.filename().c_str());
			if (hMutex == NULL)
			{
				throw "Mutex creation error";
			}

			mappedHashTable->Addr = (byte*)lp + sizeof(HTHANDLE);
			mappedHashTable->File = hFile;
			mappedHashTable->FileMapping = hMap;
			mappedHashTable->Mutex = hMutex;

			mappedHashTable->SnapThread = CreateThread(NULL, 0, IntervalSnap, mappedHashTable, 0, NULL);
			if (mappedHashTable->SnapThread == NULL)
			{
				throw "IntervalSnap thread creation error";
			}

			return mappedHashTable;
		}
		catch (char* e) {
			DWORD er = _Post_equals_last_error_::GetLastError();
			cout << "\nerror: " << e << " " << er;
			CloseHandle(hFile);
			CloseHandle(hMap);
			CloseHandle(hMutex);
			return NULL;
		}
		catch (const char* e) {
			DWORD er = _Post_equals_last_error_::GetLastError();
			cout << "\nerror: " << e << " " << er;
			CloseHandle(hFile);
			CloseHandle(hMap);
			CloseHandle(hMutex);
			return NULL;
		}
	}

	HTHANDLE* Open(const wchar_t fileName[512])
	{
		HANDLE hFile = NULL;
		HANDLE hMap = NULL;
		HANDLE hMutex = NULL;

		try
		{
			hFile = CreateFile(fileName, GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hFile == NULL)
			{
				throw "File open error";
			}

			hMap = CreateFileMapping(hFile, NULL, PAGE_READWRITE, 0, 0, L"name");
			if (hMap == NULL)
			{
				throw "File Mapping creation error";
			}

			LPVOID lp = MapViewOfFile(hMap, FILE_MAP_ALL_ACCESS, 0, 0, 0);
			if (lp == NULL)
			{
				throw "File Mapping View error";
			}

			HTHANDLE* mappedHashTable = (HTHANDLE*)lp;
			experimental::filesystem::path path(mappedHashTable->FileName);
			// Create Mutex for sync
			hMutex = CreateMutex(NULL, FALSE, path.filename().c_str());
			if (hMutex == NULL)
			{
				throw "Mutex creation error";
			}

			mappedHashTable->Addr = (byte*)lp + sizeof(HTHANDLE);
			mappedHashTable->File = hFile;
			mappedHashTable->FileMapping = hMap;
			CorrectAddresses(mappedHashTable);

			mappedHashTable->SnapThread = CreateThread(NULL, 0, IntervalSnap, mappedHashTable, 0, NULL);
			if (mappedHashTable->SnapThread == NULL)
			{
				throw "IntervalSnap thread creation error";
			}

			return mappedHashTable;
		}
		catch (char* e) {
			DWORD er = _Post_equals_last_error_::GetLastError();
			cout << "\nerror: " << e << " " << er;
			CloseHandle(hFile);
			CloseHandle(hMap);
			CloseHandle(hMutex);
			return NULL;
		}
		catch (const char* e) {
			DWORD er = _Post_equals_last_error_::GetLastError();
			cout << "\nerror: " << e << " " << er;
			CloseHandle(hFile);
			CloseHandle(hMap);
			CloseHandle(hMutex);
			return NULL;
		}
	}

	BOOL Insert(HTHANDLE* htHandle, const Element* element)
	{
		WaitForSingleObject(htHandle->Mutex, INFINITE);
		if (htHandle->CurrentCapacity == htHandle->Capacity)
		{
			ReleaseMutex(htHandle->Mutex);
			SetLastErrorMsg(htHandle, "Max capacity error");
			return false;
		}

		if (element->KeyLength > htHandle->MaxKeyLength)
		{
			ReleaseMutex(htHandle->Mutex);
			SetLastErrorMsg(htHandle, "Max KeyLength error");
			return false;
		}

		if (element->PayloadLength > htHandle->MaxPayloadLength)
		{
			ReleaseMutex(htHandle->Mutex);
			SetLastErrorMsg(htHandle, "Max PayloadLength error");
			return false;
		}

		byte* newElementAddr = (byte*)htHandle->Addr + (FULL_ELEMENT_SIZE * htHandle->CurrentCapacity);
		Element* ptr = (Element*)newElementAddr;

		ptr->Key = newElementAddr + sizeof(Element);
		ptr->Payload = newElementAddr + sizeof(Element) + htHandle->MaxKeyLength;
		ptr->KeyLength = element->KeyLength;
		ptr->PayloadLength = element->PayloadLength;
		CopyMemory(ptr->Key, element->Key, element->KeyLength);
		CopyMemory(ptr->Payload, element->Payload, element->PayloadLength);

		htHandle->CurrentCapacity++;

		ReleaseMutex(htHandle->Mutex);

		return true;
	}

	Element* Get(const HTHANDLE* htHandle, const Element* element)
	{
		WaitForSingleObject(htHandle->Mutex, INFINITE);

		byte* pointer = (byte*)htHandle->Addr;

		for (int i = 0; i < htHandle->CurrentCapacity; i++)
		{
			byte* currentPointer = pointer + (FULL_ELEMENT_SIZE * i);
			Element* currentElement = (Element*)currentPointer;
			if (currentElement->KeyLength == element->KeyLength &&
				strcmp((char*)currentElement->Key, (char*)element->Key) == 0)
			{
				ReleaseMutex(htHandle->Mutex);
				return currentElement;
			}
		}

		ReleaseMutex(htHandle->Mutex);
		SetLastErrorMsg((HTHANDLE*)htHandle, "Element not found error");
		return NULL;
	}

	BOOL Update(const HTHANDLE* htHandle, const Element* oldElement, const void* newPayload, int newPayloadLength)
	{
		WaitForSingleObject(htHandle->Mutex, INFINITE);

		Element* element = Get(htHandle, oldElement);
		if (element == NULL)
		{
			ReleaseMutex(htHandle->Mutex);
			SetLastErrorMsg((HTHANDLE*)htHandle, "Element not found error");
			return false;
		}

		element->PayloadLength = newPayloadLength;
		CopyMemory(element->Payload, newPayload, newPayloadLength);

		ReleaseMutex(htHandle->Mutex);
		return true;
	}

	BOOL Delete(HTHANDLE* htHandle, const Element* element)
	{
		WaitForSingleObject(htHandle->Mutex, INFINITE);

		Element* deletedElement = Get(htHandle, element);
		if (deletedElement == NULL)
		{
			ReleaseMutex(htHandle->Mutex);
			SetLastErrorMsg((HTHANDLE*)htHandle, "Element not found error");
			return false;
		}

		byte* deletedElementPtr = (byte*)deletedElement;
		byte* firstElementPtr = (byte*)htHandle->Addr;
		int deletedElementIndex = (deletedElementPtr - firstElementPtr) / FULL_ELEMENT_SIZE;

		// Zero deletedElement memory
		ZeroMemory(deletedElementPtr, FULL_ELEMENT_SIZE);

		// We have to replace elements after deletedElement
		byte* currentElementPtr = deletedElementPtr;
		for (int i = deletedElementIndex; i < htHandle->Capacity; i++)
		{
			// When the last element
			if (i == htHandle->Capacity - 1)
			{
				ZeroMemory(currentElementPtr, FULL_ELEMENT_SIZE);
				htHandle->CurrentCapacity--;
				ReleaseMutex(htHandle->Mutex);
				return true;
			}

			byte* nextElementPtr = currentElementPtr + FULL_ELEMENT_SIZE;
			CopyMemory(currentElementPtr, nextElementPtr, FULL_ELEMENT_SIZE);
			currentElementPtr = nextElementPtr;
		}
	}

	BOOL Close(const HTHANDLE* htHandle)
	{
		WaitForSingleObject(htHandle->Mutex, INFINITE);
		TerminateThread(htHandle->SnapThread, 0);
		if (CloseHandle(htHandle->SnapThread) &&
			CloseHandle(htHandle->FileMapping) &&
			CloseHandle(htHandle->File) &&
			ReleaseMutex(htHandle->Mutex) &&
			CloseHandle(htHandle->Mutex) &&
			UnmapViewOfFile(htHandle)
			)
		{
			return true;
		}

		return false;
	}

	BOOL Snap(HTHANDLE* htHandle)
	{
		WaitForSingleObject(htHandle->Mutex, INFINITE);

		DWORD htSize = sizeof(HTHANDLE) + htHandle->Capacity * FULL_ELEMENT_SIZE;
		if (!FlushViewOfFile(htHandle, htSize))
		{
			SetLastErrorMsg(htHandle, "FlushViewOfFile error");
			ReleaseMutex(htHandle->Mutex);
			return false;
		}

		time(&htHandle->LastSnapTime);
		char* buffer = new char[250];
		ctime_s(buffer, 250, &htHandle->LastSnapTime);

		tm* time = new tm();
		localtime_s(time, &htHandle->LastSnapTime);
		strftime(buffer, 32, "_%d_%m_%Y__%H_%M_%S", time);
		delete time;
		wstring snapFileName = wstring(htHandle->FileName);
		snapFileName.replace(snapFileName.find('.'), 0, GetWC(buffer));
		delete[] buffer;

		HANDLE fileHandle = CreateFile(snapFileName.c_str(), GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
		if (fileHandle == INVALID_HANDLE_VALUE)
		{
			SetLastErrorMsg(htHandle, "Snap file creation error");
			ReleaseMutex(htHandle->Mutex);
			return false;
		}

		WriteFile(fileHandle, htHandle, htSize, NULL, NULL);

		ReleaseMutex(htHandle->Mutex);
		return true;
	}

	DWORD WINAPI IntervalSnap(LPVOID htHandle)
	{
		HTHANDLE* hashTable = (HTHANDLE*)htHandle;
		while (1)
		{
			Sleep(hashTable->SecSnapshotInterval * 1000);
			Snap(hashTable);
		}
	}

	char* GetLastError(HTHANDLE* ht)
	{
		return ht->LastErrorMessage;
	}

	void print(const Element* element)
	{
		printf("\nElement Key: %s, Value: %s", (char*)element->Key, (char*)element->Payload);
	}
}