# chapter6

## 逻辑运算符

**&&和||**都是顺序点，**分号和逗号运算符**也是；**顺序点**就是先计算左侧的值再对右侧的值进行判定

标识符and、or和not都是C++保留字

## switch

switch语句的参数只能是**整数量**，比如char、int、常规枚举等

## 文件输入输出

- 输入：创建一个ifstream对象，open()函数链接一个文本文件，close()函数关闭链接
- 输出：创建一个ofstream对象，open()函数链接一个文本文件，close()函数关闭链接

安全起见会使用is_open()函数检测文本是否被打开

调用函数good()检测文件输入是否有EOF或者其他问题导致无法输入

## 头文件

### cctype

空终止字节字符串库的一部分

[cctype](http://www.cppds.com/cpp/header/cctype.html)

```c++
namespace std {
  int isalnum(int c); // 如果参数是字母、数字返回true
  int isalpha(int c); // 如果参数是字母返回true
  int isblank(int c); // 如果参数是空白字符，只有空格和制表符返回true
  int iscntrl(int c); // 如果参数是控制字符返回true
  int isdigit(int c); // 如果参数是数字(0~9)返回true
  int isgraph(int c); // 如果参数是除空格之外的打印字符返回true
  int islower(int c); // 如果参数是小写字母返回true
  int isprint(int c); // 如果参数是打印字符（包括空格）返回true
  int ispunct(int c); // 如果参数是标点符号返回true
  int isspace(int c); // 如果参数是标准空白符，如空格、换页、换行符、回车、水平制表符或者垂直制表符返回true
  int isupper(int c); // 如果参数是大写字母返回true
  int isxdigit(int c); // 如果参数是十六进制数字返回true
  int tolower(int c); // 参数是大写字符就返回其小写，否则返回该参数
  int toupper(int c); // 参数是小写字符就返回其大写，否则返回该参数
}
```

### fstream

输入/输出库的一部分

[fstream](http://www.cppds.com/cpp/header/fstream.html)

### cstdlib

提供杂项工具

[cstdlib](http://www.cppds.com/cpp/header/cstdlib.html)
