#ifndef LISTADUPLA_H
#define LISTADUPLA_H

#include "NoDuplo.h"

class ListaDupla {
private:
    NoDuplo* inicio;
    NoDuplo* fim;
    int tamanho;

public:
    ListaDupla();
    ~ListaDupla();
    
    // Métodos básicos
    void inserir(Processo* processo);
    Processo* removerInicio();
    bool vazia() const;
    int getTamanho() const;
    
    // Método de acesso para iterar
    NoDuplo* getInicio() const;
    
    void imprimir() const;
};

#endif