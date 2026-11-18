// Experiment 5
// Demonstrate runtime polymorphism using virtual functions and an
// abstract base class. Shape hierarchy: Circle, Rectangle, Triangle.

#include <iostream>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;  // Pure virtual function
    virtual ~Shape() = default;
};

class Circle : public Shape {
public:
    double radius = 5.0;

    double area() const override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
public:
    double width = 4.0;
    double height = 6.0;

    double area() const override {
        return width * height;
    }
};

class Triangle : public Shape {
public:
    double base = 4.0;
    double height = 5.0;

    double area() const override {
        return 0.5 * base * height;
    }
};

int main() {
    Circle c;
    Rectangle r;
    Triangle t;

    // Base-class pointers demonstrate runtime polymorphism.
    Shape* s1 = &c;
    Shape* s2 = &r;
    Shape* s3 = &t;

    cout << "Circle Area: " << s1->area() << endl;
    cout << "Rectangle Area: " << s2->area() << endl;
    cout << "Triangle Area: " << s3->area() << endl;

    return 0;
}
