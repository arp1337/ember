#include <cstdint>
#include <iostream>

void swap_copy(int x, int y) {
    int t = x;
    x = y;
    y = t;
}

void swap_ptr(int* x, int* y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int main() {
    int a = 1, b = 2;

    swap_copy(a, b);
    std::cout << a << ' ' << b << '\n';

    swap_ptr(&a, &b);
    std::cout << a << ' ' << b << '\n';
}
