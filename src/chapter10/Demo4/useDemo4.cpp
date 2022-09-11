/* using the class Stack and Merchant
 * @Author: Jetty 
 * @Date: 2022-09-11 18:10:48 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-11 21:59:11
 */
#include <iostream>
#include <cstring>
#include "Demo4.h"
#include <cctype>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    Merchant m; // 商家对象
    Item item; // 栈数据成员数组元素
    char ch; // 选项
    Stack st; // 栈
    cout << "Please enter A to add item, enter D to delete item. (Q to quit): ";
    while (cin >> ch && (ch != 'Q'))
    {
        // 输入检查，单个字符允许通过
        while (cin.get() != '\n')
        {
            continue;
        }
        if (!isalpha(ch))
        {
            continue;
        }
        switch (ch)
        {
            case 'A' : if (st.isfull())
                       {
                            cout << "Already full.\n";
                       }
                       else
                       {
                            cout << "Enter the customer's full name: ";
                            cin.getline(item.fullname, 35);
                            cout << "Enter the customer's payment: ";
                            cin >> item.payment;
                            st.push(item);
                       }
                       break;
            case 'D' : if (st.isempty())
                       {
                            cout << "Already empty.\n";
                       }
                       else
                       {
                            st.pop(item);
                            m.paid(item);
                            cout << "Customer " << item.fullname << " had paid.\n";
                            m.showTotal();
                       }
                       break;
        }
        cout << "Please enter A to add item, enter D to delete item. (Q to quit): ";
    }
    m.showTotal();
    return 0;
}