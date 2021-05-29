// dllmain.cpp : Определяет точку входа для приложения DLL.
#include "pch.h"
#include <fstream>
#include "ICom.h"
#define SEQ LONG __XXCSeq=InterlockedIncrement(&Seq)
#define LOG(x,y) LogCOM<<__XXCSeq<<":"<<x<<y<<std::endl

HMODULE hmodule;
LONG Seq = 0;
std::fstream LogCOM;

ULONG g_Components = 0;
ULONG g_ServerLocks = 0;

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
        hmodule = hModule;
        LogCOM.open("D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab13\\HT\\logCom.txt", std::ios_base::out);
        break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        LogCOM.close();
        break;
    }
    return TRUE;
}

