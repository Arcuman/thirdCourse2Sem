#include <iostream>
#include "Windows.h"

int getStrCount(LPCWSTR FileName) {
    char rbuf[10240];
    Sleep(1000);
    HANDLE hf = CreateFile(FileName, GENERIC_WRITE | GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    DWORD n = NULL;
    ZeroMemory(rbuf, sizeof(rbuf));
    BOOL b = ReadFile(hf, &rbuf, sizeof(rbuf), &n, NULL);
    int i = 0;
    int strCount = 0;
    while (rbuf[i] != '\0') {
        if (rbuf[i] == '\n')
            strCount++;
        i++;
    }
    CloseHandle(hf);
    return strCount;
}

void thread(LPCWSTR FileName) {

    std::wstring wFilePath = std::wstring(FileName);
    std::string file = std::string(wFilePath.begin(), wFilePath.end());

    std::string dir = std::string(wFilePath.begin(), wFilePath.end());

    for (int i = dir.length() - 1; i >= 0; i--) {
        if (dir[i] != '\\')
            dir.pop_back();
        else {
            break;
        }
    }
    HANDLE hNotification = FindFirstChangeNotificationA(dir.c_str(), FALSE, FILE_NOTIFY_CHANGE_LAST_WRITE); //Начинаем отслеживать изменения в заданной папке посредством специальной функции
    if (hNotification == INVALID_HANDLE_VALUE) //Если создать описатель не удалось, значит заданного пути не существует
    {
        MessageBox(NULL, L"Wrong path", L"Error", MB_OK);
    }

    int fileStrsCount = getStrCount(FileName);

    while (1) //Бесконечный цикл
    {
        FindNextChangeNotification(hNotification); //И включаем ожидание следующего изменения в папке
        DWORD dwResult = WaitForSingleObject(hNotification, INFINITE); //Ждём
        int newfileStrsCount = getStrCount(FileName);
        if (fileStrsCount != newfileStrsCount) {
            std::cout << "Old Strings Count:  " << fileStrsCount << std::endl;
            std::cout << "New Strings Count:  " << newfileStrsCount << std::endl;
            fileStrsCount = newfileStrsCount;
        }
    }
    FindCloseChangeNotification(hNotification);
}

BOOL printWathRowFileTxt(LPCWSTR FileName, DWORD msec) {

    HANDLE thtimer = CreateWaitableTimer(NULL, FALSE, NULL);
    long long sec = msec * 10000;
    sec = -sec;
    HANDLE thread2 = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)thread, (LPVOID)FileName, NULL, FALSE);
    SetWaitableTimer(thtimer, (LARGE_INTEGER*)&sec, 0, NULL, NULL, FALSE);
    WaitForSingleObject(thtimer, INFINITE);
    TerminateThread(thread2, -1);
    return TRUE;
}

int main()
{
    LPCWSTR file = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab9\\lab9\\OS09_01\\OS09_01.txt";
    printWathRowFileTxt(file, 50000);
}
