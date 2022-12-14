# chapter11

如果使用了指针或引用作为参数，如果不更改参数的值，必须const，否则编译可能无法通过

## 重载限制规则

- 重载后的运算符必须**至少**有一个操作数是用户定义的类型
- 使用运算符时不能违反运算符原来的句法规则，不能修改运算符的优先级
- 不能创建新运算符
- 不能重载某些运算符

## 友元函数

可以访问类私有成员的一种非成员函数，函数原型位于类声明中，且只能在**声明时**使用关键字friend，定义时不能加friend和类限定符

通过使用友元函数和重载类方法，可以同一个用户接口表达两种操作，友元函数**反转**操作数以调用重载类方法

重载">>, <<"类似的运算符，必须使用友元函数重载，并且返回的是类对象的引用

## 类的自动转换和强制类型转换

兼容类型自动转换，不兼容类型强制转换

当类的构造函数只接受一个参数时，可能会由于自动特性导致基本类型（如int等）转换为定义类型（类）

当不需要自动特性时，可以在构造函数的声明前加上关键字explicit，**依旧**可以通过强制类型转换来显示转换类型

将定义类型转换为基本类型的转换函数：operator typeName(); typeName是要转换的基本类型，这个方法是类方法；需要注意的是，如果值是小数，转换为int，将四舍五入

上述的转换皆不能出现二义性，转换函数也可以使用关键字explicit杜绝隐式转换，在转换函数的声明前加上；还有另外一种方式，就是定义一个功能相同的非转换函数替换转换函数

在可能会进行类型转换的类中，重载运算符有两种方法，一个是重载运算符和友元函数，另一个是单纯友元函数；前者需要更多的代码，后者则更加依赖转换
