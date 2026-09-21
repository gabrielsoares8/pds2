#include "Jogador.hpp"
#include <iostream>
#include <string>


Jogador::Jogador(std::string nome, char simbolo){
    this->nome = nome;
    this->simbolo = simbolo;
}

std::string Jogador::getNome() const{
    return nome;
}

char Jogador::getSimbolo() const{
    return simbolo;
}