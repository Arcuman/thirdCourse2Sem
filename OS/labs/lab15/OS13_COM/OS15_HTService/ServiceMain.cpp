#pragma once
#include <Windows.h>
#include <iostream>
#include <fstream>
#include "Service.h"

#include "OS13_HTCOM.h"
#include <string>
#include <algorithm>



using namespace std;

WCHAR ServiceName[] = SERVICENAME;
SERVICE_STATUS_HANDLE hServiceStatusHandle;
SERVICE_STATUS ServiceStatus;

void trace(const char* msg, int r) {
	std::ofstream out;
	out.open(TRACEPATH, r);
	out << msg << "\n";
	out.close();
}

HT::HTHANDLE* ht = NULL;

VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv) {
	trace("\nServiceMain\n");
	char temp[121];

	const wchar_t* directoryPath = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab15\\HT\\";
	std::wstring filePath(L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab15\\HT\\test.ht");
	std::wstring userName(L"HTUser01");
	std::wstring password(L"password");
	ServiceStatus.dwServiceType = SERVICE_WIN32;
	ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
	ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN | SERVICE_ACCEPT_PAUSE_CONTINUE;
	ServiceStatus.dwWin32ExitCode = 0;
	ServiceStatus.dwServiceSpecificExitCode = 0;
	ServiceStatus.dwCheckPoint = 0;
	ServiceStatus.dwWaitHint = 0;

	if (!(hServiceStatusHandle = RegisterServiceCtrlHandler(ServiceName, ServiceHandler))) {
		sprintf_s(temp, "\nSetServiceStatusFailed, error code = %d\n", GetLastError());
		trace(temp);
	}
	else {

		ServiceStatus.dwCurrentState = SERVICE_RUNNING;
		ServiceStatus.dwCheckPoint = 0;
		ServiceStatus.dwWaitHint = 0;
		if (!SetServiceStatus(hServiceStatusHandle, &ServiceStatus)) {
			sprintf_s(temp, "\nSetSetviceStatus failed, error code =%d\n", GetLastError());
			trace(temp);
		}
		else {
			try {
				trace("start service1", std::ofstream::out);
				if (ServiceStatus.dwCurrentState == SERVICE_PAUSED ||
					ServiceStatus.dwCurrentState == SERVICE_STOPPED) {
					if (ht != NULL) {
						trace("\nclick12...");
						sprintf_s(temp, "\nht:%d",
							ht);
						trace(temp);
						sprintf_s(temp, "\nHT-Storage Closing... snapshotinterval=%d, capacity = %d, maxkeylength = %d, maxdatalength = %d",
							ht->SecSnapshotInterval, ht->Capacity, ht->MaxKeyLength, ht->MaxPayloadLength);
						trace(temp);
						bool s = HTAPI::Close(ht);
						HTAPI::CloseConnection();
						return;
					}
					else {
						trace("ht=null\n");
					}
				}
				trace("before open ht ", std::ofstream::out);
				if (HTAPI::OpenConnection()) {
					trace("open success", std::ofstream::out);
					ht = HTAPI::Open(filePath.c_str(), userName.c_str(), password.c_str());
					if (ht == NULL) {
						trace("open ht error", std::ofstream::out);
						HTAPI::CloseConnection();
						return;
					}
					trace("start service12", std::ofstream::out);
					sprintf_s(temp, "\nht:%d", (int)ht);
					trace(temp);
					if (ht != NULL) {
						sprintf_s(temp, "\nHT-Storage Created snapshotinterval=%d, capacity = %d, maxkeylength = %d, maxdatalength = %d",
							ht->SecSnapshotInterval, ht->Capacity, ht->MaxKeyLength, ht->MaxPayloadLength);
						trace(temp);
					}
					else {
						trace("\n some error fail");
					}

					while (ServiceStatus.dwCurrentState == SERVICE_RUNNING && ht != NULL) {
						Sleep(3000);
						trace("\nclick12...");
					}
				}
				else {
					trace("open ht open connection error", std::ofstream::out);
				}
			}
			catch (char* e) {
				trace(e);
			}

		}
	}

}


VOID WINAPI ServiceHandler(DWORD fdwControl) {
	char temp[121];
	switch (fdwControl) {
	case SERVICE_CONTROL_STOP:
		trace("stoped\n");
	case SERVICE_CONTROL_SHUTDOWN:
		ServiceStatus.dwWin32ExitCode = 0;
		ServiceStatus.dwCurrentState = SERVICE_STOPPED;
		ServiceStatus.dwCheckPoint = 0;
		ServiceStatus.dwWaitHint = 0;
		trace("shutdown\n");

		break;
	case SERVICE_CONTROL_PAUSE:
		ServiceStatus.dwCurrentState = SERVICE_PAUSED;
		break;
	case SERVICE_CONTROL_CONTINUE:
		trace("SERVICE_RUNNING", std::ofstream::out);
		ServiceStatus.dwCurrentState = SERVICE_RUNNING;
		break;
	case SERVICE_CONTROL_INTERROGATE: break;
	default:
		sprintf_s(temp, "Unrecognized opcode%d\n", fdwControl);
		trace(temp);
	};
	if (!SetServiceStatus(hServiceStatusHandle, &ServiceStatus)) {

		sprintf_s(temp, "SetServiceStatus failed, error code = %d\n", GetLastError());
		trace(temp);
	}
}
