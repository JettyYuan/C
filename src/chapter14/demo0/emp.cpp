// emp.cpp
// Created by Jetty on 2022/10/16.
//

#include "emp.h"
#include <iostream>
using std::cout;
using std::endl;

__attribute__((unused)) abString_emp::abString_emp(const string & fn, const string & ln, const string & j) {
    fName = fn;
    lName = ln;
    job = j;
}

void abString_emp::Data() const {
    cout << "firstname: " << fName << endl;
    cout << "lastname: " << lName << endl;
    cout << "job: " << job << endl;
}

void abString_emp::ShowAll() const {
    Data();
}

void abString_emp::SetAll() {
    fName = nullptr;
    lName = nullptr;
    job = nullptr;
}

std::ostream & operator<<(std::ostream & os, const abString_emp & e) {
    os << e.fName << ", " << e.lName << ", " << e.job << endl;
    return os;
}

employee::employee(const string & fn, const string & ln, const string & j) : abString_emp(fn, ln, j) {}

void employee::ShowAll() const {
    abString_emp:: ShowAll();
}

void employee::SetAll() {
    abString_emp::SetAll();
}

manager::manager(const string & fn, const string & ln, const string & j, int ico) : abString_emp(fn, ln, j) {
    inChargeOf = ico;
}

__attribute__((unused)) manager::manager(const abString_emp & e, int ico) : abString_emp(e) {
    inChargeOf = ico;
}

manager::manager(const manager & m)  : abString_emp(m) {
    this -> inChargeOf = m.inChargeOf;
}

void manager::Data() const {
    cout << "inChargeOf: " << inChargeOf << endl;
}

void manager::ShowAll() const {
    abString_emp::Data();
    Data();
}

void manager::SetAll() {
    abString_emp::SetAll();
    inChargeOf = 0;
}

fink::fink(const string & fn, const string & ln, const string & j, const string & rpo) : abString_emp(fn, ln, j) {
    reportStr = rpo;
}

__attribute__((unused)) fink::fink(const abString_emp & e, const string & rpo) : abString_emp(e) {
    reportStr = rpo;
}

fink::fink(const fink & e)  : abString_emp(e) {
    this -> reportStr = e.reportStr;
}

void fink::Data() const {
    cout << "reportStr: " << reportStr << endl;
}

void fink::ShowAll() const {
    abString_emp::Data();
    Data();
}

void fink::SetAll() {
    abString_emp::SetAll();
    reportStr = nullptr;
}

__attribute__((unused)) highFink::highFink(const string & fn, const string & ln, const string & j, const string & rpo, int ico) : abString_emp(fn, ln, j),
                                                                                                                                  manager(fn, ln, j, ico),
                                                                                                                                  fink(fn, ln, j, rpo) {}

__attribute__((unused)) highFink::highFink(const abString_emp & e, const string & rpo, int ico) : abString_emp(e),
                                                                                                  manager(e, ico), fink(e, rpo) {}

__attribute__((unused)) highFink::highFink(const fink & f, int ico) : abString_emp((const abString_emp &) f), manager(f, ico), fink(f) {}

highFink::highFink(const manager & m, const string & rpo) : abString_emp((const abString_emp &) m), manager(m), fink(m, rpo) {}


__attribute__((unused)) highFink::highFink(const highFink & h)  : abString_emp(h), manager(h), fink(h) {

}

void highFink::Data() const {
    abString_emp::Data();
    manager::Data();
    fink::Data();
}

void highFink::ShowAll() const {
    Data();
}

void highFink::SetAll() {

}
