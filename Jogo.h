//
// Created by Hugo on 21/12/2021.
//

#ifndef TP_POO1_JOGO_H
#define TP_POO1_JOGO_H
#include "Ilha.h"
class Jogo{
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
    float getQuantidadeFerro() const{return ferro;}
    int getQuantidadeBarraDeAco() const{return barraDeAco;}
    int getQuantidadeCarvao() const{return carvao;}
    int getQuantidadeMadeira() const{return madeira;}
    int getDias() const{return dias;}
    double getDinheiro() const {return dinheiro;}
    int getQuantidadeVigasDeMadeira() const{return vigasDeMadeira;}
    int getQuantidadeEletricidade() const{return eletricidade;}
    Jogo(Ilha *aux,int di=500, int d=1, int f=100, int b=100, int c=100, int m=100, int v=100, int el=100):i(aux),dinheiro(di), dias(d),ferro(f), barraDeAco(b), carvao(c), madeira(m), vigasDeMadeira(v), eletricidade(el){}
    Jogo(const Jogo &aux, Ilha &ilha);
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


#endif //TP_POO1_JOGO_H
