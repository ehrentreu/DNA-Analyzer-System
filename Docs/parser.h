
#ifndef DNA_PARSER_H
#define DNA_PARSER_H

#include "commands.h"
#include "fileReader.h"

#include <iostream>
#include <vector>
#include <sstream>
enum function_name{NEW, SAVE, LOAD};

std::vector<std::string> splitText( std::string s, char delimiter);

class parser
{
public:
    void callParser(std::string);
};

void parser::callParser(std::string input) {

    std::vector<std::string> words_array;
    words_array=splitText(input,' ');

    std::string command=words_array[0];
    if (command=="new")
    {

        std::string  seq_string=words_array[1];
        std::string  seq_name="";
        if (words_array.size()==3) // there is name sequence
            seq_name=words_array[2].substr(1,words_array[2].length());
        DnaSequence dna_seq(seq_string);
        DnaData dna_data_item(dna_seq,seq_name);
        //add to collection

        dna_data_item.show();
    }

    if (command=="load")
    {
        std::string  file_name=words_array[1];
        std::string  seq_name="";
        if (words_array.size()==3) // there is name sequence
            seq_name=words_array[2].substr(1,words_array[2].length());
        fileReader reader_seq;
        DnaSequence dna_seq;
        dna_seq=reader_seq.loadFromFile(file_name);
        DnaData dna_data_item(dna_seq,seq_name);
        //add to collection

        dna_data_item.show();
    }

    if (command=="save")
    {
        //dna_data_item.setStatus();

    }
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
