#ifndef DEFESA_HPP
#define DEFESA_HPP

class Defesa {
private:
    int _id;
    double _energia;

protected:
    void _consumirEnergia(double qtd);

public:
    Defesa(int id, double energia);
    virtual ~Defesa();

    virtual void atacar(double &danoAcumulado) = 0;

};

#endif