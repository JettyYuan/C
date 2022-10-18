// pe14-5.cpp
// Created by Jetty on 2022/10/16.
//

#include <iostream>
#include "emp.h"
using namespace std;

int main() {
    employee em("Trip", "Harris", "Thumped");
    cout << em << endl;
    em.ShowAll();
    manager ma("A morphia", "Spin-dragon", "Nuanced", 5);
    cout << ma << endl;
    ma.ShowAll();
    fink fi("Matt", "Eggs", "Oiler", "Juno Barr");
    cout << fi << endl;
    fi.ShowAll();
    highFink hf(ma, "Curly Kew");
    hf.ShowAll();
    cout << "Press a key for next phase:\n";
    cin.get();
    highFink hf2;
    hf2.SetAll();
    cout << "Using an abString_emp * pointer:\n";
    abString_emp * tri[4] = {&em, &fi, &hf, &hf2};
    for (auto & i : tri) i -> ShowAll();
    return 0;
}
