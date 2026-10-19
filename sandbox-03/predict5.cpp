#include <cstdint>
#include <cstring>
#include <iostream>

int main() {
    float f = 1.0f;
    std::uint32_t bits = 0;

    std::memcpy(&bits, &f, sizeof(bits));
    std::cout << std::hex << bits << '\n';

    f = -1.0f;
    std::memcpy(&bits, &f, sizeof(bits));
    std::cout << bits << '\n';
}
