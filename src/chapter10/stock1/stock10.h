/* Stock class declaration with constructors, destructor added
 * @Author: Jetty 
 * @Date: 2022-09-06 20:13:27 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-06 21:10:23
 */
#ifndef STOCK10_H_
#define STOCK10_H_
#include <string>
using std::string;

class Stock
{
    private:
        string company;
        long shares;
        double share_val;
        double total_val;
        void set_tot()
        {
            total_val = shares * share_val;
        }
    public:
        // 默认构造函数
        Stock();
        // 非默认构造函数
        Stock(const string & co, long n = 0L, double pr = 0.0);
        // 析构函数
        ~Stock();
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();
};

#endif