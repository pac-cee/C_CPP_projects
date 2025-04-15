# C++ Programming: Variables and Data Types

## Variables
Variables store data values. In C++, you must declare a variable before using it:
```cpp
int age;
double salary;
char grade;
```

## Data Types
- `int`: Integer numbers (e.g., 5, -3)
- `double`: Double-precision floating-point
- `float`: Single-precision floating-point
- `char`: Single character (e.g., 'A')
- `std::string`: Sequence of characters (requires `#include <string>`)

## Example
```cpp
#include <iostream>
#include <string>

int main() {
    int age = 20;
    double height = 1.75;
    char initial = 'J';
    std::string name = "John";
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Height: " << height << std::endl;
    std::cout << "Initial: " << initial << std::endl;
    return 0;
}
```

## Input from User
```cpp
#include <iostream>
#include <string>

int main() {
    std::string name;
    int age;
    std::cout << "Enter your name: ";
    std::getline(std::cin, name);
    std::cout << "Enter your age: ";
    std::cin >> age;
    std::cout << "Hello, " << name << ". You are " << age << " years old." << std::endl;
    return 0;
}
```

## Practice
- Declare variables of each type and print them.
- Write a program that asks for your name and age, then prints them.

---
Next: Control structures, OOP basics.
