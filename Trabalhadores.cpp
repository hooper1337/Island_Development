//
// Created by Hugo on 14/12/2021.
//

#include "Trabalhadores.h"

bool Mineiro::irEmbora() {
    if((rand() % 100)<probabilidade)
        return true;
    else
        false;
}

bool Operario::irEmbora() {
    if((rand() % 100)<probabilidade)
        return true;
    else
        return false;
}

bool Lenhador::irEmbora() {
    if(probabilidade == 0)
        return false;
    else
    {
        if((rand() % 100)<probabilidade)
            return true;
        else
            return false;
    }
}
void Trabalhador::aumentaProbabilidade() {
    probabilidade = probabilidade+5;
}
void Trabalhador::incrementaDias() {
    diasContrato++;
}

