#include <cstdint>
#include <iostream>

void count(int n) {
    if (n == 0) {
        return;
    }
    std::cout << "вниз " << n << '\n';
    count(n - 1);
    std::cout << "вгору " << n << '\n';
}

int main() {
    count(3);
}
