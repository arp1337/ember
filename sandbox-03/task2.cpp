#include <iostream>

void swap_ptr(int* x, int* y) {
    int temp = *x;
    *x = *y;
    *y = temp;
}

void sort3(int* a, int* b, int* c) {
    if (*a > *b) {
        swap_ptr(a, b);
    }

    if (*a > *c) {
        swap_ptr(a, c);
    }

    if (*b > *c) {
        swap_ptr(b, c);
    }
}

int main() {
    int a = 3, b = 1, c = 2;
    sort3(&a, &b, &c);
    std::cout << a << ' ' << b << ' ' << c << '\n';

    int x = 9, y = 9, z = 1;
    sort3(&x, &y, &z);
    std::cout << x << ' ' << y << ' ' << z << '\n';
}
