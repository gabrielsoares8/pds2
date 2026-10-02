#ifndef BASE_MILITAR_HPP
#define BASE_MILITAR_HPP

#include "Defesa.hpp"

class BaseMilitar {
private:
    Defesa* _defesas[100]; 
    int _qtdAtual;      

public:
    BaseMilitar();
    ~BaseMilitar();

    void adicionarDefesa(Defesa* d);
    void defender(double &saudeInimigo); 
};

#endif