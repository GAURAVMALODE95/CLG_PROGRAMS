#include <iostream>
#include <fstream>
#include <cstring>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>

using namespace std;

#define PORT 8080
#define BUFFER_SIZE 1024

void sendFile(int clientSocket, const char* filename) {
    ifstream file(filename, ios::binary);
    if (!file.is_open()) {
        cerr << "Error opening file for reading." << endl;
        return;
    }

    char buffer[BUFFER_SIZE];

    while (!file.eof()) {
        file.read(buffer, sizeof(buffer));
        send(clientSocket, buffer, file.gcount(), 0);
    }

    file.close();
    cout << "File sent successfully." << endl;
}

int main() {
    int clientSocket;
    struct sockaddr_in serverAddr;

    clientSocket = socket(AF_INET, SOCK_STREAM, 0);
    if (clientSocket == -1) {
        cerr << "Error creating client socket." << endl;
        return -1;
    }

    memset(&serverAddr, 0, sizeof(serverAddr));
    serverAddr.sin_family = AF_INET;
    serverAddr.sin_port = htons(PORT);

    if (inet_pton(AF_INET, "127.0.0.1", &serverAddr.sin_addr) == -1) {
        cerr << "Invalid address. Error converting address." << endl;
        close(clientSocket);
        return -1;
    }

    if (connect(clientSocket, (struct sockaddr *)&serverAddr, sizeof(serverAddr)) == -1) {
        cerr << "Error connecting to server." << endl;
        close(clientSocket);
        return -1;
    }

    const char* filename = "example.txt";
    sendFile(clientSocket, filename);

    close(clientSocket);

    return 0;
}
