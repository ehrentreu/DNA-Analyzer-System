
#ifndef DNA_SEQUENCE_REFUCTOR_COUNT_H
#define DNA_SEQUENCE_REFUCTOR_COUNT_H
#include "../ICommand.h"

class Count: public ICommand{
public:
    Count(DnaSequence *dnaSequence);
    void execute();
private:
    DnaSequence *m_dnaSequence;
};

Count::Count(DnaSequence *dnaSequence) {
    m_dnaSequence = dnaSequence;
}

void Count::execute() {
//    m_dnaSequence->count_subsequence();
}

#endif //DNA_SEQUENCE_REFUCTOR_COUNT_H
