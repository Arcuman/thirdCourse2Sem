#include "HT.h";
#include <iostream>;
#include <stdio.h>;

HT::HTHANDLE* ht = nullptr;

int main() {
	LPCWSTR FileName = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab10\\HT\\test.txt";
	ht = HT::Create(1000, 3, 10, 256, FileName);
	setlocale(LC_ALL, "ru-RU");
}