#include "Processo.h"
#include <iomanip>
#include <sstream>
#include <iostream>

int Processo::nextId = 1;

Processo::Processo(Prioridade prioridade, const std::string& matriculaSolicitante,
                   const std::string& nomeSolicitante, const std::string& tipoSolicitante,
                   const std::string& assunto)
    : id(nextId++), prioridade(prioridade), matriculaSolicitante(matriculaSolicitante),
      nomeSolicitante(nomeSolicitante), tipoSolicitante(tipoSolicitante), assunto(assunto) {
    dataHoraAbertura = std::chrono::system_clock::now();
}

int Processo::getId() const {
    return id;
}

Prioridade Processo::getPrioridade() const {
    return prioridade;
}

std::string Processo::getPrioridadeString() const {
    switch(prioridade) {
        case Prioridade::ALTA: return "ALTA";
        case Prioridade::MEDIA: return "MEDIA";
        case Prioridade::BAIXA: return "BAIXA";
        default: return "DESCONHECIDA";
    }
}

std::string Processo::getMatriculaSolicitante() const {
    return matriculaSolicitante;
}

std::string Processo::getNomeSolicitante() const {
    return nomeSolicitante;
}

std::string Processo::getTipoSolicitante() const {
    return tipoSolicitante;
}

std::string Processo::getAssunto() const {
    return assunto;
}

std::string Processo::getDataHoraAbertura() const {
    auto time_t = std::chrono::system_clock::to_time_t(dataHoraAbertura);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%d/%m/%Y %H:%M:%S");
    return ss.str();
}

std::string Processo::getHoraAbertura() const {
    auto time_t = std::chrono::system_clock::to_time_t(dataHoraAbertura);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&time_t), "%H:%M:%S");
    return ss.str();
}

std::chrono::system_clock::time_point Processo::getDataHoraAberturaTimePoint() const {
    return dataHoraAbertura;
}

void Processo::imprimirInfo() const {
    std::cout << "PROC #" << id << " [" << getHoraAbertura() << "] " 
              << getPrioridadeString() << " - " << nomeSolicitante 
              << " (" << tipoSolicitante << ") - " << assunto << std::endl;
}

void Processo::imprimirInfoCompleta() const {
    std::cout << "==================================================" << std::endl;
    std::cout << "PROCESSO #" << id << std::endl;
    std::cout << "==================================================" << std::endl;
    std::cout << "PRIORIDADE: " << getPrioridadeString() << std::endl;
    std::cout << "SOLICITANTE: " << nomeSolicitante << " (" << tipoSolicitante << ")" << std::endl;
    std::cout << "MATRICULA: " << matriculaSolicitante << std::endl;
    std::cout << "ABERTURA: " << getDataHoraAbertura() << std::endl;
    std::cout << "ASSUNTO: " << assunto << std::endl;
    std::cout << "==================================================" << std::endl;
}