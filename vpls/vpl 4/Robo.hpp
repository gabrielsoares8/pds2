#ifndef ROBO_HPP
#define ROBO_HPP
#include "Ponto2D.hpp"

struct Robo {
    double _energia = 100;
    bool _com_bola;
    int _id;
    Ponto2D _posicao;

    Robo(int id, Ponto2D pos, bool ta_ou_naokkk);

    void mover(double v, double th, double t);
    double calcular_distancia(Robo* robo);
    Robo* determinar_robo_mais_proximo(Robo** naves, int n);
    void passar_bola(Robo** time, int n);
    void imprimir_status();

};

#endif