#include "GerenciadorProcessos.h"
#include <iostream>

int main() {
    std::cout << "==================================================" << std::endl;
    std::cout << "      SISTEMA DE GERENCIAMENTO DE PROCESSOS" << std::endl;
    std::cout << "           IFRN - CAMPUS NOVA CRUZ" << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << std::endl;
    
    // Parametros: pA, pM, pB, naMin, naMax, ntMin, ntMax
    GerenciadorProcessos gerenciador(0.1, 0.3, 0.6, 5, 12, 3, 8);
    
    // Simular 3 dias de trabalho
    for (int dia = 1; dia <= 3; dia++) {
        gerenciador.simularDia(dia);
    }
    
    std::cout << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << "            SIMULACAO CONCLUIDA" << std::endl;
    std::cout << "==================================================" << std::endl;
    
    return 0;
}