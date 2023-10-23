//
// Created by ricar on 20.10.2023.
//

#ifndef EMBEDDED_SHIFTREGISTER_H
#define EMBEDDED_SHIFTREGISTER_H


class ShiftRegister {
public:
    ShiftRegister(int initValue, int length);
    void shift(int val);
    int readAt(int idx) const;

private:
    int reg;
    int len;
};


#endif //EMBEDDED_SHIFTREGISTER_H
