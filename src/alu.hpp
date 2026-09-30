#pragma once

#include "cpu.hpp"

Byte alu_add(Byte a, Byte b, Flags& flags);
Byte alu_sub(Byte a, Byte b, Flags& flags);
Byte alu_and(Byte a, Byte b, Flags& flags);
Byte alu_or(Byte a, Byte b, Flags& flags);
Byte alu_xor(Byte a, Byte b, Flags& flags);
Byte alu_not(Byte a, Flags& flags);
Byte alu_shl(Byte a, Flags& flags);
Byte alu_shr(Byte a, Flags& flags);
Byte alu_inc(Byte a, Flags& flags);
Byte alu_dec(Byte a, Flags& flags);