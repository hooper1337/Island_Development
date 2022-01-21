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
    else if(tipo == "madeira")
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
    else if(tipo == "vigas")
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
    else if(tipo == "eletricidade")
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
    if(aux == "mnF")
    {
        i->getIlha()[l][c].libertaEdificio();
        dinheiro = dinheiro + i->getPrecoMNF();
    }
    else if(aux == "mnC")
    {
        i->getIlha()[l][c].libertaEdificio();
        dinheiro = dinheiro + i->getPrecoMNC();
    }
    else if(aux == "elec")
    {
        i->getIlha()[l][c].libertaEdificio();
        dinheiro = dinheiro + i->getPrecoCEN();
    }
    else if(aux == "bat")
    {
        i->getIlha()[l][c].libertaEdificio();
        dinheiro = dinheiro + i->getPrecoBAT();
    }
    else if(aux == "fun")
    {
        i->getIlha()[l][c].libertaEdificio();
        dinheiro = dinheiro + i->getPrecoFUN();
    }
    else if(aux == "ser")
    {
        i->getIlha()[l][c].libertaEdificio();
        dinheiro = dinheiro + i->getPrecoSER();
    }
}
int Jogo::constroiEdificio(string ed, int l, int c) {
    if(i->procuraZona(ed,l,c) == 1)
    {
        if (ed == "minaf")
        {
            if(i->getIlha()[l][c].getTipoZona()->getTipo() == "flr")
            {
                if(vigasDeMadeira >= 20)
                {
                    vigasDeMadeira = vigasDeMadeira - 20;
                    return 1;
                }
                else if(dinheiro >= 2*i->getPrecoMNF())
                {
                    dinheiro = dinheiro - 2*i->getPrecoMNF();
                    return 1;
                }
                else
                {
                    i->getIlha()[l][c].libertaEdificio();
                    return 0;
                }
            }
            else
            {
                if(vigasDeMadeira >= 10)
                {
                    vigasDeMadeira = vigasDeMadeira - 10;
                    return 1;
                }
                else if(dinheiro >= i->getPrecoMNF())
                {
                    dinheiro = dinheiro - i->getPrecoMNF();
                    return 1;
                }
                else
                {
                    i->getIlha()[l][c].libertaEdificio();
                    return 0;
                }
            }

        }
        if (ed == "minac")
        {
            if(i->getIlha()[l][c].getTipoZona()->getTipo() == "flr")
            {
                if(vigasDeMadeira >= 20)
                {
                    vigasDeMadeira = vigasDeMadeira - 20;
                    return 1;
                }
                else if(dinheiro >= 2*i->getPrecoMNC())
                {
                    dinheiro = dinheiro - 2*i->getPrecoMNC();
                    return 1;
                }
                else
                {
                    i->getIlha()[l][c].libertaEdificio();
                    return 0;
                }
            }
            else
            {
                if(vigasDeMadeira >= 10)
                {
                    vigasDeMadeira = vigasDeMadeira - 10;
                    return 1;
                }
                else if(dinheiro >= i->getPrecoMNC())
                {
                    dinheiro = dinheiro - i->getPrecoMNC();
                    return 1;
                }
                else
                {
                    i->getIlha()[l][c].libertaEdificio();
                    return 0;
                }
            }

        }

        else if (ed == "central")
        {
            if(i->getIlha()[l][c].getTipoZona()->getTipo() == "flr")
            {
                if(dinheiro >= 2*i->getPrecoCEN())
                {
                    dinheiro = dinheiro - 2*i->getPrecoCEN();
                    return 1;
                }
                else
                {
                    i->getIlha()[l][c].libertaEdificio();
                    return 0;
                }
            }
            else
            {
                if(dinheiro >= i->getPrecoCEN())
                {
                    dinheiro = dinheiro - i->getPrecoCEN();
                    return 1;
                }
                else
                {
                    i->getIlha()[l][c].libertaEdificio();
                    return 0;
                }
            }
        }
        else if (ed == "fund")
        {
            if(i->getIlha()[l][c].getTipoZona()->getTipo() == "flr")
            {
                if(dinheiro >= 2*i->getPrecoFUN())
                {
                    dinheiro = dinheiro - 2*i->getPrecoFUN();
                    return 1;
                }
                else
                {
                    i->getIlha()[l][c].libertaEdificio();
                    return 0;
                }
            }
            else
            {
                if(dinheiro >= i->getPrecoFUN())
                {
                    dinheiro = dinheiro - i->getPrecoFUN();
                    return 1;
                }
                else
                {
                    i->getIlha()[l][c].libertaEdificio();
                    return 0;
                }
            }
        }
        else if (ed == "bat")
        {
            if(i->getIlha()[l][c].getTipoZona()->getTipo() == "flr")
            {
                if(vigasDeMadeira >= 20 && dinheiro >= 2*i->getPrecoBAT())
                {
                    vigasDeMadeira = vigasDeMadeira - 20;
                    dinheiro = dinheiro - 2*i->getPrecoBAT();
                    return 1;
                }
                else
                {
                    i->getIlha()[l][c].libertaEdificio();
                    return 0;
                }
            }
            else
            {
                if(vigasDeMadeira >= 10 && dinheiro >= i->getPrecoBAT())
                {
                    vigasDeMadeira = vigasDeMadeira - 10;
                    dinheiro = dinheiro - i->getPrecoBAT();
                    return 1;
                }
                else
                {
                    i->getIlha()[l][c].libertaEdificio();
                    return 0;
                }
            }
        }
        else if (ed == "serr")
        {
            if(i->getIlha()[l][c].getTipoZona()->getTipo() == "flr")
            {
                if(dinheiro >= 2*i->getPrecoSER())
                {
                    dinheiro = dinheiro - 2*i->getPrecoSER();
                    return 1;
                }
                else
                {
                    i->getIlha()[l][c].libertaEdificio();
                    return 0;
                }
            }
            else
            {
                if(dinheiro >= i->getPrecoSER())
                {
                    dinheiro = dinheiro - i->getPrecoSER();
                    return 1;
                }
                else
                {
                    i->getIlha()[l][c].libertaEdificio();
                    return 0;
                }
            }
        }

    }
    else if(i->procuraZona(ed,l,c) == -6)
        return -2;
    else
        return -50;
    return 1000;
}

