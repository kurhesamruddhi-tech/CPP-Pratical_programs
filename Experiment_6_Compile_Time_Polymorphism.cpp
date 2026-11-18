// Experiment 6
// Implement compile-time polymorphism using function overloading
// and operator overloading for a Complex number class.

#include <iostream>
using namespace std;

class Complex {
public:
    double real;
    double imag;

    // Function overloading: set only the real part.
    void setValue(double r) {
        real = r;
        imag = 0.0;
    }

    // Function overloading: set both real and imaginary parts.
    void setValue(double r, double i) {
        real = r;
        imag = i;
    }

    // Operator overloading for addition of two complex numbers.
    Complex operator+(const Complex& obj) const {
        Complex temp;
        temp.real = real + obj.real;
        temp.imag = imag + obj.imag;
        return temp;
    }

    void display() const {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1, c2, c3;

    c1.setValue(3.0, 5.0);
    c2.setValue(2.0, 4.5);

    c3 = c1 + c2;

    cout << "Complex Number 1: ";
    c1.display();

    cout << "Complex Number 2: ";
    c2.display();

    cout << "Sum (C1 + C2): ";
    c3.display();

    return 0;
}
