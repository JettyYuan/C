/* augmented version
 * @Author: Jetty 
 * @Date: 2022-09-07 11:38:54 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-07 11:44:43
 */
#ifndef STOCK20_H_
#define STOCK20_H_
#include <string>
using std::string;

class Stock
{
    private:
        string company;
        int shares;
        double share_val;
        double total_val;
        void set_tot()
        {
            total_val = shares * share_val;
        }
    public:
        Stock();
        Stock(const string & co, long n = 0L, double pr = 0.0);
        ~Stock();
        void buy(long num, double price);
        void sell(long num, double price);
        void update(double price);
        void show() const;
        const Stock & topval(const Stock & s) const;
};

#endif