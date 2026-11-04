#include <iostream>

struct Vec {
    int x, y;
};

Vec add(Vec a, Vec b) {
    return {a.x + b.x, a.y + b.y};
}

void scale(Vec* v, int k) {
    v->x *= k;
    v->y *= k;
}

int main() {
    Vec result = add({1, 2}, {3, 4});

    std::cout << result.x << ' ' << result.y << '\n';

    scale(&result, 2);

    std::cout << result.x << ' ' << result.y << '\n';

    return 0;
}