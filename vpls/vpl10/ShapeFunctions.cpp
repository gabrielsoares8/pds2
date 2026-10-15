#include "ShapeFunctions.hpp"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <iomanip>

void ShapeFunctions::printShapes(const std::vector<Shape*>& shapes) {
    std::for_each(shapes.begin(), shapes.end(), [](const Shape* s) {
        if (s != nullptr) {
            std::cout << *s << std::endl;
        }
    });
}

double ShapeFunctions::totalArea(const std::vector<Shape*>& shapes) {
    return std::accumulate(shapes.begin(), shapes.end(), 0.0, [](double sum, const Shape* s) {
        return sum + (s ? s->area() : 0.0);
    });
}

std::vector<Shape*> ShapeFunctions::getShapesWithAreaGreaterThan(const std::vector<Shape*>& shapes, double minArea) {
    std::vector<Shape*> result;
    std::copy_if(shapes.begin(), shapes.end(), std::back_inserter(result), [minArea](const Shape* s) {
        return s && s->area() > minArea;
    });
    return result;
}

void ShapeFunctions::sortShapesByArea(std::vector<Shape*>& shapes) {
    std::sort(shapes.begin(), shapes.end(), [](const Shape* s1, const Shape* s2) {
        if (!s1) return false;
        if (!s2) return true;
        return s1->area() < s2->area();
    });
}

std::map<std::string, int> ShapeFunctions::countShapesByName(const std::vector<Shape*>& shapes) {
    std::map<std::string, int> counts;
    for (const Shape* s : shapes) {
        if (s) {
            counts[s->name()]++;
        }
    }
    return counts;
}

std::set<double> ShapeFunctions::uniqueAreas(const std::vector<Shape*>& shapes) {
    std::set<double> areas;
    for (const Shape* s : shapes) {
        if (s) {
            areas.insert(s->area());
        }
    }
    return areas;
}

void ShapeFunctions::verificarTraversable(const std::vector<Shape*>& shapes, double area_ambiente, double tolerancia) {
    double soma_areas = totalArea(shapes);
    double area_livre = area_ambiente - soma_areas;

    std::cout << std::fixed << std::setprecision(2);
    if (area_livre > tolerancia) {
        std::cout << "Ambiente trafegavel. Area livre: " << area_livre << std::endl;
    } else {
        std::cout << "Ambiente nao trafegavel. Area livre insuficiente: " << area_livre << std::endl;
    }
}