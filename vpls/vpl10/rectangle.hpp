#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

class Rectangle : public Shape{
    private:
      double width;
      double height;

    public:
      Rectangle(double w, double h);
      std::string name() const override;
      double area() const override;

};



#endif