#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include "shape.hpp"
#include "circle.hpp"
#include "rectangle.hpp"
#include "triangle.hpp"
#include "ShapeFunctions.hpp"

int main() {
    std::vector<Shape*> shapes;
    std::string cmd;

    while (std::cin >> cmd) {
        if (cmd == "CIRCLE") {
            double r;
            std::cin >> r;
            shapes.push_back(new Circle(r));
        } else if (cmd == "RECT") {
            double w, h;
            std::cin >> w >> h;
            shapes.push_back(new Rectangle(w, h));
        } else if (cmd == "TRIANGLE") {
            double a, b, c;
            std::cin >> a >> b >> c;
            shapes.push_back(new Triangle(a, b, c));
        } else if (cmd == "LIST") {
            ShapeFunctions::printShapes(shapes);
        } else if (cmd == "TOTAL") {
            std::cout << std::fixed << std::setprecision(2);
            std::cout << "Total: " << ShapeFunctions::totalArea(shapes) << std::endl;
        } else if (cmd == "SORT") {
            ShapeFunctions::sortShapesByArea(shapes);
            ShapeFunctions::printShapes(shapes);
        } else if (cmd == "FILTER") {
            double min_area;
            std::cin >> min_area;
            std::vector<Shape*> filtered = ShapeFunctions::getShapesWithAreaGreaterThan(shapes, min_area);
            ShapeFunctions::printShapes(filtered);
        } else if (cmd == "COUNT") {
            std::map<std::string, int> counts = ShapeFunctions::countShapesByName(shapes);
            for (const auto& pair : counts) {
                std::cout << pair.first << ": " << pair.second << std::endl;
            }
        } else if (cmd == "UNIQUE") {
            std::set<double> areas = ShapeFunctions::uniqueAreas(shapes);
            std::cout << std::fixed << std::setprecision(2);
            for (double area : areas) {
                std::cout << area << " ";
            }
            std::cout << std::endl;
        } else if (cmd == "CLEAR") {
            for (Shape* s : shapes) {
                delete s;
            }
            shapes.clear();
        } else if (cmd == "TRAVERSABLE") {
            double area_ambiente, tolerancia;
            std::cin >> area_ambiente >> tolerancia;
            ShapeFunctions::verificarTraversable(shapes, area_ambiente, tolerancia);
        }
    }

    for (Shape* s : shapes) {
        delete s;
    }

    return 0;
}