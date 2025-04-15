# C Programming: Control Structures

## If-Else Statements
Control the flow of your program based on conditions.
```c
#include <stdio.h>

int main() {
    int num = 10;
    if (num > 0) {
        printf("Positive number\n");
    } else {
        printf("Non-positive number\n");
    }
    return 0;
}
```

## Loops
### For Loop
```c
for (int i = 0; i < 5; i++) {
    printf("%d\n", i);
}
```
### While Loop
```c
int i = 0;
while (i < 5) {
    printf("%d\n", i);
    i++;
}
```
### Do-While Loop
```c
int i = 0;
do {
    printf("%d\n", i);
    i++;
} while (i < 5);
```

## Practice
- Write a program to print numbers from 1 to 10 using a loop.
- Write a program to check if a number is even or odd.

---
Next: Functions in C.
