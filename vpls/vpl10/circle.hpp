#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

class Circle : public Shape {

private:
    double radius;
    
public:
    Circle(double r);

    std::string name() const override;
    double area() const override;


};

#endif