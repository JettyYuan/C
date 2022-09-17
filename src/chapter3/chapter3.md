# chapter3

## 运算符

sizeof运算符返回类型或变量的长度，单位为**字节**

%运算符的操作数**必须**都是整数，操作数有负数余数**必为负数**

### 优先级和结合性

## 控制符

控制符dec、hex和oct用于指示cout以十进制、十六进制和八进制格式显示整数

## 数据类型

列表初始化**不允许**缩窄，即变量的类型可能无法表示赋给它的值

### 字符型

char型存储**字母和数字**

cout.put()函数显示**一个字符**

部分常用的转义字符

| 字符名称  | C++代码 |
|-------|-------|
| 换行符   | \n    |
| 水平制表符 | \t    |
| 垂直制表符 | \v    |
| 退格    | \b    |
| 回车    | \r    |
| 振铃    | \a    |
| 反斜杆   | \\    |
| 问号    | \?    |
| 单引号   | \'    |
| 双引号   | \"    |

### bool型

字面值true和false都可以通过提升转换为int型，true被转换为1，false被转换为0

| 类型          | 精度  |
|-------------|-----|
| float       | 6   |
| double      | 15  |
| long double | 18  |

### 浮点型

float型后缀为F或f long double型后缀为L或l

E表示法：适合于非常大和非常小的浮点数；数字中不能有空格

将浮点型转换为整型，C++采取**截取整数部分**而不是四舍五入的方式

## 强制类型转换

强制类型转换通用格式：(typeName) value

## 关键字auto

使用关键字auto，编译器将把变量的类型设置成与初始值相同

## 头文件

### iostream

输入/输出库的一部分

```c++
#include <ios>
#include <streambuf>
#include <istream>
#include <ostream>
 
namespace std {
  extern istream cin;
  extern ostream cout;
  extern ostream cerr;
  extern ostream clog;
 
  extern wistream wcin;
  extern wostream wcout;
  extern wostream wcerr;
  extern wostream wclog;
}
```

### climits

类型支持库的一部分，C数值极限接口的一部分

```c++
#define CHAR_BIT // char 的位数
#define SCHAR_MIN // signed char 的最小值
#define SCHAR_MAX // signed char 的最大值
#define UCHAR_MAX // unsigned char 的最大值
#define CHAR_MIN // char 的最小值
#define CHAR_MAX // char 的最大值
#define MB_LEN_MAX
#define SHRT_MIN // short 的最小值
#define SHRT_MAX // short 的最大值
#define USHRT_MAX // unsigned short 的最大值
#define INT_MIN // int 的最小值
#define INT_MAX // int 的最大值
#define UINT_MAX // unsigned int 的最大值
#define LONG_MIN // long 的最小值
#define LONG_MAX // long 的最大值
#define ULONG_MAX // unsigned long 的最大值
#define LLONG_MIN // long long 的最小值
#define LLONG_MAX // long long 的最大值
#define ULLONG_MAX // unsigned long long 的最大值
```
