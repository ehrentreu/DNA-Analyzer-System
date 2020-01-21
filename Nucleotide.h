
#ifndef DNA_NUCLEOTIDES_H
#define DNA_NUCLEOTIDES_H


class Nucleotide {
public:
    Nucleotide();

    Nucleotide(const char &my_nucleotide);

    Nucleotide &operator=(const Nucleotide &my_nucleotide);

    const char getNucleotide() const;

private:
    char m_nucleotide;
};

inline Nucleotide::Nucleotide() {}

inline Nucleotide::Nucleotide(const char &my_nucleotide) {
    if (my_nucleotide == 'A' || my_nucleotide == 'C' || my_nucleotide == 'T' ||
        my_nucleotide == 'G') {
        m_nucleotide = my_nucleotide;
    } else
        throw "invalid nucleotide";
}

inline Nucleotide &Nucleotide::operator=(const Nucleotide &my_nucleotide)
{
    m_nucleotide = my_nucleotide.m_nucleotide;
    return *this;
}


inline const char Nucleotide::getNucleotide() const {
    return m_nucleotide;
}


#endif