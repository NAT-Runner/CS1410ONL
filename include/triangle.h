#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "shape.h"

class Triangle : public Shape {
private:
    double a;
    double b;
    double c;

public:
    Triangle(double sideA, double sideB, double sideC);
    ~Triangle() override = default;

    double area() const override;
    double perimeter() const override;
    std::string name() const override;
};

#endif
