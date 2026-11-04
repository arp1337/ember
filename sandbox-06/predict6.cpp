#include <cstdint>
#include <cstring>
#include <iostream>

struct Pair {
    std::uint8_t lo;
    std::uint8_t hi;
};

int main() {
    std::uint16_t value = 0x1234;
    Pair p;

    std::memcpy(&p, &value, sizeof(p));

    std::cout << std::hex << (int)p.lo << ' '
              << (int)p.hi << '\n';
}
