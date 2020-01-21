

#ifndef DNA_Command_H
#define DNA_Command_H

#include "model/fileWriter.h"
#include "model/fileReader.h"
#include "model/DnaCollection.h"
#include "model/dnaRecord.h"

class ICommand{
public:
    ICommand();
    virtual void execute() = 0;


//    void newSD(std::string sequence_str, std::string dnaSeq_name = "");
//    void load(std::string file_name, std::string dnaSeq_name = "");
//    void save(const DnaRecord &dnaObj, std::string file_name = "");
};


#endif
