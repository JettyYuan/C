# chapter15

## 友元

类除了可以拥有友元函数外，还可以拥有友元类，友元声明可以位于公有、私有或保护部分，其与所在位置无关紧要

但在将特定的类方法作为友元加入其他的类中时，必须要注意各种声明和定义的**顺序关系**

可以将一个函数作为**多个类**的友元函数

## 嵌套类

嵌套类就是在**类中**定义的类，根据类作用域的变化灵活使用作用域运算符

## 异常

**try语句**监控try代码块并捕获异常，若异常则跳转到与异常信息对应的**catch语句**，将异常抛出的信息赋值给catch的参数列表，并执行catch代码块中的代码

**throw语句**引发异常并沿函数调用序列后退，直到找到包含try语句的函数，跳转到try语句结尾

**栈解退**机制，记录try代码块每条执行语句的地址以栈数据形式存放，在遇到异常时，按栈的释放规则释放语句中可能存在的动态变量与对象后跳转到try语句结尾

如果有一个异常类继承层次结构，应这样排列catch块：将捕获位于层次结构最下面的异常类的catch语句放在最前面，将捕获基类异常的catch语句放在最后面

如果想要捕获**任何异常**，可以将catch的参数列表设为...

exception头文件定义了exception类，作为其他异常类的基类，有一个what()的虚拟成员函数，返回一个字符串

stdexcept头文件定义了其他基于exception的异常类，logic_error和runtime_error就是基于exception，它们是头文件中其他异常的基类

在有new导致的异常，可以在new后面加上(std::nothrow)使其发生异常时返回的是空指针**而不是**一个字符串

正确的异常捕获与处理可以帮助用户使用程序，程序的完善程度也更高

## RTTI

RTTI**只适用**于包含虚函数的类

dynamic_cast运算符是RTTI的组件，用于检测对象是否可以安全的转换为其他的类对象，若能，则将对象先转换为目标类再赋值给变量，不能则返回空指针

typeid运算符使得能够确定两个对象**是否**为同种类型，返回一个对type_info类对象的引用

## 类型转换运算符

- dynamic_cast运算符，dynamic_cast <type-name> (expression)在类层次结构**向上**转换
- const_cast运算符，const_cast <type-name> (expression)将const或volatile标识的变量转换
- static_cast运算符，static_cast <type-name> (expression)在类层次结构**相互**转换
- reinterpret_cast运算符，reinterpret_cast <type-name> (expression)特殊使用

## 头文件

### cfloat

类型支持库的一部分，特别是C数值极限接口的一部分

[cfloat](http://www.cppds.com/cpp/header/cfloat.html)

### exception

错误处理库的一部分

[exception](http://www.cppds.com/cpp/header/exception.html)

### stdexcept

错误处理库的一部分

[stdexcept](http://www.cppds.com/cpp/header/stdexcept.html)

### typeinfo

类型支持库的一部分

[typeinfo](http://www.cppds.com/cpp/header/typeinfo.html)
