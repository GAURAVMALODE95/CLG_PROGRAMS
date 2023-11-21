#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

int main() {
    int clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        perror("Error creating client socket");
        return -1;
    }

    sockaddr_in serverAddr{AF_INET, htons(8080), {inet_addr("127.0.0.1")}};

    if (connect(clientSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Error connecting to server");
        close(clientSocket);
        return -1;
    }

    const char* message = "Hello";
    if (send(clientSocket, message, strlen(message), 0) == -1) {
        perror("Error sending data to server");
    } else {
        char buffer[1024];
        ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
        if (bytesRead == -1) {
            perror("Error receiving data from server");
        } else {
            buffer[bytesRead] = '\0';  // Null-terminate the received data
            cout << "Server says: " << buffer << endl;
        }
    }

    close(clientSocket);

    return 0;
}
