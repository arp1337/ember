#include <cstdint>
#include <iostream>

struct Wasteful {
    char a;
    int b;
    char c;
};

struct Tidy {
    int b;
    char a;
    char c;
};

int main() {
    std::cout << sizeof(Wasteful) << ' '
              << sizeof(Tidy) << '\n';

    return 0;
}