int Jogo::contrataTrabalhador(string t) {
    if(t == "oper" )
    {
        if(dinheiro >= i->getPrecoOPER())
        {
                if(i->procuraPasto(t,dias))
                {
                dinheiro = dinheiro - i->getPrecoOPER();
                return 1;
                }
        }
        else
            return 0;
    }
    else if(t == "miner" )
    {
        if(dinheiro >= i->getPrecoMINER())
        {
            if(i->procuraPasto(t,dias))
            {
                dinheiro = dinheiro - i->getPrecoMINER();
                return 1;
            }
        }
        else
            return 0;
    }
    else if(t == "len")
    {

        if(dinheiro >= i->getPrecoLEN())
        {
                if(i->procuraPasto(t,dias))
                {
                dinheiro = dinheiro - i->getPrecoLEN();
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

    for(int j=0; j<l; j++)
        for(int x=0; x<c; x++)
            i->getIlha()[j][x].podemMover();

    for(int j=0;j<l; j++)
        for(int x=0; x<c; x++)
            if(i->getIlha()[j][x].getTipoZona()->getTipo() == "cmp")
                if(i->getIlha()[j][x].verificaEdificio())
                    i->getIlha()[j][x].getEdificio()->duplicaProdutividade();

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
                conta = conta + lenhadores;
            }

    madeira = madeira + conta;

    // agora vou tirar as arvores das florestas caso tenham sido construidos edificios
    for(int j=0; j < l; j++)
        for(int x=0; x < c; x++)
            if(i->getIlha()[j][x].verificaEdificio())
                i->getIlha()[j][x].getTipoZona()->tiraArvores();

    // agora vamos retirar o ferro das montanhas
    for(int j=0; j < l; j++){
        for(int x=0; x < c; x++){
            if(i->getIlha()[j][x].getTipoZona()->getTipo() == "mnt")
            {
                trabalhadores = i->getIlha()[j][x].contaTrabalhadores();
                conta = conta + trabalhadores;
            }
        }
    }
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
                if(i->getIlha()[j][x].getEdificio()->getTipo() == "elec") {
                    if (x + 1 != i->getColunas()) {
                        if (i->getIlha()[j][x + 1].verificaEdificio()) {
                            if (i->getIlha()[j][x + 1].getTipoZona()->getTipo() == "flr") {
                                if (i->getIlha()[j][x + 1].getEdificio()->getTipo() == "bat") {
                                    if (i->getIlha()[j][x].getEdificio()->getEstado() == "Ligado" && i->getIlha()[j][x + 1].getEdificio()->getEstado() == "Ligado") {
                                        if (i->getIlha()[j][x].encontraOperario()) {
                                            if (i->getIlha()[j][x].getEdificio()->getNivel() == 1) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100 && i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 1) {
                                                        madeira = madeira - 1;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x + 1].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 2) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110 && i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 2) {
                                                        madeira = madeira - 2;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x + 1].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 3) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120 && i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 3) {
                                                        madeira = madeira - 3;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x + 1].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 4) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130 && i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 4) {
                                                        madeira = madeira - 4;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x + 1].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 5) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140 && i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 5) {
                                                        madeira = madeira - 5;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x + 1].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if (x - 1 != 0) {
                        if (i->getIlha()[j][x - 1].verificaEdificio()) {
                            if (i->getIlha()[j][x - 1].getTipoZona()->getTipo() == "flr") {
                                if (i->getIlha()[j][x - 1].getEdificio()->getTipo() == "bat") {
                                    if (i->getIlha()[j][x].getEdificio()->getEstado() == "Ligado" && i->getIlha()[j][x - 1].getEdificio()->getEstado() == "Ligado") {
                                        if (i->getIlha()[j][x].encontraOperario()) {
                                            if (i->getIlha()[j][x].getEdificio()->getNivel() == 1) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 1) {
                                                        madeira = madeira - 1;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x - 1].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 2) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 2) {
                                                        madeira = madeira - 2;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x - 1].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 3) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120 &&  i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 3) {
                                                        madeira = madeira - 3;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x - 1].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 4) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 4) {
                                                        madeira = madeira - 4;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x - 1].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 5) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 5) {
                                                        madeira = madeira - 5;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x - 1].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    } else if (j + 1 != i->getLinhas()) {
                        if (i->getIlha()[j + 1][x].verificaEdificio()) {
                            if (i->getIlha()[j + 1][x].getTipoZona()->getTipo() == "flr") {
                                if (i->getIlha()[j + 1][x].getEdificio()->getTipo() == "bat") {
                                    if (i->getIlha()[j][x].getEdificio()->getEstado() == "Ligado" && i->getIlha()[j + 1][x].getEdificio()->getEstado() == "Ligado") {
                                        if (i->getIlha()[j][x].encontraOperario()) {
                                            if (i->getIlha()[j][x].getEdificio()->getNivel() == 1) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100 && i->getIlha()[j + 1][x].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 1) {
                                                        madeira = madeira - 1;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j + 1][x].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 2) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110 && i->getIlha()[j + 1][x].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 2) {
                                                        madeira = madeira - 2;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j + 1][x].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 3) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120 && i->getIlha()[j + 1][x].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 3) {
                                                        madeira = madeira - 3;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j + 1][x].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 4) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130 && i->getIlha()[j + 1][x].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 4) {
                                                        madeira = madeira - 4;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j + 1][x].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 5) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140 && i->getIlha()[j + 1][x].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 5) {
                                                        madeira = madeira - 5;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j + 1][x].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                    }
                    if (j - 1 != 0) {
                        if (i->getIlha()[j - 1][x].verificaEdificio()) {
                            if (i->getIlha()[j - 1][x].getTipoZona()->getTipo() == "flr") {
                                if (i->getIlha()[j - 1][x].getEdificio()->getTipo() == "bat") {
                                    if (i->getIlha()[j][x].getEdificio()->getEstado() == "Ligado" && i->getIlha()[j - 1][x].getEdificio()->getEstado() == "Ligado") {
                                        if (i->getIlha()[j][x].encontraOperario()) {
                                            if (i->getIlha()[j][x].getEdificio()->getNivel() == 1) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100 && i->getIlha()[j - 1][x].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 1) {
                                                        madeira = madeira - 1;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j - 1][x].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 2) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110 && i->getIlha()[j - 1][x].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 2) {
                                                        madeira = madeira - 2;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j - 1][x].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 3) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120 && i->getIlha()[j - 1][x].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 3) {
                                                        madeira = madeira - 3;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j - 1][x].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 4) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130 && i->getIlha()[j - 1][x].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 4) {
                                                        madeira = madeira - 4;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j - 1][x].getEdificio()->aumentaArmazenamento();
                                                    }
                                                }
                                            } else if (i->getIlha()[j][x].getEdificio()->getNivel() == 5) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140 && i->getIlha()[j - 1][x].getEdificio()->getArmazenamento() < 100) {
                                                    if (madeira > 5) {
                                                        madeira = madeira - 5;
                                                        carvao = carvao + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                        eletricidade = eletricidade + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                        i->getIlha()[j - 1][x].getEdificio()->aumentaArmazenamento();
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
                if(i->getIlha()[j][x].getEdificio()->getTipo() == "fun")
                {
                    if(i->getIlha()[j][x].getEdificio()->getEstado() == "Ligado")
                    {
                        if(i->getIlha()[j][x].encontraOperario()) {
                            if(x+1 != i->getColunas()){
                                if (i->getIlha()[j][x + 1].verificaEdificio() && i->getIlha()[j][x - 1].verificaEdificio()) {
                                    if (i->getIlha()[j][x + 1].getEdificio()->getTipo() == "mnF" && (i->getIlha()[j][x - 1].getEdificio()->getTipo() == "mnC" || i->getIlha()[j][x - 1].getEdificio()->getTipo() == "elec")) {
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 1) {
                                            if (i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() > 1 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() > 1) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100) {
                                                    barraDeAco = barraDeAco +i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j][x + 1].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j][x + 1].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x - 1].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j][x - 1].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 2) {
                                            if (i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() > 2 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() > 2) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j][x + 1].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j][x + 1].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x - 1].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j][x - 1].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 3) {
                                            if (i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() > 3 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() > 3) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j][x + 1].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j][x + 1].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x - 1].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j][x - 1].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 4) {
                                            if (i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() > 4 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() > 4) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j][x + 1].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j][x + 1].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x - 1].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j][x - 1].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 5) {
                                            if (i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() > 5 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() > 5) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j][x + 1].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j][x + 1].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x - 1].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j][x - 1].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                    } else if ((i->getIlha()[j][x + 1].getEdificio()->getTipo() == "mnC" || i->getIlha()[j][x + 1].getEdificio()->getTipo() == "elec") && i->getIlha()[j][x - 1].getEdificio()->getTipo() == "mnF") {
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 1) {
                                            if (i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() > 1 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() > 1) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j][x - 1].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j][x - 1].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x + 1].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j][x + 1].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 2) {
                                            if (i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() > 2 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() > 2) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j][x - 1].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j][x - 1].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x + 1].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j][x + 1].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 3) {
                                            if (i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() > 3 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() > 3) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j][x - 1].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j][x - 1].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x + 1].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j][x + 1].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 4) {
                                            if (i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() > 4 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() > 4) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j][x - 1].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j][x - 1].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x + 1].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j][x + 1].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 5) {
                                            if (i->getIlha()[j][x + 1].getEdificio()->getArmazenamento() > 5 && i->getIlha()[j][x - 1].getEdificio()->getArmazenamento() > 5) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j][x - 1].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j][x - 1].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x + 1].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j][x + 1].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                    }
                                }
                            }else if(j+1 != i->getLinhas() && j-1 != 0)
                            {
                                if ((i->getIlha()[j+1][x].getEdificio()->getTipo() == "mnC" || i->getIlha()[j+1][x].getEdificio()->getTipo() == "elec") && i->getIlha()[j-1][x].getEdificio()->getTipo() == "mnF") {
                                    if (i->getIlha()[j][x].getEdificio()->getNivel() == 1) {
                                        if (i->getIlha()[j+1][x].getEdificio()->getArmazenamento() > 1 && i->getIlha()[j-1][x].getEdificio()->getArmazenamento() > 1) {
                                            if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100) {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j-1][x].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j-1][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j+1][x].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j+1][x].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                    if (i->getIlha()[j][x].getEdificio()->getNivel() == 2) {
                                        if (i->getIlha()[j+1][x].getEdificio()->getArmazenamento() > 2 && i->getIlha()[j-1][x].getEdificio()->getArmazenamento() > 2) {
                                            if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110) {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j-1][x].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j-1][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j+1][x].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j+1][x].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                    if (i->getIlha()[j][x].getEdificio()->getNivel() == 3) {
                                        if (i->getIlha()[j+1][x].getEdificio()->getArmazenamento() > 3 && i->getIlha()[j-1][x].getEdificio()->getArmazenamento() > 3) {
                                            if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120) {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j-1][x].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j-1][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j+1][x].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j+1][x].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                    if (i->getIlha()[j][x].getEdificio()->getNivel() == 4) {
                                        if (i->getIlha()[j+1][x].getEdificio()->getArmazenamento() > 4 && i->getIlha()[j-1][x].getEdificio()->getArmazenamento() > 4) {
                                            if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130) {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j-1][x].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j-1][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j+1][x].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j+1][x].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                    if (i->getIlha()[j][x].getEdificio()->getNivel() == 5) {
                                        if (i->getIlha()[j+1][x].getEdificio()->getArmazenamento() > 5 && i->getIlha()[j-1][x].getEdificio()->getArmazenamento() > 5) {
                                            if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140) {
                                                barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                i->getIlha()[j-1][x].getEdificio()->diminuiArmazenamento();
                                                ferro = ferro - i->getIlha()[j-1][x].getEdificio()->getProdutividade();
                                                i->getIlha()[j+1][x].getEdificio()->diminuiArmazenamento();
                                                carvao = carvao - i->getIlha()[j+1][x].getEdificio()->getProdutividade();
                                            }
                                        }
                                    }
                                }
                                else if((i->getIlha()[j-1][x].getEdificio()->getTipo() == "mnC" || i->getIlha()[j-1][x].getEdificio()->getTipo() == "elec") && i->getIlha()[j+1][x].getEdificio()->getTipo() == "mnF") {
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 1) {
                                            if (i->getIlha()[j-1][x].getEdificio()->getArmazenamento() > 1 && i->getIlha()[j+1][x].getEdificio()->getArmazenamento() > 1) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j+1][x].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j+1][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j-1][x].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j-1][x].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 2) {
                                            if (i->getIlha()[j-1][x].getEdificio()->getArmazenamento() > 2 && i->getIlha()[j+1][x].getEdificio()->getArmazenamento() > 2) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j+1][x].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j+1][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j-1][x].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j-1][x].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 3) {
                                            if (i->getIlha()[j-1][x].getEdificio()->getArmazenamento() > 3 && i->getIlha()[j+1][x].getEdificio()->getArmazenamento() > 3) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j+1][x].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j+1][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j-1][x].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j-1][x].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 4) {
                                            if (i->getIlha()[j-1][x].getEdificio()->getArmazenamento() > 4 && i->getIlha()[j+1][x].getEdificio()->getArmazenamento() > 4) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j+1][x].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j+1][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j-1][x].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j-1][x].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                        if (i->getIlha()[j][x].getEdificio()->getNivel() == 5) {
                                            if (i->getIlha()[j-1][x].getEdificio()->getArmazenamento() > 5 && i->getIlha()[j+1][x].getEdificio()->getArmazenamento() > 5) {
                                                if (i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140) {
                                                    barraDeAco = barraDeAco + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j][x].getEdificio()->aumentaArmazenamento();
                                                    i->getIlha()[j+1][x].getEdificio()->diminuiArmazenamento();
                                                    ferro = ferro - i->getIlha()[j+1][x].getEdificio()->getProdutividade();
                                                    i->getIlha()[j-1][x].getEdificio()->diminuiArmazenamento();
                                                    carvao = carvao - i->getIlha()[j-1][x].getEdificio()->getProdutividade();
                                                }
                                            }
                                        }
                                    }
                            }
                        }
                    }
                }
                else if(i->getIlha()[j][x].getEdificio()->getTipo() == "ser"){
                    if(i->getIlha()[j][x].encontraOperario())
                    {
                        if(i->getIlha()[j][x].getEdificio()->getEstado() == "Ligado")
                        {
                            if(i->getIlha()[j][x].getEdificio()->getNivel() == 1)
                            {
                                if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 100)
                                {
                                    if(madeira > 1)
                                    {
                                        vigasDeMadeira = vigasDeMadeira + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        madeira = madeira - 1;
                                    }
                                }
                            }
                            if(i->getIlha()[j][x].getEdificio()->getNivel() == 2)
                            {
                                if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 110)
                                {
                                    if(madeira > 1)
                                    {
                                        vigasDeMadeira = vigasDeMadeira + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        madeira = madeira - 1;
                                    }
                                }
                            }
                            if(i->getIlha()[j][x].getEdificio()->getNivel() == 3)
                            {
                                if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 120)
                                {
                                    if(madeira > 1)
                                    {
                                        vigasDeMadeira = vigasDeMadeira + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        madeira = madeira - 1;
                                    }
                                }
                            }
                            if(i->getIlha()[j][x].getEdificio()->getNivel() == 4)
                            {
                                if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 130)
                                {
                                    if(madeira > 1)
                                    {
                                        vigasDeMadeira = vigasDeMadeira + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        madeira = madeira - 1;
                                    }
                                }
                            }
                            if(i->getIlha()[j][x].getEdificio()->getNivel() == 5)
                            {
                                if(i->getIlha()[j][x].getEdificio()->getArmazenamento() < 140)
                                {
                                    if(madeira > 1)
                                    {
                                        vigasDeMadeira = vigasDeMadeira + i->getIlha()[j][x].getEdificio()->getProdutividade();
                                        madeira = madeira - 1;
                                    }
                                }
                            }
                        }
                    }
                }
            }
    if(i->getIlha()[j][x].despedeTrabalhador())
        i->decrementaTotalTrabalhadores();
}
    for(int o=0; o<l; o++)
        for(int m=0; m<c; m++)
            if(i->getIlha()[o][m].verificaEdificio())
                if(i->getIlha()[o][m].getEdificio()->desabar())
                    i->getIlha()[o][m].libertaEdificio();
}

Jogo::Jogo(const Jogo &aux)
{
    *this = aux;
}

void SaveLoad::saveJogo(Jogo* aux)
{
    jogosGuardados.push_back(aux);
}

bool SaveLoad::removeJogo(string nome)
{
    Jogo* recebe = encontraJogo(nome);
    if(recebe != nullptr)
    {
        for(int i=0; i<jogosGuardados.size(); i++)
            if(recebe->getNomeJogo() == nome)
            {
                jogosGuardados.erase(jogosGuardados.begin()+i);
                return true;
            }
    }
    return false;
}

Jogo* SaveLoad::encontraJogo(string nome)
{
    for(int i=0; i<jogosGuardados.size(); i++)
        if(jogosGuardados[i]->getNomeJogo() == nome)
        {
            return jogosGuardados[i];
        }
    return nullptr;
}



