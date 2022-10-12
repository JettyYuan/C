// vintagePort.cpp
// Created by Jetty on 2022/10/12.
//

#include "vintagePort.h"
#include <cstring>
using std::strlen;
using std::strcpy;
using std::cout;
using std::endl;

Port::Port(const char * br, const char * st, int b) {
    brand = new char[strlen(br) + 1];
    strcpy(brand, br);
    strcpy(style, st);
    bottles = b;
}

Port::Port(const Port & p) {
    this -> brand = new char[strlen(p.brand) + 1];
    strcpy(this -> brand, p.brand);
    strcpy(this -> style, p.style);
    this -> bottles = p.bottles;
}

Port & Port::operator=(const Port & p) {
    if (this == &p) return *this;
    delete [] this -> brand;
    this -> brand = new char[strlen(p.brand) + 1];
    strcpy(this -> brand, p.brand);
    strcpy(this -> style, p.style);
    this -> bottles = p.bottles;
    return *this;
}

Port & Port::operator+=(int b) {
    bottles += b;
    return *this;
}

Port & Port::operator-=(int b) {
    if (bottles >= b) bottles -= b;
    return *this;
}

void Port::Show() const {
    cout << "Brand: " << brand << endl;
    cout << "Kind: " << style << endl;
    cout << "Bottles: " << bottles << endl;
}

ostream & operator<<(ostream & os, const Port & p) {
    os << p.brand << ", " << p.style << ", " << p.bottles;
    return os;
}

VintagePort::VintagePort(const char * br, int b, const char * nn, int y) : Port(br, "vintage", b){
    nickname = new char[strlen(nn) + 1];
    strcpy(nickname, nn);
    year = y;
}

VintagePort::VintagePort(const VintagePort & vp) : Port(vp) {
    this -> nickname = new char[strlen(vp.nickname) + 1];
    strcpy(this -> nickname, vp.nickname);
    this -> year = vp.year;
}

VintagePort & VintagePort::operator=(const VintagePort & vp) {
    if (this == &vp) return *this;
    Port::operator=(vp);
    delete [] this -> nickname;
    this -> nickname = new char[strlen(vp.nickname) + 1];
    strcpy(this -> nickname, vp.nickname);
    this -> year = vp.year;
    return *this;
}

void VintagePort::Show() const {
    Port:: Show();
    cout << "NickName: " << nickname << endl;
    cout << "Year: " << year << endl;
}

ostream & operator<<(ostream & os, const VintagePort & vp) {
    os << (const Port &) vp;
    os << ", " << vp.nickname << ", " << vp.year;
    return os;
}
