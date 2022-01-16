//
// Created by Hugo on 19/12/2021.
//

#ifndef TP_POO1_TIPOZONA_H
#define TP_POO1_TIPOZONA_H
#include "utils.h"

class tipoZona{
    string tipo;
public:
    string getTipo () const{return tipo;}
    tipoZona(string t): tipo(t){}
    virtual int adicionaArvores()=0;
    virtual void tiraArvores()=0;
    virtual tipoZona* duplica() const=0;
};

class Deserto : public tipoZona{
public:
    Deserto() : tipoZona("dsr"){}
    int adicionaArvores()override {return 0;}
    void tiraArvores() override{}
    tipoZona* duplica() const override{return new Deserto(*this);}
};

class Pastagem : public tipoZona{
public:
    Pastagem() : tipoZona("pas"){}
    int adicionaArvores()override {return 0;}
    void tiraArvores() override{}
    tipoZona* duplica() const override{return new Pastagem(*this);}
};

class Floresta : public tipoZona{
    int arvores;
public:
    Floresta() : tipoZona("flr"){if((rand() % 100)<50) arvores=20; else arvores=40;}
    int adicionaArvores()override {if(arvores == 100) return 0; else{arvores++; return 1;}}
    void tiraArvores() override{arvores--;}
    tipoZona* duplica() const override{return new Floresta(*this);}
};

class Montanha : public tipoZona{
public:
    Montanha() : tipoZona("mnt"){}
    int adicionaArvores()override {return 0;}
    void tiraArvores() override{}
    tipoZona* duplica() const override{return new Montanha(*this);}
};
class Pantano : public tipoZona{
public:
    Pantano() : tipoZona("pnt"){}
    int adicionaArvores()override {return 0;}
    void tiraArvores() override{}
    tipoZona* duplica() const override{return new Pantano(*this);}
};

class Campo : public tipoZona{
public:
    Campo() : tipoZona("cmp"){}
    int adicionaArvores()override {return 0;}
    void tiraArvores() override{}
    tipoZona* duplica() const override{return new Campo(*this);}
};



#endif //TP_POO1_TIPOZONA_H
