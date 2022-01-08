#include "Zona.h"

int Zona::p=0;
int Zona::pa=0;
int Zona::d=0;
int Zona::f=0;
int Zona::m=0;
int Zona::z=0;

Zona::Zona() {
    totalTrabalhadores=0;
    e = nullptr;
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distr(1,6);
    int aux;


    if(d==0){
        tp = new Deserto;
        d++;
    }else if(pa==0){
        tp = new Pastagem;
        pa++;
    }else if(f==0){
        tp = new Floresta;
        f++;
    }else if(m==0){
        tp = new Montanha;
        m++;
    }else if(p==0){
        tp = new Pantano;
        p++;
    }else if(z==0){
        tp = new Campo;
        z++;
    }
    else{
        aux = distr(gen);
        if(aux == 1)
            tp = new Deserto;
        else if(aux == 2)
            tp = new Pastagem;
        else if(aux == 3)
            tp = new Montanha;
        else if(aux == 4)
            tp = new Floresta;
        else if (aux == 5)
            tp = new Pantano;
        else if (aux == 6)
            tp = new Campo;
    }
}

bool Zona::alocaEdificio(string ed)
{
    if(ed == "minaf")
    {
        e = new MinaFerro("mnF");
        return true;
    }
    else if(ed == "minac")
    {
        e = new MinaCarvao("mnC");
        return true;
    }
    else if(ed == "central")
    {
        e = new CentralEletrica("elec");
        return true;
    }
    else if(ed == "bat")
    {
        e = new Bateria("bat");
        return true;
    }
    else if(ed == "fund")
    {
        e = new Fundicao("fun");
        return true;
    }
    else if(ed == "serr")
    {
        e = new Serraria("ser");
        return true;
    }
    return false;
}

bool Zona::alocaTrabalhador(string traba, string id)
{
    Trabalhador *t;
    if(traba == "oper")
    {
        t = new Operario("O", id,20,5);
        trabalhadores.push_back(t);
        totalTrabalhadores++;
        return true;
    }
    else if(traba == "len")
    {
        t = new Lenhador("L", id,10,0);
        trabalhadores.push_back(t);
        totalTrabalhadores++;
        return true;
    }
    else if(traba == "miner")
    {
        t = new Mineiro("M", id,15,10);
        trabalhadores.push_back(t);
        totalTrabalhadores++;
        return true;
    }
    return false;
}

void Zona::listaTrabalhadores()
{
    for(int i=0; i<trabalhadores.size(); i++)
    {
        if(i<4)
            cout << trabalhadores[i]->getTipo();
        else
            cout << "";
    }
}

bool Zona::verificaEdificio() {
    if(e != nullptr)
        return true;
    else
        return false;
}

Trabalhador* Zona::encontraTrabalhador(string id)
{
    for(int i=0; i<trabalhadores.size(); i++)
    {
        if(trabalhadores[i]->getId() == id)
            return trabalhadores[i];
    }
    return nullptr;
}
void Zona::podemMover() {
    for(int i=0; i<trabalhadores.size(); i++)
        trabalhadores[i]->podeMover();
}

void Zona::removeTrabalhador(Trabalhador *t)
{
        for(int i=0; i<trabalhadores.size(); i++)
            if(trabalhadores[i]->getId() == t->getId())
            {
                trabalhadores.erase(trabalhadores.begin()+i);
            }
}

bool Zona::adicionaTrabalhador(Trabalhador* t){
    for(int i=0; i<trabalhadores.size(); i++)
        if(trabalhadores[i]->getId() == t->getId())
            return false;
    trabalhadores.push_back(t);
    return true;
}

void Zona::libertaEdificio() {
    delete e;
    e = nullptr;
}

int Zona::contaLenhadores() {
    int conta=0;
    for(int i=0; i<trabalhadores.size(); i++)
        if(trabalhadores[i]->getTipo() == "L")
            conta++;
    return conta;
}

int Zona::contaTrabalhadores() {
    int conta=0;
    for(int i=0; i<trabalhadores.size(); i++)
            conta++;
    return conta;
}

void Zona::limpaTrabalhadores() {
    for(int i=0; i<trabalhadores.size(); i++)
        delete trabalhadores[i];
    trabalhadores.clear();
}
bool Zona::encontraMineiro() {
    for(int i=0; i<trabalhadores.size();  i++)
        if(trabalhadores[i]->getTipo() == "M")
            return true;
        else
            return false;
    return false;
}

bool Zona::encontraOperario() {
    for(int i=0; i<trabalhadores.size();  i++)
    {
        if(trabalhadores[i]->getTipo() == "O")
            return true;
        else
            return false;
    }
    return false;
}

bool Zona::despedeTrabalhador() {
    for(int i=0; i < trabalhadores.size(); i++)
    {
        if(trabalhadores[i]->irEmbora())
        {
            delete trabalhadores[i];
            trabalhadores.erase(trabalhadores.begin()+i);
            diminuiTotalTrabalhadores();
            return true;
        }
        else
            return false;
    }
    return false;
}




