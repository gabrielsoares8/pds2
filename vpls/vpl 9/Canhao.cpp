#include "Canhao.hpp"

Canhao::Canhao(int id, double energia, double intensidade)
    : Defesa(id, energia), _intensidade(intensidade) {}

void Canhao::atacar(double &danoAcumulado) {   
    _consumirEnergia(10.0);
    danoAcumulado += _intensidade;
}