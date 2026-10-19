#include <cstdint>
#include <iostream>

int main() {
    int a[3] = {10, 20, 30};

    std::cout << (&a[1] - &a[0]) << '\n';
    std::cout << ((char*)&a[1] - (char*)&a[0]) << '\n';
    std::cout << (&a[2] - &a[0]) << '\n';
}
