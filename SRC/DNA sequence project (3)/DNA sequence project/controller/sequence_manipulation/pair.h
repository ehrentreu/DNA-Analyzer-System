
#ifndef DNA_SEQUENCE_REFUCTOR_PAIR_H
#define DNA_SEQUENCE_REFUCTOR_PAIR_H
#include "../ICommand.h"

class Pair: public ICommand{
public:
    Pair(DnaSequence *dnaSequence);
    void execute();
private:
    DnaSequence *m_dnaSequence;
};

inline Pair::Pair(DnaSequence *dnaSequence) {
    m_dnaSequence = dnaSequence;
}

inline void Pair::execute() {
    m_dnaSequence->pairing_sequence();
}

#endif //DNA_SEQUENCE_REFUCTOR_PAIR_H
