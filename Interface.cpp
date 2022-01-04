//
// Created by Hugo on 08/12/2021.
//
#include "Interface.h"


void comecaInterface(){
    string opcao;
    cout << R"(
██████╗ ███████╗███╗   ███╗    ██╗   ██╗██╗███╗   ██╗██████╗  ██████╗
██╔══██╗██╔════╝████╗ ████║    ██║   ██║██║████╗  ██║██╔══██╗██╔═══██╗
██████╔╝█████╗  ██╔████╔██║    ██║   ██║██║██╔██╗ ██║██║  ██║██║   ██║
██╔══██╗██╔══╝  ██║╚██╔╝██║    ╚██╗ ██╔╝██║██║╚██╗██║██║  ██║██║   ██║
██████╔╝███████╗██║ ╚═╝ ██║     ╚████╔╝ ██║██║ ╚████║██████╔╝╚██████╔╝
╚═════╝ ╚══════╝╚═╝     ╚═╝      ╚═══╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝
    )" << '\n';

    do
    {
        cout << "\n1- Novo Jogo\n";
        cout << "2- Carregar Jogo(em desenvolvimento)\n";
        cout << "3- Sair\n";

        cout << "\n>";
        cin >> opcao;
        if(opcao == "1")
            menuJogo();
        else if(opcao == "2")
            cout << "\nEm desenvolvimento!\n";
        else if(opcao == "3")
            exit(1);
        else
            cout << "\nIntroduza uma opção válida!\n";
    }while(opcao != "3");
}
void menuJogo(){
    int linhas=0;
    int colunas=0;
    string aux;
    string comando;
    string tipo;
    string ficheiro;


    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    do
    {
        cout << "\n\nIntroduza o tamanho da ilha que pretende(LxC):\n";
        cout << ">";
        getline(cin, aux);

        istringstream iss(aux);
        iss >> linhas >> colunas;

        if((linhas<3 || colunas<3) || (linhas>8 || colunas>16))
            cout << "\nErro!\nO tamanho da ilha deve ser entre 3x3 e 8x16!\n";
    }while((linhas<3 || colunas<3) || (linhas>8 || colunas>16));

    Ilha ilha(linhas,colunas);
    Jogo jogo(&ilha);
    mostraIlha(jogo);

    cout << "\nIntroduza <comandos> para ajuda!\n";
    do{
        cout << "\n>";
        getline(cin,comando);
        istringstream iss(comando);

        validaComando(jogo, iss);

    }while(comando != "sair");
}

void mostraComandos(){
    cout << R"(
██████╗ ██████╗ ███╗   ███╗ █████╗ ███╗   ██╗██████╗  ██████╗ ███████╗
██╔════╝██╔═══██╗████╗ ████║██╔══██╗████╗  ██║██╔══██╗██╔═══██╗██╔════╝
██║     ██║   ██║██╔████╔██║███████║██╔██╗ ██║██║  ██║██║   ██║███████╗
██║     ██║   ██║██║╚██╔╝██║██╔══██║██║╚██╗██║██║  ██║██║   ██║╚════██║
╚██████╗╚██████╔╝██║ ╚═╝ ██║██║  ██║██║ ╚████║██████╔╝╚██████╔╝███████║
╚═════╝ ╚═════╝ ╚═╝     ╚═╝╚═╝  ╚═╝╚═╝  ╚═══╝╚═════╝  ╚═════╝ ╚══════╝
    )" << '\n';

    cout << "exec <nomeficheiro>\n";
    cout << "cons <tipo> <linha> <coluna>\n";
    cout << "liga <linha> <coluna>\n";
    cout << "des <linha> <coluna>\n";
    cout << "levup <linha> <coluna>\n";
    cout << "move <id> <linha> <coluna>\n";
    cout << "vende <tipo> <quanto>\n";
    cout << "cont <tipo>\n";
    cout << "list <linha> <coluna>\n";
    cout << "vende <linha> <coluna>\n";
    cout << "next (em desenvolvimento)\n";
    cout << "save <nome> (em desenvolvimento)\n";
    cout << "load <nome> (em desenvolvimento)\n";
    cout << "apaga <nome> (em desenvolvimento)\n";
    cout << "config <ficheiro> (em desenvolvimento)\n";
}

