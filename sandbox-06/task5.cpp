#include <iostream>

struct Point {
    int x, y;
};

int main() {
    Point* points = new Point[3]{};

    for (int i = 0; i < 3; i++) {
        points[i].x = i + 1;
    }

    int sum = 0;

    for (int i = 0; i < 3; i++) {
        sum += points[i].x;
    }

    std::cout << sum << '\n';

    delete[] points;
    points = nullptr;

    return 0;
}