#include <iostream>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

using namespace std;

int main() {
    int serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        perror("Error creating server socket");
        return -1;
    }

    sockaddr_in serverAddr{AF_INET, htons(8080), {INADDR_ANY}};
    if (bind(serverSocket, (sockaddr*)&serverAddr, sizeof(serverAddr)) == -1) {
        perror("Error binding server socket");
        close(serverSocket);
        return -1;
    }

    if (listen(serverSocket, 5) == -1) {
        perror("Error listening for connections");
        close(serverSocket);
        return -1;
    }

    cout << "Server waiting for incoming connections...\n";

    int clientSocket = accept(serverSocket, nullptr, nullptr);
    if (clientSocket == -1) {
        perror("Error accepting client connection");
        close(serverSocket);
        return -1;
    }

    char buffer[1024];
    ssize_t bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0);
    if (bytesRead == -1) {
        perror("Error receiving data from client");
    } else {
        buffer[bytesRead] = '\0';  // Null-terminate the received data
        cout << "Client says: " << buffer << endl;
        send(clientSocket, "Hello from server", 17, 0);
    }

    close(clientSocket);
    close(serverSocket);

    return 0;
}
