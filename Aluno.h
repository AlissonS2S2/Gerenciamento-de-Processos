#ifndef ALUNO_H
#define ALUNO_H

#include "Pessoa.h"
#include <string>

class Aluno : public Pessoa {
private:
    std::string curso;

public:
    Aluno(const std::string& matricula, const std::string& cpf, 
          const std::string& nome, const std::string& curso);
    
    std::string getCurso() const;
    std::string getTipo() const override;
};

#endif