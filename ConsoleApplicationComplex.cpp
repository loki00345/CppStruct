#include <iostream>
#include <cmath>

struct Complex {
    double real;
    double imag;

    // Конструктор за замовчуванням
    Complex() : real(0), imag(0) {}

    // Конструктор з параметрами
    Complex(double r, double i) : real(r), imag(i) {}

    // Перевантаження оператора +
    Complex operator+(const Complex& other) const {
        return Complex(real + other.real, imag + other.imag);
    }

    // Перевантаження оператора -
    Complex operator-(const Complex& other) const {
        return Complex(real - other.real, imag - other.imag);
    }

    // Перевантаження оператора *
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real - imag * other.imag, real * other.imag + imag * other.real);
    }

    // Перевантаження оператора /
    Complex operator/(const Complex& other) const {
        double denominator = other.real * other.real + other.imag * other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,
            (imag * other.real - real * other.imag) / denominator);
    }

    // Перевантаження оператора <<
    friend std::ostream& operator<<(std::ostream& os, const Complex& c) {
        if (c.imag < 0)
            os << c.real << " - " << -c.imag << "i";
        else
            os << c.real << " + " << c.imag << "i";
        return os;
    }
};

int main() {
    Complex a(3.0, 4.0);
    Complex b(1.0, 2.0);

    Complex sum = a + b;
    Complex difference = a - b;
    Complex product = a * b;
    Complex quotient = a / b;

    std::cout << "a = " << a << std::endl;
    std::cout << "b = " << b << std::endl;
    std::cout << "a + b = " << sum << std::endl;
    std::cout << "a - b = " << difference << std::endl;
    std::cout << "a * b = " << product << std::endl;
    std::cout << "a / b = " << quotient << std::endl;

    return 0;
}
