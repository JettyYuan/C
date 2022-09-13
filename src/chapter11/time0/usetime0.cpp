/* using the first draft of the Time class
 * @Author: Jetty 
 * @Date: 2022-09-13 10:24:19 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-13 10:28:05
 */
#include <iostream>
#include "mytime0.h"

int main()
{
    using std::cout;
    using std::endl;

    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;
    cout << "Planning time = ";
    planning.Show();
    cout << endl;
    cout << "coding time = ";
    coding.Show();
    cout << endl;
    cout << "fixing time = ";
    fixing.Show();
    cout << endl;
    total = coding.Sum(fixing);
    cout << "coding.Sum(fixing) = ";
    total.Show();
    cout << endl;
    return 0;
}