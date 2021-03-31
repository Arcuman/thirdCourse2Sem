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
	int capacity = 10;
	int snapshotIntervalSec = 2;
	int maxKeyLength = 10;
	int maxPayloadLength = 10;
	wchar_t* fileName;
	const wchar_t* directoryPath = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab11\\HT\\";
	std::wstring filePath(L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab11\\HT\\test1");
	try {
		HT::HTHANDLE* HT;
		HT = HT::OpenExist(filePath.c_str());
		if (HT == NULL)
			throw "Invalid handle";
		std::cout << HT->FileMapping;
		//HT::Element* el;
		//HT::Element* el1 = new HT::Element("key1", 5, "hello", 7);
		//if (!HT::Insert(HT, el1)) {
		//	printStr(HT::GetLastErrorProg(HT));
		//	return false;
		//}
		//if ((el = HT::Get(HT, el1)) == NULL)
		//	printStr(HT::GetLastErrorProg(HT));
		//else
		//	HT::print(el);
		int key;
		std::cin >> key;
		HT::CloseExist(HT);
	}
	catch (const char* err) {
		std::cout << err << std::endl;
		return 1;
	}
	return 0;
}
