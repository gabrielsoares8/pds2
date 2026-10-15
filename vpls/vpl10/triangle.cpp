#include "triangle.hpp"
#include <cmath>

Triangle::Triangle(double s1, double s2, double s3) : a(s1), b(s2), c(s3) {}

std::string Triangle::name() const {
    return "Triangulo";
}

double Triangle::area() const {
    // Fórmula de Heron
    double s = (a + b + c) / 2.0;
    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}