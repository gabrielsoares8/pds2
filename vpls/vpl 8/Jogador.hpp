#ifndef JOGADOR_HPP
#define JOGADOR_HPP

#include <string>

class Jogador {
public:

    std::string nome;
    char simbolo;

    Jogador(std::string nome, char simbolo);

    std::string getNome() const;
    char getSimbolo() const;
};

#endif