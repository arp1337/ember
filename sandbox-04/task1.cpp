#include <iostream>

int collatz_steps(int n) {
    int steps = 0;

    while (n != 1) {
        if (n % 2 == 0) {
            n = n / 2;
        } else {
            n = 3 * n + 1;
        }

        steps++;
    }

    return steps;
}

int main() {
    int best_number = 0;
    int max_steps = 0;

    for (int i = 1; i <= 99; i++) {
        int steps = collatz_steps(i);

        if (steps > max_steps) {
            max_steps = steps;
            best_number = i;
        }
    }

    std::cout << best_number << " " << max_steps << "\n";

    return 0;
}