#include <windows.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

BOOL DeleteSecurelyFile(LPCSTR filename) {
    HANDLE hFile = NULL;
    hFile = CreateFileA(filename, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if (hFile == INVALID_HANDLE_VALUE) {
        printf("[!] Error Opening File %s\n", filename);
        printf("[!] Error: %lu\n", GetLastError());
        return FALSE; 
    }

    DWORD fileSize = GetFileSize(hFile, NULL);
    if (fileSize == INVALID_FILE_SIZE) {
        printf("[!] Error Getting File Size: %lu\n", GetLastError());
        CloseHandle(hFile);
        return FALSE;
    }

    char *buffer = (char *)malloc(fileSize);
    if (buffer == NULL) {
        printf("[!] Memory allocation failed\n");
        CloseHandle(hFile);
        return FALSE;
    }

    srand((unsigned int)time(NULL));

    for (DWORD i = 0; i < fileSize; ++i) {
        buffer[i] = (char)(rand() % 256);  
    }

    DWORD bytesWritten;
    SetFilePointer(hFile, 0, NULL, FILE_BEGIN); 
    WriteFile(hFile, buffer, fileSize, &bytesWritten, NULL);

    free(buffer);
    CloseHandle(hFile);

    if (DeleteFileA(filename)) {
        printf("[+] Successfully deleted file: %s\n", filename);
    } 
    else {
        printf("[!] Error deleting file: %s\n", filename);
        printf("[!] Error: %lu\n", GetLastError());
        return FALSE;
    }

    return TRUE;
}

int main(int argc, char* argv[]) {
    printf("\t\t[< ^ ^  SHRED Securely Deleting File with Overwriting  ^ ^ >]\n");

    if (argc < 2) {
        printf("[!] Usage: shred.exe <filename>\n");
        return -1;
    }

    LPCSTR filename = argv[1];

    if (!DeleteSecurelyFile(filename)) {
        printf("[!] Failed to securely delete the file: %s\n", filename);
        return -1;
    }

    return 0;
}
