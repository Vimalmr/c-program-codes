#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define MAX_BUFFER_SIZE 1024
#define DNS_SERVER "8.8.8.8" // Google's public DNS server

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("WSAStartup failed");
        return 1;
    }

    // Create a UDP socket
    SOCKET serverSocket;
    serverSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (serverSocket == INVALID_SOCKET) {
        perror("Failed to create socket");
        WSACleanup();
        return 1;
    }

    // Bind the socket to a specific port
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = INADDR_ANY;
    serverAddr.sin_port = htons(12345); // Choose any available port

    if (bind(serverSocket, (struct sockaddr*)&serverAddr, sizeof(serverAddr)) == SOCKET_ERROR) {
        perror("Bind failed");
        closesocket(serverSocket);
        WSACleanup();
        return 1;
    }

    printf("Server is waiting for requests...\n");

    // Receive requests and send responses
    char buffer[MAX_BUFFER_SIZE];
    struct sockaddr_in clientAddr;
    int clientAddrLen = sizeof(clientAddr);

    while (1) {
        int bytesReceived = recvfrom(serverSocket, buffer, MAX_BUFFER_SIZE, 0, (struct sockaddr*)&clientAddr, &clientAddrLen);
        if (bytesReceived == SOCKET_ERROR) {
            perror("Recvfrom failed");
            closesocket(serverSocket);
            WSACleanup();
            return 1;
        }

        buffer[bytesReceived] = '\0';

        printf("Received request: %s\n", buffer);

        // Perform DNS resolution
        struct hostent* hostInfo;
        hostInfo = gethostbyname(buffer);

        if (hostInfo != NULL) {
            struct in_addr** addressList = (struct in_addr**)hostInfo->h_addr_list;
            if (addressList[0] != NULL) {
                char* ipAddress = inet_ntoa(*addressList[0]);
                printf("Resolved IP Address: %s\n", ipAddress);

                // Send the IP address back to the client
                int bytesSent = sendto(serverSocket, ipAddress, strlen(ipAddress), 0, (struct sockaddr*)&clientAddr, clientAddrLen);
                if (bytesSent == SOCKET_ERROR) {
                    perror("Sendto failed");
                    closesocket(serverSocket);
                    WSACleanup();
                    return 1;
                }
            } else {
                printf("No IP address found.\n");
            }
        } else {
            printf("Host not found.\n");
        }
    }

    // Cleanup
    closesocket(serverSocket);
    WSACleanup();

    return 0;
}
