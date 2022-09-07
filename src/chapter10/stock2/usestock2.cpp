/* using the Stock class
 * @Author: Jetty 
 * @Date: 2022-09-07 12:00:34 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-07 12:13:15
 */
#include <iostream>
#include "stock20.h"
using std::cout;

const int STKS {4};

int main()
{
    Stock stocks[STKS]
    {
        Stock("NanoSmart", 12, 20.0),
        Stock("Boffo Objects", 200, 2.0),
        Stock("Monolithic Obelisks", 130, 3.25),
        Stock("Fleep Enterprises", 60, 6.5)
    };
    cout << "Stock holding:\n";
    int st;
    for (st = 0; st < STKS; st++)
    {
        stocks[st].show();
    }
    const Stock * top {&stocks[0]};
    for (st = 1; st < STKS; st++)
    {
        top = &top -> topval(stocks[st]);
    }
    cout << "\nMost valuable holding:\n";
    top -> show();
    return 0;
}