#ifndef PONTO2D_HPP
#define PONTO2D_HPP


struct Ponto2D {
    double x;
    double y;

    Ponto2D();
    Ponto2D(double x_in, double y_in);

    double calcular_distancia(Ponto2D* ponto);
};


#endif