void mostraIlha(Jogo &jogo){
    cout << R"(
██╗██╗     ██╗  ██╗ █████╗
██║██║     ██║  ██║██╔══██╗
██║██║     ███████║███████║
██║██║     ██╔══██║██╔══██║
██║███████╗██║  ██║██║  ██║
╚═╝╚══════╝╚═╝  ╚═╝╚═╝  ╚═╝
    )" << '\n';
    cout << "\n";
    int linhas = jogo.getIlha()->getLinhas();
    int colunas = jogo.getIlha()->getColunas();

    cout << "\nDias: " << jogo.getDias();
    cout << "\nDinheiro: " << jogo.getDinheiro();
    cout << "\nTotal de Trabalhadores: " << jogo.getTotalTrabalhadores() << endl << endl;

    for(int o=0; o<colunas;o++)
    {
        if(o == 0)
            cout  << "┌───────";
        else if(o == colunas-1)
            cout << "┬───────┐";
        else
            cout << "┬───────";

    }
    for(int i=0; i<linhas; i++)
    {
        cout << "\n│";
        for(int j=0; j<colunas; j++)
        {
            cout << jogo.getNomeZona(i,j) << "\t│";
        }
        cout << "\n" << "│";
        for(int j=0; j<colunas; j++)
        {
            if(!jogo.temEdificio(i,j))
                cout << "\t\t│";
            else
                cout << jogo.getNomeEdificio(i,j) << "\t│";
        }
        cout << "\n" << "│";
        for(int j=0; j<colunas; j++)
        {
                if(jogo.getTotalTrabalhadoresZona(i,j) < 3)
                {
                    jogo.getTrabalhadoresZona(i,j);
                    cout << "\t\t│";
                }
                else
                {
                    jogo.getTrabalhadoresZona(i,j);
                    cout << "\t│";
                }
        }
        cout << "\n" << "│";
        for(int j=0; j<colunas; j++){
            cout << jogo.getTotalTrabalhadoresZona(i,j) << "\t\t│";
        }
        cout << "\n";
        for(int o=0; o<colunas;o++)
        {
            if(i != linhas-1)
            {
            if(o == colunas-1)
                cout << "───────┤";
            else if (o == 0)
                cout  << "├───────┼";
            else
                cout  << "───────┼";
            }
            else
            {
                if(o == 0)
                    cout << "└───────┴";
                else if(o == colunas-1)
                    cout << "───────┘";
                else
                    cout << "───────┴";

            }
        }
    }
    cout <<"\n";
}

void list(Jogo &jogo, int l, int c)
{
    cout  << "*_______*\n";
    cout << "|" << jogo.getNomeZona(l,c) << "\t|\n";
    if(!jogo.temEdificio(l,c))
        cout << "|" << jogo.getNomeEdificio(l,c) << "\t\t|\n";
    else
        cout << "|" << jogo.getNomeEdificio(l,c) << "\t|\n";
    if(jogo.getTotalTrabalhadoresZona(l,c)<3)
    {
        cout << "|"; jogo.getTrabalhadoresZona(l,c);
        cout << "\t\t|\n";
    }
    else
    {
        cout << "|";
        jogo.getTrabalhadoresZona(l,c);
        cout << "\t|\n";
    }
    cout << "|" << jogo.getTotalTrabalhadoresZona(l,c) << "\t\t|\n";
    cout  << "*_______*\n";
}

bool verificaLinhaColuna(Jogo &jogo, int l, int c)
{
    int linhas = jogo.getIlha()->getLinhas();
    int colunas = jogo.getIlha()->getColunas();

    if((l >= 0 && l < linhas) && (c >= 0 && c < colunas))
        return true;
    else
        return false;
}

