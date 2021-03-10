#include "HT.h";
#include <iostream>;

HT::HTHANDLE* ht = nullptr;

int main() {
	LPCSTR FileName = "D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab10\\HT\\test.txt";
	ht = HT::Create(1000, 3, 10, 256, FileName);
	if (ht)
		std::cout << "-- Create success";
	else
		std::cout << "-- Create failed";
}