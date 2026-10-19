#include <iostream>

const int* max_ptr(const int* a, int n) {
    const int* maximum = a;

    for (int i = 1; i < n; i++) {
        if (*(a + i) > *maximum) {
            maximum = a + i;
        }
    }

    return maximum;
}

int main() {
    int a[5] = {3, 9, 2, 9, 5};

    const int* p = max_ptr(a, 5);

    std::cout << *p << ' ' << (p - a) << '\n';
}
