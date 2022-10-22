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

## 头文件

### memory

动态内存管理库的一部分

[memory](http://www.cppds.com/cpp/header/memory.html)

### algorithm

算法库的一部分

[algorithm](http://www.cppds.com/cpp/header/algorithm.html)
