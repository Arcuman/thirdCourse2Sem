#pragma once
#define _SILENCE_EXPERIMENTAL_FILESYSTEM_DEPRECATION_WARNING
#include <Windows.h>
#include <windef.h>
#include <iostream>
#include <string>
#include <experimental/filesystem>


namespace HT
{
	// API HT - программный интерфейс для доступа к HT-хранилищу
	//			HT - хранилище предназначено для хранения данных в ОП в формате ключ/значение
	//			Персистентность (сохранность) данных обеспечивается с помощью snapshot - механизма
	//			Create	- создать и открыть HT-хранилище для использования
	//			Open	- открыть HT-хранилище для использования
	//			Insert	- создать элемент данных
	//			Delete	- удалить элемент данных
	//			Get		- читать элемент данных
	//			Update	- изменить элемент данных
	//			Snap	- выполнить snapshot
	//			Close	- выполнить Snap и закрыть HT-хранилище для использования
	//			GetLastError - получить сообщения о последней ошибке


	struct HTHANDLE
	{
		HTHANDLE();
		HTHANDLE(int Capacity, int SecSnapshotInterval, int MaxKeyLength, int MaxPayloadLength, const wchar_t FileName[512]);
		int		Capacity;
		int		CurrentCapacity;
		int		SecSnapshotInterval;
		int		MaxKeyLength;
		int		MaxPayloadLength;
		wchar_t	FileName[512];
		HANDLE	File;
		HANDLE	FileMapping;
		HANDLE	Mutex;
		HANDLE	SnapThread;
		LPVOID	Addr;
		char	LastErrorMessage[512];
		time_t	LastSnapTime;
	};

	struct Element
	{
		Element();
		Element(const void* Key, int KeyLength);
		Element(const void* Key, int KeyLength, const void* Payload, int PayloadLength);
		Element(Element* OldElement, const void* NewPayload, int NewPayloadLegth);
		void* Key;
		int		KeyLength;
		void* Payload;
		int		PayloadLength;
	};

	HTHANDLE* Create(int Capacity, int SecSnapshotInterval, int MaxKeyLength, int MaxPayloadLength, const wchar_t FileName[512]);

	HTHANDLE* Open(const wchar_t fileName[512]);

	BOOL Snap(HTHANDLE* htHandle);

	BOOL Close(const HTHANDLE* htHandle);

	BOOL Insert(HTHANDLE* htHandle, const Element* element);

	BOOL Delete(HTHANDLE* htHandle, const Element* element);

	Element* Get(const HTHANDLE* htHandle, const Element* element);

	BOOL Update(const HTHANDLE* htHandle, const Element* oldElement, const void* newPayload, int newPayloadLength);

	char* GetLastError(HTHANDLE* ht);

	void print(const Element* element);
}