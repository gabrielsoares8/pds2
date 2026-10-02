#ifndef LANCADOR_MISSIL_HPP
#define LANCADOR_MISSIL_HPP

#include "Defesa.hpp"

class LancadorMissil : public Defesa {
private:
    int _misseis;

public:
    LancadorMissil(int id, double energia, int misseis);
    ~LancadorMissil() override = default;

    void atacar(double &danoAcumulado) override;
};

#endif