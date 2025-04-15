# Solutions to C++ Exercises

## 1. Read names from a file and print them
```cpp
#include <iostream>
#include <fstream>
#include <string>

int main() {
    std::ifstream fin("names.txt");
    std::string name;
    while (getline(fin, name)) {
        std::cout << name << std::endl;
    }
    fin.close();
    return 0;
}
```

## 2. Simple Banking System
```cpp
#include <iostream>
#include <string>

class Account {
    std::string owner;
    double balance;
public:
    Account(std::string n, double b) : owner(n), balance(b) {}
    void deposit(double amt) { balance += amt; }
    void withdraw(double amt) { if (amt <= balance) balance -= amt; }
    void display() const {
        std::cout << owner << ": $" << balance << std::endl;
    }
};

int main() {
    Account acc("Alice", 1000);
    acc.deposit(200);
    acc.withdraw(150);
    acc.display();
    return 0;
}
```
