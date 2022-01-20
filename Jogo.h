//
// Created by Hugo on 21/12/2021.
//

#ifndef TP_POO1_JOGO_H
#define TP_POO1_JOGO_H
#include "Ilha.h"
class Jogo{
    string nomeJogo;
    Ilha *i;
    int dias;
    double dinheiro;
    float ferro;
    int barraDeAco;
    int carvao;
    int madeira;
    int vigasDeMadeira;
    int eletricidade;
public:
    Ilha* getIlha() const{return i;}
    void setNomeJogo(string nome){nomeJogo = nome;}
    string getNomeJogo() const{return nomeJogo;}
    float getQuantidadeFerro() const{return ferro;}
    int getQuantidadeBarraDeAco() const{return barraDeAco;}
    int getQuantidadeCarvao() const{return carvao;}
    int getQuantidadeMadeira() const{return madeira;}
    int getDias() const{return dias;}
    double getDinheiro() const {return dinheiro;}
    int getQuantidadeVigasDeMadeira() const{return vigasDeMadeira;}
    int getQuantidadeEletricidade() const{return eletricidade;}
    Jogo(Ilha *aux,int di=400, int d=1, int f=0, int b=0, int c=0, int m=0, int v=0, int el=0):i(aux),dinheiro(di), dias(d),ferro(f), barraDeAco(b), carvao(c), madeira(m), vigasDeMadeira(v), eletricidade(el){}
    Jogo(const Jogo &aux);
    Jogo& operator=(const Jogo& aux)
    {
        nomeJogo = aux.nomeJogo;
        i = aux.i;
        dias = aux.dias;
        dinheiro = aux.dinheiro;
        ferro = aux.ferro;
        barraDeAco = aux.barraDeAco;
        carvao = aux.carvao;
        madeira = aux.madeira;
        vigasDeMadeira = aux.vigasDeMadeira;
        eletricidade = aux.eletricidade;
        return *this;
    }
    int vendeRecursos(string tipo, int quanto);
    void vendeEdificio(int l, int c);
    int constroiEdificio(string ed, int l, int c);
    int contrataTrabalhador(string t);
    string getNomeZona(int l, int c){return i->getIlha()[l][c].getTipoZona()->getTipo();}
    string getNomeEdificio(int l, int c){return i->getIlha()[l][c].getEdificio()->getTipo();}
    int getTotalTrabalhadoresZona(int l, int c){return i->getIlha()[l][c].getTotalTrabalhadores();}
    void getTrabalhadoresZona(int l, int c){i->getIlha()[l][c].listaTrabalhadores();}
    int getTotalTrabalhadores(){return i->getTotalTrabalhadores();}
    bool temEdificio(int l, int c);
    void amanhecer();
    void anoitecer();
    void incrementaDias(){dias++;}
};

class SaveLoad{
    vector<Jogo*> jogosGuardados;
public:
    void saveJogo(Jogo* aux);
    bool removeJogo(string nome);
    Jogo* encontraJogo(string nome);
};


#endif //TP_POO1_JOGO_H
