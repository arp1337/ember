#include <cstdint>
#include <cstring>
#include <iostream>

void show_float(float number) {
    std::uint32_t bits = 0;
    std::memcpy(&bits, &number, sizeof(bits));

    std::uint32_t sign = bits >> 31;
    std::uint32_t exponent = (bits >> 23) & 0xFF;

    std::cout << sign << ' ' << exponent << '\n';
}

int main() {
    show_float(-2.5f);
    show_float(1.0f);
}
