#include <cstdint>
#include <iostream>

int depth(int n) {
    if (n < 0) {
        return 0;
    }
    return 1 + depth(n + 1);
}

int main() {
    std::cout << depth(0) << '\n';
}
