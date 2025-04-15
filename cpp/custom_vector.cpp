// Custom Vector Implementation in C++
#include <iostream>

class MyVector {
    int* data;
    size_t sz;
    size_t cap;
    void resize() {
        cap = cap ? cap * 2 : 1;
        int* new_data = new int[cap];
        for (size_t i = 0; i < sz; ++i) new_data[i] = data[i];
        delete[] data;
        data = new_data;
    }
public:
    MyVector() : data(nullptr), sz(0), cap(0) {}
    ~MyVector() { delete[] data; }
    void push_back(int val) {
        if (sz == cap) resize();
        data[sz++] = val;
    }
    int& operator[](size_t idx) { return data[idx]; }
    size_t size() const { return sz; }
};

int main() {
    MyVector v;
    for (int i = 0; i < 10; ++i) v.push_back(i * i);
    for (size_t i = 0; i < v.size(); ++i)
        std::cout << v[i] << " ";
    std::cout << std::endl;
    return 0;
}
