#include <iostream>
#include <Windows.h>

using namespace std;


bool insRowFileTxt(LPWSTR  FileName, LPWSTR str, DWORD row) {
    HANDLE fileHandle = CreateFile(FileName, GENERIC_READ | GENERIC_WRITE, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (fileHandle == INVALID_HANDLE_VALUE)
        return false;

    _BY_HANDLE_FILE_INFORMATION fileInformation;
    if (!GetFileInformationByHandle(fileHandle, &fileInformation)) {
        CloseHandle(fileHandle);
        return false;
    }


    char buf[1024];
    char* reBuf = buf;
    ZeroMemory(buf, sizeof(buf));
    DWORD readedBytes = NULL;

    if (!ReadFile(fileHandle, buf, fileInformation.nFileSizeLow + 1, &readedBytes, NULL))
        return false;

    LARGE_INTEGER newPointer;
    DWORD positionMode;
    DWORD nPosition = 0;
    wstring wStr = wstring(str);
    string writeString = string(wStr.begin(), wStr.end());

    DWORD writenSymbols = 0;

    switch (row)
    {
    case DWORD(-1): {
        writeString = "\r\n" + writeString;
        WriteFile(fileHandle, writeString.c_str(), writeString.size(), &writenSymbols, NULL);
        break;
    }
    case 0: {
        newPointer.QuadPart = 0;
        writeString += "\r\n";

        SetFilePointerEx(fileHandle, newPointer, NULL, FILE_BEGIN);

        SetEndOfFile(fileHandle);

        WriteFile(fileHandle, writeString.c_str(), writeString.size(), &writenSymbols, NULL);

        WriteFile(fileHandle, reBuf, readedBytes, &writenSymbols, NULL);

        break;
    }
    default:
        for (DWORD j = 0; nPosition < sizeof(buf); nPosition++) {
            if (j == row - 1)
                break;
            if (buf[nPosition] == '\n')
                j++;
        }

        writeString += "\r\n";
        newPointer.QuadPart = nPosition;

        SetFilePointerEx(fileHandle, newPointer, NULL, FILE_BEGIN);

        SetEndOfFile(fileHandle);

        WriteFile(fileHandle, writeString.c_str(), writeString.size(), &writenSymbols, NULL);

        char* end = new char[fileInformation.nFileSizeLow - nPosition];

        int check = 0;
        int checkEnd = 0;
        while (*reBuf++) {
            if (check < nPosition)
                check++;
            else
            {
                end[checkEnd] = buf[check];
                checkEnd++;
                check++;
            }
        }
        writenSymbols = 0;

        WriteFile(fileHandle, end, checkEnd, &writenSymbols, NULL);

        break;
    }


    CloseHandle(fileHandle);
    return true;
}

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
int main() {
    SetConsoleOutputCP(1251);
    LPCWSTR file = L"D:\\BSTU32\\thirdCourse2Sem\\OS\\labs\\lab9\\lab9\\OS09_01\\OS09_01.txt";
    LPCWSTR srt1 = L"something";
    printFileTxt(LPWSTR(file));
    insRowFileTxt(LPWSTR(file), LPWSTR(srt1), 0);
    insRowFileTxt(LPWSTR(file), LPWSTR(srt1), -1);

    insRowFileTxt(LPWSTR(file), LPWSTR(srt1), 5);

    insRowFileTxt(LPWSTR(file), LPWSTR(srt1), 7);
    cout << "________________________" << endl;
    if (!printFileTxt(LPWSTR(file)))
        cout << "Error";
    return 0;
}
