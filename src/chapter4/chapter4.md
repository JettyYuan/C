如果将sizeof运算符用于数组名，得到的将是整个数组中的字节数
如果将sizeof用于数组元素，得到的将是元素的长度

在确定存储字符串所需的最短数组时，要将结尾的空字符('\0')计算在内

strlen()只计算可见的字符，而不把空字符计算在内

共用体的长度为其最大成员的长度

枚举量是整型，可被提升为int型，但int型不能自动转换为枚举型

不能使用sizeof运算符来确定动态分配的数组包含的字节数

C++将数组名解释为地址并视其为第1个元素的地址

如果给cout提供一个字符的地址，则它将从该字符开始打印，直到遇到空字符为止

模板类vector类似于string类，是一种动态数组

vector创建vt对象
vector<typename> vt(n_elem)

模板类array创建arr对象
array<typename, n_elem> arr

cstring头文件

string头文件

vector头文件

array头文件