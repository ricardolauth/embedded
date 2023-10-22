#include <iostream>
#include<tuple>
#include <fstream>
#include <sstream>
#include <vector>
#include "Generator.h"
using namespace std;

tuple <int, int> config[24] = {
        make_tuple(2, 6),
        make_tuple(3, 7),
        make_tuple(4, 8),
        make_tuple(5, 9),
        make_tuple(1, 9),
        make_tuple(2, 10),
        make_tuple(1, 8),
        make_tuple(2, 9),
        make_tuple(3, 10),
        make_tuple(2, 3),
        make_tuple(3, 4),
        make_tuple(5, 6),
        make_tuple(6, 7),
        make_tuple(7, 8),
        make_tuple(8, 9),
        make_tuple(9, 10),
        make_tuple(1, 4),
        make_tuple(2, 5),
        make_tuple(3, 6),
        make_tuple(4, 7),
        make_tuple(5, 8),
        make_tuple(6, 9),
        make_tuple(1, 3),
        make_tuple(4, 6),
};

vector<int> chips[24];

int convert(const string& str)
{
    if(str == "0"){
        return 0;
    }
    if(str == "1"){
        return 1;
    }
    if(str == "2"){
        return 2;
    }
    if(str == "3"){
        return 3;
    }
    if(str == "4"){
        return 4;
    }
    if(str == "-1"){
        return -1;
    }
    if(str == "-2"){
        return -2;
    }
    if(str == "-3"){
        return -3;
    }
    if(str == "-4"){
        return -4;
    }

    return 0;
}

int corrolation(vector<int> digits, vector<int> chip, int rotation){
    int sum = 0;
    for(int i = 0; i < 1023; i++){
        int idx = rotation + i >= 1023 ? rotation + i - 1023 : rotation + i;
        sum += digits[idx] * chip[i];
    }
    return sum;
}

int main(int argc, char *argv[]) {
    // Generate the chips for every tuple
    for(int i = 0; i < 24; i++)
    {
        auto entry = config[i];
        Generator sat = *new Generator(get<0>(entry), get<1>(entry));
        chips[i] = sat.CalculateSequence();
    }

    // read the file
    std::ifstream file;
    file.open(argv[1]);
    std::stringstream ss;
    vector<int> vec;
    vec.reserve(1023);
    if ( file.is_open() ) {
        char myChar;
        while ( file ) {
            myChar = (char) file.get();
            if(myChar == ' ')
            {
                string str = ss.str();
                if(str.length() > 0){
                    vec.push_back(convert(str));
                    ss.str(std::string()); // clears the stringstream
                }
            } else
            {
                ss << myChar;
            }

        }
    }

    // calculate the corrolation foreach sat with all rotations
    for(int i = 0; i < 24; i++)
    {
        for(int j = 0; j < vec.size(); j++)
        {
            int cor = corrolation(vec, chips[i], j);
            if(cor >= 828){
                cout << "Satellite " << i << " has send bit 1 (Delta=" << j <<")" << endl;
            }
            if(cor <= -834){
                cout << "Satellite " << i << " has send bit 0 (Delta=" << j <<")" << endl;
            }
        }
    }

    return 0;
}


