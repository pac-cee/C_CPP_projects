# C++ Programming: STL (Standard Template Library)

## What is STL?
The STL provides ready-to-use classes and functions for data structures and algorithms (like vectors, lists, maps, and more).

## Example: Using `std::vector`
```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> numbers = {1, 2, 3, 4, 5};
    for (int num : numbers) {
        std::cout << num << std::endl;
    }
    return 0;
}
```

## Example: Using `std::map`
```cpp
#include <iostream>
#include <map>

int main() {
    std::map<std::string, int> ages;
    ages["Alice"] = 30;
    ages["Bob"] = 25;
    for (const auto& pair : ages) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
    return 0;
}
```

## Practice
- Create a vector of strings and print them.
- Use a map to store and display student grades.

---
Next: Advanced C++ topics (templates, memory management).
