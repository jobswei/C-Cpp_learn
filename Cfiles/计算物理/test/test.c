#include<stdio.h>
#include<math.h>
#include<string.h>
#include<time.h>
#include<memory.h>
#include<malloc.h>
#include <stdbool.h>
#include<unistd.h>
#include<winnt.h>
#include<psapi.h>

int main() {
    HANDLE hProcess = OpenProcess(PROCESS_VM_READ, FALSE, GetCurrentProcessId());
    if (hProcess == NULL) {
        printf("打开进程失败：%d\n", GetLastError());
        return 1;
    }

    int value;
    SIZE_T bytesRead;
    BOOL success = ReadProcessMemory(hProcess, &value, (LPVOID)0x1000, sizeof(value), &bytesRead);
    if (success) {
        printf("读取成功，实际读取字节数：%llu，读取的值为：%d\n", bytesRead, value);
    } else {
        printf("读取失败：%d\n", GetLastError());
    }

    CloseHandle(hProcess);

    return 0;
}
