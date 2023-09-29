#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

#define SERVER_IP "127.0.0.1" // Change to the server's IP address
#define SERVER_PORT 12345
#define MAX_IP_LENGTH 16 // Maximum length for an IP address (including null terminator)

int main() {
    // Initialize Winsock
    WSADATA wsaData;
    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
        perror("WSAStartup failed");
        return 1;
    }

    // Create a UDP socket
    SOCKET clientSocket;
    clientSocket = socket(AF_INET, SOCK_DGRAM, 0);
    if (clientSocket == INVALID_SOCKET) {
        perror("Failed to create socket");
        WSACleanup();
        return 1;
    }

    // Server information
    struct sockaddr_in serverAddr;
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(SERVER_PORT);
    serverAddr.sin_addr.s_addr = inet_addr(SERVER_IP);

    // Get the hostname from the user
    char hostname[100];
    printf("Enter hostname (e.g., www.google.com): ");
    fgets(hostname, sizeof(hostname), stdin);
    hostname[strlen(hostname) - 1] = '\0'; // Remove newline character

    // Send the hostname to the server
    int bytesSent = sendto(clientSocket, hostname, strlen(hostname), 0, (struct sockaddr*)&serverAddr, sizeof(serverAddr));
    if (bytesSent == SOCKET_ERROR) {
        perror("Sendto failed");
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    // Receive the IP address from the server
    char buffer[MAX_IP_LENGTH];
    int serverAddrLen = sizeof(serverAddr);
    int bytesReceived = recvfrom(clientSocket, buffer, MAX_IP_LENGTH - 1, 0, (struct sockaddr*)&serverAddr, &serverAddrLen);
    if (bytesReceived == SOCKET_ERROR) {
        perror("Recvfrom failed");
        closesocket(clientSocket);
        WSACleanup();
        return 1;
    }

    buffer[bytesReceived] = '\0';
    printf("IP Address: %s\n", buffer);
    printf("Press Enter to exit...");
	getchar();

    // Cleanup
    closesocket(clientSocket);
    WSACleanup();

    return 0;
}
