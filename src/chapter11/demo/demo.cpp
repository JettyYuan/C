//
// Created by jetty on 2022/10/3.
//
#include "demo.h"

complex::complex() = default;

complex::complex(double real, double imag) {
    this -> real = real;
    this -> imag = imag;
}

complex complex::operator + (const complex &c) const {
    complex temp;
    temp.real = this->real + c.real;
    temp.imag = this->imag + c.imag;
    return temp;
}

complex complex::operator - (const complex & c) const {
    complex temp;
    temp.real = this -> real - c.real;
    temp.imag = this -> imag - c.imag;
    return temp;
}

complex complex::operator * (const complex & c) const {
    complex temp;
    temp.real = this -> real * c.real;
    temp.imag = this -> imag * c.imag;
    return temp;
}

complex complex::operator * (const int & d) const {
    complex temp;
    temp.real = this->real * d;
    temp.imag = this -> imag * d;
    return temp;
}

complex operator * (const int & d, const complex & c) {
    return c * d;
}

complex complex::operator ~ () const {
    complex temp;
    temp.real = this -> real;
    temp.imag = 0 - this -> imag;
    return temp;
}

std::istream & operator >> (std::istream & is, complex & c) {
    std::cout << "real: ";
    if (is >> c.real) {
        std::cout << "imaginary: ";
        is >> c.imag;
    }
    return is;
}

std::ostream & operator << (std::ostream & os, const complex & c) {
    os << '(' << c.real << ',' << c.imag << "i)";
    return os;
}
