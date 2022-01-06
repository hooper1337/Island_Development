//
// Created by Hugo on 21/12/2021.
//

#include "Jogo.h"

int Jogo::vendeRecursos(string tipo, int quanto) {
    if(tipo == "ferro")
    {
        if(quanto > ferro)
            return 0;
        else
        {
            ferro = ferro - quanto;
            dinheiro = dinheiro + quanto;
            return 1;
        }
    }
    else if(tipo == "aco")
    {
        if(quanto > barraDeAco)
            return 0;
        else
        {
            barraDeAco = barraDeAco - quanto;
            dinheiro = dinheiro + (2*quanto);
            return 1;
        }
    }
    else if(tipo == "carvao")
    {
        if(quanto > carvao)
            return 0;
        else
        {
            carvao = carvao - quanto;
            dinheiro = dinheiro + quanto;
            return 1;
        }
    }
    else if(tipo == "mad")
    {
        if(quanto > madeira)
            return 0;
        else
        {
            madeira = madeira - quanto;
            dinheiro = dinheiro + quanto;
            return 1;
        }
    }
    else if(tipo == "viga")
    {
        if (quanto > vigasDeMadeira)
            return 0;
        else
        {
            vigasDeMadeira = vigasDeMadeira - quanto;
            dinheiro = dinheiro + (2*quanto);
            return 1;
        }
    }
    else if(tipo == "eletr")
    {
        if (quanto > eletricidade)
            return 0;
        else
        {
            eletricidade = eletricidade - quanto;
            dinheiro = dinheiro + (1.5*quanto);
            return 1;
        }
    }
    else
    {
        return -1;
    }
}

void Jogo::vendeEdificio(int l, int c) {
    string aux = i->getIlha()[l][c].getEdificio()->getTipo();
    if(aux == "mnF" || aux == "mnC")
    {
        i->getIlha()[l][c].libertaEdificio();
        dinheiro = dinheiro + 100;
    }
    else if(aux == "elec")
    {
        i->getIlha()[l][c].libertaEdificio();
        dinheiro = dinheiro + 15;
    }
    else if(aux == "bat" || aux == "fun")
    {
        i->getIlha()[l][c].libertaEdificio();
        dinheiro = dinheiro + 10;
    }
}

int Jogo::constroiEdificio(string ed, int l, int c) {
        if(ed == "minaf" || ed == "minac")
        {
                if(vigasDeMadeira >= 10)
                {
                    if(i->procuraZona(ed,l,c))
                    {
                        vigasDeMadeira = vigasDeMadeira - 10;
                        return 1;
                    }
                    else
                        return -1;
                }
                else if(vigasDeMadeira >= 20 && i->getIlha()[l][c].getTipoZona()->getTipo() == "flr")
                {
                    if(i->procuraZona(ed,l,c))
                    {
                        vigasDeMadeira = vigasDeMadeira - 20;
                        return 1;
                    }
                    else
                        return -1;
                }
                else if(dinheiro >= 200 && i->getIlha()[l][c].getTipoZona()->getTipo() == "flr")
                {
                    if(i->procuraZona(ed,l,c))
                    {
                        dinheiro = dinheiro - 200;
                        return 1;
                    }
                    else
                        return -1;
                }
                else if(dinheiro >= 100 && i->getIlha()[l][c].getTipoZona()->getTipo() != "flr")
                {
                    if(i->procuraZona(ed,l,c))
                    {
                        dinheiro = dinheiro - 100;
                        return 1;
                    }
                    else
                        return -1;
                }
                else
                    return 0;
        }
        else if(ed == "central")
        {
            if(dinheiro >= 15 && i->getIlha()[l][c].getTipoZona()->getTipo() != "flr")
            {
                if(i->procuraZona(ed,l,c))
                {
                    dinheiro = dinheiro - 15;
                    return 1;
                }
                else
                    return -1;
            }
            else if(dinheiro >= 30 && i->getIlha()[l][c].getTipoZona()->getTipo() == "flr")
            {
                if(i->procuraZona(ed,l,c))
                {
                    dinheiro = dinheiro - 30;
                    return 1;
                }
                else
                    return -1;
            }
            else
                return 0;
        }
        else if(ed == "bat")
        {
            if(vigasDeMadeira >= 10 && dinheiro >= 10 && i->getIlha()[l][c].getTipoZona()->getTipo() != "flr")
            {
                if(i->procuraZona(ed,l,c))
                {
                    dinheiro = dinheiro - 10;
                    vigasDeMadeira = vigasDeMadeira - 10;
                    return 1;
                }
                else
                    return -1;
            }
            else if(vigasDeMadeira >= 20 && dinheiro >= 20 && i->getIlha()[l][c].getTipoZona()->getTipo() == "flr")
            {
                if(i->procuraZona(ed,l,c))
                {
                    dinheiro = dinheiro - 20;
                    vigasDeMadeira = vigasDeMadeira - 20;
                    return 1;
                }
                else
                    return -1;
            }
            else
                return 0;
        }
        else if(ed == "fund")
        {
            if(dinheiro >= 10 && i->getIlha()[l][c].getTipoZona()->getTipo() != "flr")
               {
                   if(i->procuraZona(ed,l,c))
                   {
                        dinheiro = dinheiro - 10;
                        return 1;
                   }
                   else
                       return -1;
               }
            else if(dinheiro >= 20 && i->getIlha()[l][c].getTipoZona()->getTipo() == "flr")
            {
                if(i->procuraZona(ed,l,c))
                {
                    dinheiro = dinheiro - 20;
                    return 1;
                }
                else
                    return -1;
            }
            else
                return 0;
        }
        else
            return -2;
}

