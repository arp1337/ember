#include <iostream>

int find_last(const int* a, int n, int x) {
    int result = -1;

    for (int i = 0; i < n; i++) {
        if (a[i] == x) {
            result = i;
        }
    }

    return result;
}

int main() {
    int a[5] = {4, 2, 4, 4, 1};

    std::cout << find_last(a, 5, 4) << " ";
    std::cout << find_last(a, 5, 9) << "\n";

    return 0;
}