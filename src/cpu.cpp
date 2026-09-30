#include "cpu.hpp"
#include "alu.hpp"

#include <iostream>

// Результат розбору одного опкода:
// group — старший півбайт, index — молодший.
struct DecodedOp {
    Byte group;
    Byte index;
};

static DecodedOp decode(Byte op) {
    DecodedOp d;

    d.group = static_cast<Byte>((op >> 4) & 0x0F);
    d.index = static_cast<Byte>(op & 0x0F);

    return d;
}

void step(CPU& cpu) {
    // Після HALT нові інструкції не виконуються
    if (cpu.halted) {
        std::cout << "halted\n";
        return;
    }

    // Читаємо опкод за адресою PC
    Byte op = mem_get(*cpu.mem, cpu.pc);

    // Розбиваємо його на групу та індекс
    DecodedOp d = decode(op);

    switch (d.group) {
    case 0x0:
        // Група 0x0_: HALT, NOP
        switch (d.index) {
        case 0x0:
            cpu.halted = true;
            cpu.pc += 1;
            break;

        case 0x1:
            cpu.pc += 1;
            break;

        default:
            // Невідомий опкод поки поводиться як NOP
            cpu.pc += 1;
            break;
        }
        break;

    case 0x1:
        // Група 0x1_: ALU
        switch (d.index) {
        case 0x0:
            cpu.a = alu_add(cpu.a, cpu.b, cpu.f);
            cpu.pc += 1;
            break;

        case 0x1:
            cpu.a = alu_sub(cpu.a, cpu.b, cpu.f);
            cpu.pc += 1;
            break;

        case 0x2:
            cpu.a = alu_and(cpu.a, cpu.b, cpu.f);
            cpu.pc += 1;
            break;

        case 0x3:
            cpu.a = alu_or(cpu.a, cpu.b, cpu.f);
            cpu.pc += 1;
            break;

        case 0x4:
            cpu.a = alu_xor(cpu.a, cpu.b, cpu.f);
            cpu.pc += 1;
            break;

        case 0x5:
            cpu.a = alu_not(cpu.a, cpu.f);
            cpu.pc += 1;
            break;

        case 0x6:
            cpu.a = alu_shl(cpu.a, cpu.f);
            cpu.pc += 1;
            break;

        case 0x7:
            cpu.a = alu_shr(cpu.a, cpu.f);
            cpu.pc += 1;
            break;

        case 0x8:
            cpu.a = alu_inc(cpu.a, cpu.f);
            cpu.pc += 1;
            break;

        case 0x9:
            cpu.a = alu_dec(cpu.a, cpu.f);
            cpu.pc += 1;
            break;

        default:
            cpu.pc += 1;
            break;
        }
        break;

    default:
        // Інші групи будуть у наступних лабораторних
        cpu.pc += 1;
        break;
    }
}

void dump_regs(const CPU& cpu) {
    std::cout << "PC=" << cpu.pc
              << " A=" << static_cast<int>(cpu.a)
              << " B=" << static_cast<int>(cpu.b)
              << " Z=" << cpu.f.z
              << " N=" << cpu.f.n
              << " C=" << cpu.f.c
              << '\n';
}