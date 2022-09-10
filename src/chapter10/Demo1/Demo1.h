/* class Person
 * @Author: Jetty 
 * @Date: 2022-09-10 20:15:50 
 * @Last Modified by: Jetty
 * @Last Modified time: 2022-09-10 20:41:57
 */
#ifndef DEMO1_H_
#define DEMO1_H_
#include <string>
using std::string;

class Person
{
    private:
        static const int LIMIT {25}; // 类内常量
        string lname; // 姓
        char fname[LIMIT]; // 名
    public:
        Person(); // 默认构造
        Person(const string & ln, const char * fn = "Heyyou"); // 非默认构造
        void Show() const; // 显示
        void FormalShow() const; // 正式显示
};

#endif