//
// Created by ricar on 20.10.2023.
//

#ifndef EMBEDDED_GENERATOR_H
#define EMBEDDED_GENERATOR_H


#include <vector>
#include "ShiftRegister.h"

class Generator {
public:
    Generator(int firstSeed, int secondSeed);
    std::vector<int> CalculateSequence();
private:
    int CalculateNextBit();
    ShiftRegister upperReg;
    ShiftRegister lowerReg;
    int firstSeed;
    int secondSeed;
};


#endif //EMBEDDED_GENERATOR_H
