#include <cstdint>
#include <iostream>

int main() {
    int a[3] = {1, 2, 3};
    int* p = a + 2;

    std::cout << *p << '\n';

    p = p + 1;
    std::cout << *p << '\n';
}
