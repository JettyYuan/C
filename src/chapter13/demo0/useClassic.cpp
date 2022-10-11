// useClassic.cpp
// Created by Jetty on 2022/10/11.
//

#include <iostream>
#include "classic.h"
using namespace std;

void Bravo(const Cd & disk);

int main() {
    /*
     * c1: Cd类对象变量
     * c2: Classic类对象变量
     * pcd: 存放的是c1的地址
     */
    Cd c1("Beatles", "Capitol", 14, 35.5);
    Classic c2 = Classic("Piano Sonata in B flat, Fantasia in C", "Alfred Brenden", "Philips", 2, 57.17);
    Cd * pcd = &c1;
    // 直接使用对象变量调用函数
    cout << "Using object directly:\n";
    c1.Report();
    c2.Report();
    // 使用指针调用指向的对象变量的函数
    cout << "Using type cd * pointer to objects:\n";
    pcd -> Report();
    pcd = &c2;
    pcd -> Report();
    // 通过函数调用参数引用的对象变量的函数
    cout << "Calling a function with a Cd reference argument:\n";
    Bravo(c1);
    Bravo(c2);
    // 将一个Classic类对象变量复制给另一个Classic类对象变量调用函数
    cout << "Testing assignment: ";
    // copy: Classic类对象变量
    Classic copy;
    copy = c2;
    copy.Report();
    return 0;
}

// 调用参数引用的对象变量的函数
void Bravo(const Cd & disk) {
    disk.Report();
}
