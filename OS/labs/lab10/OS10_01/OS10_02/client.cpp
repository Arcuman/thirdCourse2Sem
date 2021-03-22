// OS10_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OS10_HTAPI.h"
using namespace HT;

int main()
{
	const wchar_t* FileName = (LPWSTR)L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab10\\HT\\example.ht";

	std::experimental::filesystem::path path(FileName);
	std::cout << path.filename() << std::endl;
	std::string key1 = "key1";
	std::string data1 = "data1";
	std::string dataX = "XXXXX";
	std::string key2 = "key2";
	std::string data2 = "data2";

	//HTHANDLE* hashTable = Create(20, 5, 20, 20, FileName);
	HTHANDLE* hashTable = Open(FileName);
	if (!hashTable) {
		return 1;
	}
	Element* element1 = new Element(key1.c_str(), key1.length(), data1.c_str(), data1.length());
	Element* element2 = new Element(key2.c_str(), key2.length(), data2.c_str(), data2.length());
	if (!Insert(hashTable, element1)) {
		std::cout << hashTable->LastErrorMessage;
	}
	if (!Insert(hashTable, element2)) {
		std::cout << hashTable->LastErrorMessage;
	}
	Element* finded1 = Get(hashTable, element1);
	if (finded1 != NULL)
	{
		std::cout << "Finded1: " << (char*)finded1->Key << " " << (char*)finded1->Payload << std::endl;
	}
	Element* finded2 = Get(hashTable, element2);
	if (finded2 != NULL)
	{
		std::cout << "Finded2: " << (char*)finded2->Key << " " << (char*)finded2->Payload << std::endl;
	}
	Delete(hashTable, finded2);
	if (Get(hashTable, finded2) == NULL)
	{
		std::cout << "Deleted successfuly!" << std::endl;
	}
	Update(hashTable, finded1, dataX.c_str(), dataX.length());
	Element* updated1 = Get(hashTable, element1);
	print(updated1);
	Snap(hashTable);
	Sleep(15000);
	Close(hashTable);
}
