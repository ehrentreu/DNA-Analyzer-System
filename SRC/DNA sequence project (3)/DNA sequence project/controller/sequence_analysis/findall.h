
#ifndef DNA_SEQUENCE_REFUCTOR_FINDALL_H
#define DNA_SEQUENCE_REFUCTOR_FINDALL_H
#include "../ICommand.h"

class Findall: public ICommand{
public:
    Findall(DnaSequence *dnaSequence);
    void execute();
private:
    DnaSequence *m_dnaSequence;
};

Findall::Findall(DnaSequence *dnaSequence) {
    m_dnaSequence = dnaSequence;
}

void Findall::execute() {
//    m_dnaSequence->findAll_subsequence();
}

#endif //DNA_SEQUENCE_REFUCTOR_FINDALL_H
