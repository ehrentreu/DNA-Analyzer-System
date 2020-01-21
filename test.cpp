
#include "test.h"
void test()
{

    try {
        std::string s = "ACGGATACGCAC";
        DnaSequence my_sequence(s);
        std::cout << my_sequence;
        std::cout << my_sequence.dnaSequenceLength()<<"\n";
        DnaSequence my_sequence1 = my_sequence.getDnaSequenceSlice(0, 8);
        std::cout << my_sequence1;
        DnaSequence my_sequence2 = my_sequence1.pairingDnaSequence();
        std::cout << my_sequence2;
        DnaSequence my_sequence3("ACGC");
        std::cout<< my_sequence.findSubSequence(my_sequence3)<<"\n";
        DnaSequence my_sequence4("AC");
        std::cout<< my_sequence.countSubSequence(my_sequence4)<<"\n";
        std::vector<size_t > all_indexes = my_sequence.findAllSubSequence(my_sequence4);
        for (size_t i = 0; i < all_indexes.size(); ++i)
        {
            std::cout <<all_indexes[i]<<"  ";
        }
        std::cout << "\n";
        DnaSequence my_sequence5("ATATGTAGTAAATGTGA");
        std::vector<DnaSequence > all_consensus = my_sequence5.find_all_consensus();
        for (size_t i = 0; i < all_consensus.size(); ++i)
        {
            std::cout <<all_consensus[i];
        }
//std::vector<DnaSequence> my_vector=readDnaSequenceFromFile(3,)


/*std::cout << "Hello, World!" << std::endl;
std::string s = "ACTAC";
char *s1 = (char*)"TGAGTCTA";
DnaSequence my_sequence(s);
DnaSequence my_sequence1(s1);
my_sequence[1] = 'A';
std::cout<<my_sequence;

std::cout<< "-----------------" << my_sequence[2].getNucleotide() << std::endl;
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
std::cout<<my_sequence1;*/
    }
    catch (const char* msg)
    {
        std::cerr << msg << '\n';
    }
}