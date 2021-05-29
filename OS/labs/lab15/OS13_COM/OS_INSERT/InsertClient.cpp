#include <iostream>
#include "OS13_HTCOM.h"
#include "INTERFACE.h"
#include <string>
#include <string>
#include <sstream>
#include <ctime>
#define IERR(s)    std::cout<<"error "<<s<<std::endl
#define IRES(s,r)  std::cout<<s<<r<<std::endl

IOS13* pIOS13 = nullptr;

void printStr(char* str) {
	std::cout << "ERROR:\t";
	int i = 0;
	while (str[i]) {
		std::cout << str[i];
		i++;
	}
	std::cout << std::endl;
}



int main(int argc, char* argv[])
{
	wchar_t* fileName;
	HT::HTHANDLE* HT;
	const wchar_t* directoryPath = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab15\\HT\\";
	std::wstring filePath(L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab15\\HT\\test.ht");
	if (argv[1]) {
		fileName = HTAPI::GetWC(argv[1]);
		std::wstring s(directoryPath);
		s += std::wstring(fileName);
		filePath = s;
	}
	else {
		printf("\nProgram need 1 parameter! argc: %d.\nDefault parameters are used", argc);
	}

	if (HTAPI::OpenConnection()) {

		HT = HTAPI::OpenExist(filePath.c_str());

		if (HT != NULL) {
			printf("\nHT-Storage Open filename=%s, snapshotinterval=%d, capacity = %d, maxkeylength = %d, maxdatalength = %d",
				filePath.c_str(), HT->SecSnapshotInterval, HT->Capacity, HT->MaxKeyLength, HT->MaxPayloadLength);
		}
		else {
			printf("\n Cant create Handle");
			if (HTAPI::CloseConnection() == false)
				printf("error with close api\n");
			return -1;
		}


		for (; ; ) {
			int numberKey = rand() % 50 + 1;
			std::string key;
			std::stringstream convert;
			convert << numberKey;
			key = convert.str();
			std::cout << "Key: " << key << std::endl;
			std::string payload = "0";
			HT::Element* el1;
			el1 = HTAPI::CreateElement(&key, &payload);
			if (!el1 != NULL) {
				std::cout << "CreateElement Error" << std::endl;
			}
			bool isSucInsert = HTAPI::Insert(HT, &el1);
			if (!isSucInsert) {
				std::string err = HTAPI::GetLastErrorProg(HT);
				std::cout << err.c_str() << std::endl;
				HTAPI::print(el1);
				Sleep(1000);
				continue;
			}
			std::cout << "Success Insert/Replace" << std::endl;
			Sleep(1000);
		}
		if (HTAPI::CloseConnection() == false)
			printf("error with close api\n");
	}
	else {
		printf("error with open api\n");
	}
	return 0;
}