// Simple TCP Client-Server Example (Server Part) in C++
// Note: For simplicity, this is a basic blocking server for Unix-like systems
#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>
#include <cstring>

int main() {
    int server_fd = socket(AF_INET, SOCK_STREAM, 0);
    if (server_fd == -1) {
        std::cerr << "Socket creation failed\n";
        return 1;
    }
    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(8080);
    if (bind(server_fd, (sockaddr*)&address, sizeof(address)) < 0) {
        std::cerr << "Bind failed\n";
        return 1;
    }
    listen(server_fd, 1);
    std::cout << "Server listening on port 8080...\n";
    int addrlen = sizeof(address);
    int client_fd = accept(server_fd, (sockaddr*)&address, (socklen_t*)&addrlen);
    if (client_fd < 0) {
        std::cerr << "Accept failed\n";
        return 1;
    }
    char buffer[1024] = {0};
    read(client_fd, buffer, 1024);
    std::cout << "Received: " << buffer << std::endl;
    const char* reply = "Hello from server!";
    send(client_fd, reply, strlen(reply), 0);
    close(client_fd);
    close(server_fd);
    return 0;
}

// For a client, you can use netcat: nc localhost 8080
