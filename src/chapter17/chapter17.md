# chapter17

## cout输出

cout可以调用一个write()函数，接受两个参数，第一个是地址，第二个是打印的个数，返回cout对象引用

cout将在信息输出之后清空缓冲区

flush控制符**刷新缓冲区**，立即生效一次，可以以函数的形式，如flush(cout)，或者在输出的语句中加上该控制符、

dec、hex和oct控制符设置输出的进制，分别为十、十六和八，它们都可以以函数形式调用，一直生效直到更改为其他格式

width()函数设置字段宽度，**只影响下一个输出**，默认右对齐，之后恢复默认；但如果字段宽度不够，程序将**自动**增宽字段

默认使用空格填充未使用的字段，可以使用fill()函数更改填充字符，一直生效知道更改为其他的字符

精度指的是小数点后的位数

C++的默认精度为6（但不显示末尾的0）precision()函数可以**更改精度**，一直生效知道更改为其他精度

cout.setf()，设置输出格式，参数是格式常量，修改一种有效直到被修改

格式常量格式

| 常量                  | 含义                       |
|---------------------|--------------------------|
| ios_base::boolalpha | 输入和输出bool值，可以为true或false |
| ios_base::showbase  | 对于输出，使用C++基数前缀（0，0x）     |
| ios_base::showpoint | 显式末尾的小数点                 |
| ios_base::uppercase | 对于16进制输出，使用大写字母，E表示法     |
| ios_base::showpos   | 在正数前面加上+                 |

只有十进制才使用+，对于十六进制和八进制都视为无符号的

| 第二个参数                 | 第一个参数                | 含义              |
|-----------------------|----------------------|-----------------|
| ios_base::basefield   | ios_base::dec        | 使用基数10          |
|                       | ios_base::oct        | 使用基数8           |
|                       | ios_base::hex        | 使用基数16          |
| ios_base::floatfield  | ios_base::fixed      | 使用定点计数法         |
|                       | ios_base::scientific | 使用科学计数法         |
| ios_base::adjustfield | ios_base::left       | 使用左对齐           |
|                       | ios_base::right      | 使用右对齐           |
|                       | ios_base::internal   | 符号或基数前缀左对齐，值右对齐 |

两个参数使用setf()函数将第一个参数设置为0恢复默认方法，一个参数使用unsetf()函数恢复默认方法

一些标准控制符可以代替使用setf()和unsetf()函数

| 控制符         | 调用                                               |
|-------------|--------------------------------------------------|
| boolalpha   | setf(ios_base::boolalpha)                        |
| noboolalpha | unsetf(ios_base::boolalpha)                      |
| showbase    | setf(ios_base::showbase)                         |
| noshowbase  | unsetf(ios_base::showbase)                       |
| showpoint   | setf(ios_base::showpoint)                        |
| noshowpoint | unsetf(ios_base::showpoint)                      |
| showpos     | setf(ios_base::showpos)                          |
| uppercase   | setf(ios_base::uppercase)                        |
| nouppercase | unsetf(ios_base::uppercase)                      |
| internal    | setf(ios_base::internal, ios_base::adjustfield)  |
| left        | setf(ios_base::left, ios_base::adjustfield)      |
| right       | setf(ios_base::right, ios_base::adjustfield)     |
| dec         | setf(ios_base::dec, ios_base::basefield)         |
| hex         | setf(ios_base::hex, ios_base::basefield)         |
| oct         | setf(ios_base::oct, ios_base::basefield)         |
| fixed       | setf(ios_base::fixed, ios_base::floatfield)      |
| scientific  | setf(ios_base::scientific, ios_base::floatfield) |

iomanip头文件有一些带参数的控制符，setprecision()设置精度，setfill()填充字符，setw()设置字段宽度，由于控制符用于cout语句中，所以这三个控制符可以直接使用在输出语句里

## cin输入

流状态

