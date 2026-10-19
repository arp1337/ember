#include <iostream>

int sum(const int* begin, const int* end) {
    int result = 0;

    while (begin != end) {
        result += *begin;
        ++begin;
    }

    return result;
}

int main() {
    int a[3] = {1, 2, 3};

    std::cout << sum(a, a + 3) << ' ';
    std::cout << sum(a, a) << '\n';
}
