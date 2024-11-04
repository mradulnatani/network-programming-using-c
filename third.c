#include <winsock2.h>
#include <stdio.h>

#pragma comment(lib, "ws2_32.lib") // Link Winsock library

int main() {
    // Step 1: Initialize Winsock
    WSADATA wsaData;
    int result = WSAStartup(MAKEWORD(2, 2), &wsaData);
    if (result != 0) {
        printf("WSAStartup failed: %d\n", result);
        return 1;
    }

    // Step 2: Create a socket
    SOCKET mySocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (mySocket == INVALID_SOCKET) {
        printf("Socket creation failed: %d\n", WSAGetLastError());
        WSACleanup();
        return 1;
    }

    // Step 3: Define server address
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(8080); // Port number
    serverAddr.sin_addr.s_addr = inet_addr("127.0.0.1"); // Localhost

    // Step 4: Connect to server
    result = connect(mySocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (result == SOCKET_ERROR) {
        printf("Connection failed: %d\n", WSAGetLastError());
        closesocket(mySocket);
        WSACleanup();
        return 1;
    }

    printf("Connected to server!\n");

    // Step 5: Clean up
    closesocket(mySocket);
    WSACleanup();
    return 0;
}
