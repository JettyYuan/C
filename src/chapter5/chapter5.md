# chapter5

## 循环

通常，cout在显示bool值之前将它们转换为int，但cout.setf(ios_base::boolalpha)函数调用设置了一个标记，该标记命令cout显示true和false而并不是1和0

除此之外，sef()函数还可以设置其他的格式化输出

递增运算符(++)和递减运算符(--)一般是**前缀版本效率更高**

strcmp()函数**比较C字符串**按照字典顺序，两个字符串相同，该函数返回0；如果第一个字符串在第二字符串之前，函数返回一个负数；如果第一个字符串在第二个字符串之后，函数返回一个正数

建立**类型别名**

- 预处理器, #define BYTE char
- 关键字typedef, typedef typeName aliasName

基于范围的for循环：对数组（或容器类，如vector和array）的**每个元素**执行相同的操作，如for (double x : prices) statement;

## 文本输入

cin.get(ch)与ch=cin.get()

| 属性            | cin.get(ch)                | ch=cin.get() |
|---------------|----------------------------|--------------|
| 传递输入字符的方式     | 赋给参数ch                     | 将函数返回值赋给ch   |
| 用于字符输入时函数的返回值 | istream对象(执行bool转换后为true)  | int类型的字符编码   |
| 到达EOF时函数的返回值  | istream对象(执行bool转换后为false) | EOF          |

函数eof()和fail()用于EOF检测，fail()包含EOF以及其他导致无法输入的情况

## 头文件

### ctime

C 风格日期和时间库的一部分

[ctime](http://www.cppds.com/cpp/header/ctime.html)
