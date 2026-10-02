#ifndef CANHAOORRBITAL_HPP
#define CANHAOORBITAL_HPP

#include "Canhao.hpp"

class CanhaoOrbital : public Canhao {
    private:
    double _multiplicadorGravitacional;

    public:
    CanhaoOrbital(int id, double energia, double intensidade, double multiplicadorGravitacional);
    ~CanhaoOrbital() override = default;

    void atacar(double &danoAcumulado) override;
};


#endif