# chapter16

## string类

string类有很多构造函数，可适当了解

## 智能指针模板类

unique_ptr和shared_ptr都是，两者有不完全一样，要使用它们必须包含头文件memory，它们位于命名空间std中

unique_ptr采用**所有权模型**，它不允许将相同的地址赋给多个unique_ptr模板类变量，除非是临时右值

使用new []分配内存时，**不能**使用shared_ptr，这时**只能**使用unique_ptr

## STL

分配器：管理内存工具

迭代器：广义指针

一些用于容器的方法：

- size()，返回容器中元素数目
- swap()，交换两个容器的内容
- begin()，返回一个指向容器中第一个元素的迭代器
- end()，返回一个表示超过容器尾的迭代器
- push_bach()，将元素添加到矢量末尾
- erase()，删除矢量中给定区间的元素
- insert()，在矢量中给定区间添加元素

一些STL函数：

- for_each()，可以代替for循环，但不可修改容器元素的值
- Random_shuffle()，随机排列区间内元素，要求容器类允许随机访问，比如vector类
- sort()，排序区间内元素，要求容器类允许随机访问，比如vector类，如果元素是自定义对象，则要重载<运算符进行矢量比较

基于范围的for循环也是为STL设计的，但它可以通过引用参数修改容器的内容

## 泛型编程

泛型编程旨在编写独立于数据类型的代码

常规指针就能满足迭代器的要求，所以如果有函数的参数是迭代器，则可以直接使用指针作为参数

C++将operator++作为前缀版本，将operator++(int)作为后缀版本

| 迭代器功能    | 输入  | 输出  | 正向  | 双向  | 随机访问 |
|----------|-----|-----|-----|-----|------|
| 解除引用读取   | T   | F   | T   | T   | T    |
| 解除引用写入   | F   | T   | T   | T   | T    |
| 固定和可重复排序 | F   | F   | T   | T   | T    |
| ++i i++  | T   | T   | T   | T   | T    |
| --i i--  | F   | F   | F   | T   | T    |
| i[n]     | F   | F   | F   | F   | T    |
| i+n      | F   | F   | F   | F   | T    |
| i-n      | F   | F   | F   | F   | T    |
| i+=n     | F   | F   | F   | F   | T    |
| i-=n     | F   | F   | F   | F   | T    |

矢量迭代器是随机访问迭代器，指针满足所有的迭代器要求

预定义迭代器，迭代器概念的**模型**，适配器；例如ostream_iterator就是输出迭代器概念的模型，这些适配器需要包含头文件iterator才可以使用

vector类的特殊功能函数rbegin()和rend()，它们返回与begin()和end()相反的迭代器，对它们执行递增操作导致其递减

rbegin()和rend()的返回值就是begin()和end()的返回值的反向指针，反向指针**先递减**，才会解除引用

## 头文件

### memory

动态内存管理库的一部分

[memory](http://www.cppds.com/cpp/header/memory.html)

### algorithm

算法库的一部分

[algorithm](http://www.cppds.com/cpp/header/algorithm.html)

### iterator

迭代器库的一部分

[iterator](http://www.cppds.com/cpp/header/iterator.html)
