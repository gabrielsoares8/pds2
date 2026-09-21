#include "Partida.hpp"
#include <iostream>

Partida::Partida(Jogador jogador1, Jogador jogador2) 
    : jogador1(jogador1), jogador2(jogador2) {
    this->atual = &this->jogador1;
}

Jogador& Partida::getJogadorAtual() {
    return *this->atual;
}

void Partida::executarJogada(int linha, int coluna) {
    char simboloAtual = this->atual->getSimbolo();

    if (this->tabuleiro.validaJogada(linha, coluna, simboloAtual)) {
        this->tabuleiro.fazerJogada(linha, coluna, simboloAtual);
        
        if (this->atual == &this->jogador1) {
            this->atual = &this->jogador2;
        } else {
            this->atual = &this->jogador1;
        }
    } else {
        std::cout << "Jogada invalida!\n";
    }
}

char Partida::statusPartida() {
    return this->tabuleiro.verificarEstadoPartida();
}

void Partida::exibirPartida() {
    this->tabuleiro.imprimir();
}