/* augmented version
 * @Author: Jetty 
 * @Date: 2022-09-07 11:45:35 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-07 11:58:01
 */
#include <iostream>
#include "stock20.h"
using std::string;
using std::cout;
// 默认构造函数
Stock::Stock()
{
    company = "no name";
    shares = 0;
    share_val = 0.0;
    total_val = 0.0;
}
// 非默认构造函数
Stock::Stock(const string & co, long n, double pr)
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
// 析构函数
Stock::~Stock() {}
// 买
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
// 卖
void Stock::sell(long num, double price)
{
    if (num < 0)
    {
        cout << "Number of shares sold can't be negative. "
             << "Transaction is aborted..\n";
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
// 更新
void Stock::update(double price)
{
    share_val = price;
    set_tot();
}
// 显示
void Stock::show() const
{
    using std::ios_base;
    using std::streamsize;

    ios_base::fmtflags orig {cout.setf(ios_base::fixed, ios_base::floatfield)};
    streamsize prec {cout.precision(3)};
    cout << "Company: " << company
         << " Shares: " << shares << '\n';
    cout << " Share Price: $" << share_val;
    cout.precision(2);
    cout << " Total Worth: $" << total_val << '\n';
    cout.setf(orig, ios_base::floatfield);
    cout.precision(prec);
}
// 最值
const Stock & Stock::topval(const Stock & s) const
{
    if (s.total_val > total_val)
    {
        return s;
    }
    else
    {
        return *this;
    }
}