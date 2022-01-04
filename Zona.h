//
// Created by Hugo on 10/12/2021.
//

#ifndef TP_POO1_ZONA_H
#define TP_POO1_ZONA_H
#include "Trabalhadores.h"
#include "Edificio.h"
#include "tipoZona.h"

class Zona{
private:
    tipoZona *tp;
    Edificio *e;
    vector<Trabalhador*> trabalhadores;
    int totalTrabalhadores;
    static int p, d, pa, f, m, z;
public:
    tipoZona* getTipoZona() const{return tp;}
    Edificio* getEdificio() const{return e;}
    int getTotalTrabalhadores() const{return totalTrabalhadores;}
    Zona();
    ~Zona(){for(int i=0;i<trabalhadores.size();i++) delete trabalhadores[i]; delete e;}
    bool alocaTrabalhador(string traba, string id);
    bool alocaEdificio(string ed);
    bool verificaEdificio();
    void listaTrabalhadores();
    bool encontraMineiro();
    bool encontraOperario();
    Trabalhador* encontraTrabalhador(string id);
    int contaLenhadores();
    int contaTrabalhadores();
    void removeTrabalhador(Trabalhador *t);
    bool adicionaTrabalhador(Trabalhador* t);
    void aumentaTotalTrabalhadores (){totalTrabalhadores++;}
    void diminuiTotalTrabalhadores(){totalTrabalhadores--;}
    void subtraiTotalTrabalhadores(int conta){totalTrabalhadores = totalTrabalhadores - conta;}
    void libertaEdificio();
    void limpaTrabalhadores();
};




#endif //TP_POO1_ZONA_H
