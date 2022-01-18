//
// Created by Hugo on 16/12/2021.
//
#include "utils.h"
#include "Edificio.h"

bool MinaFerro::aumentaNivel() {
    if(nivel == 5)
        return false;
    else{
        nivel++;
        produtividade++;
        return true;
    }
}
void MinaFerro::diminuiProdutividade() {
    produtividade=produtividade/2;
}

void MinaCarvao::diminuiProdutividade() {
    produtividade=produtividade/2;
}

bool MinaCarvao::aumentaNivel() {
    if(nivel == 5)
        return false;
    else{
        nivel++;
        produtividade++;
        return true;
    }
}

bool Fundicao::aumentaNivel() {
    if(nivel == 5)
        return false;
    else
    {
        nivel++;
        produtividade++;
        return true;
    }
}

bool Serraria::aumentaNivel() {
    if(nivel == 5)
        return false;
    else
    {
        nivel++;
        produtividade++;
        return true;
    }
}

bool Bateria::aumentaNivel() {return false;}

bool CentralEletrica::aumentaNivel() {
    if(nivel == 5)
        return false;
    else
    {
        nivel++;
        produtividade++;
    }
    return false;
}


bool Edificio::ligaEdificio()
{
    if(estado == "Ligado")
        return false;
    else
    {
        estado = "Ligado";
        return true;
    }
}

bool Edificio::desligaEdificio()
{
    if(estado == "Desligado")
        return false;
    else
    {
        estado = "Desligado";
        return true;
    }
}

void Edificio::aumentaArmazenamento() {
    armazenamento = armazenamento + produtividade;
}

void Edificio::diminuiArmazenamento() {
    armazenamento = armazenamento - produtividade;
}


bool Edificio::desabar() const{
    if((rand() % 100)<probabilidade) {
        return true;
    }
    else
        return false;
}