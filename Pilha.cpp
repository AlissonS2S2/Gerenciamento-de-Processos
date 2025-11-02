#include "Pilha.h"
#include <iostream>

Pilha::Pilha() : topo(nullptr), tamanho(0) {}

Pilha::~Pilha() {
    while (!vazia()) {
        desempilhar();
    }
}

void Pilha::empilhar(Processo* processo) {
    NoSimples* novoNo = new NoSimples(processo);
    novoNo->proximo = topo;
    topo = novoNo;
    tamanho++;
}

Processo* Pilha::desempilhar() {
    if (vazia()) {
        return nullptr;
    }
    
    NoSimples* noRemovido = topo;
    Processo* processo = noRemovido->processo;
    topo = topo->proximo;
    
    // Não deletamos o processo aqui, apenas o nó
    noRemovido->processo = nullptr;
    delete noRemovido;
    tamanho--;
    
    return processo;
}

bool Pilha::vazia() const {
    return topo == nullptr;
}

int Pilha::getTamanho() const {
    return tamanho;
}

void Pilha::imprimir() const {
    NoSimples* atual = topo;
    while (atual != nullptr) {
        atual->processo->imprimirInfo();
        atual = atual->proximo;
    }
}