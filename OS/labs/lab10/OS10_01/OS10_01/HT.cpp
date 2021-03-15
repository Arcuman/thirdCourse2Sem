#include <iostream>
#include <stdio.h>
#include "HT.h";


HT::HTHANDLE* Create(
	int			Capacity,
	int			SecSnapshotInterval,
	int			MaxKeyLength,
	int			MaxPayloadLength,
	LPCWSTR FileName
)
{
	//create or replace file
	HANDLE hHTFile = CreateFile(
		FileName,
		GENERIC_READ | GENERIC_WRITE,
		0,	//sharing not allowed
		NULL,
		CREATE_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	if (hHTFile == INVALID_HANDLE_VALUE) {
		std::cout << "Failed to creat new HT-file";
	}

	//initialize meta and write it to th beginning of file
	HT::HTMeta* pMeta = new HT::HTMeta(
		Capacity,
		SecSnapshotInterval,
		MaxKeyLength,
		MaxPayloadLength
	);
	DWORD numberOfMetaBytesWritten;
	WriteFile(
		hHTFile,
		pMeta,
		sizeof(HT::HTMeta),
		&numberOfMetaBytesWritten,
		NULL
	);

	//!!!!!!!!!!!!
	delete pMeta;
	CloseHandle(hHTFile);

	return HT::Open(FileName);
}