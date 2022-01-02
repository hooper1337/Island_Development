//
// Created by Hugo on 16/12/2021.
//

#ifndef TP_POO1_EDIFICIO_H
#define TP_POO1_EDIFICIO_H
class Edificio{
    string tipo;
    string estado;
protected:
    int nivel;
    int produtividade;
    int armazenamento;
public:
    string getTipo () const{return tipo;}
    string getEstado() const{return estado;}
    int getProdutividade() const {return produtividade;}
    int getNivel() const{return nivel;}
    int getArmazenamento() const{return armazenamento;}
    Edificio(string t,int pro=0, string e="Desligado", int n=1, int arma=0): tipo(t),produtividade(pro), estado(e){}
    virtual ~Edificio()=default;
    bool ligaEdificio();
    bool desligaEdificio();
    virtual bool aumentaNivel()=0;
    virtual void diminuiProdutividade()=0;
    void aumentaArmazenamento();
};

class MinaFerro : public Edificio{
public:
    MinaFerro(string tipo) : Edificio(tipo,2){}
    bool aumentaNivel() override;
    void diminuiProdutividade() override;
};

class MinaCarvao : public Edificio{
public:
    MinaCarvao(string tipo) : Edificio(tipo,2){}
    bool aumentaNivel() override;
    void diminuiProdutividade() override;
};

class CentralEletrica : public Edificio{
public:
    CentralEletrica(string tipo) : Edificio(tipo){}
    bool aumentaNivel() override;
    void diminuiProdutividade() override;
};

class Bateria : public Edificio{
public:
    Bateria(string tipo) : Edificio(tipo){}
    bool aumentaNivel() override;
    void diminuiProdutividade() override;
};

class Fundicao : public Edificio{
public:
    Fundicao(string tipo) : Edificio(tipo){}
    bool aumentaNivel() override;
    void diminuiProdutividade() override;
};




#endif //TP_POO1_EDIFICIO_H
