#include <iostream>
#include <Windows.h>

using namespace std;


bool printFileTxt(LPWSTR FileName) {
	HANDLE fileHandle = CreateFile(FileName, GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (fileHandle == INVALID_HANDLE_VALUE)
		return false;

	DWORD n = NULL;
	char buf[1024];

	ZeroMemory(buf, sizeof(buf));
	bool readFile = ReadFile(fileHandle, &buf, sizeof(buf), &n, NULL);

	cout << "Read file:\n" << buf << endl;
	CloseHandle(fileHandle);
}

bool printFileInfo(LPWSTR FileName) {
	HANDLE fileHandle = CreateFile(FileName, GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	if (fileHandle == INVALID_HANDLE_VALUE)
		return false;

	_BY_HANDLE_FILE_INFORMATION fileInformation;
	if (!GetFileInformationByHandle(fileHandle, &fileInformation)) {
		CloseHandle(fileHandle);
		return false;
	}
	cout << "File name:" << FileName << endl;

	cout << "File type:";

	DWORD fileType = GetFileType(fileHandle);

	switch (fileType) {
	case FILE_TYPE_CHAR: cout << "FILE_TYPE_CHAR" << std::endl; break;
	case FILE_TYPE_DISK: cout << "FILE_TYPE_DISK" << std::endl; break;
	case FILE_TYPE_PIPE: cout << "FILE_TYPE_PIPE" << std::endl; break;
	case FILE_TYPE_REMOTE: cout << "FILE_TYPE_REMOTE" << std::endl; break;
	case FILE_TYPE_UNKNOWN: cout << "FILE_TYPE_UNKNOWN" << std::endl; break;
	default:cout << " FILE_TYPE_UNKNOWN" << endl << endl; break;
	}

	LARGE_INTEGER lFileSize;
	BOOL bGetSize = GetFileSizeEx(fileHandle, &lFileSize);
	if (!bGetSize)
		return false;
	cout << "File size:" << lFileSize.QuadPart << endl;

	FILETIME createFile = fileInformation.ftCreationTime;
	SYSTEMTIME createFileToSystemTime;
	FileTimeToSystemTime(&createFile, &createFileToSystemTime);
	cout << "Create date and time:"
		<< "Year:" << createFileToSystemTime.wYear
		<< "\tMonth:" << createFileToSystemTime.wMonth
		<< "\tDay:" << createFileToSystemTime.wDay
		<< "\t" << createFileToSystemTime.wHour
		<< ":" << createFileToSystemTime.wMinute
		<< endl;

	FILETIME lastUpdate = fileInformation.ftLastWriteTime;
	SYSTEMTIME lastUpdateToSysTime;
	FileTimeToSystemTime(&lastUpdate, &lastUpdateToSysTime);
	cout << "Last update date and time:"
		<< "Year:" << lastUpdateToSysTime.wYear
		<< "\tMonth:" << lastUpdateToSysTime.wMonth
		<< "\tDay:" << lastUpdateToSysTime.wDay
		<< "\t" << lastUpdateToSysTime.wHour
		<< ":" << lastUpdateToSysTime.wMinute
		<< endl;

	CloseHandle(fileHandle);
	return true;
}

int main() {
	setlocale(LC_ALL,"Russian");
	SetConsoleOutputCP(1251);
	LPCWSTR file = L"E:\\bstu\\ThirdCourse\\OS\\labs\\lab9\\lab9\\OS09_01\\OS09_01.txt";
	cout << "Task 1" << endl;
	if (!printFileInfo(LPWSTR(file)))
		cout << "Error";

	cout << "\nTask 2" << endl;
	if (!printFileTxt(LPWSTR(file)))
		cout << "Error";

	return 0;
}
