#include "alu.hpp"

// Оновлює прапорці Z і N за результатом
static void set_zn(Byte result, Flags& flags) {
    flags.z = (result == 0);
    flags.n = (result & 0x80) != 0;
}

Byte alu_add(Byte a, Byte b, Flags& flags) {
    unsigned int sum = static_cast<unsigned int>(a) +
                       static_cast<unsigned int>(b);

    Byte result = static_cast<Byte>(sum);

    set_zn(result, flags);
    flags.c = (sum > 255); // перенос за межі 8 біт

    return result;
}

Byte alu_sub(Byte a, Byte b, Flags& flags) {
    Byte result = static_cast<Byte>(a - b);

    set_zn(result, flags);
    flags.c = (a < b); // була позика

    return result;
}

Byte alu_and(Byte a, Byte b, Flags& flags) {
    Byte result = static_cast<Byte>(a & b);

    set_zn(result, flags);
    flags.c = false;

    return result;
}

Byte alu_or(Byte a, Byte b, Flags& flags) {
    Byte result = static_cast<Byte>(a | b);

    set_zn(result, flags);
    flags.c = false;

    return result;
}

Byte alu_xor(Byte a, Byte b, Flags& flags) {
    Byte result = static_cast<Byte>(a ^ b);

    set_zn(result, flags);
    flags.c = false;

    return result;
}

Byte alu_not(Byte a, Flags& flags) {
    Byte result = static_cast<Byte>(~a);

    set_zn(result, flags);
    flags.c = false;

    return result;
}

Byte alu_shl(Byte a, Flags& flags) {
    flags.c = (a & 0x80) != 0; // старший біт виїде за край

    Byte result = static_cast<Byte>(a << 1);

    set_zn(result, flags);

    return result;
}

Byte alu_shr(Byte a, Flags& flags) {
    flags.c = (a & 0x01) != 0; // молодший біт виїде за край

    Byte result = static_cast<Byte>(a >> 1);

    set_zn(result, flags);

    return result;
}

Byte alu_inc(Byte a, Flags& flags) {
    Byte result = static_cast<Byte>(a + 1);

    set_zn(result, flags);

    return result;
}

Byte alu_dec(Byte a, Flags& flags) {
    Byte result = static_cast<Byte>(a - 1);

    set_zn(result, flags);

    return result;
}