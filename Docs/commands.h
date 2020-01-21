
#ifndef DNA_COMMANDS_H
#define DNA_COMMANDS_H

#include "fileReader.h"
#include "fileWriter.h"
#include "DnaData.h"


class commands
{
public:
    void newSeq(std::string sequence_str, std::string seq_name="");
    void load(std::string file_name, std::string seq_name="");
    void save(const DnaData & my_dna, std::string file_name="");
};

inline void commands::newSeq(std::string sequence_str, std::string seq_name) {

}

inline void commands::load(std::string file_name, std::string seq_name) {

}

inline void commands::save(const DnaData &my_dna, std::string file_name) {

}


#endif
