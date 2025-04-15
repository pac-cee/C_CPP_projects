// Simple TCP Client in C++ (UNIX-like systems)
#include <iostream>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <cstring>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        std::cerr << "Socket creation failed\n";
        return 1;
    }
    sockaddr_in server{};
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    inet_pton(AF_INET, "127.0.0.1", &server.sin_addr);
    if (connect(sock, (sockaddr*)&server, sizeof(server)) < 0) {
        std::cerr << "Connect failed\n";
        return 1;
    }
    const char* msg = "Hello from client!";
    send(sock, msg, strlen(msg), 0);
    char buffer[1024] = {0};
    read(sock, buffer, 1024);
    std::cout << "Received: " << buffer << std::endl;
    close(sock);
    return 0;
}
