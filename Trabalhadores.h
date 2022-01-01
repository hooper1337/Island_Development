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
protected:
    int probabilidade;
public:
    string getTipo() const{return tipo;}
    string getId() const {return id;}
    int getPrecoContrat() const{return precoContrat;}
    Trabalhador(string t, string i, int p,int pro, int dC=0): tipo(t), precoContrat(p),probabilidade(pro), diasContrato(dC), id(i){}
    virtual ~Trabalhador()=default;
    void incrementaDias();
    void aumentaProbabilidade();
    virtual bool irEmbora()=0;
    virtual void atribuiProbabilidade()=0;
};

class Mineiro : public Trabalhador{
public:
    Mineiro(string tipo, string id, int p, int pro=0) : Trabalhador(tipo,id,p,pro){};
    bool irEmbora() override;
    void atribuiProbabilidade() override{probabilidade = 10;}
};

class Operario : public Trabalhador{
public:
    Operario(string tipo, string id, int p, int pro=0) : Trabalhador(tipo,id,p,pro){};
    bool irEmbora() override;
    void atribuiProbabilidade() override{probabilidade = 5;}
};

class Lenhador : public Trabalhador{
public:
    Lenhador(string tipo, string id, int p, int pro=0) : Trabalhador(tipo,id,p,pro){};
    bool irEmbora() override;
    void atribuiProbabilidade() override{probabilidade = 0;}
};









#endif //TP_POO1_TRABALHADORES_H