int Jogo::contrataTrabalhador(string t) {
    if(t == "oper" || t == "miner")
    {
        if(dinheiro >= 15)
        {
                if(i->procuraPasto(t,dias))
                {
                dinheiro = dinheiro - 15;
                return 1;
                }
        }
        else
            return 0;
    }
    else if(t == "len")
    {

        if(dinheiro >= 20)
        {
                if(i->procuraPasto(t,dias))
                {
                dinheiro = dinheiro - 20;
                return 1;
                }
        }
        else
            return 0;
    }
    else
        return -1;
    return -50;
}

bool Jogo::temEdificio(int l, int c)
{
    if(i->getIlha()[l][c].verificaEdificio())
        return true;
    else
        false;
    return false;
}

void Jogo::amanhecer()
{
    int l = i->getLinhas();
    int c = i->getColunas();
    int lenhadores;
    int trabalhadores;
    int conta=0;

    // vejo se passaram dois dias e caso tenham passado adiciono arvores na floresta
    if(dias % 2 == 0)
        for(int j=0; j < l; j++)
            for(int x=0; x < c; x++)
                if(!i->getIlha()[j][x].verificaEdificio())
                    i->getIlha()[j][x].getTipoZona()->adicionaArvores();

    // fico com madeira tanto quantos os lenhadores totais existirem
    for(int j=0; j < l; j++)
        for(int x=0; x < c; x++)
            if(i->getIlha()[j][x].getTipoZona()->getTipo() == "flr")
            {
                lenhadores = i->getIlha()[j][x].contaLenhadores();
                for(int k=0; k<lenhadores; k++)
                    i->getIlha()[j][x].getTipoZona()->tiraArvores();
            }
            conta = conta + lenhadores;

    madeira = madeira + conta;

    // agora vou tirar as arvores das florestas caso tenham sido construidos edificios
    for(int j=0; j < l; j++)
        for(int x=0; x < c; x++)
            if(i->getIlha()[j][x].verificaEdificio())
                i->getIlha()[j][x].getTipoZona()->tiraArvores();

    // agora vamos retirar o ferro das montanhas
    for(int j=0; j < l; j++)
        for(int x=0; x < c; x++)
            if(i->getIlha()[j][x].getTipoZona()->getTipo() == "mnt")
                trabalhadores = i->getIlha()[j][x].contaTrabalhadores();
            conta = conta + trabalhadores;

    ferro = ferro + (conta*0.1);

        for(int j=0; j < l; j++)
            for(int x=0; x < c; x++)
                if(i->getIlha()[j][x].getTipoZona()->getTipo() == "pnt")
                {
                    if(dias % 10 == 0)
                    {
                        if(i->getIlha()[j][x].verificaEdificio())
                             i->getIlha()[j][x].libertaEdificio();
                        conta = i->getIlha()[j][x].contaTrabalhadores();
                        i->getIlha()[j][x].subtraiTotalTrabalhadores(conta);
                        i->retiraTotalTrabalhadores(conta);
                        i->getIlha()[j][x].limpaTrabalhadores();
                    }
                }
}

