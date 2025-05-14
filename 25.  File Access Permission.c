#include <stdio.h>
#include <windows.h>

void printAttributes(DWORD attrs) {
    printf("File Attributes:\n");
    if (attrs & FILE_ATTRIBUTE_READONLY)  printf(" - Read-Only\n");
    if (attrs & FILE_ATTRIBUTE_HIDDEN)    printf(" - Hidden\n");
    if (attrs & FILE_ATTRIBUTE_SYSTEM)    printf(" - System\n");
    if (attrs & FILE_ATTRIBUTE_ARCHIVE)   printf(" - Archive\n");
    if (attrs & FILE_ATTRIBUTE_NORMAL)    printf(" - Normal\n");
    if (attrs == INVALID_FILE_ATTRIBUTES) printf(" - Invalid or file not found\n");
}

int main() {
    const char *filename = "windows_demo.txt";
    HANDLE hFile;

    // Step 1: Create the file
    hFile = CreateFileA(
        filename,
        GENERIC_WRITE,
        0,
        NULL,
        CREATE_ALWAYS,
        FILE_ATTRIBUTE_NORMAL,
        NULL
    );

    if (hFile == INVALID_HANDLE_VALUE) {
        printf("Failed to create file. Error: %lu\n", GetLastError());
        return 1;
    }

    const char *text = "This file is created on Windows.\n";
    DWORD written;
    WriteFile(hFile, text, strlen(text), &written, NULL);
    CloseHandle(hFile);

    // Step 2: Get and show current attributes
    DWORD attrs = GetFileAttributesA(filename);
    printf("\n[Before changing attributes]\n");
    printAttributes(attrs);

    // Step 3: Change attribute to read-only
    printf("\nSetting file to READ-ONLY...\n");
    if (!SetFileAttributesA(filename, FILE_ATTRIBUTE_READONLY)) {
        printf("Failed to change attributes. Error: %lu\n", GetLastError());
        return 1;
    }

    // Step 4: Get and show new attributes
    attrs = GetFileAttributesA(filename);
    printf("\n[After changing attributes]\n");
    printAttributes(attrs);

    return 0;
}
