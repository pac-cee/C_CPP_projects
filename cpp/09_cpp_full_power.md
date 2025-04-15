# C++ Language: Unlocking Full Power

## 1. Templates & Metaprogramming
```cpp
template<int N>
struct Factorial { static const int value = N * Factorial<N-1>::value; };
template<>
struct Factorial<0> { static const int value = 1; };
#include <iostream>
int main() {
    std::cout << Factorial<5>::value << std::endl; // 120
    return 0;
}
```

## 2. Lambdas & Functional Programming
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
int main() {
    std::vector<int> v = {1,2,3,4};
    std::for_each(v.begin(), v.end(), [](int x){ std::cout << x*x << ' '; });
    std::cout << std::endl;
    return 0;
}
```

## 3. RAII & Smart Pointers
- Resource Acquisition Is Initialization: manage memory, files, sockets safely.

## 4. Move Semantics
```cpp
#include <iostream>
#include <vector>
int main() {
    std::vector<int> v1 = {1,2,3};
    std::vector<int> v2 = std::move(v1);
    std::cout << "v1 size: " << v1.size() << ", v2 size: " << v2.size() << std::endl;
    return 0;
}
```

## 5. Exception Handling
```cpp
try {
    throw std::runtime_error("Oops!");
} catch(const std::exception& e) {
    std::cout << e.what() << std::endl;
}
```

## 6. Multithreading & Concurrency
- Use `<thread>`, `<future>`, `<mutex>` for parallelism.

## 7. Operator Overloading
```cpp
struct Point {
    int x, y;
    Point operator+(const Point& other) const { return {x+other.x, y+other.y}; }
};
```

## 8. STL Algorithms & Containers
- Explore `std::map`, `std::set`, `std::priority_queue`, `std::sort`, `std::find_if`, etc.

## 9. Interfacing with C & Legacy Code
- Use `extern "C"` for C/C++ interoperability.

## 10. Graphics, Games, and GUIs
- Use SFML, SDL, OpenGL for graphics and games.

## 11. Modern C++ (C++11/14/17/20/23)
- Smart pointers, ranges, concepts, coroutines, modules.

## 12. Quiz
1. What is the main advantage of RAII?
2. What does `std::move` do?
3. How do you catch all exceptions in C++?

---
Master these to wield the full power of C++!
