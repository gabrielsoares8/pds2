#include <iostream>
#include "BaseMilitar.hpp"
#include "Canhao.hpp"
#include "CanhaoOrbital.hpp"
#include "LancadorMissil.hpp"

int main() {
    BaseMilitar base;
    char comando;

    while (std::cin >> comando) {
        if (comando == 'c') {
            int id;
            double energia, intensidade;
            std::cin >> id >> energia >> intensidade;
            
            Canhao* c = new Canhao(id, energia, intensidade);
            base.adicionarDefesa(c);
        }
        else if (comando == 'o') {
            int id;
            double energia, intensidade, gravidade;
            std::cin >> id >> energia >> intensidade >> gravidade;
            
            CanhaoOrbital* co = new CanhaoOrbital(id, energia, intensidade, gravidade);
            base.adicionarDefesa(co);
        }
        else if (comando == 'm') {
            int id, misseis;
            double energia;
            std::cin >> id >> energia >> misseis;
            
            LancadorMissil* lm = new LancadorMissil(id, energia, misseis);
            base.adicionarDefesa(lm);
        }
        else if (comando == 'd') {
            double vidaInimigo;
            std::cin >> vidaInimigo;
            
            base.defender(vidaInimigo);
        }
        else if (comando == 's') {
            break;
        }
    }

    return 0;
}