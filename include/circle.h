#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r);
    ~Circle() override = default;

    double area() const override;
    double perimeter() const override;
    std::string name() const override;
};

#endif
