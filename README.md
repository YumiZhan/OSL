# Object-oriented Scientific Library (OSL)

面向对象的科学计算库

## 简介

本项目是基于 GSL (GNU Scientific Library) 构建的用于解决数值方法问题的科学计算库，其主要形式为源文件和带有接口的动态链接库。OSL 使用面向对象的设计方式，可以极大地简化数值方法问题求解的程序设计，在工程或教学活动中能使用户更专注于问题本身而不是忙于思考具体的编写方式。



## 使用方式

在项目的 [Github 主页](https://github.com/YumiZhan/OSL) 中选择合适的分支（推荐 master 或 develop 分支）点击 “code” 按钮即可下载对应最新的源码用于查看，推荐使用 Visual Studio 作为 IDE。如果希望直接将该库用于编译 C/C++ 程序而不需要查看各功能的具体实现，请到 [Release 页面](https://github.com/YumiZhan/OSL/releases) 的 “Asset” 标签下载所需的包。如果遇到相关的问题，欢迎到 [Issues 栏目](https://github.com/YumiZhan/OSL/issues) 中讨论！OSL 各库的使用方式详见其 “使用方式” 标题下的内容。本项目依赖的额外资源被放在 “Dependent package backup” 目录中以便临时使用。



## Number 库

### real 类

#### 一、简介

以`double`类型数值为分子和分母的分数形式记录数值，拥有已知性标识、有限大标识。由于使用分数的方式记录数值，在数值计算过程中，它有效地规避了计算机内存有限地储存无限循环小数造成的精度损失，因次其运算精度不低于`double`类型。即使拥有更精确的运算和功能，其定义、初始化和使用的方式却与`double`类型几乎完全相同，使用者不会觉得难以接受。不过由于这是一种对象（C++ class），运算效率不及`double`类。

#### 二、使用方式

将 number.h 和 number.lib 放置到项目的同一个文件夹中，调用 real 或 complex 类前包含头文件（如`#include "number.h"`）。运行程序前，把 number.dll 放置在可执行文件（如 example.exe）所在的文件夹里。

#### 三、数据成员

##### (一) 私有

- `double _denominator`分母
- `double _numerator`分子

##### (二) 公有

- `bool known`已知性标识

#### 四、函数

##### (一) 构造函数 (real.cpp)

- 默认构造函数
- 复制构造函数
- 一个`double`参数的构造函数
- 两个`double`参数的构造函数，分别为分子和分母
- 使用 C 风格字符串来初始化
- 使用指向 `wchar_t` 类型的指针来初始化

##### (二) 功能函数 (real.cpp)

- `zero()`: 判断是否为零
- `infinite()`: 判断是否无穷大
- `denominator()`: 返回`double`的分母
- `numerator()`: 返回`double`的分子
- `print()`: 以 `double` 的形式打印，并输出一个回车
- `show()`: 以 “分子 / 分母” 的形式打印，并输出一个回车
- `to_radian()`: 将角度转换成弧度
- `to_degree()`: 将弧度转换成角度

##### (三) 操作运算对象本身的函数 (object_operation.cpp)

- `reciprocal()`: 倒数
- `rabs()`: 变为绝对值
- `add()`: 增大一个数
- `subtract()`: 减小一个数
- `multiply()`: 倍乘一个数
- `divide()`: 除去一个数

##### (四) 比较 (comparation.cpp)

- `larger_than()`: 判断大于
- `not_less_than()`: 判断不小于
- `less_than()`: 判断小于
- `not_larger_than()`: 判断不大于
- `equal_to()`: 判断一定精度下的绝对相等

##### (五) 运算符重载 (operator.cpp)

以下内容省略`operator`符号

###### 1. 类型转换

- `double()`: 返回 real 对象的 double 值

###### 2. 流输出和读入

- `<<()`: 移位重载，输出到流
- `>>()`: 移位重载，从流读入

###### 3. 特殊处理

- `~()`: 倒数
- `&()`: 分子分母分别相加
- `|()`: 分子分母分别相减

###### 4. 复合赋值

- `+=()`: 复合加法赋值
- `-=()`: 复合减法赋值
- `*=()`: 复合乘法赋值
- `/=()`: 复合触发赋值

###### 5. 自增和自减运算

- `++()`: 自增
- `--()`: 自减

###### 6. 基本运算

- `+()`: 加法
- `-z()`: 减法
- `-()`: 取负
- `*()`: 乘法
- `/()`: 除法

###### 7. 逻辑运算

- `==()`: 相等
- `!=()`: 不相等
- `<()`: 小于
- `<=()`: 小于等于
- `>()`: 大于
- `>=()`: 大于等于
- `!()`: 是否未知

##### (六) `<cmath>`函数重载 (overload_cmath.cpp)

参考：http://www.cppfans.com/cbknowledge/reference/cmath/

- `cos()`: 余弦
- `cosh()`: 双曲余弦
- `sin()`: 正弦
- `sinh()`: 双曲正弦
- `tan()`: 正切
- `tanh()`: 双曲正切
- `acos()`: 反余弦
- `acosh()`: 反双曲余弦
- `asin()`: 反正弦
- `asinh()`: 反双曲正弦
- `atan()`: 反正切
- `atan2()`: 双参数的反正切
- `atanh()`: 反双曲正切
- `exp(x)`: 计算 $e^x$
- `exp2(x)`: 计算 $2^x$
- `expm1(x)`: 计算 $e^x - 1$
- `frexp(num, *exponent)`: 把`num`分解成有效数字和指数，返回有效数字，指数存入`exponent`中
- `ldexp(num, exponent)`: `num`乘以 2 的`exponent`次幂
- `log()`: 取对数
- `ln()`: 以 e 为底的对数
- `log2()`: 以 2 为底的对数
- `log10()`: 以 10 为底的对数
- `lg()`: 同上
- `log1p(x)`: 计算 $\ln(1+x)$
- `copysign(x, y)`: 返回由 y 的符号和 x 的绝对值组成的数
- `modf(x, *integer)`: 返回 x 的小数部分，整数部分存入`integer`
- `pow(x, y)`: 返回 x 的 y 次幂
- `pow2()`: 平方
- `pow10()`: 10 次方
- `sqrt()`: 平方根
- `hypot(x, y)`: 计算 $\sqrt{x^2+y^2}$
- `ceil()`: 向上取整
- `round()`: 四舍五入取整
- `floor()`: 向下取整
- `trunc()`: 丢弃小数部分取整
- `fabs()`: 绝对值
- `fmod(x, y)`: 返回 x 除以 y 的余数



### complex 类

#### 一、简介

以`real`类成员为实部和虚部的形式记录复数的值。其定义、初始化和使用方式同`double`类型相似，拥有许多处理复数的函数。

#### 二、数据成员

##### (一) 私有

- _real
- _imag

##### (二) 公有

- known

#### 三、函数

##### (一) 构造函数 (complex.cpp)

- 默认构造函数
- 复制构造函数
- 双 num 对象构造函数

##### (二) 功能函数 (complex.cpp)

- `real()`: 返回实部
- `imag()`: 返回虚部



## Matrix 库

### matrix 类

#### 一、简介

采用类模板方法，用二维指针指向动态分配的数组空间，基本类型（元素类型）默认为`class real`，可以自定义为其它类型。拥有专业的矩阵运算函数，同时利用运算符重载，极大地简化了矩阵运算的编写方式。