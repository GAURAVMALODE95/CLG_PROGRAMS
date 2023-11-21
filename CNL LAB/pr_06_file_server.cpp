#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

using namespace std;

#define PORT 8080
#define BUFFER_SIZE 1024

void receiveFile(int clientSocket, const char* filename) {
    ofstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file for writing." << endl;
        return;
    }

    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;

    while ((bytesRead = recv(clientSocket, buffer, sizeof(buffer), 0)) > 0) {
        file.write(buffer, bytesRead);
    }

    if (bytesRead == -1) {
        cerr << "Error receiving data from client." << endl;
    }

    file.close();
    cout << "File received successfully." << endl;
}

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddr, clientAddr;
    socklen_t addrSize = sizeof(struct sockaddr_in);

    serverSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (serverSocket == -1) {
        cerr << "Error creating server socket." << endl;
        return -1;
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_addr.s_addr = htonl(INADDR_ANY);
    serverAddr.sin_port = htons(PORT);

    if (bind(serverSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        cerr << "Error binding server socket." << endl;
        close(serverSocket);
        return -1;
    }

    if (listen(serverSocket, 5) == -1) {
        cerr << "Error listening for connections." << endl;
        close(serverSocket);
        return -1;
    }

    cout << "Server is listening on port " << PORT << "..." << endl;

    clientSocket = accept(serverSocket, (struct sockaddr *)&clientAddr, &addrSize);
    if (clientSocket == -1) {
        cerr << "Error accepting client connection." << endl;
        close(serverSocket);
        return -1;
    }

    const char* filename = "received_file.txt";
    receiveFile(clientSocket, filename);

    close(clientSocket);
    close(serverSocket);

    return 0;
}
