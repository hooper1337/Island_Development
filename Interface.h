//
// Created by Hugo on 08/12/2021.
//

#ifndef TP_POO1_INTERFACE_H
#define TP_POO1_INTERFACE_H
#include "Ilha.h"
#include "Jogo.h"

void comecaInterface();
void menuJogo();
void mostraComandos();
void mostraIlha(Jogo &jogo);
void list(Jogo &jogo, int l, int c);
bool verificaLinhaColuna(Jogo &jogo, int l, int c);
void validaComando(Jogo &jogo,SaveLoad &jogos, istringstream &recebe);
void mostraRecursos(Jogo &jogo);
bool leFicheiro(Jogo &jogo, SaveLoad &jogos, string ficheiro);


#endif //TP_POO1_INTERFACE_H
