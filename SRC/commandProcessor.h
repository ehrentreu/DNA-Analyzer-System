
#ifndef DNA_COMMANDPROCESSOR_H
#define DNA_COMMANDPROCESSOR_H

#include "fileReader.h"
#include "DnaCollection.h"
#include "fileWriter.h"

#include <iostream>
#include <vector>
#include <sstream>
//enum function_name{NEW, SAVE, LOAD};

std::vector<std::string> splitText( std::string s, char delimiter);

class commandProcessor
{
public:
    commandProcessor();
    void callParser(std::string);
    void newSeq(std::string sequence_str, std::string seq_name="");
    void load(std::string file_name, std::string seq_name="");
    void save(const DnaData & my_dna, std::string file_name="");

private:
    DnaCollection m_dna_collection;
    static size_t seq_num;
};

size_t commandProcessor::seq_num = 0;

commandProcessor::commandProcessor() {
    m_dna_collection = DnaCollection();
}

void commandProcessor::callParser(std::string input) {

    std::vector<std::string> words_array;
    words_array=splitText(input,' ');
    std::string command=words_array[0];
    if (command=="new")
    {
        std::string  seq_string=words_array[1];
        std::string  seq_name="";
        if (words_array.size()==3) // there is name sequence
            seq_name=words_array[2].substr(1,words_array[2].length());
        newSeq(seq_string, seq_name);
    }

    if (command=="load")
    {

        std::string  file_name=words_array[1];
        std::string  seq_name="";
        if (words_array.size()==3) // there is name sequence
            seq_name=words_array[2].substr(1,words_array[2].length());

    }

    if (command=="save")
    {
        //dna_data_item.setStatus();

    }
}

void commandProcessor::newSeq(std::string sequence_str, std::string seq_name) {
    DnaSequence dna_seq(sequence_str);
    std::cout<<dna_seq;
    std::cout<<seq_name;
    DnaData dna_data_item(dna_seq,seq_name);
    //add to collection
  //  m_dna_collection.add(dna_data_item);
    dna_data_item.show();
}

void commandProcessor::load(std::string file_name, std::string seq_name) {
    fileReader reader_seq;
    DnaSequence dna_seq;
    dna_seq=reader_seq.loadFromFile(file_name);
    DnaData dna_data_item(dna_seq,seq_name);
   // fileWriter.add(dna_data_item);
    dna_data_item.show();
}

void commandProcessor::save(const DnaData &my_dna, std::string file_name) {
    //dna_data_item.setStatus();   // in save

}


std::vector<std::string> splitText( std::string s, char delimiter)
{
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter))
    {
        tokens.push_back(token);
    }
    return tokens;
}




#endif
