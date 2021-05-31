using namespace std;

#include <windows.h>
#include <process.h>
#include <Tlhelp32.h>
#include <winbase.h>
#include "OS13_HTCOM.h"
#include "INTERFACE.h"
#include <string.h>

#include <iostream>


void killProcessByName(const wchar_t* filename)
{
    HANDLE hSnapShot = CreateToolhelp32Snapshot(TH32CS_SNAPALL, NULL);
    PROCESSENTRY32 pEntry;
    pEntry.dwSize = sizeof(pEntry);

    BOOL hRes = Process32First(hSnapShot, &pEntry);
    while (hRes)
    {
        if (wcscmp(pEntry.szExeFile, filename) == 0)
        {
            HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, 0,
                (DWORD)pEntry.th32ProcessID);
            if (hProcess != NULL)
            {
                TerminateProcess(hProcess, 9);
                CloseHandle(hProcess);
            }
        }
        hRes = Process32Next(hSnapShot, &pEntry);
    }
    CloseHandle(hSnapShot);
}

int main(int argc, char* argv[])
{
    wchar_t* fileName;
    const wchar_t* directoryPath = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab15\\HT\\";
    std::wstring filePath(L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab15\\HT\\test.ht");
    if (argv[1]) {
        fileName = HTAPI::GetWC(argv[1]);
        std::wstring s(directoryPath);
        s += std::wstring(fileName);
        filePath = s;
    }
	if (HTAPI::OpenConnection()) {
        HT::HTHANDLE* HT;
        HT = HTAPI::OpenExist(filePath.c_str());
        if (HT == NULL) {
            printf("Not started\n");
            return -1;
        }
        HTAPI::Snap(HT);
        killProcessByName(L"OS_START.exe");
        killProcessByName(L"OS_INSERT.exe");
        killProcessByName(L"Delete.exe");
        killProcessByName(L"Update.exe");
        if (HTAPI::CloseConnection() == false)
            printf("error with close api\n");
    }
	else {
		printf("error with open api\n");
	}
	return 0;
}