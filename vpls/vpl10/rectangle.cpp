#include "rectangle.hpp"

Rectangle::Rectangle(double w, double h){
    width = w;
    height = h;
}

std::string Rectangle::name() const{
    return "Retangulo";
}

double Rectangle::area() const{
    return width * height;
}

