
#ifndef DNA_DNASEQUENCE_H
#define DNA_DNASEQUENCE_H

#include <cassert>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include "Nucleotide.h"

#define MIN_CONSENUS_LENGTH 6;
#define MULTIPLICATION_CODON 3;

class DnaSequence {
public:
    DnaSequence();

    DnaSequence(const std::string &my_dna);

    DnaSequence(const DnaSequence &my_dna);

    ~DnaSequence();

    DnaSequence &operator=(const DnaSequence &my_dna);

    DnaSequence &operator=(const std::string &my_dna_sequence);

    void buildNucleotide(const char *my_dna_sequence);

    Nucleotide *getDnaSequence() const;

    const Nucleotide operator[](size_t index) const;  /*read only*/

    Nucleotide & operator[](size_t index);

    size_t dnaSequenceLength() const;

    DnaSequence getDnaSequenceSlice (size_t index_begin, size_t index_end)const;

    DnaSequence pairingDnaSequence() const;

    size_t findSubSequence (const DnaSequence &subSequence) const;

    size_t countSubSequence (const DnaSequence &subSequence) const;

    std::vector<size_t > findAllSubSequence(const DnaSequence &subSequence) const;

    std::vector<DnaSequence>find_all_consensus() const;

    friend std::ostream &operator<<(std::ostream &os, const DnaSequence &my_dna);

private:
    Nucleotide *m_dnaSequence;
    size_t m_dnaSequence_len;
};

bool beginWithSubSequence (Nucleotide * p_sub_sequence, const DnaSequence &subSequence);

void writeDnaSequenceToFile(const DnaSequence* writeSequence, size_t number_of_nucleotide_to_write, const char *const path);

const std::vector<DnaSequence> readDnaSequenceFromFile(size_t number_of_dna_sequence_to_read,const char *const path);

inline void my_sequence_cpy(Nucleotide dst[], const Nucleotide src[], size_t len) {
    for (size_t i = 0; i < len; ++i)
    {
        *dst = *src;
        dst++;
        src++;
    }

}

inline size_t my_sequence_len(const char sequence[]) {
    const char *sequence_pointer = sequence;
    while (*sequence_pointer++);
    return sequence_pointer - sequence - 1;
}


inline int my_sequence_cmp(const DnaSequence & dna1, const DnaSequence
& dna2) {
    const Nucleotide *sequence1 = dna1.getDnaSequence();
    const Nucleotide *sequence2 = dna2.getDnaSequence();

    if (dna1.dnaSequenceLength() != dna2.dnaSequenceLength())
        return 0;
    for (size_t i = 0; i < dna1.dnaSequenceLength(); ++i)
    {
        if(sequence1[i].getNucleotide() == sequence2[i].getNucleotide()){}
        else
            return 0;
    }
    return 1;
}


inline void DnaSequence::buildNucleotide(const char my_dna_sequence[]) {
    m_dnaSequence = new Nucleotide[m_dnaSequence_len];
    const char *dna_sequence_pointer = my_dna_sequence;
    Nucleotide my_nucleotide;

    for(size_t i = 0; i < m_dnaSequence_len; ++i)
    {
        my_nucleotide = Nucleotide(*dna_sequence_pointer++);
        m_dnaSequence[i] = my_nucleotide;
    }

}

inline DnaSequence::DnaSequence(){}

inline DnaSequence::DnaSequence(const std::string &my_dna_sequence) {
    const char *my_dna_sequence1 = my_dna_sequence.c_str();

    if (my_dna_sequence1)
    {
        m_dnaSequence_len = my_sequence_len(my_dna_sequence1);
        buildNucleotide(my_dna_sequence1);
    }
}

inline DnaSequence::DnaSequence(const DnaSequence &my_dna) {
    m_dnaSequence = new Nucleotide[my_dna.m_dnaSequence_len];
    my_sequence_cpy(m_dnaSequence, my_dna.m_dnaSequence, my_dna.dnaSequenceLength());
    m_dnaSequence_len = my_dna.m_dnaSequence_len;
}

inline DnaSequence::~DnaSequence()
{
    delete [] m_dnaSequence;
}

inline DnaSequence &DnaSequence::operator=(const DnaSequence &my_dna){
    if (this != &my_dna)
    {
        /*delete [] m_dnaSequence;*/
        if (my_dna.m_dnaSequence)
        {
            this->m_dnaSequence = new Nucleotide[my_dna.m_dnaSequence_len];
            my_sequence_cpy(m_dnaSequence, my_dna.m_dnaSequence, my_dna.dnaSequenceLength());
            m_dnaSequence_len = my_dna.m_dnaSequence_len;
        }

        else
        {
            this->m_dnaSequence = NULL;
        }

    }
    return *this;
}

inline DnaSequence &DnaSequence::operator=(const std::string &my_dna_sequence) {
    DnaSequence dna(my_dna_sequence);
    *this = dna;
    return *this;

}

inline Nucleotide *DnaSequence::getDnaSequence() const {
    assert(m_dnaSequence);
    return m_dnaSequence;
}


inline const Nucleotide DnaSequence::operator[](size_t index) const /*read only*/
{
    if (index >= m_dnaSequence_len)
        throw "invalid index!";
    return m_dnaSequence[index];
}

inline Nucleotide & DnaSequence::operator[](size_t index)
{
    if (index >= m_dnaSequence_len)
        throw "invalid index!";
    return m_dnaSequence[index];
}

inline size_t DnaSequence::dnaSequenceLength() const {
    return m_dnaSequence_len;
}

inline std::ostream &operator<<(std::ostream &os, const DnaSequence &my_dna) {

    for (size_t i = 0; i < my_dna.dnaSequenceLength(); ++i)
    {
        os << my_dna.getDnaSequence()[i].getNucleotide();
    }

    os << "\n";
    return os;
}

inline bool operator==(const DnaSequence &dna1, const DnaSequence &dna2) {
    return my_sequence_cmp(dna1, dna2);
}

inline bool operator!=(const DnaSequence &dna1, const DnaSequence &dna2) {
    return !my_sequence_cmp(dna1, dna2);
}

inline bool is_start_codon(Nucleotide *nucleotide)
{
    if (nucleotide[0].getNucleotide() == 'A' && nucleotide[1].getNucleotide() == 'T'
        && nucleotide[2].getNucleotide() == 'G')
        return true;
    return false;
}

inline bool is_end_codon(Nucleotide *nucleotide)
{
    if ((nucleotide[0].getNucleotide() == 'T' && nucleotide[1].getNucleotide() == 'A'
         && nucleotide[2].getNucleotide() == 'G') ||
        (nucleotide[0].getNucleotide() == 'T' && nucleotide[1].getNucleotide() == 'G'
         && nucleotide[2].getNucleotide() == 'A') ||
        (nucleotide[0].getNucleotide() == 'T' && nucleotide[1].getNucleotide() == 'A'
         && nucleotide[2].getNucleotide() == 'A'))
        return true;
    return false;
}


#endif
