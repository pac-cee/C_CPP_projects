# C++ Programming: Applications

## Where is C++ Used?
- Game development (Unreal Engine, Unity scripting)
- Operating systems and device drivers
- High-performance computing
- Financial modeling
- Embedded systems

## Example: Simple Game Loop
```cpp
#include <iostream>

int main() {
    char input;
    std::cout << "Press q to quit.\n";
    while (true) {
        std::cout << "Enter a key: ";
        std::cin >> input;
        if (input == 'q') break;
        std::cout << "You pressed: " << input << std::endl;
    }
    return 0;
}
```

## Example: File I/O
```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream fout("output.txt");
    fout << "Hello from C++!" << std::endl;
    fout.close();
    return 0;
}
```

## Practice
- Write a program that reads names from a file and prints them.
- Simulate a simple banking system (deposit/withdraw) using classes.

---
Next: Exercises and solutions.
