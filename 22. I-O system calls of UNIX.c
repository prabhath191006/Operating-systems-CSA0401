#include <windows.h>
#include <stdio.h>
#include <string.h>

int main() {
    HANDLE hFile;
    DWORD bytesWritten, bytesRead;
    char buffer[50];
    DWORD fileSize;
    LARGE_INTEGER fileSizeLarge;

    // Open or create file
    hFile = CreateFile("example.txt", GENERIC_READ | GENERIC_WRITE, 0, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Open failed with error code %lu\n", GetLastError());
        return 1;
    }

    const char *text = "Hello File System";         // 17 characters
    size_t len = strlen(text);                      // len = 17

    // Write to the file
    if (!WriteFile(hFile, text, len, &bytesWritten, NULL)) {
        printf("Write failed with error code %lu\n", GetLastError());
        CloseHandle(hFile);  // Close the file before exiting
        return 1;
    }

    // Move to the beginning of the file for reading
    if (SetFilePointer(hFile, 0, NULL, FILE_BEGIN) == INVALID_SET_FILE_POINTER) {
        printf("SetFilePointer failed with error code %lu\n", GetLastError());
        CloseHandle(hFile);  // Close the file before exiting
        return 1;
    }

    // Read from the file
    if (!ReadFile(hFile, buffer, len, &bytesRead, NULL)) {
        printf("Read failed with error code %lu\n", GetLastError());
        CloseHandle(hFile);  // Close the file before exiting
        return 1;
    }
    buffer[bytesRead] = '\0';  // Null-terminate the string

    printf("Content: %s\n", buffer);

    // Get file size
    fileSizeLarge.QuadPart = 0;
    if (!GetFileSizeEx(hFile, &fileSizeLarge)) {
        printf("GetFileSizeEx failed with error code %lu\n", GetLastError());
        CloseHandle(hFile);  // Close the file before exiting
        return 1;
    }
    fileSize = (DWORD)fileSizeLarge.QuadPart;

    printf("Size: %lu\n", fileSize);

    // Close the file
    CloseHandle(hFile);
    return 0;
}
