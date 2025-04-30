#include <iostream>
using namespace std;

class Complex {
private:
    double real;
    double imag;

public:
    // Constructor
    Complex(double r = 0, double i = 0) {
        real = r;
        imag = i;
    }

    // Operator Overloading for +
    Complex operator+(const Complex& other) {
        return Complex(real + other.real, imag + other.imag);
    }

    // Operator Overloading for -
    Complex operator-(const Complex& other) {
        return Complex(real - other.real, imag - other.imag);
    }

    // Operator Overloading for /
    Complex operator/(const Complex& other) {
        double denominator = other.real * other.real + other.imag * other.imag;
        double newReal = (real * other.real + imag * other.imag) / denominator;
        double newImag = (imag * other.real - real * other.imag) / denominator;
        return Complex(newReal, newImag);
    }

    // Friend function for <<
    friend ostream& operator<<(ostream& out, const Complex& c) {
        if (c.imag >= 0)
            out << c.real << " + " << c.imag << "i";
        else
            out << c.real << " - " << -c.imag << "i";
        return out;
    }
};

int main() {
    Complex c1(4, 5), c2(2, -3);

    cout << "c1 = " << c1 << endl;
    cout << "c2 = " << c2 << endl;

    cout << "Sum = " << c1 + c2 << endl;
    cout << "Difference = " << c1 - c2 << endl;
    cout << "Quotient = " << c1 / c2 << endl;

    return 0;
}
