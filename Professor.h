#ifndef PROFESSOR_H
#define PROFESSOR_H

#include "Pessoa.h"
#include <string>

enum class AreaAtuacao { INFORMATICA, ADMINISTRACAO, PROPEDEUTICA, QUIMICA };

class Professor : public Pessoa {
private:
    AreaAtuacao area;

public:
    Professor(const std::string& matricula, const std::string& cpf, 
              const std::string& nome, AreaAtuacao area);
    
    AreaAtuacao getArea() const;
    std::string getAreaString() const;
    std::string getTipo() const override;
};

#endif