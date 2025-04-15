// Mini Shell in C
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define MAX_CMD_LEN 128

int main() {
    char cmd[MAX_CMD_LEN];
    while (1) {
        printf("myshell> ");
        if (!fgets(cmd, MAX_CMD_LEN, stdin)) break;
        if (strncmp(cmd, "exit", 4) == 0) break;
        cmd[strcspn(cmd, "\n")] = 0; // Remove newline
        if (fork() == 0) {
            execlp(cmd, cmd, NULL);
            perror("exec");
            exit(1);
        } else {
            wait(NULL);
        }
    }
    return 0;
}
