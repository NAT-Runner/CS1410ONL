#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w);
    ~Rectangle() override = default;

    double area() const override;
    double perimeter() const override;
    std::string name() const override;
};

#endif
