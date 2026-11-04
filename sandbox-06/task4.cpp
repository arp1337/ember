#include <cstdint>
#include <iostream>

std::uint8_t pack(const bool b[8]) {
    std::uint8_t result = 0;

    for (int i = 0; i < 8; i++) {
        if (b[i]) {
            result |= (1u << i);
        }
    }

    return result;
}

int main() {
    const bool buttons[8] = {1, 0, 0, 1, 1, 0, 0, 0};

    std::uint8_t packed = pack(buttons);

    std::cout << static_cast<int>(packed) << '\n';

    for (int i = 0; i < 8; i++) {
        int bit = (packed >> i) & 1u;
        std::cout << bit;

        if (i < 7) {
            std::cout << ' ';
        }
    }

    std::cout << '\n';

    return 0;
}