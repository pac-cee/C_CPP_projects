# C++ Programming: Control Structures & OOP Basics

## If-Else Statements
```cpp
#include <iostream>

int main() {
    int num = 10;
    if (num > 0) {
        std::cout << "Positive number" << std::endl;
    } else {
        std::cout << "Non-positive number" << std::endl;
    }
    return 0;
}
```

## Loops
### For Loop
```cpp
for (int i = 0; i < 5; i++) {
    std::cout << i << std::endl;
}
```
### While Loop
```cpp
int i = 0;
while (i < 5) {
    std::cout << i << std::endl;
    i++;
}
```
### Do-While Loop
```cpp
int i = 0;
do {
    std::cout << i << std::endl;
    i++;
} while (i < 5);
```

## OOP Basics: Classes
```cpp
#include <iostream>
class Person {
public:
    std::string name;
    int age;
    void greet() {
        std::cout << "Hello, my name is " << name << std::endl;
    }
};

int main() {
    Person p;
    p.name = "Alice";
    p.age = 30;
    p.greet();
    return 0;
}
```

## Practice
- Write a program to print numbers from 1 to 10 using a loop.
- Create a class `Car` with attributes and a method to display details.

---
Next: STL (Standard Template Library) in C++.
