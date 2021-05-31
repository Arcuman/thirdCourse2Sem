#include "Service.h"

WCHAR ServiceName[] = SERVICENAME;
SERVICE_STATUS_HANDLE	hServiceStatusHandle;
SERVICE_STATUS			ServiceStatus;

void trace(const char* msg, int r)
{
	std::ofstream out;

	out.open(TRACEPATH, r);
	out << msg << "\n";

	out.close();
}

VOID WINAPI ServiceMain(DWORD dwArgc, LPTSTR* lpszArgv)
{
	char temp[121];

	ServiceStatus.dwServiceType = SERVICE_WIN32;
	ServiceStatus.dwCurrentState = SERVICE_START_PENDING;
	ServiceStatus.dwControlsAccepted = SERVICE_ACCEPT_STOP | SERVICE_ACCEPT_SHUTDOWN | SERVICE_ACCEPT_PAUSE_CONTINUE;
	ServiceStatus.dwWin32ExitCode = 0;
	ServiceStatus.dwServiceSpecificExitCode = 0;
	ServiceStatus.dwCheckPoint = 0;
	ServiceStatus.dwWaitHint = 0;

	if (!(hServiceStatusHandle = RegisterServiceCtrlHandler(ServiceName, ServiceHandler)))
	{
		sprintf_s(temp, "RegisterServiceCtrlHandler failed, error code = %d\n", GetLastError());
		trace(temp);
	}
	else
	{
		ServiceStatus.dwCurrentState = SERVICE_RUNNING;
		ServiceStatus.dwCheckPoint = 0;
		ServiceStatus.dwWaitHint = 0;
		if (!SetServiceStatus(hServiceStatusHandle, &ServiceStatus))
		{
			sprintf_s(temp, "\nSetServiceStatus failed, error code = %d\n", GetLastError());
			trace(temp);
		}
		else
		{
			int k = 0;
			system("start D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab15\\OS13_COM\\Debug\\OS_START.exe test.ht HTUser01 password");
			trace("Start service", std::ofstream::out);
			while (ServiceStatus.dwCurrentState == SERVICE_RUNNING)
			{
				Sleep(3000);
				sprintf_s(temp, "Service running = %d", k++);
				trace(temp);
			}
		}
	}
}

VOID WINAPI ServiceHandler(DWORD fdwControl)
{
	char temp[121];

	switch (fdwControl)
	{
	case SERVICE_CONTROL_STOP:
	case SERVICE_CONTROL_SHUTDOWN:
		ServiceStatus.dwWin32ExitCode = 0;
		ServiceStatus.dwCurrentState = SERVICE_STOPPED;
		ServiceStatus.dwCheckPoint = 0;
		ServiceStatus.dwWaitHint = 0;
		system("start D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab15\\OS13_COM\\Debug\\Stop.exe ");
		break;
	case SERVICE_CONTROL_PAUSE:
		ServiceStatus.dwCurrentState = SERVICE_PAUSED;
		break;
	case SERVICE_CONTROL_CONTINUE:
		ServiceStatus.dwCurrentState = SERVICE_RUNNING;
		break;
	case SERVICE_CONTROL_INTERROGATE:
		break;
	default:
		sprintf_s(temp, "Unrecognized code %d\n", fdwControl);
		trace(temp);
		break;
	}

	if (!SetServiceStatus(hServiceStatusHandle, &ServiceStatus))
	{
		sprintf_s(temp, "SetServiceStatus failed, error code = %d\n", GetLastError());
		trace(temp);
	}
}