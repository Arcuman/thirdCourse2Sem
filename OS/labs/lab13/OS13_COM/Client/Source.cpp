#include <objbase.h>
#include <iostream>
#include "INTERFACE.h"
#define IERR(s)    std::cout<<"error "<<s<<std::endl
#define IRES(s,r)  std::cout<<s<<r<<std::endl

IOS13* pIOS13 = nullptr;


int main()
{
	IUnknown* pIUnknown = NULL;
	CoInitialize(NULL);// инициализация библиотеки OLE32
	HRESULT hr0 = CoCreateInstance(CLSID_CA, NULL, CLSCTX_INPROC_SERVER, IID_IUnknown, (void**)&pIUnknown);
	if (SUCCEEDED(hr0))
	{
		std::cout << "CoCreateInstance succeeded" << std::endl;
		std::cout << "CoCreateInstance succeeded" << std::endl;
		if (SUCCEEDED(pIUnknown->QueryInterface(IID_IOS13, (void**)&pIOS13)))
		{
			int capacity = 1000;
			int snapshotIntervalSec = 2;
			int maxKeyLength = 10;
			int maxPayloadLength = 10;
			wchar_t* fileName;
			const wchar_t* directoryPath = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab11v2\\HT\\";
			std::wstring filePath(L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab13\\HT\\test.ht");
			
			HT::HTHANDLE* pht;
			if (SUCCEEDED(pIOS13->Create(capacity, snapshotIntervalSec, maxKeyLength, maxPayloadLength, filePath.c_str(), &pht))) {
				std::cout << pht;
			}
			else {
				IERR("Create handle error");
				return NULL;
			}
		}
		else  IERR("IOS13");
	}
	else  std::cout << "CoCreateInstance error" << std::endl;
	pIUnknown->Release();
	CoFreeUnusedLibraries();                   // завершение работы с библиотекой      
	system("pause");
	return 0;
}