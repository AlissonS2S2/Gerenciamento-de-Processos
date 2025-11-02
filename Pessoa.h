#ifndef PESSOA_H
#define PESSOA_H

#include <string>

class Pessoa {
protected:
    std::string matricula;
    std::string cpf;
    std::string nome;

public:
    Pessoa(const std::string& matricula, const std::string& cpf, const std::string& nome);
    virtual ~Pessoa() = default;
    
    std::string getMatricula() const;
    std::string getCPF() const;
    std::string getNome() const;
    
    virtual std::string getTipo() const = 0;
};

#endif