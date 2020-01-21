
#ifndef DNA_CLI_H
#define DNA_CLI_H

#include <string>
#include "commandProcessor.h"

class Cli
{
public:
    Cli();
    void getInputCommands();
    void printDna()const;

private:
    commandProcessor m_command_analyzer;
};

void Cli::getInputCommands()
{
    std::string command_input;
    std:: cout << "enter your commands\n";
    do{
        std::cout<<"> cmd >>>";
        getline(std::cin,command_input);
        m_command_analyzer.callParser(command_input);
    } while (command_input!="quit");
    std::cout << "Thank you for using Dnalanzer\nGoodbye!";
}

Cli::Cli() {
    m_command_analyzer = commandProcessor();
}

void Cli::printDna() const {

}


#endif


