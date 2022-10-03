//
// Created by jetty on 2022/10/3.
//
#include <iostream>
#include "demo.h"
using namespace std;

int main() {
    // 接受两个double参数和无参初始化变量
    complex a(3.0, 4.0);
    // 默认值为(10.0, 12.0)
    complex c;
    cout << "Enter a complex number (q to quit):\n";
    // 重载">>"输入复数
    while (cin >> c) {
        // 重载"<<"输出复数
        cout << "c is " << c << '\n';
        // 重载'~'
        cout << "complex conjugate is " << ~c << '\n';
        cout << "a is " << a << '\n';
        // 重载"+, -, *"运算符
        cout << "a + c is " << a + c << '\n';
        cout << "a - c is " << a - c << '\n';
        cout << "a * c is " << a * c << '\n';
        // 友元函数定义一个'*'运算
        cout << "2 * c is " << 2 * c << '\n';
        cout << "Enter a complex number (q to quit):\n";
    }
    cout << "Done!\n";
    return 0;
}
