// OS10_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OS10_HTAPI.h"
using namespace HT;

bool CREATE_TEST()
{
	const wchar_t* FileName = (LPWSTR)L"D:\\bstu\\thirdCourse2Sem\\OS\labs\\lab10\\HT\\test.ht";
	HTHANDLE* hashTable = Create(20, 10, 20, 20, FileName);
	if (hashTable) {
		Close(hashTable);
		return true;
	}
	return false;
}

bool GET_TEST()
{
	const wchar_t* FileName = (LPWSTR)L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab10\\HT\\test.ht";
	std::string key1 = "key1";
	std::string data1 = "data1";
	Element* element1 = new Element(key1.c_str(), key1.length(), data1.c_str(), data1.length());
	HTHANDLE* hashTable = Create(20, 10, 20, 20, FileName);
	Element* finded1 = Get(hashTable, element1);
	if (!finded1) {
		if (!Close(hashTable)) {
			std::cout << "close error";
		}
		return false;
	}
	if (strcmp((char*)element1->Key, (char*)finded1->Key) && strcmp((char*)element1->Payload, (char*)finded1->Payload))
	{
		Close(hashTable);
		return true;
	}

}

int main()
{
	
	if (CREATE_TEST()) {
		std::cout << "Success create test" << std::endl;
	}
	if (GET_TEST()) {
		std::cout << "test failed" << std::endl;
	}
	else {
		std::cout << "test success" << std::endl;
	}
}
