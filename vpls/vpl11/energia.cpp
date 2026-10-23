#include "energia.hpp"

Energia::Energia(int carga_inicial) : carga_(carga_inicial) {
    if (carga_ < 0) {
        carga_ = 0;
    }
}

int Energia::getCarga() const {
    return carga_;
}

void Energia::consumir(int quantidade) {
    // Apenas consome se a quantidade for positiva (protege contra exploit de negativo)
    if (quantidade > 0) {
        carga_ -= quantidade;
        if (carga_ < 0) {
            carga_ = 0;
        }
    }
}