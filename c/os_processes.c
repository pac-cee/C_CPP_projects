// Simple OS Process Management Example in C
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    pid_t pid = fork();
    if (pid < 0) {
        perror("fork failed");
        return 1;
    } else if (pid == 0) {
        printf("Child process: PID=%d\n", getpid());
        execlp("ls", "ls", NULL);
        perror("exec failed");
        exit(1);
    } else {
        printf("Parent process: PID=%d, Child PID=%d\n", getpid(), pid);
        wait(NULL);
        printf("Child finished.\n");
    }
    return 0;
}
