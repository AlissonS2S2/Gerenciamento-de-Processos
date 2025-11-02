#include "Professor.h"

Professor::Professor(const std::string& matricula, const std::string& cpf, 
                     const std::string& nome, AreaAtuacao area)
    : Pessoa(matricula, cpf, nome), area(area) {}

AreaAtuacao Professor::getArea() const {
    return area;
}

std::string Professor::getAreaString() const {
    switch(area) {
        case AreaAtuacao::INFORMATICA: return "Informatica";
        case AreaAtuacao::ADMINISTRACAO: return "Administracao";
        case AreaAtuacao::PROPEDEUTICA: return "Propedeutica";
        case AreaAtuacao::QUIMICA: return "Quimica";
        default: return "Desconhecida";
    }
}

std::string Professor::getTipo() const {
    return "Professor";
}