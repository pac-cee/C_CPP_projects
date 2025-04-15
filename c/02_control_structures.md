# C Programming: Variables and Data Types

## Variables
Variables are used to store data. You must declare a variable before using it:
```c
int age;
float salary;
char grade;
```

## Data Types
- `int`: Integer numbers (e.g., 5, -3)
- `float`: Floating-point numbers (e.g., 3.14)
- `double`: Double-precision floating-point
- `char`: Single character (e.g., 'A')

## Example
```c
#include <stdio.h>

int main() {
    int age = 20;
    float height = 1.75;
    char initial = 'J';
    printf("Age: %d\n", age);
    printf("Height: %.2f\n", height);
    printf("Initial: %c\n", initial);
    return 0;
}
```

## Input from User
```c
#include <stdio.h>

int main() {
    int number;
    printf("Enter a number: ");
    scanf("%d", &number);
    printf("You entered: %d\n", number);
    return 0;
}
```

## Practice
- Declare variables of each type and print them.
- Write a program that asks for your name and age, then prints them.

---
Next: Control structures (if, else, loops).
