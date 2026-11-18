#include <cstdint>
#include <iostream>

void calculate(const char* s) {
    if (s == nullptr) {
        return;
    }

    int i = 0;
    int num1 = 0;
    while (s[i] >= '0' && s[i] <= '9') {
        num1 = num1 * 10 + (s[i] - '0');
        i++;
    }

    char op = s[i];
    i++;

    int num2 = 0;
    while (s[i] >= '0' && s[i] <= '9') {
        num2 = num2 * 10 + (s[i] - '0');
        i++;
    }

    if (s[i] != '\0') {
        std::cout << "error at " << i << '\n';
        return;
    }

    if (op == '+') {
        std::cout << num1 + num2 << '\n';
    } else if (op == '-') {
        std::cout << num1 - num2 << '\n';
    } else if (op == '*') {
        std::cout << num1 * num2 << '\n';
    }
}

int main() {
    calculate("12+34");
    calculate("7*6x");
    return 0;
}
