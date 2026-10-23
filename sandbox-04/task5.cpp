#include <iostream>

int main() {
    for (unsigned i = 10; ; --i) {
        std::cout << i << " ";

        if (i == 0) {
            break;
        }
    }

    std::cout << "\n";
    return 0;
}