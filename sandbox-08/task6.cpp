#include <cstdint>
#include <iostream>

void tokenize(const char* s) {
    if (s == nullptr) {
        return;
    }

    int i = 0;
    bool first = true;

    while (s[i] != '\0') {
        if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n' || s[i] == '\r') {
            i++;
            continue;
        }

        if (!first) {
            std::cout << ' ';
        }
        first = false;

        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
            std::cout << "Ident(";
            while ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z')) {
                std::cout << s[i];
                i++;
            }
            std::cout << ')';
        } else if (s[i] >= '0' && s[i] <= '9') {
            std::cout << "Number(";
            while (s[i] >= '0' && s[i] <= '9') {
                std::cout << s[i];
                i++;
            }
            std::cout << ')';
        } else {
            std::cout << "Punct(" << s[i] << ')';
            i++;
        }
    }

    std::cout << '\n';
}

int main() {
    tokenize("ab=7");
    tokenize("count=12+x");
    return 0;
}