void validaComando(Jogo &jogo, istringstream &recebe)
{
    string tipo;
    int linha;
    int coluna;
    string ficheiro;
    string id;
    string com;
    recebe >> com;

    if(com == "cons")
    {
        recebe >> tipo >> linha >> coluna;
        if(recebe.fail()) cout << "\nComando inválido!";
        else
        {
            if(verificaLinhaColuna(jogo,linha, coluna))
            {
                if(jogo.constroiEdificio(tipo,linha,coluna) == 1)
                    cout << "\nEdificio " << tipo << " contruido na linha [" << linha << "] e na coluna [" << coluna << "]!\n";
                else if(jogo.constroiEdificio(tipo,linha,coluna)==0)
                    cout << "\nNão tem dinheiro/recursos para construir o edificio!\n";
                else if (jogo.constroiEdificio(tipo,linha,coluna)==-2)
                    cout << "\nEdificio Inválido!\n";
                else
                    cout << "\nJá tem um edificio construido!\n";
            }
            else{
                cout << "\nEssa zona não pertence à ilha!\n";
            }
        }
    }
    else if(com == "exec")
    {
        recebe >> ficheiro;
        if(leFicheiro(jogo,ficheiro))
            cout << "\nFicheiro lido com sucesso!\n";
        else
            cout << "\nErro ao abrir ficheiro!\n";
    }
    else if(com == "cont")
    {
        recebe >> tipo;
        if(recebe.fail()) cout << "\nComando inválido!\n";
        else
        {
            if(jogo.contrataTrabalhador(tipo) == 1)
                cout << "\nTrabalhador " << tipo <<  " contratado!\n";
            else if(jogo.contrataTrabalhador(tipo)== 0)
                cout << "\nNão tem dinheiro para contratar o trabalhador!\n";
            else
                cout << "\nNão existe esse tipo de trabalhador!\n";
        }
    }
    else if(com == "list")
    {
        recebe >> linha >> coluna;
        if(recebe.fail()) mostraIlha(jogo);
        else if(verificaLinhaColuna(jogo,linha, coluna))
            list(jogo,linha,coluna);
        else
            cout << "\nEssa zona não pertence à ilha!\n";
    }
    else if(com == "comandos")
        mostraComandos();
    else if(com == "liga")
    {
            recebe >> linha >> coluna;

            if(recebe.fail())
                cout << "\nNão introduziu números!\n";
            else if(verificaLinhaColuna(jogo,linha,coluna))
            {
                if(jogo.getIlha()->getIlha()[linha][coluna].getEdificio() != nullptr)
                {
                    if(jogo.getIlha()->getIlha()[linha][coluna].getEdificio()->ligaEdificio())
                    {
                        cout << "\nEdificio ligado!\n";
                    }
                    else
                        cout << "\nEsse edificio já se encontra ligado!\n";
                }
                else
                    cout << "\nNão existe nenhum edificio nessa zona!\n";
            }
            else
                cout << "\nEssa zona não pertence à ilha!\n";
    }
    else if(com == "vende")
    {
        recebe >> linha >> coluna;
        if(recebe.fail())
            cout << "\nNão introduziu números!\n";
        else if(verificaLinhaColuna(jogo, linha,coluna))
        {
            if(jogo.getIlha()->getIlha()[linha][coluna].getEdificio() != nullptr)
            {
                jogo.vendeEdificio(linha,coluna);
                cout << "\nEdificio vendido!\n";
            }
            else
            {
                cout << "\nNão existe nenhum edíficio nessa zona!\n";
            }
        }
        else
        {
            cout << "\nEssa zona não pertence á ilha!\n";
        }
    }
    else if(com == "des")
    {
        recebe >> linha >> coluna;

        if(recebe.fail())
            cout << "\nNão introduziu números!\n";
        else if(verificaLinhaColuna(jogo,linha,coluna))
        {
            if(jogo.getIlha()->getIlha()[linha][coluna].getEdificio() != nullptr)
            {
                if(jogo.getIlha()->getIlha()[linha][coluna].getEdificio()->desligaEdificio())
                    {
                        cout << "\nEdificio desligado!\n";
                    }
                else
                    cout << "\nEsse edificio já se encontra desligado!\n";
            }
            else
                cout << "\nNão existe nenhum edificio nessa zona!\n";
        }
        else
            cout << "\nEssa zona não pertence à ilha!\n";
    }
    else if(com == "levup")
    {
        recebe >> linha >> coluna;
        if(recebe.fail())
            cout << "Não introduziu números!\n";
        else if(verificaLinhaColuna(jogo,linha,coluna))
        {
            if(jogo.temEdificio(linha,coluna))
            {
                if(jogo.getIlha()->getIlha()[linha][coluna].getEdificio()->aumentaNivel())
                    cout << "\nNível aumentado!\n";
                else
                    cout << "\nEsse edificio já se encontra ao nivel máximo!\n";
            }
            else
                cout << "\nNão existe nenhum edificio nessa zona!\n";
        }
        else
            cout << "\nEssa zona não pertence à ilha!\n";

    }
    else if(com == "move")
    {
        recebe >> id >> linha >> coluna;
        if(recebe.fail())
            cout << "\nComando não introduzido corretamente!\n";
        else
        {
            if(verificaLinhaColuna(jogo,linha,coluna))
            {
                if(jogo.getIlha()->moveTrabalhador(id,linha,coluna)==1)
                    cout << "\nTrabalhador movido para a linha [" << linha << "] e coluna [" << coluna << "]!\n";
                else if(jogo.getIlha()->moveTrabalhador(id,linha,coluna)==0)
                    cout << "\nTrabalhador não encontrado!\n";
                else
                    cout << "\nEsse trabalhador já está zona!\n";
            }
            else
                cout << "\nEssa zona não pertence à ilha!\n";
        }
    }
    else if(com == "next")
    {
        jogo.anoitecer();
        jogo.incrementaDias();
        jogo.amanhecer();
    }
    else if(com == "sair")
        cout << "\nA sair do jogo atual!\n";
    else
        cout << "\nComando inválido!\n";
}

bool leFicheiro(Jogo &jogo, string ficheiro){
    ifstream readData;
    string aux;

    readData.open(ficheiro);

    if(!readData){
        return false;
    }
    while(getline(readData, aux)){
        istringstream recebe(aux);
        validaComando(jogo, recebe);
    }
    readData.close();
    return true;
}