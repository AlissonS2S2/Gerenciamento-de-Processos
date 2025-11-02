#ifndef NODUPLO_H
#define NODUPLO_H

#include "Processo.h"

class NoDuplo {
public:
    Processo* processo;
    NoDuplo* anterior;
    NoDuplo* proximo;
    
    NoDuplo(Processo* processo);
    ~NoDuplo();
};

#endif