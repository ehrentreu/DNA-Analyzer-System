
#ifndef DNA_SEQUENCE_REFUCTOR_SAVE_H
#define DNA_SEQUENCE_REFUCTOR_SAVE_H
#include "../ICommand.h"
#include "../fileWriter.h"

class Save: public ICommand{
public:
    Save(FileWriter *fileWriter);
    void execute(std::vector<std::string>);
private:
    FileWriter *m_fileWriter;
};

inline Save::Save(FileWriter *fileWriter) {
    m_fileWriter = fileWriter;
}


inline void Save::execute(std::vector<std::string> parse_vec) {

//    m_fileWriter->saveToFile();
}





#endif //DNA_SEQUENCE_REFUCTOR_SAVE_H
