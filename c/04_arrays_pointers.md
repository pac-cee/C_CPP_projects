# C Programming: Functions

## What are Functions?
Functions are reusable blocks of code that perform a specific task. They help organize and modularize your programs.

### Function Declaration and Definition
```c
#include <stdio.h>

// Function declaration
to int add(int a, int b);

int main() {
    int result = add(5, 3);
    printf("Sum: %d\n", result);
    return 0;
}

// Function definition
int add(int a, int b) {
    return a + b;
}
```

## Function Parameters and Return Values
- Parameters are variables passed to the function.
- The return value is the result the function gives back.

## Practice
- Write a function to multiply two numbers.
- Write a function that takes an integer and returns 1 if it's even, 0 if odd.

---
Next: Arrays and pointers.
