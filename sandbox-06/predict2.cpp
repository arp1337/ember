#include <cstdint>
#include <iostream>

enum Color { Red, Green, Blue };

int main() {
    Color c = Green;
    int x = c + 10;
    std::cout << x << '\n';
}