#include "rectangle.h"

Rectangle::Rectangle(double l, double w)
    : length(l), width(w) {
}

double Rectangle::area() const {
    return length * width;
}

double Rectangle::perimeter() const {
    return 2 * (length + width);
}

std::string Rectangle::name() const {
    return "Rectangle";
}
