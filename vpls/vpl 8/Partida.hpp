#ifndef PARTIDA_HPP
#define PARTIDA_HPP

#include "Tabuleiro.hpp"
#include "Jogador.hpp"

class Partida {
public:
    Tabuleiro tabuleiro;
    Jogador jogador1;
    Jogador jogador2;
    Jogador* atual;

    Partida(Jogador jogador1, Jogador jogador2);
    Jogador& getJogadorAtual();
    void executarJogada(int linha, int coluna);
    char statusPartida();
    void exibirPartida();
};

#endif 