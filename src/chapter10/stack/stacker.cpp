/* testing the Stack class
 * @Author: Jetty 
 * @Date: 2022-09-08 21:11:41 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-08 21:35:36
 */
#include <iostream>
#include <cctype>
#include "stack.h"

int main()
{
    using std::cout;
    using std::cin;

    Stack st;
    char ch;
    unsigned long po;
    cout << "Please enter A to add a purchase order,\n"
         << "P to process a PO, or Q to quit.\n";
    while (cin >> ch && toupper(ch) != 'Q')
    {
        // 只能输入一个字符
        while (cin.get() != '\n')
        {
            continue;
        }
        // 必须是字母
        if (!isalpha(ch))
        {
            cout << '\a';
            continue;
        }
        switch (ch)
        {
            case 'A' :
            case 'a' : cout << "Enter a PO number to add: ";
                       cin >> po;
                       if (st.isfull())
                       {
                            cout << "stack already full\n";
                       }
                       else
                       {
                            st.push(po);
                       }
                       break;
            case 'P' :
            case 'p' : if (st.isempty())
                       {
                            cout << "stack already empty\n";
                       }
                       else
                       {
                            st.pop(po);
                            cout << "PO #" << po << " popped\n";
                       }
                       break;
        }
        cout << "Please enter A to add a purchase order,\n"
             << "P to process a PO, or Q to quit.\n";
    }
    cout << "Bye\n";
    return 0;
}