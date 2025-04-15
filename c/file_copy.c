// File Copy Program in C
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *src = fopen("source.txt", "r");
    if (!src) {
        perror("Cannot open source.txt");
        return 1;
    }
    FILE *dst = fopen("dest.txt", "w");
    if (!dst) {
        perror("Cannot open dest.txt");
        fclose(src);
        return 1;
    }
    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dst);
    }
    fclose(src);
    fclose(dst);
    printf("File copied successfully.\n");
    return 0;
}
