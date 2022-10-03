# chapter12

## 类中动态内存

如果在类中使用new和delete运算符动态控制内存，析构函数**必不可少**，可能还需要重载赋值运算符

在构造函数中使用new来分配内存时，**必须**在相应的析构函数中使用delete来释放内存

### 静态类成员

静态类成员有一个特点：无论创建了多少对象，程序**只**创建一个静态类变量副本，也就是所有的对象使用同一个值

静态类成员不在类声明中初始化，并且它也不是在构造函数内初始化，**单独初始化**，初始化时也不带有static关键字；但如果静态成员是const整数类型或枚举型，则可以在类声明初始化

带参数的构造函数**也可以**是默认构造函数，只要所有参数都有默认值；也就是说可以只定义一个带有默认值参数的构造函数，但只能存在一个默认的构造函数

### 复制构造函数

复制构造函数原型：Class_name(const Class_name &)，当函数按值传递对象或函数返回对象时，即**生成对象副本**的时候都会调用复制构造函数，逐个复制**非静态**成员的值，即浅复制

复制构造函数构造的对象副本也会在失效的时候调用析构函数，这是一个**注意点**

在动态分配内存是，如果有调用复制构造函数按值传递对象，可能会导致两个对象的成员指向同一个地址，这时其中一个对象失效导致另一个对象存在**不确定性**

为解决这种不确定性，应该**显式**定义复制构造函数，深度复制，确保每一个对象都有自己的成员值

### 重载赋值运算符

与复制构造函数类似，赋值运算符的隐式实现也是浅复制，但也有一些不同之处

重载的赋值运算符需要做到：

- delete动态分配的内存
- 避免将对象赋给自身
- 返回一个指向调用对象的引用

在动态分配内存的类，使用默认的赋值运算符可能会导致错误的生成，所以需要重载运算符避免错误的发生

复制构造函数与重载的赋值运算符的**主要区别**在于，前者是创建了一个新的对象，而后者是更改原来的对象；因此，重载的赋值运算符会有一个delete释放内存的操作