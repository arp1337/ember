#include <cstdint>
#include <cstring>
#include <iostream>

int main() {
    std::uint32_t value = 0x12345678;
    unsigned char bytes[4];

    std::memcpy(bytes, &value, 4);

    std::cout << std::hex;

    for (int i = 0; i < 4; ++i) {
        std::cout << (int)bytes[i] << ' ';
    }

    std::cout << '\n';
}
