
#ifndef DNA_CLI_H
#define DNA_CLI_H

#include <string>

class Cli
{
public:
    void callParser(std::string input);

private:
    std::string m_input;
};

#endif

