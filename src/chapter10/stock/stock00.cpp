/* implementing the Stock class
 * @Author: Jetty 
 * @Date: 2022-09-04 21:24:19 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-04 21:38:12
 */
#include <iostream>
#include "stock00.h"
using std::cout;

void Stock::acquire(const std::string & co, long n, double pr)
{
    company = co;
    if (n < 0)
    {
        cout << "Number of shares can't be negative; "
             << company << " shares set to 0.\n";
        shares = 0;
    }
    else
    {
        shares = n;
    }
    share_val = pr;
    set_tot();
}

void Stock::buy(long num, double price)
{
    if (num < 0)
    {
        cout << "Number of shares purchased can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares += num;
        share_val = price;
        set_tot();
    }
}

void Stock::sell(long num, double price)
{
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted.\n";
    }
    else
    if (num > shares)
    {
        cout << "You can't sell more than you have! "
             << "Transaction is aborted.\n";
    }
    else
    {
        shares -= num;
        share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    share_val = price;
    set_tot();
}

void Stock::show()
{
    cout << "Company: " << company
         << " Shares: " << shares << '\n'
         << " Share Price: $" << share_val
         << " Total Worth: $" << total_val << '\n';
}