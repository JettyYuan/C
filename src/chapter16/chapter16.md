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

copy()函数用于复制容器内容到另一个容器，这会覆盖目标容器

预定义迭代器，迭代器概念的**模型**，适配器；例如ostream_iterator就是输出迭代器概念的模型，这些适配器可能需要包含头文件iterator才可以使用

- ostream_iterator<使用参数类型, 输出参数类型> 迭代器变量名(cout等, 每个使用参数之间的间隔值)
- istream_iterator<使用参数类型, 输出参数类型> 迭代器变量名(cin等)，如果没有构造函数参数，则表示输入失败
- reverse_iterator与普通iterator一样直接用于容器类型创建迭代器变量
- back_insert_iterator<容器类型> 迭代器变量名(容器标识符)，插入到容器尾部
- front_insert_iterator<容器类型> 迭代器变量名(容器标识符)，插入到容器前端
- insert_iterator<容器类型> 迭代器变量名(容器标识符, 插入容器位置)，插入到指定位置前端

对reverse_iterator执行递增操作将**导致**它被递减

vector类的特殊功能函数rbegin()和rend()，它们返回与begin()和end()相反的迭代器，对它们执行递增操作导致其递减

rbegin()和rend()的返回值就是begin()和end()的返回值的反向指针，反向指针**先递减**，才会解除引用

容器存储的对象可以是基本类型的，也可以是自定义类型的，但必须有公开的复制构造函数和重载的赋值运算符

描述复杂度的时间：

- 编译时间，在编译时执行操作，执行时间为0
- 固定时间，在运行时执行操作，但独立于对象中元素数目
- 线性时间，时间与元素数目成正比

一些容器类型

- vector 默认类型，可随机访问，可反转容器，在尾部添加和删除元素的时间是固定的，但在头部或中间插入和删除元素的复杂度为线性时间
- deque 双端队列，可随机访问，在头部或尾部时间是固定的，但在中间时间是线性的
- list 双向链表，不可随机访问，可反转容器，在任意位置时间都是固定的
- forward_list 单链表，只需要正向迭代器，不可反转容器
- queue 适配器类，给底层类默认为deque提供队列接口，不可随机访问，不可遍历元素
- priority_queue 适配器类，给底层类默认为vector提供队列接口，把最大的元素移到队首，不可随机访问，不可遍历元素
- stack 适配器类，给底层类默认为vector提供栈接口，不可随机访问，不可遍历元素

list模板类的一些成员函数

- void merge(list<T, Alloc> & x) 将链表x与调用链表合并；两个链表必须已经排序；合并后的经过排序的链表保存在调用链表中，x为空；复杂度为线性时间
- void remove(const T & val) 从链表中删除val的所有实例；复杂度为线性时间
- void sort() 使用<运算符对链表进行排序；N个元素的复杂度为NlogN
- void splice(iterator pos, list<T, Alloc> x) 将链表x的内容插入到pos的前面，x将为空；复杂度为固定时间
- void unique() 将连续的相同元素压缩为单个元素；复杂度为线性时间

insert()和splice()之间的**主要区别**在于：insert()将原始区间的副本插入目标地址，而splice()则将原始区间移到目标地址

**非成员**函数sort()不可用于链表，它需要随机访问迭代器，所以list只能使用其**成员**函数sort()

queue和priority_queue的操作

- bool empty() const 如果队列为空，则返回true；否则返回false
- size_type size() const 返回队列中元素的数目
- T & front() 返回指向队首元素的引用
- T & back() 返回指向队尾元素的引用
- void push(const T & x) 在队尾插入x
- void pop() 删除队首元素

stack的操作

- bool empty() const 如果栈为空，则返回为true；否则返回false
- size_type size() const 返回栈中的元素数目
- T & top() 返回指向栈顶元素的引用
- void push(const T & x) 在栈顶部插入x
- void pop() 删除栈顶元素

STL的关联容器：set、multiset、map、multimap，前两者类似存放在set头文件，后两者类似存放在map头文件中

关联容器基于**树结构**

关联容器set会**自动**排序容器内的元素并合并相同元素，因为set的值与键类型相同，键唯一，对于set而言键就是值

关联容器set部分函数 

- set_union() 得到两个set对象的并集set对象
- set_intersection() 得到两个set对象的交集set对象
- set_difference() 得到调用set对象有但目标set对象没有的元素并存放在另一个set对象中
- lower_bound() 容器内第一个不小于键参数的成员
- upper_bound() 容器内第一个大于键参数的成员

关联容器multimap部分函数

- count() 得到该键的元素数
- lower_bound()
- upper_bound()
- equal_range() 键作为参数，返回迭代器封装在pair对象中

无序关联容器基于**哈希表**

## 函数对象

函数对象也叫函数符，作为参数用于STL的一些算法

函数符就是自定义类且提供了重载的()

transform()函数就是利用预定义的函数符操作的

运算符和相应的函数符

| 运算符 | 相应的函数符        |
|-----|---------------|
| +   | plus          |
| -   | minus         |
| *   | multiplies    |
| /   | divides       |
| %   | modulus       |
| -   | negate        |
| ==  | equal_to      |
| !=  | not_equal_to  |
| >   | greater       |
| <   | less          |
| >=  | greater_equal |
| <=  | less_equal    |
| &&  | logical_and   |
| or  | logical_or    |
| !   | logical_not   |

可以使用binder1st和binder2nd类将自适应二元函数**转换**为自适应一元函数，它们都有各自的助手函数，分别为bind1st()和bind2nd()函数

## 算法

STL的四组算法库

- 非修改式序列操作 对区间内每个元素进行操作，但不做修改
- 修改式序列操作 对区间内每个元素进行操作，但可以修改，甚至可以修改排序顺序
- 排序和相关操作 一些排序函数以及其他函数
- 通用数字运算 关于数字操作的函数

new_permutation()函数搭配循环对**已排序**的字符串列出所有除自己本身外的可能排序

模板initializer_list类似于模板类等，用于容器类，但它的迭代器类型是const，所以不能修改它存放的值

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

### deque

容器库的一部分

[deque](http://www.cppds.com/cpp/header/deque.html)

### list

容器库的一部分

[list](http://www.cppds.com/cpp/header/list.html)

### forward_list

容器库的一部分

[forward_list](http://www.cppds.com/cpp/header/forward_list.html)

### queue

容器库的一部分

[queue](http://www.cppds.com/cpp/header/queue.html)

### stack

容器库的一部分

[stack](http://www.cppds.com/cpp/header/stack.html)

### set

容器库的一部分

[set](http://www.cppds.com/cpp/header/set.html)

### map

容器库的一部分

[map](http://www.cppds.com/cpp/header/map.html)

### functional

函数对象库的一部分并提供标准散列函数

[functional](http://www.cppds.com/cpp/header/functional.html)

### numeric

数值库的一部分

[numeric](http://www.cppds.com/cpp/header/numeric.html)

### complex

数值库的一部分

[complex](http://www.cppds.com/cpp/header/complex.html)

### initializer_list

工具库的一部分

[initializer_list](http://www.cppds.com/cpp/header/initializer_list.html)
