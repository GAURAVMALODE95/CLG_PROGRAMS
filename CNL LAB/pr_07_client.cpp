#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

#define SIZE 1024

void send_file_data(std::ifstream& file, int sockfd, struct sockaddr_in& addr) {
    int n;
    char buffer[SIZE];

    // Sending the data
    while (file.getline(buffer, SIZE)) {
        std::cout << "[SENDING] Data: " << buffer << std::endl;

        n = sendto(sockfd, buffer, SIZE, 0, reinterpret_cast<struct sockaddr*>(&addr), sizeof(addr));
        if (n == -1) {
            perror("[ERROR] sending data to the server.");
            exit(1);
        }
        memset(buffer, 0, SIZE);
    }

    // Sending the 'END'
    strcpy(buffer, "END");
    sendto(sockfd, buffer, SIZE, 0, reinterpret_cast<struct sockaddr*>(&addr), sizeof(addr));

    file.close();
}

int main() {
    // Defining the IP and Port
    const char* ip = "127.0.0.1";
    const int port = 8080;

    // Defining variables
    int server_sockfd;
    struct sockaddr_in server_addr;
    const char* filename = "client.txt";
    std::ifstream file(filename);

    // Creating a UDP socket
    server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_sockfd < 0) {
        perror("[ERROR] socket error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    // Reading the text file
    if (!file.is_open()) {
        perror("[ERROR] reading the file");
        exit(1);
    }

    // Sending the file data to the server
    send_file_data(file, server_sockfd, server_addr);

    std::cout << "[SUCCESS] Data transfer complete." << std::endl;
    std::cout << "[CLOSING] Disconnecting from the server." << std::endl;

    close(server_sockfd);

    return 0;
}
