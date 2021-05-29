#include <Windows.h>
#include <iostream>

#define SERVICENAME L"Lab15v1"
#define SERVICEPATH L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab15\\OS13_COM\\Debug\\OS15_HTService.exe"


char* errortxt(const char* msg, int code) {
	char* buf = new char[512];
	sprintf_s(buf, 512, "%s: error code = %d\n", msg, code);
	return buf;
}


int create() {
	SC_HANDLE schService = NULL, schSCManager = NULL;
	try {
		schSCManager = OpenSCManager(NULL, NULL, SC_MANAGER_CREATE_SERVICE);
		if (!schSCManager) throw errortxt("OpenSCManager", GetLastError());
		else {
			schService = CreateService(
				schSCManager,
				SERVICENAME,
				SERVICENAME,
				SERVICE_ALL_ACCESS,
				SERVICE_WIN32_OWN_PROCESS,
				SERVICE_AUTO_START,
				SERVICE_ERROR_NORMAL,
				SERVICEPATH,
				NULL,
				NULL,
				NULL,
				NULL,
				NULL);
			if (!schService) throw errortxt("CreateService", GetLastError());
		}
	}
	catch (char* txt) { std::cout << txt << "\n"; }
	if (schSCManager) CloseServiceHandle(schSCManager);
	if (schService) CloseServiceHandle(schSCManager);
	system("pause");
}

int deleteS() {
	//DELETE -------------------------------
	SC_HANDLE schSCManager;
	SC_HANDLE schService;
	SERVICE_STATUS ssStatus;

	// Get a handle to the SCM database. 

	schSCManager = OpenSCManager(
		NULL,                    // local computer
		NULL,                    // ServicesActive database 
		SC_MANAGER_ALL_ACCESS);  // full access rights 

	if (NULL == schSCManager)
	{
		printf("OpenSCManager failed (%d)\n", GetLastError());
		return 0;
	}

	// Get a handle to the service.

	schService = OpenService(
		schSCManager,       // SCM database 
		SERVICENAME,          // name of service 
		DELETE);            // need delete access 

	if (schService == NULL)
	{
		printf("OpenService failed (%d)\n", GetLastError());
		CloseServiceHandle(schSCManager);
		return 0;
	}

	// Delete the service.

	if (!DeleteService(schService))
	{
		printf("DeleteService failed (%d)\n", GetLastError());
	}
	else printf("Service deleted successfully\n");

	CloseServiceHandle(schService);
	CloseServiceHandle(schSCManager);
	return 0;
}

int main()
{
	create();

	// deleteS();


	
}