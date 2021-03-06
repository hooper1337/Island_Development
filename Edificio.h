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
    int probabilidade;
public:
    string getTipo () const{return tipo;}
    string getEstado() const{return estado;}
    int getProdutividade() const {return produtividade;}
    int getNivel() const{return nivel;}
    int getArmazenamento() const{return armazenamento;}
    Edificio(string t, int p=0, int pro=0, string e="Desligado", int n=1, int arma=0): tipo(t), produtividade(p),probabilidade(pro), estado(e), nivel(n), armazenamento(arma){}
    virtual ~Edificio()=default;
    bool ligaEdificio();
    bool desligaEdificio();
    virtual bool aumentaNivel()=0;
    virtual void diminuiProdutividade()=0;
    virtual Edificio* duplica() const=0;
    void duplicaProdutividade(){produtividade = produtividade*2;}
    void aumentaArmazenamento();
    void diminuiArmazenamento();
    bool desabar() const;
};

class MinaFerro : public Edificio {
public:
    MinaFerro(string tipo) : Edificio(tipo, 2, 15) {}
    bool aumentaNivel() override;
    void diminuiProdutividade() override;
    Edificio *duplica() const override { return new MinaFerro(*this);}
};

class MinaCarvao : public Edificio{
public:
    MinaCarvao(string tipo) : Edificio(tipo,2,10){}
    bool aumentaNivel() override;
    void diminuiProdutividade() override;
    Edificio* duplica() const override{return new MinaCarvao(*this);}
};

class CentralEletrica : public Edificio{
public:
    CentralEletrica(string tipo) : Edificio(tipo,1,10){}
    bool aumentaNivel() override;
    void diminuiProdutividade() override{}
    Edificio* duplica() const override{return new CentralEletrica(*this);}
};

class Bateria : public Edificio{
public:
    Bateria(string tipo) : Edificio(tipo,1,10){}
    bool aumentaNivel() override;
    void diminuiProdutividade() override{}
    Edificio* duplica() const override{return new Bateria(*this);}
};

class Fundicao : public Edificio{
public:
    Fundicao(string tipo) : Edificio(tipo,1,10){}
    bool aumentaNivel() override;
    void diminuiProdutividade() override{}
    Edificio* duplica() const override{return new Fundicao(*this);}
};

class Serraria : public Edificio {
public:
    Serraria(string tipo) : Edificio(tipo,2, 10) {}
    bool aumentaNivel() override;
    void diminuiProdutividade() override{}
    Edificio *duplica() const override { return new Serraria(*this);}
    };





#endif //TP_POO1_EDIFICIO_H
