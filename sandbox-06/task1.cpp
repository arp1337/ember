#include <iostream>

// Початкова структура
struct Packet {
    char type;
    double value;
    char flags;
    int id;
};

// Оптимізована структура
struct OptimizedPacket {
    double value;
    int id;
    char type;
    char flags;
};

int main() {
    std::cout << sizeof(Packet) << ' '
              << sizeof(OptimizedPacket) << '\n';

    return 0;
}