#ifndef NOSIMPLES_H
#define NOSIMPLES_H

#include "Processo.h"

class NoSimples {
public:
    Processo* processo;
    NoSimples* proximo;
    
    NoSimples(Processo* processo);
    ~NoSimples();
};

#endif