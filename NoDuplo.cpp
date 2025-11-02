#include "NoDuplo.h"

NoDuplo::NoDuplo(Processo* processo) 
    : processo(processo), anterior(nullptr), proximo(nullptr) {}

NoDuplo::~NoDuplo() {
    delete processo;
}