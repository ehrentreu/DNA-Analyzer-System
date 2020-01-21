
#ifndef DNA_SEQUENCE_REFUCTOR_FIND_H
#define DNA_SEQUENCE_REFUCTOR_FIND_H
#include "../ICommand.h"

class Find: public ICommand{
public:
    Find(DnaSequence *dnaSequence);
    void execute();
private:
    DnaSequence *m_dnaSequence;
};

inline Find::Find(DnaSequence *dnaSequence) {
    m_dnaSequence = dnaSequence;
}

void Find::execute() {
//    m_dnaSequence ->find_subsequence();
}

#endif //DNA_SEQUENCE_REFUCTOR_FIND_H
