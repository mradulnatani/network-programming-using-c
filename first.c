#include <winsock2.h>
#include <stdio.h>

int main() {
    WSADATA wsaData;
    int result;

    // Step 1: Initialize Winsock
    result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        printf("WSAStartup failed: %d\n", result);
        return 1;
    }

    printf("Winsock initialized.\n");
    // Step 2: Use Winsock functions here (e.g., socket(), connect(), etc.)

    // Step 3: Cleanup Winsock
    WSACleanup();

    return 0;
}
