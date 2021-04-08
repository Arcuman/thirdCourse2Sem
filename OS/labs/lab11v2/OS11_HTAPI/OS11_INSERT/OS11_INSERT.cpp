// OS11_CREATE.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <iostream>
#include "OS11_HTAPI.h"
#include <string>
#include <sstream>
#include <wchar.h>
#include <ctime>

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
	srand(time(0));
	int capacity = 10;
	int snapshotIntervalSec = 2;
	int maxKeyLength = 10;
	int maxPayloadLength = 10;
	wchar_t* fileName;
	const wchar_t* directoryPath = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab11v2\\HT\\";
	std::wstring filePath(L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab11v2\\HT\\test.ht");
	try {
		if (argv[1]) {
			fileName = GetWC(argv[1]);
			std::wstring s(directoryPath);
			s += std::wstring(fileName);
			filePath = s;
		}
		std::wcout << "filename: " << filePath << std::endl;
		HT::HTHANDLE* HT;
		HT = HT::OpenExist(filePath.c_str());
		std::cout << HT;
		if (HT == NULL)
			throw "Invalid handle";

		for (; ; ) {
			int numberKey = rand() % 50 + 1;
			std::string key;
			std::stringstream convert;
			convert << numberKey;
			key = convert.str();
			std::cout << key << ' ' << key.length() << std::endl;
			HT::Element* el;
			HT::Element* el1 = new HT::Element(key.c_str(), key.length() + 1, "0", 2);
			if (!HT::Insert(HT, el1)) {
				printStr(HT::GetLastErrorProg(HT));
			}
			else if ((el = HT::Get(HT, el1)) == NULL)
				printStr(HT::GetLastErrorProg(HT));
			else if(el)
				HT::print(el); 
			Sleep(1000);
		}

		int key;
		std::cin >> key;
		// HT::CloseExist(HT);
	}
	catch (const char* err) {
		std::cout << err << std::endl;
		return 1;
	}
	return 0;
}
