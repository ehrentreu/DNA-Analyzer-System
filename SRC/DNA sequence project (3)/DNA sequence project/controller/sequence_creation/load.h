
#ifndef DNA_SEQUENCE_REFUCTOR_LOAD_H
#define DNA_SEQUENCE_REFUCTOR_LOAD_H
#include "../ICommand.h"
#include "../model/fileReader.h"

class Load: public ICommand{
public:
    Load(std::FileReader *fileReader);
    void execute();
private:
    FileReader *m_fileReader;
};

inline Load::Load(FileReader *fileReader) {
    m_fileReader = fileReader;
}

inline void Load::execute() {
//    m_fileReader->loadFromFile();
}



#endif //DNA_SEQUENCE_REFUCTOR_LOAD_H
