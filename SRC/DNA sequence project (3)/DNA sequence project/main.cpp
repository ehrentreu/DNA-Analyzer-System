#include <iostream>
#include "model/dna_sequence.h"
#include "view/CLI.h"
#include <exception>
#include <string>


int main()
{
    CLI cli;
    cli.getInputCLI();
}


/*int main() {
    try {
        DnaSequence dna_test("GTATGATGCCCTGATGTAA");
        std::vector<DnaSequence> vec = dna_test.find_consensus();
        vec[0].get_sequence_as_str();
        std::string s = "GTCGCATGCCCCC";
        char *s1 = (char*)"TGAGTCTA";
        DnaSequence my_sequence(s);
        DnaSequence find("C");
        DnaSequence sub_seq(my_sequence.sequence_slicing(0,5));
        std::cout<<find_sub_in_start(my_sequence.get_sequence(),sub_seq );
        std::cout<<my_sequence.find_subsequence(find);
        std::cout<<my_sequence.count_subsequence(find);
        my_sequence.findAll_subsequence(find);

        std::cout<<"slice s from 2 to 5:  "<<sub_seq;
        DnaSequence pair_seq(my_sequence.pairing_sequence());
        std::cout<<"pairing of s is:  "<<pair_seq<<std::endl;
        DnaSequence my_sequence1(s1);
        std::cout << std::endl<<my_sequence[2].getNucleotide() << std::endl;
        std::cout<<my_sequence1;
        DnaSequence my_sequence2 = my_sequence1;
        std::cout<<my_sequence2;
        std :: cout << "first index " << my_sequence2[5].getNucleotide()<< std::endl;
        DnaSequence my_sequence3;
        my_sequence3 = my_sequence1;
        DnaSequence my_sequence4;
        my_sequence4 =(char*)"AAGGG";
        std::cout<<my_sequence4;
        std::cout<<"3    "<<my_sequence3;
        Nucleotide *m_dnaSequence = new Nucleotide[5];
        Nucleotide n('C');
        m_dnaSequence[2] = Nucleotide('A');
        std::cout << m_dnaSequence[2].getNucleotide() << std::endl;
        std::cout << sizeof(Nucleotide) << std::endl;
        std::cout << sizeof(n) << std::endl;
        int b ;
        if (my_sequence1 != my_sequence)
            b = 1;
        else
            b = 0;
        std::cout<< b << "\n";
        int b1;
        if (my_sequence1 == my_sequence)
            b1 = 1;
        else
            b1 = 0;
        std::cout<< b1 << "\n";
        std::cout<<my_sequence;
        std::cout<<my_sequence1;
    }
    catch (const char* msg)
    {
        std::cerr << msg << '\n';
    }

    return 0;
}*/