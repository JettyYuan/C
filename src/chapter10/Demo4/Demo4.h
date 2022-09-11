/* class Stack and struct customer
 * @Author: Jetty 
 * @Date: 2022-09-11 14:06:35 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-11 21:55:44
 */
#ifndef DEMO4_H_
#define DEMO4_H_

struct customer
{
    char fullname[35]; // 顾客的全名
    double payment; // 顾客需要支付的金额
};
typedef customer Item;
class Stack
{
    private:
        enum {MAX = 10}; // 栈长
        Item items[MAX]; // 栈
        int top; // 栈顶
    public:
        Stack(); // 默认构造
        bool isempty() const; // 空？
        bool isfull() const; // 满？
        bool push(const Item & c); // 加栈
        bool pop(Item & c); // 清栈
};
class Merchant
{
    private:
        double total; // 总数
    public:
        Merchant(); // 默认构造
        void paid(const Item & c); // 计算总数
        void showTotal() const; // 显示总数
};

#endif