| 成员                      | 描述                                                                                |
|-------------------------|-----------------------------------------------------------------------------------|
| eofbit                  | 如果到达文件尾，则设置为1                                                                     |
| badbit                  | 如果流被破坏，则设置为1；例如，文件读取错误                                                            |
| failbit                 | 如果输入操作未能读取预期的字符或输出操作没有写入预期的字符，则设置为1                                               |
| goodbit                 | 另一种表示0的方法                                                                         |
| good()                  | 如果流可以使用（所有的位都被清除），则返回true                                                         |
| eof()                   | 如果eofbit被设置，则返回true                                                               |
| bad()                   | 如果badbit被设置，则返回true                                                               |
| fail()                  | 如果badbit或failbit被设置，则返回true                                                       |
| rdstate()               | 返回流状态                                                                             |
| exceptions()            | 返回一个位掩码，指出哪些标记导致异常被引发                                                             |
| exceptions(isostate ex) | 设置哪些状态将导致clear()引发异常；例如，如果ex是eofbit，则如果eofbit被设置，clear()将引发异常                     |
| clear(iostate s)        | 将流状态设置为s；s的默认值为0(goodbit)；如果(restate & exceptions()) != 0，则引发异常basic_ios::failure |
| setstate(iostate s)     | 调用clear(restate() s)，这将设置与s中设置对应的流状态位，其他流状态位保持不变                                  |

clear()可以有参数，默认值为0，如果有，则将设置该位，并将其他状态位清除，但setstate()只影响参数位

ignore()函数接受两个参数，第一个是需要读取并丢弃的字符个数，第二个是字符分界符，读取并丢弃到某一个特定字符

getline(char *, int)在没有读取到字符（不包括换行符）或读取到最大数目字符但行中还有字符时设置failbit

get(char *, int)在没有读取到字符时设置failbit

一些istream方法

- read()函数读取指定数目的字节，并将它们存储在指定的位置中
- peek()函数查看输入流中下一个字符
- gcount()函数返回最后一个非格式化抽取方法读取的字符，即不是用抽取运算符>>读取的字符
- putback()函数将一个字符插入到输入字符串中，被插入的字符将是下一条输入语句读取的第一个字符

## 文件输入输出

open()函数连接文件

close()函数关闭连接

c_str()函数将string对象转换为C风格字符串

is_open()方法检查文件是否被打开

创建文件流对象并连接文件，可以有第二个参数，即文件模式常量，ifstream和ofstream对象提供了默认值，而fstream没有

文件模式常量

| 常量               | 含义           |
|------------------|--------------|
| ios_base::in     | 打开文件，以便读取    |
| ios_base::out    | 打开文件，以便写入    |
| ios_base::ate    | 打开文件，并移到文件尾  |
| ios_base::app    | 追加到文件尾       |
| ios_base::trunc  | 如果文件存在，则截短文件 |
| ios_base::binary | 二进制文件        |

使用write()函数以**二进制格式**存储数据，第一个参数必须是指向char的指针，第二个参数是要复制的字符个数

与write()函数类似的read()函数用于从文件读取信息存放到指定地址

fstream类有两个方法（事实上是缓冲区中的位置）

- seekg()，将输入指针移到指定的文件位置
- seekp()，将输出指针移到指定的文件位置

它们都有两个版本，接受一个参数或接受两个参数，其中两个参数的第二参数有三个常量可以选择，第一个参数就是**以字节为单位**的偏移量

- ios_base::beg 相对于文件开始
- ios_base::cur 相对于当前位置
- ios_base::end 相对于文件尾

一个参数的版本，其参数是绝对值，相对于文件开始，**以字节为单位**，开始位置编号为0

输入流使用tellg()，输出流使用tellp()获取当前指针位置的编号

cstdio头文件中有tmpnam_s()函数可以为临时文件命名，常量L_tmpnam限制文件名包含的字符数，TMP_MAX则是在不重复命名的情况下tmpnam_s()可调用次数

ostringstream类有一个str()函数用于将sstream对象输出的内容保存在一个string对象中

istringstream类有一个instr()函数可以从string对象获取字符作为输入使用，比如string对象中都是数字，就可以赋值给数字类型

## 头文件

### cstdio

C 风格输入/输出库的一部分

[cstdio](http://www.cppds.com/cpp/header/cstdio.html)

### iomanip

输入/输出库的一部分

[iomanip](http://www.cppds.com/cpp/header/iomanip.html)

### sstream

输入/输出库的一部分

[sstream](http://www.cppds.com/cpp/header/sstream.html)
