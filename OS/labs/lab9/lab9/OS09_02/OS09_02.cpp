#include <iostream>
#include <Windows.h>

using namespace std;

bool delRowFileTxt(LPWSTR FileName, DWORD row)
{
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
    DWORD nPosition = 0;

    if (!ReadFile(fileHandle, buf, sizeof(buf), &readedBytes, NULL)) {
        CloseHandle(fileHandle);
        return false;
    }


    DWORD countStr = 0;
    for (DWORD i = 0; i < sizeof(buf); i++)
    {
        if (buf[i] == '\n')
            countStr++;
        if (buf[i] == '\0') {
            countStr++;
            break;
        }
    }
    cout << "HERE: " << countStr;
    if (countStr < row) {
        CloseHandle(fileHandle);
        cout << "The file has less " << row << " lines" << endl;
        return false;
    }
    LARGE_INTEGER newPointer;
    for (DWORD j = 0; nPosition < sizeof(buf); nPosition++) {
        if (j == row - 1)
            break;
        if (buf[nPosition] == '\n')
            j++;
        if (buf[nPosition] == '\0')
            j++;
    }

    newPointer.QuadPart = nPosition;
    
    SetFilePointerEx(fileHandle, newPointer, NULL, FILE_BEGIN);
    
    SetEndOfFile(fileHandle);
    DWORD endStr = nPosition;
    for (DWORD i = nPosition; endStr < sizeof(buf); endStr++)
    {
        if (buf[endStr] != '\n')
            i++;
        else
            break;
    }
    endStr++;
    char* end = new char[fileInformation.nFileSizeLow - endStr];

    int check = 0;
    int checkEnd = 0;

    while (*reBuf++) {
        if (check < endStr)
            check++;
        else
        {
            end[checkEnd] = buf[check];
            checkEnd++;
            check++;
        }
    }

    DWORD writenSymbols = 0;

    WriteFile(fileHandle, end, checkEnd, &writenSymbols, NULL);

    SetEndOfFile(fileHandle);

    CloseHandle(fileHandle);

    return true;
}

bool printFileTxt(LPWSTR FileName) {
    HANDLE fileHandle = CreateFile(FileName, GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (fileHandle == INVALID_HANDLE_VALUE) {
        cout << GetLastError() << endl;
        return false;
    }

    DWORD n = NULL;
    char buf[1024];

    ZeroMemory(buf, sizeof(buf));
    bool readFile = ReadFile(fileHandle, &buf, sizeof(buf), &n, NULL);

    cout << "Read file:\n" << buf << std::endl;
    CloseHandle(fileHandle);
}

int main()
{
    LPCWSTR file = L"E:\\bstu\\ThirdCourse\\OS\\labs\\lab9\\lab9\\OS09_01\\OS09_01.txt";
    if (!delRowFileTxt((LPWSTR)file, 1))
        cout << "Error del" << endl;
    if (!delRowFileTxt((LPWSTR)file, 3))
        cout << "Error del" << endl;
    if (!delRowFileTxt((LPWSTR)file, 8))
        cout << "Error del" << endl;
    if (!delRowFileTxt((LPWSTR)file, 10))
        cout << "Error del" << endl;
    printFileTxt((LPWSTR)file);
}
