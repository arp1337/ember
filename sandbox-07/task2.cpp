#include <cstdint>
#include <iostream>

int fib(int n) {
    if (n <= 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }

    int prev = 0;
    int curr = 1;

    for (int i = 2; i <= n; ++i) {
        int next = prev + curr;
        prev = curr;
        curr = next;
    }

    return curr;
}

int main() {
    std::cout << fib(10) << ' ' << fib(40) << '\n';
    return 0;
}
