//
// Created by jetty on 2022/10/3.
//

#ifndef C_DEMO_H
#define C_DEMO_H
#include <iostream>

// 复数类
class complex {
private:
    // 实数
    double real = 0.0;
    // 虚数
    double imag = 0.0;
public:
    complex();
    complex(double real, double imag);
    // 重载"+, -, *, ~, >>, <<"运算符
    complex operator + (const complex & c) const;
    complex operator - (const complex & c) const;
    complex operator * (const complex & c) const;
    complex operator * (const int & d) const;
    friend complex operator * (const int & d, const complex & c);
    complex operator ~ () const;
    friend std::istream & operator >> (std::istream & is, complex & c);
    friend std::ostream & operator << (std::ostream & os, const complex & c);
};

#endif //C_DEMO_H
