//
// Created by ricar on 20.10.2023.
//

#include "Generator.h"
#include <iostream>
#include <vector>

int Generator::CalculateNextBit() {
    // Generate value from first register
    int upperOp = upperReg.readAt(7);
    int upperCurrent = upperReg.readAt(0);
    upperReg.shift(upperOp ^ upperCurrent); // bitwise xor

    // read the current bits of the lower reg
    int lowerCurrent1 = lowerReg.readAt(10 - firstSeed);
    int lowerCurrent2 = lowerReg.readAt(10 - secondSeed);
    int lowerResult = lowerCurrent1 ^ lowerCurrent2;

    // shift lower reg further
    int lowerOp8 = lowerReg.readAt(8);
    int lowerOp7 = lowerReg.readAt(7);
    int lowerOp4 = lowerReg.readAt(4);
    int lowerOp2 = lowerReg.readAt(2);
    int lowerOp1 = lowerReg.readAt(1);
    int lowerOp0 = lowerReg.readAt(0);

    int nextLower = lowerOp0 ^ lowerOp1 ^ lowerOp2 ^ lowerOp4 ^ lowerOp7 ^ lowerOp8;
    lowerReg.shift(nextLower);

    int result = upperCurrent ^ lowerResult;

    return result == 0 ? -1 : result;
}

std::vector<int> Generator::CalculateSequence() {
    std::vector<int> vec;
    vec.reserve(1023);
    for(int i = 0; i < 1023; i++){
        vec.push_back(CalculateNextBit());
    }

    return vec;
}

Generator::Generator(int firstSeed, int secondSeed): upperReg(1023, 10), lowerReg(1023, 10){
    this -> firstSeed = firstSeed;
    this -> secondSeed = secondSeed;
}

