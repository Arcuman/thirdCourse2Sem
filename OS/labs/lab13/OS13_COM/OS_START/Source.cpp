#include <iostream>
#include "OS13_HTCOM.h"
#include <string>
#define IERR(s)    std::cout<<"error "<<s<<std::endl
#define IRES(s,r)  std::cout<<s<<r<<std::endl


int main(int argc, char* argv[])
{
	wchar_t* fileName;
	HT::HTHANDLE* HT;
	const wchar_t* directoryPath = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab13\\HT\\";
	std::wstring filePath(L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab13\\HT\\test.ht");
	std::wstring userName;
	std::wstring password;
	if (argv[1] && argv[2] && argv[3]) {
		fileName = HTAPI::GetWC(argv[1]);
		std::wstring s(directoryPath);
		s += std::wstring(fileName);
		filePath = s;

		fileName = HTAPI::GetWC(argv[2]);
		userName = std::wstring(fileName);

		fileName = HTAPI::GetWC(argv[3]);
		password = std::wstring(fileName);
	}
	else {
		printf("\nProgram need 1 parameter! argc: %d.\nDefault parameters are used", argc);
	}

	if (HTAPI::OpenConnection()) {
		if (userName.empty()) {
			HT = HTAPI::Open(filePath.c_str());
		}
		else {
			HT = HTAPI::Open(filePath.c_str(), userName.c_str(), password.c_str());
		}

		if (HT != NULL) {
			printf("\nHT-Storage Open filename=%s, snapshotinterval=%d, capacity = %d, maxkeylength = %d, maxdatalength = %d",
				filePath.c_str(), HT->SecSnapshotInterval, HT->Capacity, HT->MaxKeyLength, HT->MaxPayloadLength);

			int key;
			std::cin >> key;

			bool s = HTAPI::Close(HT);
		}
		else {
			printf("\n some error fail@");
		}

		if (HTAPI::CloseConnection() == false)
			printf("error with close api\n");
	}
	else {
		printf("error with open api\n");
	}
	return 0;
}