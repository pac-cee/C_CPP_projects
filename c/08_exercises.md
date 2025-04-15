# C Programming: Applications

## Where is C Used?
- Operating systems (Linux, Windows parts)
- Embedded systems (microcontrollers, IoT)
- Compilers and interpreters
- Game engines
- Database engines (MySQL)

## Example: Simple Calculator
```c
#include <stdio.h>

int main() {
    int a, b;
    char op;
    printf("Enter expression (a + b): ");
    scanf("%d %c %d", &a, &op, &b);
    int result;
    switch(op) {
        case '+': result = a + b; break;
        case '-': result = a - b; break;
        case '*': result = a * b; break;
        case '/': result = b != 0 ? a / b : 0; break;
        default: printf("Invalid operator\n"); return 1;
    }
    printf("Result: %d\n", result);
    return 0;
}
```

## Example: File Copy
```c
#include <stdio.h>

int main() {
    FILE *src = fopen("source.txt", "r");
    FILE *dst = fopen("dest.txt", "w");
    char ch;
    while ((ch = fgetc(src)) != EOF) {
        fputc(ch, dst);
    }
    fclose(src);
    fclose(dst);
    return 0;
}
```

## Practice
- Write a program that counts the number of words in a file.
- Implement a simple student record system using structs and files.

---
Next: Exercises and solutions.
