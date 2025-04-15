# C++ Programming: Advanced Topics

## 1. Smart Pointers
```cpp
#include <iostream>
#include <memory>

int main() {
    std::unique_ptr<int> ptr(new int(42));
    std::cout << "Value: " << *ptr << std::endl;
    // ptr is automatically deleted when it goes out of scope
    return 0;
}
```

---
## 2. Multithreading
```cpp
#include <iostream>
#include <thread>

void hello() {
    std::cout << "Hello from thread!" << std::endl;
}

int main() {
    std::thread t(hello);
    t.join();
    return 0;
}
```

---
## 3. Networking (Sockets)
// (Requires platform-specific libraries, e.g., Boost.Asio)

---
## Quiz
1. What is the difference between `unique_ptr` and `shared_ptr`?
2. How do you start a thread in C++?
