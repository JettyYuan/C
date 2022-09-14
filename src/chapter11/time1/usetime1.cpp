/* using the second draft of the Time class
 * @Author: Jetty 
 * @Date: 2022-09-14 20:21:23 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-14 20:27:27
 */
#include <iostream>
#include "mytime1.h"

int main()
{
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;
    cout << "planning time = ";
    planning.Show();
    cout << endl;
    cout << "coding time = ";
    coding.Show();
    cout << endl;
    cout << "fixing time = ";
    fixing.Show();
    cout << endl;
    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;
    Time morefixing(3, 28);
    cout << "more fixing time = ";
    morefixing.Show();
    cout << endl;
    total = morefixing.operator+(total);
    cout << "morefixing.operator+(total) = ";
    total.Show();
    cout << endl;
    return 0;
}