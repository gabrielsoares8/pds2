#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "shape.hpp"
#include <string>

class Triangle : public Shape {
private:
    double a;
    double b;
    double c;

public:
    Triangle(double s1, double s2, double s3);

    std::string name() const override;
    double area() const override;
};

#endif