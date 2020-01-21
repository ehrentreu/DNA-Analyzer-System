
#ifndef DNA_FILEREADER_H
#define DNA_FILEREADER_H

#include "DnaSequence.h"
#include <string>

class fileReader
{
public:
    DnaSequence & loadFromFile(std::string file_name);
};

inline DnaSequence &fileReader::loadFromFile(std::string file_name) {
    std::string str;
    std::ifstream file(file_name.c_str());
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            str += line;
        }
        file.close();
    }
}

#endif
