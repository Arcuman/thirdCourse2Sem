#pragma once
#include <Windows.h>
#include "INTERFACE.h"
#include <string>

namespace HTAPI    // HT API
{
	bool OpenConnection();
	bool CloseConnection();


	HT::HTHANDLE* Create   //  ������� HT             
	(
		int	  Capacity,					   // ������� ���������
		int   SecSnapshotInterval,		   // ������������� ���������� � ���.
		int   MaxKeyLength,                // ������������ ������ �����
		int   MaxPayloadLength,            // ������������ ������ ������
		const wchar_t   FileName[512]          // ��� ����� 
	);

	HT::HTHANDLE* Open     //  ������� HT             
	(
		const wchar_t     FileName[512]         // ��� ����� 
	); 	// != NULL �������� ����������  

	HT::HTHANDLE* OpenExist     //  ������� HT             
	(
		const wchar_t     FileName[512]         // ��� ����� 
	); 	// != NULL �������� ����������  

	BOOL Snap         // ��������� Snapshot
	(
		HT::HTHANDLE* hthandle           // ���������� HT (File, FileMapping)
	);


	BOOL Close        // Snap � ������� HT  �  �������� HT::HTHANDLE
	(
		HT::HTHANDLE* hthandle           // ���������� HT (File, FileMapping)
	);	//  == TRUE �������� ����������   


	BOOL Insert      // �������� ������� � ���������
	(
		HT::HTHANDLE* hthandle,            // ���������� HT
		HT::Element** element              // �������
	);	//  == TRUE �������� ���������� 


	BOOL Delete      // ������� ������� � ���������
	(
		HT::HTHANDLE* hthandle,            // ���������� HT (����)
		HT::Element* element              // ������� 
	);	//  == TRUE �������� ���������� 

	HT::Element* Get     //  ������ ������� � ���������
	(
		HT::HTHANDLE* hthandle,            // ���������� HT
		HT::Element* element              // ������� 
	); 	//  != NULL �������� ���������� 


	BOOL Update     //  ������� ������� � ���������
	(
		HT::HTHANDLE* hthandle,            // ���������� HT
		HT::Element* oldelement,          // ������ ������� (����, ������ �����)
		void* newpayload,          // ����� ������  
		int             newpayloadlength     // ������ ����� ������
	); 	//  != NULL �������� ���������� 

	std::string GetLastErrorProg  // �������� ��������� � ��������� ������
	(
		HT::HTHANDLE* ht                         // ���������� HT
	);


	HT::Element* CreateElement     //  ������ ������� � ���������
	(
		std::string* key         // ������� 
	); 	//  != NULL �������� ���������� 

	HT::Element* CreateElement     //  ������ ������� � ���������
	(
		std::string* key,
		std::string* payload      // ������� 
	); 	//  != NULL �������� ���������� 

	BOOL print  // �������� ��������� � ��������� ������
	(
		HT::Element* oldelement                       // ���������� HT
	);

	wchar_t* GetWC(const char* c);

};
