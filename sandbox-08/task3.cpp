#include <cstdint>
#include <iostream>

int hex_value(const char* s) {
    if (s == nullptr) {
        return 0;
    }

    int i = 0;
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X')) {
        i = 2;
    }

    int result = 0;
    while (s[i] != '\0') {
        char c = s[i];
        int digit = 0;
        if (c >= '0' && c <= '9') {
            digit = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            digit = c - 'a' + 10;
        } else if (c >= 'A' && c <= 'F') {
            digit = c - 'A' + 10;
        } else {
            break;
        }
        result = result * 16 + digit;
        i++;
    }

    return result;
}

int main() {
    std::cout << hex_value("0x41") << ' ' << hex_value("0xff") << ' ' << hex_value("0x1A2") << '\n';
    return 0;
}
