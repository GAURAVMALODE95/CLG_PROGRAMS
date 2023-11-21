#include <iostream>
#include <fstream>
#include <cstring>
#include <unistd.h>
#include <arpa/inet.h>

#define SIZE 1024

void write_file(int sockfd, struct sockaddr_in& addr)
{
    char* filename = "server.txt";
    int n;
    char buffer[SIZE];
    socklen_t addr_size;

    // Creating a file.
    FILE* fp = fopen(filename, "w");

    // Receiving the data and writing it into the file.
    while (true)
    {
        addr_size = sizeof(addr);
        n = recvfrom(sockfd, buffer, SIZE, 0, reinterpret_cast<struct sockaddr*>(&addr), &addr_size);

        if (strcmp(buffer, "END") == 0)
        {
            break;
        }

        std::cout << "[RECEIVING] Data: " << buffer;
        fprintf(fp, "%s", buffer);
        memset(buffer, 0, SIZE);
    }

    fclose(fp);
}

int main()
{
    // Defining the IP and Port
    const char* ip = "127.0.0.1";
    const int port = 8080;

    // Defining variables
    int server_sockfd;
    struct sockaddr_in server_addr, client_addr;
    char buffer[SIZE];
    int e;

    // Creating a UDP socket
    server_sockfd = socket(AF_INET, SOCK_DGRAM, 0);
    if (server_sockfd < 0)
    {
        perror("[ERROR] socket error");
        exit(1);
    }

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons(port);
    server_addr.sin_addr.s_addr = inet_addr(ip);

    e = bind(server_sockfd, reinterpret_cast<struct sockaddr*>(&server_addr), sizeof(server_addr));
    if (e < 0)
    {
        perror("[ERROR] bind error");
        exit(1);
    }

    std::cout << "[STARTING] UDP File Server started. \n";
    write_file(server_sockfd, client_addr);

    std::cout << "[SUCCESS] Data transfer complete.\n";
    std::cout << "[CLOSING] Closing the server.\n";

    close(server_sockfd);

    return 0;
}
