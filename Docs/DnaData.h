
#ifndef DNA_DNADATA_H
#define DNA_DNADATA_H

#include <cstddef>
#include <iostream>
#include "DnaSequence.h"

class DnaData
{
public:
    DnaData(DnaSequence &dnaSeq, std::string dnaSeq_name);
    void show();
    size_t getCurrentId() const;
    void setStatus (char new_status);

private:
    size_t m_id;
    char m_status;
    std:: string m_name;
    DnaSequence m_dna_seq;
    static size_t current_id;
};

size_t DnaData :: current_id = 0;


inline DnaData::DnaData(DnaSequence &dnaSeq, std::string dnaSeq_name): m_dna_seq(dnaSeq){
    m_id = getCurrentId();
    if(dnaSeq_name != "")
        m_name = dnaSeq_name;
    else
        m_name = "seq" + m_id;
    m_status = '*';
}

inline size_t DnaData::getCurrentId() const {
    return ++current_id;
}

inline void DnaData::show() {
    std::cout << "[" << m_id << "] " << m_name << m_status << "\n";
    for (size_t i = 0; i < m_dna_seq.dnaSequenceLength(); ++i)
    {
        std::cout<<m_dna_seq[i].getNucleotide();

        if(i % 99 == 0)
        {
            std::cout << "/n";
        }
    }
}

inline void DnaData::setStatus(char new_status) {
    m_status = new_status;

}


#endif
