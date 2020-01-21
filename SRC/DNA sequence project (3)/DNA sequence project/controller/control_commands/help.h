
#ifndef DNA_HELP_H
#define DNA_HELP_H

#include "../ICommand.h"
class Help: public ICommand{
public:
    Help();
    void execute();
private:
};

Help::Help(){

}

inline void Help::execute() {

}

#endif //DNA_SEQUENCE_REFUCTOR_HELP_H
