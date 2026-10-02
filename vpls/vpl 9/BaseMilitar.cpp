#include "BaseMilitar.hpp"
#include <iostream>
#include <iomanip>

BaseMilitar::BaseMilitar() : _qtdAtual(0) {
    for (int i = 0; i < 100; ++i) {
        _defesas[i] = nullptr;
    }
}

BaseMilitar::~BaseMilitar() {

    for (int i = 0; i < _qtdAtual; ++i) {
        delete _defesas[i];
        _defesas[i] = nullptr;
    }
}

void BaseMilitar::adicionarDefesa(Defesa* d) {
    if (_qtdAtual < 100) {
        _defesas[_qtdAtual] = d;
        _qtdAtual++;
    }
}

void BaseMilitar::defender(double &saudeInimigo) {
    double danoTotalTurno = 0.0;

    for (int i = 0; i < _qtdAtual; ++i) {
        if (_defesas[i] != nullptr) {
            _defesas[i]->atacar(danoTotalTurno);
        }
    }

    saudeInimigo -= danoTotalTurno;
    if (saudeInimigo < 0) {
        saudeInimigo = 0;
    }

    std::cout << std::fixed << std::setprecision(2);
    std::cout << "Saude Inimigo: " << saudeInimigo << std::endl;
}