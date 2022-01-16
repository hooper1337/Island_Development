//
// Created by Hugo on 08/12/2021.
//

#ifndef TP_POO1_INTERFACE_H
#define TP_POO1_INTERFACE_H
#include "Ilha.h"
#include "Jogo.h"
#include "utils.h"
class Interface{
public:
    static void comecaInterface();
    static void menuJogo();
    static void mostraComandos();
    static void mostraIlha(Jogo &jogo);
    static void list(Jogo &jogo, int l, int c);
    static bool verificaLinhaColuna(Jogo &jogo, int l, int c);
    static void validaComando(Jogo &jogo,SaveLoad &jogos, istringstream &recebe);
    static void mostraRecursos(Jogo &jogo);
    static bool leFicheiro(Jogo &jogo, SaveLoad &jogos, string ficheiro);
    static bool config(Jogo &jogo, string ficheiro);
};



#endif //TP_POO1_INTERFACE_H
