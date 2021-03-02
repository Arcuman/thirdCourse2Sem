#include <iostream>
#include <Windows.h>

using namespace std;

bool delRowFileTxt(LPWSTR FileName, DWORD row)
{
    HANDLE fileHandle = CreateFile(FileName, GENERIC_WRITE | GENERIC_READ, NULL, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (fileHandle == INVALID_HANDLE_VALUE)
        return false;
    DWORD n = NULL;
    char buf[1024];
    ZeroMemory(buf, sizeof(buf));
    bool readFile = ReadFile(fileHandle, &buf, 1024, &n, NULL);
    int i = 0;
    int currentRowNum = 1;
    int filePointer = 0;
    char wbuf[1024];
    while (buf[i++] != '\0')
    {
        if (currentRowNum == row)
        {
            while (buf[i] != '\n' && buf[i] != '\0')
            {
                i++;
            }
            int y = 0;
            while (buf[i] != '\0')
            {
                i++;
                wbuf[y++] = buf[i];
            }
            SetFilePointer(fileHandle, filePointer, NULL, FILE_BEGIN);
            WriteFile(fileHandle, &wbuf, sizeof(char) * y - 1, &n, NULL);
            SetEndOfFile(fileHandle);
        }
        if (buf[i] == '\n')
            currentRowNum++;
        if (currentRowNum == row)
            filePointer = i + 1;
    }
    CloseHandle(fileHandle);
    if (currentRowNum < row)
        return false;

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
    LPCWSTR file = L"D:\\bstu\\thirdCourse2Sem\\OS\\labs\\lab9\\lab9\\OS09_01\\OS09_01.txt";
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
