/* Stack member functions
 * @Author: Jetty 
 * @Date: 2022-09-08 21:00:20 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-08 21:38:27
 */
#include "stack.h"
// 默认构造函数
Stack::Stack()
{
    top = 0;
}
// 操作前检查栈是否空
bool Stack::isempty() const
{
    return top == 0;
}
// 操作前检查栈是否满
bool Stack::isfull() const
{
    return top == MAX;
}
// 加栈
bool Stack::push(const Item & item)
{
    if (top < MAX)
    {
        items[top++] = item;
        return true;
    }
    else
    {
        return false;
    }
}
// 清栈
bool Stack::pop(Item & item)
{
    if (top > 0)
    {
        item = items[--top];
        return true;
    }
    else
    {
        return false;
    }
}