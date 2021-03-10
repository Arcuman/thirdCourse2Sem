#include <Windows.h>
#include "HT.h"
#include <string>
#include <iostream>
#include <algorithm>	

using namespace std;

namespace HT {

	const wchar_t* GetWC(const char* c)
	{
		const size_t cSize = strlen(c) + 1;
		wchar_t* wc = new wchar_t[cSize];
		size_t outSize;
		mbstowcs_s(&outSize, wc, cSize, c, cSize - 1);

		return wc;
	}

#pragma region constructors

	HTHANDLE::HTHANDLE() {
	}
	HTHANDLE::HTHANDLE(int Capacity, int SecSnapshotInterval, int MaxKeyLength, int MaxPayloadLength, const wchar_t FileName[512]) {
		this->Capacity = Capacity;
		this->SecSnapshotInterval = SecSnapshotInterval;
		this->MaxKeyLength = MaxKeyLength;
		this->MaxPayloadLength = MaxPayloadLength;
		wcscpy_s(this->FileName, _countof(this->FileName), FileName);

	}

#pragma endregion

	//open map file and return hthandle, that was mapped there
	// != NULL успешное завершение  
	HTHANDLE* OpenHtFromFile     //  открыть HT             
	(
		const wchar_t    FileName[512]         // имя файла 
	) {
		HANDLE hf = NULL;
		HANDLE hm = NULL;
		try {
			hf = CreateFile(
				FileName,
				GENERIC_READ | GENERIC_WRITE,
				NULL,
				NULL,
				OPEN_ALWAYS,
				FILE_ATTRIBUTE_NORMAL,
				NULL
			);
			if (hf == INVALID_HANDLE_VALUE)
				throw "create file error";

			//map file name
			wstring mapFileName = wstring(FileName);
			std::replace(mapFileName.begin(), mapFileName.end(), '\\', '_');
			mapFileName += L"map";

			hm = CreateFileMapping(
				hf,
				NULL,
				PAGE_READWRITE,
				0, 0, mapFileName.c_str());
			if (!hm) throw "create filemapping error";

			LPVOID lp = MapViewOfFile(
				hm,
				FILE_MAP_ALL_ACCESS,
				0, 0, 0);
			if (!lp) throw "mapping file error";

			byte* pointer = (byte*)lp;

			HTHANDLE* ht = (HTHANDLE*)pointer;
			ht->Addr = pointer + sizeof(HTHANDLE);
			ht->File = hf;
			ht->FileMapping = hm;

			wcscpy_s(ht->FileName, _countof(ht->FileName), FileName);

			//mutex name
			wstring mutexName = wstring(FileName);
			std::replace(mutexName.begin(), mutexName.end(), '\\', '_');
			mutexName += L"mutex";
			wcscpy_s(ht->mutexName, _countof(ht->mutexName), mutexName.c_str());

			//mpa file name
			wcscpy_s(ht->fileMapName, _countof(ht->fileMapName), mapFileName.c_str());

			////timer name
			//wstring timerName = wstring(FileName);
			//std::replace(timerName.begin(), timerName.end(), '\\', '_');
			//timerName += L"timer";
			//wcscpy_s(ht->timerName, _countof(ht->timerName), timerName.c_str());

			//timer
			DWORD   dwThreadId;

			//ht->hTimerThread = NULL;
			//ht->hTimerThread = CreateThread(
			//	NULL,                   // default security attributes
			//	0,                      // use default stack size  
			//	PeriodicSnapShot,       // thread function name
			//	ht,          // argument to thread function 
			//	0,                      // use default creation flags 
			//	&dwThreadId);   // returns the thread identifier 

			//if (ht->hTimerThread == NULL)
			//{
			//	throw "Creating snap shot thread error";
			//}

			return ht;
		}
		catch (char* e) {
			cout << "\nerror: " << e;
			CloseHandle(hf);
			CloseHandle(hm);
			DWORD er = _Post_equals_last_error_::GetLastError();
			er = er;
		}
		catch (const char* e) {
			cout << "\nerror: " << e;
			CloseHandle(hf);
			CloseHandle(hm);
			DWORD er = _Post_equals_last_error_::GetLastError();
			er = er;
		}
		return NULL;
	}

	// != NULL успешное завершение  
	HTHANDLE* Create   //  создать HT             
	(
		int	  Capacity,					   // емкость хранилища
		int   SecSnapshotInterval,		   // переодичность сохранения в сек.
		int   MaxKeyLength,                // максимальный размер ключа
		int   MaxPayloadLength,            // максимальный размер данных
		const char  FileName[512]          // имя файла 
	) {
		const wchar_t* wFileName = GetWC(FileName);
		HTHANDLE* ht = OpenHtFromFile(wFileName);
		if (ht == NULL) {
			return NULL;
		}

		//clear memory, that may contains old elements
		int totalHtSize = 0;
		totalHtSize += Capacity * (sizeof(Element) + MaxKeyLength + MaxPayloadLength);
		//ZeroMemory(ht->Addr, totalHtSize);

		ht->Capacity = Capacity;
		ht->SecSnapshotInterval = SecSnapshotInterval;
		ht->MaxKeyLength = MaxKeyLength;
		ht->MaxPayloadLength = MaxPayloadLength;
		//ht->creatorPid = GetCurrentProcessId();

		return ht;
	}
}