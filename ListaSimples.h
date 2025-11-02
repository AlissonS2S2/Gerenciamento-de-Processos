#ifndef LISTASIMPLES_H
#define LISTASIMPLES_H

#include "NoSimples.h"

class ListaSimples {
private:
    NoSimples* inicio;
    NoSimples* fim;
    int tamanho;

public:
    ListaSimples();
    ~ListaSimples();
    
    // Métodos básicos
    void inserir(Processo* processo);
    Processo* removerInicio();
    bool vazia() const;
    int getTamanho() const;
    
    // Método de acesso para iterar
    NoSimples* getInicio() const;
    
    void imprimir() const;
};

#endif