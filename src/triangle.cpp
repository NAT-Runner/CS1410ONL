#include "triangle.h"

#include <cmath>

Triangle::Triangle(double sideA, double sideB, double sideC)
    : a(sideA), b(sideB), c(sideC) {
}

double Triangle::area() const {
    double s = (a + b + c) / 2.0;

    return std::sqrt(s * (s - a) * (s - b) * (s - c));
}

double Triangle::perimeter() const {
    return a + b + c;
}

std::string Triangle::name() const {
    return "Triangle";
}
