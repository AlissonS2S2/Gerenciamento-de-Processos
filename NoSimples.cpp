#include "NoSimples.h"

NoSimples::NoSimples(Processo* processo) 
    : processo(processo), proximo(nullptr) {}

NoSimples::~NoSimples() {
    delete processo;
}