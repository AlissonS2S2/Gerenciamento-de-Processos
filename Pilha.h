#ifndef PILHA_H
#define PILHA_H

#include "NoSimples.h"

class Pilha {
private:
    NoSimples* topo;
    int tamanho;

public:
    Pilha();
    ~Pilha();
    
    void empilhar(Processo* processo);
    Processo* desempilhar();
    bool vazia() const;
    int getTamanho() const;
    void imprimir() const;
};

#endif