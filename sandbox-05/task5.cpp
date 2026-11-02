#include <iostream>

int max_of(const int* a, int n) {
    int maximum = a[0];

    for (int i = 1; i < n; i++) {
        if (a[i] > maximum) {
            maximum = a[i];
        }
    }

    return maximum;
}

int main() {
    int data[10] = {5, 42, 7, 1, 9, 13, 2, 8, 30, 11};

    int n = sizeof(data) / sizeof(data[0]);

    std::cout << n << ' ' << max_of(data, n) << '\n';
}