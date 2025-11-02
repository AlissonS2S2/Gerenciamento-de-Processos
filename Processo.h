#ifndef PROCESSO_H
#define PROCESSO_H

#include <string>
#include <chrono>

enum class Prioridade { BAIXA, MEDIA, ALTA };

class Processo {
private:
    static int nextId;
    int id;
    Prioridade prioridade;
    std::string matriculaSolicitante;
    std::string nomeSolicitante;
    std::string tipoSolicitante;
    std::chrono::system_clock::time_point dataHoraAbertura;
    std::string assunto;

public:
    Processo(Prioridade prioridade, const std::string& matriculaSolicitante,
             const std::string& nomeSolicitante, const std::string& tipoSolicitante,
             const std::string& assunto);
    
    // Getters
    int getId() const;
    Prioridade getPrioridade() const;
    std::string getPrioridadeString() const;
    std::string getMatriculaSolicitante() const;
    std::string getNomeSolicitante() const;
    std::string getTipoSolicitante() const;
    std::string getAssunto() const;
    std::string getDataHoraAbertura() const;
    std::string getHoraAbertura() const;
    std::chrono::system_clock::time_point getDataHoraAberturaTimePoint() const;
    
    // Métodos de impressão
    void imprimirInfo() const;
    void imprimirInfoCompleta() const;
};

#endif