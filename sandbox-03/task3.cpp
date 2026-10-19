#include <iostream>

void reverse(int* a, int n) {
    int* left = a;
    int* right = a + n - 1;

    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

int main() {
    int a[5] = {1, 2, 3, 4, 5};

    reverse(a, 5);

    for (int i = 0; i < 5; i++) {
        std::cout << a[i] << ' ';
    }

    std::cout << '\n';
}