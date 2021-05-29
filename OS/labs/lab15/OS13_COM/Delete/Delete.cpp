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
			HT::Element* findElem;
			el1 = HTAPI::CreateElement(&key, &payload);
			if (el1 == NULL) {
				std::cout << "CreateElement ERROR" << std::endl;
				return -1;
			}
			findElem = HTAPI::Get(HT, el1);
			if (findElem == NULL) {
				std::string err = HTAPI::GetLastErrorProg(HT);
				std::cout << err.c_str() << std::endl;
				std::cout << "ELEMENT NOT FOUND" << std::endl;
				Sleep(1000);
				continue;
			}
			
			bool isSucDelete = HTAPI::Delete(HT, findElem);
			if (!isSucDelete) {
				std::string err = HTAPI::GetLastErrorProg(HT);
				std::cout << err.c_str() << std::endl;
				Sleep(1000);
				continue;
			}
			std::cout << "Success Delete" << std::endl;
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


//
//
//int main()
//{
//	IUnknown* pIUnknown = NULL;
//	CoInitialize(NULL);// инициализация библиотеки OLE32
//	HRESULT hr0 = CoCreateInstance(CLSID_CA, NULL, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pIUnknown);
//	if (SUCCEEDED(hr0))
//	{
//		std::cout << "CoCreateInstance succeeded" << std::endl;
//		if (SUCCEEDED(pIUnknown->QueryInterface(IID_IOS13, (void**)&pIOS13)))
//		{
//			std::wstring filePath(L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab13\\HT\\test.ht");
//
//			HT::HTHANDLE* pht;
//			if (SUCCEEDED(pIOS13->OpenExist(filePath.c_str(), &pht))) {
//				std::cout << "Open Success";
//				std::string err;
//				for (; ; ) {
//					int numberKey = rand() % 50 + 1;
//					std::string key;
//					std::stringstream convert;
//					convert << numberKey;
//					key = convert.str();
//					std::cout << "Key: " << key << std::endl;
//					std::string payload = "0";
//					HT::Element* res;
//					HT::Element* el1;
//					if (SUCCEEDED(pIOS13->CreateElement(&key, &el1))) {
//						std::cout << "SUCCESS CreateElement" << std::endl;
//					}
//					else {
//						std::cout << "CreateElement Error" << std::endl;
//					}
//					if (SUCCEEDED(pIOS13->Get(&res, &pht, &el1))) {
//						std::cout << "SUCCESS GET" << std::endl;
//						if (!SUCCEEDED(pIOS13->print(&res))) {
//							std::cout << "Print Error" << std::endl;
//							continue;
//						}
//						if (SUCCEEDED(pIOS13->Delete(&pht, &res))) {
//							std::cout << "SUCCESS DELETE" << std::endl;
//						}
//						else {
//							if (SUCCEEDED(pIOS13->GetLastErrorProg(err, &pht))) {
//								std::cout << err.c_str() << std::endl;
//							}
//							else {
//								std::cout << "GetLastErrorProg Error" << std::endl;
//							}
//						}
//					}
//					else {
//						if (SUCCEEDED(pIOS13->GetLastErrorProg(err, &pht))) {
//							std::cout << err.c_str() << std::endl;
//						}
//						else {
//							std::cout << "GetLastErrorProg Error" << std::endl;
//						}
//					}
//					Sleep(1000);
//				}
//			}
//			else {
//				IERR("Open handle error");
//				return NULL;
//			}
//		}
//		else  IERR("IOS13");
//	}
//	else  std::cout << "CoCreateInstance error" << std::endl;
//	pIUnknown->Release();
//	CoFreeUnusedLibraries();                   // завершение работы с библиотекой      
//	system("pause");
//	return 0;
//}