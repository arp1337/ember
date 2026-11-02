#include <iostream>

int main() {
    int a[5] = {5, 4, 3, 2, 1};
    int shifts = 0;

    for (int i = 1; i < 5; i++) {
        int key = a[i];
        int j = i - 1;

        while (j >= 0 && a[j] > key) {
            a[j + 1] = a[j];
            shifts++;
            j--;
        }

        a[j + 1] = key;
    }

    for (int i = 0; i < 5; i++) {
        std::cout << a[i] << ' ';
    }

    std::cout << shifts << '\n';
}