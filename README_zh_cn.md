# 面向对象的科学计算库（OSL）

Copyright (C) 2021 詹煜民，<https://github.com/YumiZhan>

## 简介

OSL 是基于 GNU 科学函数库（GSL）构建的用于解决数值计算问题的科学计算库。它使用面向对象的设计方式从而可以极大地简化数值方法求解的程序设计，使工程师更专注于解决工程问题本身而不用太费心于敲代码。



## 使用方式

### 查看源码

#### Github

在项目的 [Github 主页](https://github.com/YumiZhan/OSL) 中选择合适的分支（推荐 master 或 develop 分支）点击 “code” 按钮即可下载对应的源码。如果希望直接将该库用于编译 C/C++ 程序而不需要查看各功能的具体实现，请到 [Release 页面](https://github.com/YumiZhan/OSL/releases) 的 “Asset” 标签下载所需的包。如果遇到相关的问题，欢迎到 [Issues 栏目](https://github.com/YumiZhan/OSL/issues) 中讨论！OSL 各子库的使用方式详见其 “使用方式” 标题下的内容。本项目依赖的额外资源被放在 “Dependent package backup” 目录中以便临时使用。

#### Gitee

敬请期待~

### 链接库和运行时



## Number 库

### 类型别名说明

- `argument`和`arg`：一般用作函数参数的数字类型`const double&`的别名
- `agm_real`：用作`real`类相关函数的参数的数字类型`const real&`的别名
- `agm_cpl`：用作`complex`类相关函数的参数的数字类型`const complex&`的别名



### real 类

#### 一、简介

以`double`类型数值为分子和分母的分数形式记录数值，拥有已知性标识、有限大标识。由于使用分数的方式记录数值，在数值计算过程中，它有效地规避了计算机内存有限地储存无限循环小数造成的精度损失，因次其运算精度不低于`double`类型。即使拥有更精确的运算和功能，其定义、初始化和使用的方式却与`double`类型几乎完全相同，使用者不会觉得难以接受。不过由于这是一种对象（C++ class），运算效率不及`double`类。

#### 二、使用方式

将 number.h 和 number.lib 放置到项目的同一个文件夹中，调用 real 或 complex 类前包含头文件（如`#include "number.h"`）。运行程序前，把 number.dll 放置在可执行文件（如 example.exe）所在的文件夹里。

#### 三、数据成员

##### (一) 私有

- `double _denominator`：分母
- `double _numerator`：分子
- `simplify()`：调用 `simplify_fraction()` 函数化简对象分数

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

- `zero()`：判断是否为零
- `infinite()`：判断是否无穷大
- `denominator()`：返回`double`的分母
- `numerator()`：返回`double`的分子
- `print()`：以 `double` 的形式打印，并输出一个回车
- `show()`：以 “分子 / 分母” 的形式打印，并输出一个回车
- `to_radian()`：将角度转换成弧度
- `to_degree()`：将弧度转换成角度

##### (三) 操作自身的函数 (real_modifier.cpp.cpp)

- `rec()`：倒置
- `rabs()`：绝对值化
- `add()`：自增一个数
- `sub()`：自减一个数
- `mul()`：自乘一个数
- `div()`：自除一个数

##### (四) 比较 (real_comparation.cpp)

- `larger_than()`：判断大于
- `not_less_than()`：判断不小于
- `less_than()`：判断小于
- `not_larger_than()`：判断不大于
- `equal_to()`：判断一定精度下的绝对相等

##### (五) 运算符重载 (real_overload_operators.cpp)

以下内容省略`operator`符号

###### 1. 类型转换

- `double()`：返回 real 对象的 double 值

###### 2. 流输出和读入

- `<<()`：流输出
- `>>()`：流读取

###### 3. 特殊处理

- `~()`：倒数

###### 4. 复合赋值

- `+=()`：加法复合赋值
- `-=()`：减法复合赋值
- `*=()`：乘法复合赋值
- `/=()`：除法复合赋值
- `^=()`：数函数复合指赋值

###### 5. 自增和自减运算

- `++()`：自增
- `--()`：自减

###### 6. 基本运算

- 单目 `+()`：返回原值
- 单目 `-()`：返回相反数
- 双目 `+()`：加法
- 双目 `-()`：减法
- `*()`：乘法
- `/()`：除法
- `^()`：指数函数

###### 7. 逻辑运算

- `==()`：相等
- `!=()`：不相等
- `<()`：小于
- `<=()`：小于等于
- `>()`：大于
- `>=()`：大于等于
- `!()`：是否未知

##### (六) `<cmath>`函数重载 (real_overload_cmath.cpp)

参考：http://www.cppfans.com/cbknowledge/reference/cmath/

- `cos()`：余弦
- `cosh()`：双曲余弦
- `sin()`：正弦
- `sinh()`：双曲正弦
- `tan()`：正切
- `tanh()`：双曲正切
- `acos()`：反余弦
- `acosh()`：反双曲余弦
- `asin()`：反正弦
- `asinh()`：反双曲正弦
- `atan()`：反正切
- `atan2()`：双参数的反正切
- `atanh()`：反双曲正切
- `exp(x)`：计算 $e^x$
- `exp2(x)`：计算 $2^x$
- `expm1(x)`：计算 $e^x - 1$
- `frexp(num, *exponent)`：把`num`分解成有效数字和指数，返回有效数字，指数存入`exponent`中
- `ldexp(num, exponent)`：`num`乘以 2 的`exponent`次幂
- `log()`：取对数
- `ln()`：以 e 为底的对数
- `log2()`：以 2 为底的对数
- `log10()`：以 10 为底的对数
- `lg()`：同上
- `log1p(x)`：计算 $\ln(1+x)$
- `copysign(x, y)`：返回由 y 的符号和 x 的绝对值组成的数
- `modf(x, *integer)`：返回 x 的小数部分，整数部分存入`integer`
- `pow(x, y)`：返回 x 的 y 次幂
- `pow2()`：平方
- `pow10()`：10 次方
- `sqrt()`：平方根
- `hypot(x, y)`：计算 $\sqrt{x^2+y^2}$
- `ceil()`：向上取整
- `round()`：四舍五入取整
- `floor()`：向下取整
- `trunc()`：丢弃小数部分取整
- `fabs()`：绝对值
- `fmod(x, y)`：返回 x 除以 y 的余数



### complex 类

#### 一、简介

以`double`类成员为实部和虚部的形式记录复数的值。其定义、初始化和使用方式同`double`类型相似，拥有许多处理复数的函数。

#### 二、数据成员

##### (一) 私有

- `_real`：实部
- `_imag`：虚部

##### (二) 公有

- `known`：已知性标识

#### 三、函数

##### (一) 构造函数 (complex.cpp)

- 默认构造函数
- 复制构造函数
- 单`double`参数的构造函数
- 双`double`参数和一个模式标识的构造函数

##### (二) 功能函数 (complex.cpp)

- `console_print_rect()`：以  的形式输出到控制台
- `console_print_polar()`：以  的形式输出到控制台
- `real()`：返回实部
- `imag()`：返回虚部
- `abs()`：返回绝对值
- `abs2()`：返回绝对值的平方
- `agl()`：返回角度
- `logabs()`：返回绝对值的自然对数
- `conjugate()`：返回共轭复数
- `inverse()`：返回倒数
- `pow()`：指数函数
- `sqrt()`：开方

##### (三) 操作自身的函数 (complex_modifier.cpp)

- `add()`：自增一个复数
- `sub()`：自减一个复数
- `mul()`：自乘一个复数
- `div()`：自除一个复数
- `exc()`：交换实部和虚部
- `absc()`：将实部和虚部分别变为原来的绝对值

##### (四) 运算符重载 (complex_overload_operators.cpp)

- `<<()`：流输出
- `>>()`：流读取
- `~()`：返回共轭复数
- 单目 `+()`：返回原值
- 单目 `-()`：返回相反数
- 双目 `+()`：加法
- 双目 `-()`：减法
- `*()`：乘法
- `/()`：除法
- `^()`：指数函数
- `+=()`：加法复合赋值
- `-=()`：减法复合赋值
- `*=()`：乘法复合赋值
- `/=()`：除法复合赋值
- `^=()`：指数函数复合指赋值



### 其它实用函数 (number.cpp)

- `simplify_fraction()`：将过大或过小的指数同时减小或增大一个相同的值，从而限制分子和分母的取值范围，使其不至于过大或过小



## Matrix 库

### matrix 类

#### 一、简介

采用类模板方法，用二维指针指向动态分配的数组空间，基本类型（元素类型）默认为`class real`，可以自定义为其它类型。拥有专业的矩阵运算函数，同时利用运算符重载，极大地简化了矩阵运算的编写方式。