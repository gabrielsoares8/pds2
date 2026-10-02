#include "LancadorMissil.hpp"

LancadorMissil::LancadorMissil(int id, double energia, int misseis)
    : Defesa(id, energia), _misseis(misseis) {}

void LancadorMissil::atacar(double &danoAcumulado) {
    if (_misseis > 0) {
        _misseis--;
        
        _consumirEnergia(5.0);
        danoAcumulado += 40.0;
    }
}