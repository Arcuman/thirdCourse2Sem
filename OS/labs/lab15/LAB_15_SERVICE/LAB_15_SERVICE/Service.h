#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>

#define SERVICENAME L"bor15"
#define TRACEPATH "D:\\Service.trace"

VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv);
VOID WINAPI ServiceHandler(DWORD fdwControl);

void trace(const char* msg, int r = std::ofstream::app);