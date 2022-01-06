//
// Created by Hugo on 14/12/2021.
//

#include "Trabalhadores.h"

bool Trabalhador::irEmbora()
{
    if((rand() % 100)<probabilidade)
        return true;
    else
        return false;
}
void Trabalhador::aumentaProbabilidade() {
    probabilidade = probabilidade+5;
}
void Trabalhador::incrementaDias() {
    diasContrato++;
}

