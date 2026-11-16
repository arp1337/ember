#include <cstdint>
#include <iostream>

int main() {
    const long long max_int = 2147483647LL;
    long long fact = 1;
    int n = 1;

    while (true) {
        long long next_fact = fact * (n + 1);
        if (next_fact > max_int) {
            break;
        }
        fact = next_fact;
        n = n + 1;
    }

    std::cout << n << '\n';
    return 0;
}
