#include "Pessoa.h"

Pessoa::Pessoa(const std::string& matricula, const std::string& cpf, const std::string& nome)
    : matricula(matricula), cpf(cpf), nome(nome) {}

std::string Pessoa::getMatricula() const {
    return matricula;
}

std::string Pessoa::getCPF() const {
    return cpf;
}

std::string Pessoa::getNome() const {
    return nome;
}