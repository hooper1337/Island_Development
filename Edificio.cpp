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
        armazenamento=armazenamento+10;
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
        armazenamento=armazenamento+10;
        return true;
    }
}

bool Bateria::aumentaNivel() {
    if(nivel == 5)
        return false;
    else{
        nivel++;
        armazenamento=armazenamento+10;
        return true;
    }
}

bool  CentralEletrica::aumentaNivel() {
    return false;
}

bool Fundicao::aumentaNivel() {
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
void CentralEletrica::diminuiProdutividade() {
    produtividade=0;
}

void Bateria::diminuiProdutividade() {
    produtividade=0;
}

void Fundicao::diminuiProdutividade() {
    produtividade=0;
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