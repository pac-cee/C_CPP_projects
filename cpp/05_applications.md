# C++ Programming: Advanced Topics

## Templates
Templates allow you to write generic functions and classes.
```cpp
template <typename T>
T add(T a, T b) {
    return a + b;
}

int main() {
    std::cout << add(2, 3) << std::endl;
    std::cout << add(2.5, 3.1) << std::endl;
    return 0;
}
```

## Memory Management
C++ uses `new` and `delete` for dynamic memory.
```cpp
int* p = new int(5);
std::cout << *p << std::endl;
delete p;
```

## Practice
- Write a template function for multiplication.
- Dynamically allocate an array, fill it, and print the values.

---
Next: Applications of C++.
