//
// Created by Hugo on 08/12/2021.
//
#include "Ilha.h"

Ilha::Ilha(int l, int c)
{
    totalTrabalhadores=0;
    precoBAT = 10;
    precoMNF = 100;
    precoMNC = 100;
    precoCEN = 15;
    precoFUN = 10;
    precoSER = 20;
    precoOPER = 15;
    precoLEN = 20;
    precoMINER = 10;
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

int Ilha::procuraZona(string ed, int l, int c)
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
                    return 1;
                }
                else
                    return 1;
            }
            else
                return 1;
        }
        else
            return -6;
    }
    else
        return -4;
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
                if(t->getContraolaI() == 0)
                {
                    t->naoPodeMover();
                    if(ilha[l][c].getTipoZona()->getTipo() == "mnt")
                        t->aumentaProbabilidade();
                    if(ilha[l][c].adicionaTrabalhador(t))
                    {
                        ilha[l][c].aumentaTotalTrabalhadores();
                        ilha[i][j].removeTrabalhador(t);
                        ilha[i][j].diminuiTotalTrabalhadores();
                        return 1;
                    }
                    else
                        return -1;
                }
                else
                    return -2;

            }
        }
    return 0;
}


Ilha::Ilha(const Ilha &aux)
{
    LINHAS = aux.LINHAS;
    COLUNAS = aux.COLUNAS;
    for(int i=0; i<LINHAS; i++)
        for(int j=0; j<COLUNAS; j++)
        {
            ilha[i][j].operator=(aux.ilha[i][j]);
        }

    totalTrabalhadores = aux.totalTrabalhadores;
}

void Ilha::setPreco(istringstream &recebe)
{
    string ed;
    int preco;
    recebe >> ed;

    if(ed == "minaf")
    {
        recebe >> preco;
        precoMNF = preco;
    }
    else if(ed == "minac")
    {
        recebe >> preco;
        precoMNC = preco;
    }
    else if(ed == "fund")
    {
        recebe >> preco;
        precoFUN = preco;
    }
    else if(ed == "bat")
    {
        recebe >> preco;
        precoBAT = preco;
    }
    else if(ed == "serr")
    {
        recebe >> preco;
        precoSER = preco;
    }
    else if(ed == "central")
    {
        recebe >> preco;
        precoCEN = preco;
    }
}

void Ilha::setPrecoTraba(istringstream &recebe)
{
    string traba;
    int preco;
    recebe >> traba;

    if(traba == "miner")
    {
        recebe >> preco;
        precoMINER = preco;
    }
    else if(traba == "oper")
    {
        recebe >> preco;
        precoOPER = preco;
    }
    else if(traba == "len")
    {
        recebe >> preco;
        precoLEN = preco;
    }

}
