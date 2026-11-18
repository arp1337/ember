#include <cstdint>
#include <iostream>

int hex_to_digit(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    return -1;
}

bool check_nmea(const char* s) {
    if (s == nullptr) {
        return false;
    }

    int i = 0;
    while (s[i] != '\0' && s[i] != '$') {
        i++;
    }
    if (s[i] != '$') {
        return false;
    }
    i++;

    uint8_t checksum = 0;
    while (s[i] != '\0' && s[i] != '*') {
        checksum ^= static_cast<uint8_t>(s[i]);
        i++;
    }
    if (s[i] != '*') {
        return false;
    }
    i++;

    int h1 = hex_to_digit(s[i]);
    int h2 = hex_to_digit(s[i + 1]);
    if (h1 == -1 || h2 == -1) {
        return false;
    }

    int expected = (h1 << 4) | h2;
    return checksum == expected;
}

int main() {
    const char* s1 = "$GPGGA,123519,4807.038,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";
    const char* s2 = "$GPGGA,123519,4807.039,N,01131.000,E,1,08,0.9,545.4,M,46.9,M,,*47";

    std::cout << check_nmea(s1) << ' ' << check_nmea(s2) << '\n';
    return 0;
}
