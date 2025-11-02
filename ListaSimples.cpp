#include "ListaSimples.h"
#include <iostream>

ListaSimples::ListaSimples() : inicio(nullptr), fim(nullptr), tamanho(0) {}

ListaSimples::~ListaSimples() {
    while (!vazia()) {
        removerInicio();
    }
}

void ListaSimples::inserir(Processo* processo) {
    NoSimples* novoNo = new NoSimples(processo);
    
    if (vazia()) {
        inicio = fim = novoNo;
    } else {
        fim->proximo = novoNo;
        fim = novoNo;
    }
    tamanho++;
}

Processo* ListaSimples::removerInicio() {
    if (vazia()) {
        return nullptr;
    }
    
    NoSimples* noRemovido = inicio;
    Processo* processo = noRemovido->processo;
    inicio = inicio->proximo;
    
    if (inicio == nullptr) {
        fim = nullptr;
    }
    
    noRemovido->processo = nullptr;
    delete noRemovido;
    tamanho--;
    
    return processo;
}

bool ListaSimples::vazia() const {
    return inicio == nullptr;
}

int ListaSimples::getTamanho() const {
    return tamanho;
}

NoSimples* ListaSimples::getInicio() const {
    return inicio;
}

void ListaSimples::imprimir() const {
    NoSimples* atual = inicio;
    while (atual != nullptr) {
        atual->processo->imprimirInfo();
        atual = atual->proximo;
    }
}