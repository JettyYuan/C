# chapter10

将函数原型放在类声明中，实现细节另存其他文件

公有成员函数是程序和对象的私有成员之间的桥梁，提供了对象和程序之间的接口

类声明中可以不使用关键字private，只是默认的访问控制，但一般会显式使用

结构的默认访问控制是public，类的默认访问控制是private，但一般结构只作为纯粹的数据对象

成员函数的特征

- 定义成员函数时，使用作用域解析运算符（::）来标识函数所属的类
- 类方法可以访问类的private组件

定义于类声明中的函数自动成为内联函数，也可以在类声明之外定义成员函数并使用inline限定符使其成为内联函数

内联函数的特殊规则要求在每个使用它们的文件中都对其进行定义，最简便的方法是将内联定义放在定义类的头文件中

在类声明中定义方法等同于用原型替换方法定义，然后在类声明的后面将定义改写为内联函数