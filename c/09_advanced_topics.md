# C Programming: Advanced Topics

## 1. Multithreading with POSIX Threads
```c
#include <stdio.h>
#include <pthread.h>

void* print_message(void* ptr) {
    char* message = (char*) ptr;
    printf("%s\n", message);
    return NULL;
}

int main() {
    pthread_t thread1, thread2;
    char* msg1 = "Hello from thread 1!";
    char* msg2 = "Hello from thread 2!";

    pthread_create(&thread1, NULL, print_message, msg1);
    pthread_create(&thread2, NULL, print_message, msg2);

    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

    return 0;
}
```

**Compile with:**
`gcc advanced_threads.c -o advanced_threads -lpthread`

---
## 2. Networking (Sockets)
```c
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

int main() {
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    struct sockaddr_in server;
    server.sin_addr.s_addr = inet_addr("127.0.0.1");
    server.sin_family = AF_INET;
    server.sin_port = htons(8080);
    connect(sock, (struct sockaddr*)&server, sizeof(server));
    char* message = "Hello, server!";
    send(sock, message, strlen(message), 0);
    close(sock);
    return 0;
}
```

---
## Quiz
1. What does `pthread_join` do in a multithreaded C program?
2. Which header file is needed for socket programming?
