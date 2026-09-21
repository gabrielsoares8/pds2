#include "Tabuleiro.hpp"
#include <iostream>
#include <string>

Tabuleiro::Tabuleiro(){
    for(int i = 0;i < 3; i++){
        for(int j = 0; j < 3; j++){
            tabuleiro[i][j] = ' ';
        }
    }

}

bool Tabuleiro::validaJogada(int linha, int coluna, char simbolo){
    if (linha < 0 || linha > 2 || coluna < 0 || coluna > 2) {
        return false;
    }
   if (simbolo != 'X' && simbolo != 'O') {
        return false;
    }
    if (tabuleiro[linha][coluna] != ' ') {
        return false;
    }
    return true;
}

void Tabuleiro::fazerJogada(int linha, int coluna, char simbolo) {
    tabuleiro[linha][coluna] = simbolo;
}

char Tabuleiro::verificarEstadoPartida() {
    for (int i = 0; i < 3; i++) {
        if (tabuleiro[i][0] != ' ' && 
            tabuleiro[i][0] == tabuleiro[i][1] && 
            tabuleiro[i][1] == tabuleiro[i][2]) {
            return tabuleiro[i][0]; // Retorna 'X' ou 'O'
        }
    }

    for (int j = 0; j < 3; j++) {
        if (tabuleiro[0][j] != ' ' && 
            tabuleiro[0][j] == tabuleiro[1][j] && 
            tabuleiro[1][j] == tabuleiro[2][j]) {
            return tabuleiro[0][j]; // Retorna 'X' ou 'O'
        }
    }

    if (tabuleiro[0][0] != ' ' && 
        tabuleiro[0][0] == tabuleiro[1][1] && 
        tabuleiro[1][1] == tabuleiro[2][2]) {
        return tabuleiro[0][0];
    }

    if (tabuleiro[0][2] != ' ' && 
        tabuleiro[0][2] == tabuleiro[1][1] && 
        tabuleiro[1][1] == tabuleiro[2][0]) {
        return tabuleiro[0][2];
    }

    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (tabuleiro[i][j] == ' ') {
                return 'P'; // Partida em andamento
            }
        }
    }
    return 'E';
}

void Tabuleiro::imprimir() {
    for (int i = 0; i < 3; i++) {
        std::cout << " " << tabuleiro[i][0] << " | "
                  << tabuleiro[i][1] << " | "
                  << tabuleiro[i][2] << "\n";
        if (i < 2)
            std::cout << "-----------\n";
    }
}
