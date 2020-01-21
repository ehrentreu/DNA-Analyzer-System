#include "DnaSequence.h"

bool beginWithSubSequence (Nucleotide * p_sub_sequence, const DnaSequence &subSequence)
{
    Nucleotide * sub_sequence_to_find = subSequence.getDnaSequence();

    for (size_t i = 0; i < subSequence.dnaSequenceLength(); ++i)
    {
        if(p_sub_sequence->getNucleotide() == sub_sequence_to_find->getNucleotide())
        {
            ++p_sub_sequence;
            ++sub_sequence_to_find;
        }
        else
            return false;
    }

    return true;
}

DnaSequence DnaSequence::getDnaSequenceSlice(size_t index_begin, size_t index_end) const
{
    if (index_begin < 0 || index_end > m_dnaSequence_len)
        throw "invalid index for sequence slice";

    size_t slice_len = index_end - index_begin;
    char *my_sliced_sequence = new char[slice_len];
    size_t next_index = 0;

    for (size_t i = index_begin; i < index_end; ++i)
    {
        my_sliced_sequence[next_index++] = m_dnaSequence[i].getNucleotide();
    }

    DnaSequence sliced_sequence(my_sliced_sequence);
    delete[] my_sliced_sequence;
    return sliced_sequence;
}

DnaSequence DnaSequence::pairingDnaSequence() const
{
    char my_pair;
    /*std::string my_paired;*/
    char * my_paired = new char[m_dnaSequence_len];
    size_t next_index = m_dnaSequence_len-1;
    for (size_t i = 0; i < m_dnaSequence_len; ++i)
    {
        switch (m_dnaSequence[i].getNucleotide())
        {
            case 'A':
                my_pair = 'T'; break;
            case 'T':
                my_pair = 'A'; break;
            case 'C':
                my_pair = 'G'; break;
            case 'G':
                my_pair = 'C'; break;
        }

        my_paired[next_index--] = my_pair;
    }

    DnaSequence my_paired_dna_sequence (my_paired);
    delete [] my_paired;
    return my_paired_dna_sequence;
}

size_t DnaSequence::findSubSequence (const DnaSequence &subSequence) const
{
    if (m_dnaSequence_len < subSequence.dnaSequenceLength())
        throw "invalid - sub sequence to find is bigger then sequence!";

    size_t indexes_lengh = m_dnaSequence_len-subSequence.dnaSequenceLength();
    Nucleotide * my_nucleotide = m_dnaSequence;

    for(size_t i = 0; i <= indexes_lengh; ++i)
    {
        if(beginWithSubSequence(my_nucleotide++, subSequence))
            return i;
    }

    return m_dnaSequence_len; /*subsequence wasn't found returns index after the end of sequence*/
}

size_t DnaSequence:: countSubSequence (const DnaSequence &subSequence) const
{
    size_t count = 0;

    if (m_dnaSequence_len < subSequence.dnaSequenceLength())
        throw "invalid - sub sequence to find is bigger then sequence!";

    size_t indexes_lengh = m_dnaSequence_len-subSequence.dnaSequenceLength();
    Nucleotide * my_nucleotide = m_dnaSequence;

    for(size_t i = 0; i <= indexes_lengh; ++i)
    {
        if(beginWithSubSequence(my_nucleotide++, subSequence))
            ++count;
    }

    return count;
}

std::vector<size_t > DnaSequence::findAllSubSequence(const DnaSequence &subSequence) const
{
    std::vector<size_t > indexes_of_sub_sequence;
    if (m_dnaSequence_len < subSequence.dnaSequenceLength())
        throw "invalid - sub sequence to find is bigger then sequence!";

    size_t indexes_lengh = m_dnaSequence_len-subSequence.dnaSequenceLength();
    Nucleotide * my_nucleotide = m_dnaSequence;

    for(size_t i = 0; i <= indexes_lengh; ++i)
    {
        if(beginWithSubSequence(my_nucleotide++, subSequence))
            indexes_of_sub_sequence.push_back(i);
    }

    return indexes_of_sub_sequence;
}


std::vector<DnaSequence> DnaSequence::find_all_consensus() const{
    size_t index = 0;
    size_t consensus_index = 0;
    std::vector<DnaSequence> all_consensus_sequence;
    size_t index_from;
    size_t index_to;
    size_t length = m_dnaSequence_len - MIN_CONSENUS_LENGTH;
    Nucleotide *nucleotide = m_dnaSequence;

    while (index <= length)
    {
        if (is_start_codon(&nucleotide[index]))
        {
            consensus_index = index;
            index_from = consensus_index;
            consensus_index += MULTIPLICATION_CODON;

            while (!is_end_codon(&nucleotide[consensus_index]) && consensus_index < length-3)
                consensus_index += MULTIPLICATION_CODON;

            if (is_end_codon(&nucleotide[consensus_index]))
            {
                index_to = consensus_index + MULTIPLICATION_CODON;
                all_consensus_sequence.push_back(getDnaSequenceSlice(index_from, index_to));
            }
            ++index;
        }

        else
            ++index;
    }
    return all_consensus_sequence;
}

void writeDnaSequenceToFile(const DnaSequence* writeSequence, size_t number_of_nucleotide_to_write, const char *const path)
{
    std::ofstream dnaSequenceFile (path);
    if (!dnaSequenceFile.is_open())
        throw "file does not exist";

    for (size_t i = 0; i < number_of_nucleotide_to_write; ++i)
        dnaSequenceFile << writeSequence[i];
    dnaSequenceFile.close();
}

const std::vector<DnaSequence> readDnaSequenceFromFile(size_t number_of_dna_sequence_to_read, const char *const path)
{
    std::vector <DnaSequence> read_dna_sequence;
    std::ifstream dnaSequenceFile (path);

    if (!dnaSequenceFile.is_open())
        throw "file does not exist";
    std::string readDnaString;

    for (size_t i = 0; i < number_of_dna_sequence_to_read ; ++i)
    {
        //std::string readString;
        dnaSequenceFile >> readDnaString;
        if (dnaSequenceFile.eof())
            throw "too many dna sequences to read";
        read_dna_sequence.push_back(DnaSequence(readDnaString));
    }
    dnaSequenceFile.close();

    return read_dna_sequence;
}



