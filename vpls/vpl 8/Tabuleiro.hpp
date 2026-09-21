#ifndef TABULEIRO_HPP
#define TABULEIRO_HPP
#include "Jogador.hpp"
#include <string>
#include <iostream>

class Tabuleiro {
public:
       
    char tabuleiro[3][3];

    Tabuleiro();
    bool validaJogada(int linha, int coluna, char simbolo);
    void fazerJogada(int linha, int coluna, char simbolo);
    char verificarEstadoPartida();
    void imprimir();
};

#endif