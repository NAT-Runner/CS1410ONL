#ifndef SHAPE_H
#define SHAPE_H

#include <string>

/*
 * PLAN
 * ----
 * Abstract class: Shape is abstract because area(), perimeter(), and name()
 *                 are pure virtual functions.
 *
 * Derived classes: Circle stores a radius. Rectangle stores a length and
 *                  width. Triangle stores three side lengths.
 *
 * Polymorphism:    main() will use a Shape* pointer that can point to a
 *                  Circle, Rectangle, or Triangle. Calling the virtual
 *                  functions through the pointer will run the correct
 *                  derived-class function.
 *
 * File I/O:        The program will read each line from shapes.txt. The first
 *                  word determines which type of shape object is created.
 */

class Shape {
public:
    virtual ~Shape() = default;

    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual std::string name() const = 0;
};

#endif
