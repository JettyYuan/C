// vintagePort.h
// Created by Jetty on 2022/10/12.
//

#ifndef C_VINTAGE_PORT_H
#define C_VINTAGE_PORT_H
#include <iostream>
using namespace std;

class Port {
private:
    char * brand = nullptr;
    char style[20] = "";
    int bottles = 0;
public:
    explicit Port(const char * br = "none", const char * st = "none", int b = 0);
    Port(const Port & p);
    virtual ~Port() {delete [] brand;}
    Port & operator=(const Port & p);
    Port & operator+=(int b);
    Port & operator-=(int b);
    int BottleCount() const {return bottles;}
    virtual void Show() const;
    friend ostream & operator<<(ostream & os, const Port & p);
};

class VintagePort : public Port {
private:
    char * nickname = nullptr;
    int year = 0;
public:
    VintagePort() = default;
    VintagePort(const char * br, int b, const char * nn, int y);
    VintagePort(const VintagePort & vp);
    ~VintagePort() override {delete [] nickname;}
    VintagePort & operator=(const VintagePort & vp);
    void Show() const override;
    friend ostream & operator<<(ostream & os, const VintagePort & vp);
};

#endif //C_VINTAGE_PORT_H
