//
// Created by Hugo on 08/12/2021.
//

#ifndef TP_POO1_ILHA_H
#define TP_POO1_ILHA_H

#include "utils.h"
#include "Zona.h"

class Ilha{
private:
   Zona **ilha;
   int LINHAS;
   int COLUNAS;
   int totalTrabalhadores;
public:
    Zona**getIlha() const{return ilha;}
    int getLinhas() const{return LINHAS;}
    int getColunas() const{return COLUNAS;}
    int getTotalTrabalhadores() const{return totalTrabalhadores;}
    Ilha(int l=0, int c=0);
    ~Ilha(){delete[]ilha;}
    bool procuraZona(string ed, int l, int c);
    bool procuraPasto(string traba, int d);
    int moveTrabalhador(string id, int l, int c);
    void alteraLinhasColunas(int l, int c){LINHAS=l; COLUNAS=c;}
    void cresceArvores();
    void diminuiArvores();
};





#endif //TP_POO1_ILHA_H
