/* Stack member functions
 * @Author: Jetty 
 * @Date: 2022-09-11 14:16:40 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-11 21:55:43
 */
#include "Demo4.h"
#include <iostream>
#include <fstream>
using std::ofstream;

Stack::Stack()
{
    top = 0;
}

bool Stack::isempty() const
{
    return top == 0;
}

bool Stack::isfull() const
{
    return top == MAX;
}

bool Stack::push(const Item & c)
{
    if (top < MAX)
    {
        items[top++] = c;
        return true;
    }
    else
    {
        return false;
    }
}

bool Stack::pop(Item & c)
{
    if (top > 0)
    {
        c = items[--top];
        return true;
    }
    else
    {
        return false;
    }
}

Merchant::Merchant()
{
    total = 0.0;
}

void Merchant::paid(const Item & c)
{
    total += c.payment;
}

void Merchant::showTotal() const
{
    std::cout << "You have got " << total << '\n';
}