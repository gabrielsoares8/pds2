#include "Ponto2D.hpp"
#include <cmath>
#include <iostream>

Ponto2D::Ponto2D() {
    this->x = 0;
    this->y = 0;
}

Ponto2D::Ponto2D(double x_in, double y_in){
    this-> x = x_in;
    this-> y = y_in;
}

double Ponto2D::calcular_distancia(Ponto2D* ponto){
    double distancia_x = this->x - ponto->x;
    double distancia_y = this->y - ponto->y;

    return std::sqrt(pow(distancia_x, 2)+ pow(distancia_y, 2));

}



