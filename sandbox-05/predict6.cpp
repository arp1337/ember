#include <cstdint>
#include <iostream>

int main() {
    char text[] = "hello";
    int shift = 3;

    for (int i = 0; text[i] != '\0'; ++i) {
        text[i] = (char)('a' + (text[i] - 'a' + shift) % 26);
    }

    std::cout << text << '\n';
}