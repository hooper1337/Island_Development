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
   int precoMNF;
   int precoMNC;
   int precoCEN;
   int precoBAT;
   int precoFUN;
   int precoSER;
   int precoOPER;
   int precoLEN;
   int precoMINER;
public:
    Zona**getIlha() const{return ilha;}
    int getPrecoOPER() const{return precoOPER;}
    int getPrecoLEN() const{return precoLEN;}
    int getPrecoMINER() const{return precoMINER;}
    int getLinhas() const{return LINHAS;}
    int getColunas() const{return COLUNAS;}
    int getTotalTrabalhadores() const{return totalTrabalhadores;}
    int getPrecoMNF() const{return precoMNF;}
    int getPrecoMNC() const{return precoMNC;}
    int getPrecoCEN() const{return precoCEN;}
    int getPrecoBAT() const{return precoBAT;}
    int getPrecoFUN() const{return precoFUN;}
    int getPrecoSER() const{return precoSER;}
    void setPreco(istringstream &recebe);
    void setPrecoTraba(istringstream &recebe);
    Ilha(int l=0, int c=0);
    Ilha(const Ilha& aux);
    ~Ilha(){delete[]ilha;}
    int procuraZona(string ed, int l, int c);
    bool procuraPasto(string traba, int d);
    int moveTrabalhador(string id, int l, int c);
    void retiraTotalTrabalhadores(int conta){totalTrabalhadores = totalTrabalhadores - conta;}
    void decrementaTotalTrabalhadores(){totalTrabalhadores--;}
    void cresceArvores();
    void diminuiArvores();
};





#endif //TP_POO1_ILHA_H