void Jogo::anoitecer()
{
    int l = i->getLinhas();
    int c = i->getColunas();

    for(int j=0; j < l; j++)
        for(int x=0; x < c; x++)
        {
            if(i->getIlha()[j][x].verificaEdificio())
            {
                if(i->getIlha()[j][x].getEdificio()->getTipo() == "mnF" || i->getIlha()[j][x].getEdificio()->getTipo() == "mnC")
                {
                    if(i->getIlha()[j][x].getEdificio()->getEstado() == "Ligado")
                    {
                        if(i->getIlha()[j][x].encontraMineiro())
                        {
                            if(i->getIlha()[j][x].getEdificio()->getNivel() == 1)
                            {
                                if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100)
                                {
                                    if(i->getIlha()[j][x].getEdificio()->getTipo() == "mnF")
                                    {
                                    ferro = ferro + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                    }
                                    if(i->getIlha()[j][x].getEdificio()->getTipo() == "mnC")
                                    {
                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                    }
                                }
                            }
                            else if(i->getIlha()[j][x].getEdificio()->getNivel() == 2)
                            {
                                if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110)
                                {
                                    if(i->getIlha()[j][x].getEdificio()->getTipo() == "mnF")
                                    {
                                        ferro = ferro + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                    }
                                    if(i->getIlha()[j][x].getEdificio()->getTipo() == "mnC")
                                    {
                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                    }
                                }
                            }
                            else if(i->getIlha()[j][x].getEdificio()->getNivel() == 3)
                            {
                                if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120)
                                {
                                    if(i->getIlha()[j][x].getEdificio()->getTipo() == "mnF")
                                    {
                                        ferro = ferro + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                    }
                                    if(i->getIlha()[j][x].getEdificio()->getTipo() == "mnC")
                                    {
                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                    }
                                }
                            }
                            else if(i->getIlha()[j][x].getEdificio()->getNivel() == 4)
                            {
                                if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130)
                                {
                                    if(i->getIlha()[j][x].getEdificio()->getTipo() == "mnF")
                                    {
                                        ferro = ferro + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                    }
                                    if(i->getIlha()[j][x].getEdificio()->getTipo() == "mnC")
                                    {
                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                    }
                                }
                            }
                            else if(i->getIlha()[j][x].getEdificio()->getNivel() == 5)
                            {
                                if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140)
                                {
                                    if(i->getIlha()[j][x].getEdificio()->getTipo() == "mnF")
                                    {
                                        ferro = ferro + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                    }
                                    if(i->getIlha()[j][x].getEdificio()->getTipo() == "mnC")
                                    {
                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                    }
                                }
                            }
                        }
                    }
                }
                if(i->getIlha()[j][x].getEdificio()->getTipo() == "elec")
                {
                    if(i->getIlha()[j][x+1].verificaEdificio())
                    {
                        if(i->getIlha()[j][x+1].getTipoZona()->getTipo() == "flr")
                        {
                            if(i->getIlha()[j][x+1].getEdificio()->getTipo() == "bat")
                            {
                                if(i->getIlha()[j][x].getEdificio()->getEstado() == "Ligado" && i->getIlha()[j][x+1].getEdificio()->getEstado() == "Ligado")
                                {
                                    if(i->getIlha()[j][x].encontraOperario())
                                    {
                                        if(i->getIlha()[j][x].getEdificio()->getNivel() == 1)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100 && i->getIlha()[j][x+1].getEdificio()->getArmazenamento() < 100)
                                            {
                                                if(madeira > 1)
                                                {
                                                    madeira = madeira - 1;
                                                    carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x+1].getEdificio()->aumentaArmazenamento();
                                                }
                                            }
                                        }
                                        else if(i->getIlha()[j][x].getEdificio()->getNivel() == 2)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110 && i->getIlha()[j][x+1].getEdificio()->getArmazenamento() < 100)
                                            {
                                                if(madeira > 2)
                                                {
                                                    madeira = madeira - 2;
                                                    carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x+1].getEdificio()->aumentaArmazenamento();
                                                }
                                            }
                                        }
                                        else if(i->getIlha()[j][x].getEdificio()->getNivel() == 3)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120 && i->getIlha()[j][x+1].getEdificio()->getArmazenamento() < 100)
                                            {
                                                if(madeira > 3)
                                                {
                                                    madeira = madeira - 3;
                                                    carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x+1].getEdificio()->aumentaArmazenamento();
                                                }
                                            }
                                        }
                                        else if(i->getIlha()[j][x].getEdificio()->getNivel() == 4)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130 && i->getIlha()[j][x+1].getEdificio()->getArmazenamento() < 100)
                                            {
                                                if(madeira > 4)
                                                {
                                                    madeira = madeira - 4;
                                                    carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x+1].getEdificio()->aumentaArmazenamento();
                                                }
                                            }
                                        }
                                        else if(i->getIlha()[j][x].getEdificio()->getNivel() == 5)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140 && i->getIlha()[j][x+1].getEdificio()->getArmazenamento() < 100)
                                            {
                                                if(madeira > 5)
                                                {
                                                    madeira = madeira - 5;
                                                    carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x+1].getEdificio()->aumentaArmazenamento();
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    else if(i->getIlha()[j][x-1].verificaEdificio())
                    {
                        if(i->getIlha()[j][x-1].getTipoZona()->getTipo() == "flr")
                        {
                            if(i->getIlha()[j][x-1].getEdificio()->getTipo() == "bat")
                            {
                                if(i->getIlha()[j][x].getEdificio()->getEstado() == "Ligado" && i->getIlha()[j][x-1].getEdificio()->getEstado() == "Ligado")
                                {
                                    if(i->getIlha()[j][x].encontraOperario())
                                    {
                                        if(i->getIlha()[j][x].getEdificio()->getNivel() == 1)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() < 100)
                                            {
                                                if(madeira > 1)
                                                {
                                                    madeira = madeira - 1;
                                                    carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x-1].getEdificio()->aumentaArmazenamento();
                                                }
                                            }
                                        }
                                        else if(i->getIlha()[j][x].getEdificio()->getNivel() == 2)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() < 100)
                                            {
                                                if(madeira > 2)
                                                {
                                                    madeira = madeira - 2;
                                                    carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x-1].getEdificio()->aumentaArmazenamento();
                                                }
                                            }
                                        }
                                        else if(i->getIlha()[j][x].getEdificio()->getNivel() == 3)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() < 100)
                                            {
                                                if(madeira > 3)
                                                {
                                                    madeira = madeira - 3;
                                                    carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x-1].getEdificio()->aumentaArmazenamento();
                                                }
                                            }
                                        }
                                        else if(i->getIlha()[j][x].getEdificio()->getNivel() == 4)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() < 100)
                                            {
                                                if(madeira > 4)
                                                {
                                                    madeira = madeira - 4;
                                                    carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x-1].getEdificio()->aumentaArmazenamento();
                                                }
                                            }
                                        }
                                        else if(i->getIlha()[j][x].getEdificio()->getNivel() == 5)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() < 100)
                                            {
                                                if(madeira > 5)
                                                {
                                                    madeira = madeira - 5;
                                                    carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x-1].getEdificio()->aumentaArmazenamento();
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if(i->getIlha()[j][x].getEdificio()->getTipo() == "fun")
                {
                    if(i->getIlha()[j][x].getEdificio()->getEstado() == "Ligado")
                    {
                        if(i->getIlha()[j][x].encontraOperario())
                        {
                            if(i->getIlha()[j][x+1].verificaEdificio() && i->getIlha()[j][x-1].verificaEdificio())
                            {
                                if(i->getIlha()[j][x+1].getEdificio()->getTipo() == "mnF" && i->getIlha()[j][x-1].getEdificio()->getTipo() == "mnC")
                                {
                                    if(i->getIlha()[j][x].getEdificio()->getNivel() == 1)
                                    {
                                        if(i->getIlha()[j][x+1].getEdificio()->getArmazenamento() > 1 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() > 1)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100)
                                            {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j][x+1].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j][x+1].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x-1].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j][x-1].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                    if(i->getIlha()[j][x].getEdificio()->getNivel() == 2)
                                    {
                                        if(i->getIlha()[j][x+1].getEdificio()->getArmazenamento() > 2 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() > 2)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110)
                                            {
                                            barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                            i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                            i->getIlha()[j][x+1].getEdificio()->diminuiArmazenamento();
                                            ferro = ferro - i->getIlha()[j][x+1].getEdificio()->getProdutividade();
                                            i->getIlha()[j][x-1].getEdificio()->diminuiArmazenamento();
                                            carvao = carvao - i->getIlha()[j][x-1].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                    if(i->getIlha()[j][x].getEdificio()->getNivel() == 3)
                                    {
                                        if(i->getIlha()[j][x+1].getEdificio()->getArmazenamento() > 3 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() > 3)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120)
                                            {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j][x+1].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j][x+1].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x-1].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j][x-1].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                    if(i->getIlha()[j][x].getEdificio()->getNivel() == 4)
                                    {
                                        if(i->getIlha()[j][x+1].getEdificio()->getArmazenamento() > 4 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() > 4)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130)
                                            {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j][x+1].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j][x+1].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x-1].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j][x-1].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                    if(i->getIlha()[j][x].getEdificio()->getNivel() == 5)
                                    {
                                        if(i->getIlha()[j][x+1].getEdificio()->getArmazenamento() > 5 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() > 5)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140)
                                            {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j][x+1].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j][x+1].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x-1].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j][x-1].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
                if(i->getIlha()[j][x].getEdificio()->getTipo() == "fun")
                {
                    if(i->getIlha()[j][x].getEdificio()->getEstado() == "Ligado")
                    {
                        if(i->getIlha()[j][x].encontraOperario())
                        {
                            if(i->getIlha()[j][x+1].verificaEdificio() && i->getIlha()[j][x-1].verificaEdificio())
                            {
                                if(i->getIlha()[j][x+1].getEdificio()->getTipo() == "mnC" && i->getIlha()[j][x-1].getEdificio()->getTipo() == "mnF")
                                {
                                    if(i->getIlha()[j][x].getEdificio()->getNivel() == 1)
                                    {
                                        if(i->getIlha()[j][x+1].getEdificio()->getArmazenamento() > 1 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() > 1)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100)
                                            {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j][x-1].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j][x-1].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x+1].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j][x+1].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                    if(i->getIlha()[j][x].getEdificio()->getNivel() == 2)
                                    {
                                        if(i->getIlha()[j][x+1].getEdificio()->getArmazenamento() > 2 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() > 2)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110)
                                            {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j][x-1].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j][x-1].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x+1].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j][x+1].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                    if(i->getIlha()[j][x].getEdificio()->getNivel() == 3)
                                    {
                                        if(i->getIlha()[j][x+1].getEdificio()->getArmazenamento() > 3 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() > 3)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120)
                                            {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j][x-1].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j][x-1].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x+1].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j][x+1].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                    if(i->getIlha()[j][x].getEdificio()->getNivel() == 4)
                                    {
                                        if(i->getIlha()[j][x+1].getEdificio()->getArmazenamento() > 4 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() > 4)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130)
                                            {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j][x-1].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j][x-1].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x+1].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j][x+1].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                    if(i->getIlha()[j][x].getEdificio()->getNivel() == 5)
                                    {
                                        if(i->getIlha()[j][x+1].getEdificio()->getArmazenamento() > 5 && i->getIlha()[j][x-1].getEdificio()->getArmazenamento() > 5)
                                        {
                                            if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140)
                                            {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j][x-1].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j][x-1].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x+1].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j][x+1].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
}