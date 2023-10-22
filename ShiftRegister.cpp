//
// Created by ricar on 20.10.2023.
//

#include "ShiftRegister.h"

void ShiftRegister::shift(int val)
{
    reg >>= 1; // right shift by one
    if(val == 1){
        int mask = 1 << (len - 1); // left shift the bit to the most significant bit (within our length)
        reg |= mask; // sets the bit
    }
}

int ShiftRegister::readAt(int idx) const
{
    int mask = 1 << idx; // shift the mask bit to the index
    int ret = mask & reg; // bitwise and sets everything else to zero
    ret >>= idx; // shift the bit at idx to the lowest bit

    return ret;
}

ShiftRegister::ShiftRegister(int initValue, int length)
{
    reg = initValue;
    len = length;
}
