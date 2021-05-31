#include "Service.h"

int main()
{
	WCHAR ServiceName[] = SERVICENAME;

	SERVICE_TABLE_ENTRY ServiceStartTable[] = { {ServiceName, ServiceMain}, {NULL, NULL} };

	if (!StartServiceCtrlDispatcher(ServiceStartTable))
	{
		trace("StartServiceCtrlDispatcher", std::ofstream::out);
	}

	return 0;
}