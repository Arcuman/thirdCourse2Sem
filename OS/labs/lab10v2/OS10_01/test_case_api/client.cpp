// OS10_02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "OS10_HTAPI.h"
using namespace HT;

void printStr(char* str) {
	std::cout << "ERROR:\t";
	int i = 0;
	while (str[i]) {
		std::cout << str[i];
		i++;
	}
	std::cout << std::endl;
}

bool CREATE_TEST()
{
	int capacity = 10;
	int capacity2 = 4;
	int snapshotIntervalSec = 2;
	int maxKeyLength = 10;
	int maxKeyLength2 = 4;
	int maxPayloadLength = 10;
	const wchar_t* fileName = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab10v2\\HT\\test.ht";
	HT::HTHANDLE* HT;
	try {
		HT = HT::Create(capacity, snapshotIntervalSec, maxKeyLength, maxPayloadLength, fileName);
		if (HT == NULL)
			throw "Invalid handle";
		HT::Close(HT);
	}
	catch (const char* err) {
		std::cout << err << std::endl;
		return false;
	}
	return true;
}

bool INSERT_TEST()
{
	int capacity = 10;
	int snapshotIntervalSec = 2;
	int maxKeyLength = 10;
	int maxPayloadLength = 10;
	const wchar_t* fileName = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab10v2\\HT\\test.ht";
	HT::HTHANDLE* HT;
	try {
		HT = HT::Open(fileName);
		if (HT == NULL)
			throw "Invalid handle";
		HT::Element* el;
		HT::Element* el1 = new HT::Element("key1", 5, "hello", 7);
		if (!HT::Insert(HT, el1)) {
			printStr(HT::GetLastError(HT));
			return false;
		}
		if ((el = HT::Get(HT, el1)) == NULL)
			printStr(HT::GetLastError(HT));
		else
			HT::print(el);
		HT::Close(HT);
	}
	catch (const char* err) {
		std::cout << err << std::endl;
		return false;
	}
	return true;
}

bool UPDATE_TEST()
{
	int capacity = 10;
	int snapshotIntervalSec = 2;
	int maxKeyLength = 10;
	int maxPayloadLength = 10;
	const wchar_t* fileName = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab10v2\\HT\\test.ht";
	HT::HTHANDLE* HT;
	try {
		HT = HT::Open(fileName);
		if (HT == NULL)
			throw "Invalid handle";
		HT::Element* el;
		HT::Element* el1 = new HT::Element("key1", 5, "hello", 7);
		HT::Element* el3 = new HT::Element("key1", 5, "world", 6);
		if (!HT::Update(HT, el1, el3->payload, el3->payloadlength)) {
			printStr(HT::GetLastError(HT));
			return false;
		}
		if ((el = HT::Get(HT, el1)) == NULL) {
			printStr(HT::GetLastError(HT));
			HT::Close(HT);
			return false;
		}
		else
			HT::print(el);
		HT::Close(HT);
	}
	catch (const char* err) {
		std::cout << err << std::endl;
		return false;
	}
	return true;
}

bool DELETE_TEST()
{
	int capacity = 10;
	int snapshotIntervalSec = 2;
	int maxKeyLength = 10;
	int maxPayloadLength = 10;
	const wchar_t* fileName = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab10v2\\HT\\test.ht";
	try {
		HT::HTHANDLE* HT = HT::Open(fileName);
		if (HT == NULL)
			throw "Invalid handle";
		HT::Element* el;
		HT::Element* el1 = new HT::Element("key1", 5, "hello", 7);
		if (!HT::Delete(HT, el1)) {
			printStr(HT::GetLastError(HT));
			HT::Close(HT);
			return false;
		}
		if ((el = HT::Get(HT, el1)) == NULL)
		{
			HT::Close(HT);
			return true;
		}
		HT::Close(HT);
		return false;
	}
	catch (const char* err) {
		std::cout << err << std::endl;
		return false;
	}
	return true;
}

int main()
{

	if (CREATE_TEST()) {
		std::cout << "Success create test" << std::endl;
	}
	else {
		std::cout << "Failed test" << std::endl;
	}
	if (INSERT_TEST()) {
		std::cout << "Success insert test" << std::endl;
	}
	else {
		std::cout << "Failed test" << std::endl;
	}
	if (UPDATE_TEST()) {
		std::cout << "Success update test" << std::endl;
	}
	else {
		std::cout << "Failed test" << std::endl;
	}
	if (DELETE_TEST()) {
		std::cout << "Success delete test" << std::endl;
	}
	else {
		std::cout << "Failed test" << std::endl;
	}
	return 0;
}
