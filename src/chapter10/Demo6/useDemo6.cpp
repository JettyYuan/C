/* using the class Plorg
 * @Author: Jetty 
 * @Date: 2022-09-12 11:00:11 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-12 11:04:14
 */
#include <iostream>
#include "Demo6.h"

int main()
{
    Plorg plorg;
    Plorg plorg1("plorg1", 40);
    plorg.setCI();
    plorg1.setCI();
    plorg.show();
    plorg1.show();
    return 0;
}