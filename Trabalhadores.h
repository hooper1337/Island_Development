//
// Created by Hugo on 14/12/2021.
//

#ifndef TP_POO1_TRABALHADORES_H
#define TP_POO1_TRABALHADORES_H
#include "utils.h"

class Trabalhador{
    string tipo;
    string id;
    int precoContrat;
    int diasContrato;
    int controla;
    int ativo;
protected:
    int probabilidade;
public:
    string getTipo() const{return tipo;}
    string getId() const {return id;}
    int getPrecoContrat() const{return precoContrat;}
    int getDiasContrato() const{return  diasContrato;}
    int getContraolaI() const{return controla;}
    Trabalhador(string t, string i, int p,int pro,int c=0, int dC=0): tipo(t), precoContrat(p),probabilidade(pro),controla(c), diasContrato(dC), id(i){}
    virtual ~Trabalhador()=default;
    void incrementaDias();
    void aumentaProbabilidade();
    bool irEmbora();
};

class Mineiro : public Trabalhador{
public:
    Mineiro(string tipo, string id, int p, int pro) : Trabalhador(tipo,id,p,pro){};
};

class Operario : public Trabalhador{
public:
    Operario(string tipo, string id, int p, int pro) : Trabalhador(tipo,id,p,pro){};
};

class Lenhador : public Trabalhador{
public:
    Lenhador(string tipo, string id, int p, int pro) : Trabalhador(tipo,id,p,pro){};
};









#endif //TP_POO1_TRABALHADORES_H
