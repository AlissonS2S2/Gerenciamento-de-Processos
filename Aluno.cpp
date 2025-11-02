#include "Aluno.h"

Aluno::Aluno(const std::string& matricula, const std::string& cpf, 
             const std::string& nome, const std::string& curso)
    : Pessoa(matricula, cpf, nome), curso(curso) {}

std::string Aluno::getCurso() const {
    return curso;
}

std::string Aluno::getTipo() const {
    return "Aluno";
}