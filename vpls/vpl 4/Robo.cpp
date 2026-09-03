#include "Robo.hpp"
#include "Ponto2D.hpp"
#include <cmath>
#include <iostream>

Robo::Robo(int id, Ponto2D pos, bool ta_ou_naokkk){
    this->_id = id;
    this->_posicao = pos;
    this->_com_bola = ta_ou_naokkk;
}

void Robo::mover(double v, double th, double t){
    double distancia = v * t;

    this->_posicao.x = this->_posicao.x + distancia * std::cos(th);
    this->_posicao.y = this->_posicao.y + distancia * std::sin(th);

    this->_energia = this->_energia - distancia;
}

double Robo::calcular_distancia(Robo* robo){
    return this->_posicao.calcular_distancia(&(robo->_posicao));
}

Robo* Robo::determinar_robo_mais_proximo(Robo** naves, int n) {
    Robo* mais_proximo = nullptr;
    double menor_distancia = -1;

    for (int i = 0; i < n; i++) {
        if (naves[i] == this) {
            continue;
        }
    double dist = this->calcular_distancia(naves[i]);

    if (menor_distancia == -1 || dist < menor_distancia) {
        menor_distancia = dist;
        mais_proximo = naves[i];
        }
    }
    return mais_proximo;
}

void Robo::passar_bola(Robo** time, int n){
    if (!this->_com_bola) {
        std::cout << "Estou sem a bola!" << std::endl;
        return; 
    }
    Robo* destino = this->determinar_robo_mais_proximo(time, n);
    if (destino != nullptr) {
        this->_com_bola = false;
        destino->_com_bola = true;
    }
}

void Robo::imprimir_status() {
    std::cout << this->_id << "\t"
              << this->_posicao.x << "\t"
              << this->_posicao.y << "\t"
              << this->_com_bola << "\t"
              << this->_energia << std::endl;
}