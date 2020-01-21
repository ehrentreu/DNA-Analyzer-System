
#ifndef DNA_SEQUENCE_REFUCTOR_RENAME_H
#define DNA_SEQUENCE_REFUCTOR_RENAME_H
#include "../ICommand.h"

class Rename: public ICommand{
    Rename();
    void execute();
};

Rename::Rename() {

}

void Rename::execute() {

}



#endif //DNA_SEQUENCE_REFUCTOR_RENAME_H
