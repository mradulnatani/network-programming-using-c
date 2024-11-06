#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>
#include <ws2tcpip.h>

int main() {
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        fprintf(stderr, "WSAStartup failed\n");
        return EXIT_FAILURE;
    }

    struct sockaddr_in sa;  // IPv4
    struct sockaddr_in6 sa6;  // IPv6
    int result;

    // IPv4 Conversion
    result = inet_pton(AF_INET, "10.12.110.57", &(sa.sin_addr));
    if (result <= 0) {
        if (result == 0)
            printf("Invalid IPv4 address %d\n",result);
        else
            perror("inet_pton");
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    printf("IPv4 address converted successfully %d\n",result);

    // IPv6 Conversion
    result = inet_pton(AF_INET6, "2001:db8:63b3:1::3490", &(sa6.sin6_addr));
    if (result <= 0) {
        if (result == 0)
            printf("Invalid IPv6 address %d\n",result);
        else
            perror("inet_pton");
        WSACleanup();
        exit(EXIT_FAILURE);
    }
    printf("IPv6 address converted successfully %d\n",result);

    WSACleanup();
    return 0;
}
