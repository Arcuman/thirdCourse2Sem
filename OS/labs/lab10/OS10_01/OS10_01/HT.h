#pragma once
#include <Windows.h>

namespace HT    // HT API
{
	// API HT - ����������� ��������� ��� ������� � ��-��������� 
	//          ��-��������� ������������� ��� �������� ������ � �� � ������� ����/��������
	//          ���������������� (�����������) ������ �������������� � ������� snapshot-���������� 
	//          Create - �������  � ������� HT-��������� ��� �������������   
	//          Open   - ������� HT-��������� ��� �������������
	//          Insert - ������� ������� ������
	//          Delete - ������� ������� ������    
	//          Get    - ������  ������� ������
	//          Update - �������� ������� ������
	//          Snap   - �������� snapshot
	//          Close  - ��������� Snap � ������� HT-��������� ��� �������������
	//          GetLastError - �������� ��������� � ��������� ������


	struct HTHANDLE    // ���� ���������� HT
	{
		HTHANDLE();
		HTHANDLE(int Capacity, int SecSnapshotInterval, int MaxKeyLength, int MaxPayloadLength, const wchar_t FileName[512]);
		int     Capacity = 20;               // ������� ��������� � ���������� ��������� 
		int     SecSnapshotInterval = 120;    // ������������� ���������� � ���. 
		int     MaxKeyLength = 64;           // ������������ ����� �����
		int     MaxPayloadLength = 64;       // ������������ ����� ������
		wchar_t    FileName[512] = L"map.txt";          // ��� ����� 
		HANDLE  File = 0;                   // File HANDLE != 0, ���� ���� ������
		HANDLE  FileMapping = 0;            // Mapping File HANDLE != 0, ���� mapping ������  
		LPVOID  Addr = 0;                   // Addr != NULL, ���� mapview ��������. ����� � ����� ���������� ��������  
		char    LastErrorMessage[512] = "\0";  // ��������� �� ��������� ������ ��� 0x00  
		time_t  lastsnaptime = 0;           // ���� ���������� snap'a (time())  

		wchar_t mutexName[512];
		wchar_t fileMapName[512];
		wchar_t timerName[512];

		DWORD creatorPid;
		HANDLE hTimer;
		HANDLE hTimerThread;
	};

	struct Element   // ������� 
	{
		Element();
		Element(const void* key, int keylength);                                             // for Get
		Element(const void* key, int keylength, const void* payload, int  payloadlength);    // for Insert
		Element(Element* oldelement, const void* newpayload, int  newpayloadlength);         // for update
		void* key;                 // �������� ����� 
		int             keylength;           // ������ �����
		void* payload;             // ������ 
		int             payloadlength;       // ������ ������
	};

	HTHANDLE* Create   //  ������� HT             
	(
		int	  Capacity,					   // ������� ���������
		int   SecSnapshotInterval,		   // ������������� ���������� � ���.
		int   MaxKeyLength,                // ������������ ������ �����
		int   MaxPayloadLength,            // ������������ ������ ������
		const char  FileName[512]          // ��� ����� 
	); 	// != NULL �������� ����������  

	HTHANDLE* Open     //  ������� HT             
	(
		const char    FileName[512]         // ��� ����� 
	); 	// != NULL �������� ����������  

	BOOL Snap         // ��������� Snapshot
	(
		const HTHANDLE* hthandle           // ���������� HT (File, FileMapping)
	);


	BOOL Close        // Snap � ������� HT  �  �������� HTHANDLE
	(
		const HTHANDLE* hthandle           // ���������� HT (File, FileMapping)
	);	//  == TRUE �������� ����������   


	BOOL Insert      // �������� ������� � ���������
	(
		const HTHANDLE* hthandle,            // ���������� HT
		const Element* element              // �������
	);	//  == TRUE �������� ���������� 


	BOOL Delete      // ������� ������� � ���������
	(
		const HTHANDLE* hthandle,            // ���������� HT (����)
		const Element* element              // ������� 
	);	//  == TRUE �������� ���������� 

	Element* Get     //  ������ ������� � ���������
	(
		const HTHANDLE* hthandle,            // ���������� HT
		const Element* element              // ������� 
	); 	//  != NULL �������� ���������� 

	int PrintAll     // print all elements aand return their count
	(
		HTHANDLE* ht           // ���������� HT
	); 	//  != NULL �������� ���������� 


	BOOL Update     //  ������� ������� � ���������
	(
		const HTHANDLE* hthandle,            // ���������� HT
		const Element* oldelement,          // ������ ������� (����, ������ �����)
		const void* newpayload,          // ����� ������  
		int             newpayloadlength     // ������ ����� ������
	); 	//  != NULL �������� ���������� 

	char* GetLastError1  // �������� ��������� � ��������� ������
	(
		HTHANDLE* ht                         // ���������� HT
	);

	void print                               // ����������� ������� 
	(
		const Element* element              // ������� 
	);


};
