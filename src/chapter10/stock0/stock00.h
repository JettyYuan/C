/* Stock class interface
 * @Author: Jetty 
 * @Date: 2022-09-04 17:43:43 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-04 17:49:11
 */
#ifndef STOCK00_H_
#define STOCK00_H_
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
        void acquire(const string & co, long n, double pr);
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show();
};

#endif