/* Person member functions
 * @Author: Jetty 
 * @Date: 2022-09-10 20:26:33 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-10 21:07:15
 */
#include <iostream>
#include "Demo1.h"
#include <cstring>
using std::cout;
using std::endl;
// 默认构造
Person::Person()
{
    lname = "lname";
    strcpy(fname, "fname");
}
// 非默认构造
Person::Person(const string & ln, const char * fn)
{
    lname = ln;
    strcpy(fname, fn);
}
// 类数据成员显示
void Person::Show() const
{
    cout << "lastname: " << lname << endl;
    cout << "firstname: " << fname << endl;
}
// 姓名显示
void Person::FormalShow() const
{
    cout << "name: " << fname << ' ' << lname << endl;
}