# chapter5

通常，cout在显示bool值之前将它们转换为int，但cout.setf(ios::boolalpha)函数调用设置了一个标记，该标记命令cout显示true和false而并不是1和0

递增运算符（++）和递减运算符（--）一般都是前缀版本效率更高

strcmp()函数对于C字符串按照字典顺序，两个字符串相同，该函数返回0；如果第一个字符串在第二字符串之前，函数返回一个负数；如果第一个字符串在第二个字符串之后，函数返回一个正数

建立类型别名

- 预处理器, #define BYTE char
- 关键字typedef, typedef typeName aliasName

基于范围的for循环：对数组（或容器类，如vector和array）的每个元素执行相同的操作，如for (double x : prices) statement;

ctime头文件
