
#ifndef DNA_DNACOLLECTION_H
#define DNA_DNACOLLECTION_H

#include "DnaData.h"
#include <iostream>
#include <map>
class DnaCollection
{

public:
    void add(DnaData & my_dna);
    void remove(size_t id);
    void update(size_t dna_src_id, DnaData & dna_data_dest);

private:
    std::map<std::string, size_t> name_id_seq_map;
    std::map<size_t , DnaData*> id_dna_data_map;
};

#endif
