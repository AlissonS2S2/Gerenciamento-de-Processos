#include "ListaDupla.h"
#include <iostream>

ListaDupla::ListaDupla() : inicio(nullptr), fim(nullptr), tamanho(0) {}

ListaDupla::~ListaDupla() {
    while (!vazia()) {
        removerInicio();
    }
}

void ListaDupla::inserir(Processo* processo) {
    NoDuplo* novoNo = new NoDuplo(processo);
    
    if (vazia()) {
        inicio = fim = novoNo;
    } else {
        fim->proximo = novoNo;
        novoNo->anterior = fim;
        fim = novoNo;
    }
    tamanho++;
}

Processo* ListaDupla::removerInicio() {
    if (vazia()) {
        return nullptr;
    }
    
    NoDuplo* noRemovido = inicio;
    Processo* processo = noRemovido->processo;
    inicio = inicio->proximo;
    
    if (inicio != nullptr) {
        inicio->anterior = nullptr;
    } else {
        fim = nullptr;
    }
    
    noRemovido->processo = nullptr;
    delete noRemovido;
    tamanho--;
    
    return processo;
}

bool ListaDupla::vazia() const {
    return inicio == nullptr;
}

int ListaDupla::getTamanho() const {
    return tamanho;
}

NoDuplo* ListaDupla::getInicio() const {
    return inicio;
}

void ListaDupla::imprimir() const {
    NoDuplo* atual = inicio;
    while (atual != nullptr) {
        atual->processo->imprimirInfo();
        atual = atual->proximo;
    }
}