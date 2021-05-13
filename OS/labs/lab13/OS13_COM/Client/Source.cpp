#include <objbase.h>
#include <iostream>
#include "OS13_HTCOM.h"
#include <string>
#define IERR(s)    std::cout<<"error "<<s<<std::endl
#define IRES(s,r)  std::cout<<s<<r<<std::endl


int main(int argc, char* argv[])
{
	int capacity = 2000, maxKeyLength = 4, maxPayloadLength = 4, snapshotIntervalSec = 2;
	wchar_t* fileName;
	HT::HTHANDLE* HT;
	const wchar_t* directoryPath = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab13\\HT\\";
	std::wstring filePath(L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab13\\HT\\test.ht");
	if (argv[1] && argv[2] && argv[3] && argv[4] && argv[5]) {
		capacity = std::stoi(argv[2]);
		snapshotIntervalSec = std::stoi(argv[3]);
		maxKeyLength = std::stoi(argv[4]);
		maxPayloadLength = std::stoi(argv[5]);
		fileName = HTAPI::GetWC(argv[1]);
		std::wstring s(directoryPath);
		s += std::wstring(fileName);
		filePath = s;
	}
	else {
		printf("\nProgram need 5 parameters! argc: %d.\nDefault parameters are used", argc);
	}

	if (HTAPI::OpenConnection()) {

		HT = HTAPI::Create(capacity, snapshotIntervalSec, maxKeyLength, maxPayloadLength, filePath.c_str());

		if (HT != NULL) {
			printf("\nHT-Storage Created filename=%s, snapshotinterval=%d, capacity = %d, maxkeylength = %d, maxdatalength = %d",
				filePath.c_str(), snapshotIntervalSec, capacity, maxKeyLength, maxPayloadLength);
		}
		else {
			printf("\n some error fail");
		}


		bool s = HTAPI::Close(HT);


		if (HTAPI::CloseConnection() == false)
			printf("error with close api\n");
	}
	else {
		printf("error with open api\n");
	}
	return 0;
}