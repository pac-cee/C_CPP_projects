# C Language: Unlocking Full Power

## 1. Bit Manipulation
```c
#include <stdio.h>
int main() {
    unsigned int x = 5; // 0000 0101
    printf("x << 1 = %u\n", x << 1); // Left shift
    printf("x & 1 = %u\n", x & 1);   // Bitwise AND
    printf("x | 2 = %u\n", x | 2);   // Bitwise OR
    printf("~x = %u\n", ~x);         // Bitwise NOT
    return 0;
}
```

## 2. Macros & Preprocessor Magic
```c
#include <stdio.h>
#define SQUARE(x) ((x)*(x))
int main() {
    printf("SQUARE(5) = %d\n", SQUARE(5));
    return 0;
}
```

## 3. Unions
```c
#include <stdio.h>
union Data {
    int i;
    float f;
    char str[20];
};
int main() {
    union Data d;
    d.i = 10;
    printf("d.i = %d\n", d.i);
    d.f = 220.5;
    printf("d.f = %f\n", d.f);
    return 0;
}
```

## 4. Function Pointers
```c
#include <stdio.h>
void hello() { printf("Hello!\n"); }
int main() {
    void (*func_ptr)() = hello;
    func_ptr();
    return 0;
}
```

## 5. Dynamic Libraries (shared objects)
- Learn to compile and use `.so` libraries (see gcc `-shared` and `dlopen`).

## 6. Inline Assembly
```c
#include <stdio.h>
int main() {
    int a = 10, b = 5, result;
    __asm__("addl %%ebx, %%eax;" : "=a"(result) : "a"(a), "b"(b));
    printf("%d + %d = %d\n", a, b, result);
    return 0;
}
```

## 7. Portability & Cross-Platform
- C code can run on microcontrollers, supercomputers, and everything in between.

## 8. Interfacing with Hardware
- Use memory-mapped I/O, direct register access (e.g., for embedded/OS dev).

## 9. C in the Real World
- OS kernels (Linux), databases (MySQL), interpreters (Python), embedded (Arduino, STM32), graphics (OpenGL), networking (curl).

## 10. Security & Exploits
- Buffer overflows, format string attacks, and how to avoid them.

## 11. Quiz
1. What is the output of `x ^ x` for any integer x?
2. What is the danger of `gets()`?
3. What is the difference between a macro and an inline function?

---
Explore these topics for true mastery of C!
