#ifndef GERENCIADORPROCESSOS_H
#define GERENCIADORPROCESSOS_H

#include "Pilha.h"
#include "ListaSimples.h"
#include "ListaDupla.h"
#include "Aluno.h"
#include "Professor.h"
#include <vector>
#include <memory>

class GerenciadorProcessos {
private:
    Pilha caixaProcessos;
    ListaSimples processosAlta;
    ListaDupla processosMedia;
    ListaDupla processosBaixa;
    
    std::vector<std::unique_ptr<Pessoa>> pessoas;
    
    // Parâmetros do sistema
    double pA, pM, pB;  // Probabilidades
    int naMin, naMax;   // Número de processos abertos
    int ntMin, ntMax;   // Número de processos tramitados
    
    void carregarPessoas();
    Pessoa* getPessoaAleatoria();
    Prioridade getPrioridadeAleatoria();
    std::string getAssuntoAleatorio(Prioridade prioridade, const std::string& tipoSolicitante);
    
public:
    GerenciadorProcessos(double pA = 0.1, double pM = 0.3, double pB = 0.6,
                        int naMin = 5, int naMax = 15, int ntMin = 3, int ntMax = 8);
    
    void simularDia(int dia);
    void abrirProcessos();
    void organizarProcessos();
    void tramitarProcessos();
    void imprimirProcessosPendentes() const;
};

#endif