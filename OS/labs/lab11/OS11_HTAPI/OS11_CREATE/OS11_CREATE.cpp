// OS11_CREATE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "OS11_HTAPI.h"
#include <wchar.h>



wchar_t* GetWC(const char* c)
{
	const size_t cSize = strlen(c) + 1;
	wchar_t* wc = new wchar_t[cSize];
	mbstowcs(wc, c, cSize);

	return wc;
}

int main(int argc, char* argv[])
{
	int capacity = 10;
	int snapshotIntervalSec = 2;
	int maxKeyLength = 10;
	int maxPayloadLength = 10;
	wchar_t* fileName;
	const wchar_t* directoryPath = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab11\\HT\\";
	std::wstring filePath (L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab11\\HT\\test.ht");
	try {
	if (argv[1]) {
		fileName = GetWC(argv[1]);
		std::wstring s(directoryPath);
		s += std::wstring(fileName);
		filePath = s;
	}
	else {

	}
	HT::HTHANDLE* HT;
		HT = HT::Create(capacity, snapshotIntervalSec, maxKeyLength, maxPayloadLength, filePath.c_str());
		if (HT == NULL)
			throw "Invalid handle";
		HT::Close(HT);
		std::cout << "HT-Storage Created " << std::endl;
		std::wcout << "filename: " << filePath << std::endl;
		std::cout << "snapshotIntervalSec: " << snapshotIntervalSec << std::endl;
		std::cout << "capacity: " << capacity << std::endl;
		std::cout << "maxKeyLength: " << maxKeyLength << std::endl;
		std::cout << "maxPayloadLength: " << maxPayloadLength << std::endl;
	}
	catch (const char* err) {
		std::cout << err << std::endl;
		return 1;
	}
	return 0;
}
