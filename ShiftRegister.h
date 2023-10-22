//
// Created by ricar on 20.10.2023.
//

#ifndef EMBEDDED_SHIFTREGISTER_H
#define EMBEDDED_SHIFTREGISTER_H


class ShiftRegister {
public:
    ShiftRegister(int initValue, int length);

    void shift(int val);
//    {
//        int ret = reg & 1; // this reads the lowest bit
//        reg >>= 1; // right shift by one
//        if(val == 1){
//            int mask = 1 << (len - 1); // left shift the bit to the most significant bit (within our length)
//            reg &= mask; // sets the bit
//        }
//
//        return ret;
//    }

    int readAt(int idx) const;
/*    {
        int mask = 1 << idx; // shift the mask bit to the index
        int ret = mask & reg; // bitwise and sets everything else to zero
        ret >>= idx; // shift the bit at idx to the lowest bit
        if(ret == 0){
            ret = -1;
        }

        return ret;
    }*/

/*    ShiftRegister(int initValue, int length);
    {
        reg = initValue;
        len = length;
    }*/

private:
    int reg;
    int len;
};


#endif //EMBEDDED_SHIFTREGISTER_H
