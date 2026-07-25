// A2: Shape Collection
// Kandall Emile 

/* PLAN
Data design:
Use a enum class named ShapeKind with three values: Circle, Square, and Rectangle. 
Use a Shape struct with three values: kind, length, and width. 
Squares, length and width will both store the side length.
Rectangles, length and width will store separate measurements.
 
Functions:
area(Shape s) will return the area of a circle, square, or rectangle.
perimeter(Shape s) will return the perimeter/circumference of the shape.
nameOf(Shape s) will return the shape name as a string.
promptAndFill(Shape& s) will ask the user for measurements and fill in the Shape.
displayAll(Shape shapes[], int count) will print all shapes in a formatted table.
displaySummary(Shape shapes[], int count) will print total shapes, combined area,
average perimeter, and the shape with the largest area.
 
Menu logic:
Program will use a do-while loop to keep showing the menu until the user chooses option 4 to quit.
Menu options:
    1. Add a shape
    2. View all shapes
    3. View summary
    4. Quit

Error handling:
If the collection already has 10 shapes, the program will not add another shape and will print Collection Full.
If the user tries to view or summarize shape before adding any, the program will print No shapes. 
If the user enters an invalid menu choice, the program will print "Invalid choice." and show the menu again.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>

using namespace std;

enum class ShapeKind { Circle, Square, Rectangle };

struct Shape { 
ShapeKind kind;
double length;
double width;
};

// Function prototypes
double area(Shape s);
double perimeter(Shape s);
string nameOf(Shape s);
void promptAndFill(Shape& s);
void displayAll(Shape shapes[], int count);
void displaySummary(Shape shapes[], int count);

int main() { 
Shape shapes[10];
int count = 0;
int choice = 0;

do {
cout << "\nSHAPE COLLECTION\n";
cout << "1. Add a shape\n";
cout << "2. View all shapes\n";
cout << "3. View summary\n";
cout << "4. Quit\n";
cout << "\nEnter your choice: ";
cin >> choice;

if (choice == 1) {
if (count == 10) {
cout << "Collection Full.\n";
}
else {
int kindChoice;

cout << "\nPick a shape?\n";
cout << "1. Circle\n";
cout << "2. Square\n";
cout << "3. Rectangle\n";
cout << "Enter your choice: ";
cin >> kindChoice;

Shape temp;

if (kindChoice == 1) {
temp.kind = ShapeKind::Circle;
promptAndFill(temp);
shapes[count] = temp;
count++;
}
else if (kindChoice == 2) {
temp.kind = ShapeKind::Square;
promptAndFill(temp);
shapes[count] = temp;
count++;
}
else if (kindChoice == 3) {
temp.kind = ShapeKind::Rectangle;
promptAndFill(temp);
shapes[count] = temp;
count++;
}
else {
cout << "Invalid shape choice.\n";
}
}
}
else if (choice == 2) {
if (count == 0) {
cout << "No shapes yet.\n";
}
else {
displayAll(shapes, count);
}
}
else if (choice == 3) {
if (count == 0) {
cout << "No shapes yet.\n";
}
else {
displaySummary(shapes, count);
}
}
else if (choice == 4) {
cout << "Goodbye.\n";
}
else {
cout << "Invalid choice.\n";
}

} while (choice != 4);

return 0;
}

double area(Shape s) {
if (s.kind == ShapeKind::Circle) {
return M_PI * pow(s.length / 2, 2);
}
else if (s.kind == ShapeKind::Square) {
return s.length * s.length;
}
else {
return s.length * s.width;
}
}

double perimeter(Shape s) {
if (s.kind == ShapeKind::Circle) {
return M_PI * s.length;
}
else if (s.kind == ShapeKind::Square) {
return 4 * s.length;
}
else {
return 2 * (s.length + s.width);
}
}

string nameOf(Shape s) {
if (s.kind == ShapeKind::Circle) {
return "Circle";
}
else if (s.kind == ShapeKind::Square) {
return "Square";
}
else {
return "Rectangle";
}
}

void promptAndFill(Shape& s) {
if (s.kind == ShapeKind::Circle) {
cout << "Enter diameter: ";
cin >> s.length;
s.width = s.length;
}
else if (s.kind == ShapeKind::Square) {
cout << "Enter side length: ";
cin >> s.length;
s.width = s.length;
}
else if (s.kind == ShapeKind::Rectangle) {
cout << "Enter length: ";
cin >> s.length;

cout << "Enter width: ";
cin >> s.width;

if (s.length == s.width) {
s.kind = ShapeKind::Square;
}
}
}

void displayAll(Shape shapes[], int count) {
cout << fixed << setprecision(2);

cout << left
<< setw(15) << "Shape"
<< setw(12) << "Length"
<< setw(12) << "Width"
<< setw(12) << "Area"
<< setw(12) << "Perimeter"
<< endl;

cout << string(63, '-') << endl;

for (int i = 0; i < count; i++) {
cout << left
<< setw(15) << nameOf(shapes[i])
<< setw(12) << shapes[i].length
<< setw(12) << shapes[i].width
<< setw(12) << area(shapes[i])
<< setw(12) << perimeter(shapes[i])
<< endl;
}
}

void displaySummary(Shape shapes[], int count) {
double totalArea = 0;
double totalPerimeter = 0;

int largestIndex = 0;

for (int i = 0; i < count; i++) {
totalArea += area(shapes[i]);
totalPerimeter += perimeter(shapes[i]);

if (area(shapes[i]) > area(shapes[largestIndex])) {
largestIndex = i;
}
}

double averagePerimeter = totalPerimeter / count;

cout << fixed << setprecision(2);

cout << "\nSUMMARY\n";
cout << "Total number of shapes: " << count << endl;
cout << "Combined area: " << totalArea << endl;
cout << "Average perimeter: " << averagePerimeter << endl;
cout << "Largest shape: " << nameOf(shapes[largestIndex]) << endl;
cout << "Largest area: " << area(shapes[largestIndex]) << endl;
}