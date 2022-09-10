/* using the Person class
 * @Author: Jetty 
 * @Date: 2022-09-10 20:29:05 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-10 21:09:57
 */
#include <iostream>
#include "Demo1.h"
using std::cout;
using std::endl;

int main()
{
    Person one;
    Person two("Smythecraft");
    Person three("Dimwiddy", "Sam");
    one.Show();
    two.Show();
    three.Show();
    cout << endl;
    one.FormalShow();
    two.FormalShow();
    three.FormalShow();
    return 0;
}