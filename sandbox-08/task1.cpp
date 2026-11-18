#include <cstdint>
#include <iostream>

bool is_delimiter(char c) { return c == ' ' || c == ',' || c == '\t'; }

int count_words(const char* text) {
    if (text == nullptr) {
        return 0;
    }

    int count = 0;
    bool in_word = false;

    for (int i = 0; text[i] != '\0'; ++i) {
        if (is_delimiter(text[i])) {
            in_word = false;
        } else {
            if (!in_word) {
                count++;
                in_word = true;
            }
        }
    }

    return count;
}

int main() {
    std::cout << count_words("one,two three") << ' ' << count_words("  a,,b ") << '\n';
    return 0;
}
