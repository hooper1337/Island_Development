//
// Created by Hugo on 08/12/2021.
//
#include "Ilha.h"

Ilha::Ilha(int l, int c)
{
    totalTrabalhadores=0;
    LINHAS= l;
    COLUNAS= c;
    ilha = new Zona*[LINHAS];
    for(int i=0; i<LINHAS; i++)
        ilha[i] = new Zona[COLUNAS];
}

void Ilha::cresceArvores()
{
        for(int i=0; i<LINHAS; i++)
            for(int j=0; j<COLUNAS; j++)
            {
                if(ilha[i][j].getTipoZona()->getTipo() == "flr")
                {
                    ilha[i][j].getTipoZona()->adicionaArvores();
                }

            }
}

void Ilha::diminuiArvores() {
    for(int i=0; i<LINHAS; i++)
        for(int j=0; j<COLUNAS; j++)
        {
            if(ilha[i][j].getTipoZona()->getTipo() == "flr")
                ilha[i][j].getTipoZona()->tiraArvores();
        }
}

bool Ilha::procuraZona(string ed, int l, int c)
{
    if(ilha[l][c].getEdificio() == nullptr)
    {
        if(ilha[l][c].alocaEdificio(ed))
        {
            if(ilha[l][c].getTipoZona()->getTipo() == "dsr")
            {
                if(ed == "minaf" || ed == "minac")
                {
                    ilha[l][c].getEdificio()->diminuiProdutividade();
                    return true;
                }
                else
                    return true;
            }
            else
                return true;
        }
    }
    else
        return false;
    return -50;
}

bool Ilha::procuraPasto(string traba, int d)
{
    int conta=0;
    int inteiro;
    int aux=0;
    string auxiliar;
    totalTrabalhadores++;
    auxiliar = to_string(totalTrabalhadores) + "." + to_string(d);
    for(int i=0; i<LINHAS; i++)
        for(int j=0; j<COLUNAS; j++)
        {
            if(ilha[i][j].getTipoZona()->getTipo() == "pas")
                conta++;
        }
    if(conta == 0)
        return false;
    inteiro = rand()%conta+1;
    for(int i=0; i<LINHAS; i++)
        for(int j=0; j<COLUNAS; j++)
            if(ilha[i][j].getTipoZona()->getTipo() == "pas")
            {
                aux++;
                if(aux==inteiro)
                {
                    ilha[i][j].alocaTrabalhador(traba,auxiliar);
                        return true;
                }
            }
    return false;
}


int Ilha::moveTrabalhador(string id, int l, int c) {
    Trabalhador *t;
    for(int i=0; i<LINHAS; i++)
        for(int j=0; j<COLUNAS; j++)
        {
            t = ilha[i][j].encontraTrabalhador(id);
            if(t != nullptr)
            {
                t->atribuiProbabilidade();
                if(ilha[l][c].getTipoZona()->getTipo() == "mnt")
                    t->aumentaProbabilidade();
                if(ilha[l][c].adicionaTrabalhador(t)){
                ilha[l][c].aumentaTotalTrabalhadores();
                ilha[i][j].removeTrabalhador(t);
                ilha[i][j].diminuiTotalTrabalhadores();
                return 1;
                }
                else
                    return -1;
            }
        }
    return 0;
}




