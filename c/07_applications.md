# C Programming: Advanced Topics

## Dynamic Memory Allocation
Use `malloc`, `calloc`, and `free` for dynamic memory.
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *arr = (int*) malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++) arr[i] = i*i;
    for (int i = 0; i < 5; i++) printf("%d ", arr[i]);
    free(arr);
    return 0;
}
```

## Preprocessor Directives
- `#define` for macros
- `#include` for including files

## Example
```c
#define PI 3.14159
#include <stdio.h>

int main() {
    printf("Value of PI: %f\n", PI);
    return 0;
}
```

## Practice
- Write a program that uses `malloc` to create an array of user-defined size.
- Use a macro to define a constant, then use it in a calculation.

---
Next: Applications of C.
