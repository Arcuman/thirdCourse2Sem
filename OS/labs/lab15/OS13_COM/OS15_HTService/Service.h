#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>


#define SERVICENAME L"Lab15v1"
#define TRACEPATH "D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab15\\HT\\ServciceLog.txt"
VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);
VOID WINAPI ServiceHandler(DWORD fdwControl);

void trace(const char* msg, int r = std::ofstream::app);







