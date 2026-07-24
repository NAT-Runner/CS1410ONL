#include <fstream>
#include <iomanip>
#include <iostream>
#include <sstream>
#include <string>

#include "circle.h"
#include "rectangle.h"
#include "shape.h"
#include "triangle.h"

using namespace std;

void printShape(ostream& output, const Shape* shape) {
    output << left << setw(12) << shape->name()
           << right << fixed << setprecision(2)
           << setw(10) << shape->area()
           << setw(10) << shape->perimeter()
           << '\n';
}

int main() {
    ifstream inputFile("shapes.txt");

    if (!inputFile) {
        cerr << "Error: Could not open shapes.txt." << endl;
        return 1;
    }

    ofstream outputFile("results.txt");

    if (!outputFile) {
        cerr << "Error: Could not open results.txt." << endl;
        return 1;
    }

    cout << "Shape          Area   Perimeter\n";
    cout << "================================\n";

    outputFile << "Shape          Area   Perimeter\n";
    outputFile << "================================\n";

    string line;

    while (getline(inputFile, line)) {
        if (line.empty()) {
            continue;
        }

        istringstream lineStream(line);

        string shapeType;
        lineStream >> shapeType;

        Shape* shape = nullptr;

        if (shapeType == "circle") {
            double radius;
            lineStream >> radius;

            shape = new Circle(radius);
        }
        else if (shapeType == "rectangle") {
            double length;
            double width;

            lineStream >> length >> width;

            shape = new Rectangle(length, width);
        }
        else if (shapeType == "triangle") {
            double a;
            double b;
            double c;

            lineStream >> a >> b >> c;

            shape = new Triangle(a, b, c);
        }
        else {
            cerr << "Unknown shape type: " << shapeType << endl;
        }

        if (shape != nullptr) {
            printShape(cout, shape);
            printShape(outputFile, shape);

            delete shape;
            shape = nullptr;
        }
    }

    inputFile.close();
    outputFile.close();

    return 0;
}
