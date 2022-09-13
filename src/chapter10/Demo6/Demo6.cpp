/* Plorg member functions
 * @Author: Jetty 
 * @Date: 2022-09-12 10:53:07 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-12 11:08:38
 */
#include <iostream>
#include "Demo6.h"
#include <cstring>
using std::cout;
using std::endl;

Plorg::Plorg(const char * n, double c)
{
    strcpy(name, n);
    CI = c;
}



void Plorg::setCI()
{
    this -> CI *= 0.8;
}

void Plorg::show() const
{
    cout << name << ' ' << CI << endl;
}