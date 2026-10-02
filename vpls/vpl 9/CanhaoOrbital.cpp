#include "CanhaoOrbital.hpp"
#include <iostream>

CanhaoOrbital::CanhaoOrbital(int id, double energia, double intensidade, double multiplicadorGravitacional)
    : Canhao(id, energia, intensidade), _multiplicadorGravitacional(multiplicadorGravitacional) {}

void CanhaoOrbital::atacar(double &danoAcumulado) {
    double danoBase = 0.0;

    Canhao::atacar(danoBase);

    danoAcumulado += (danoBase * _multiplicadorGravitacional);

    std::cout << "Ataque Orbital realizado!" << std::endl;
}