#include "circle.hpp"
#include <cmath>

Circle::Circle(double r) {
    radius = r;
}

std::string Circle::name() const{
    return "Circulo";
}

double Circle::area() const{
    const double pi = std::acos(-1.0);
    return pi * radius * radius;
}
