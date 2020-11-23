# Number 类

## real类

### 一、简介

以 double 类型的分子和分母的分数形式记录数值，拥有已知数性质标识、有限大标识、名称。其定义、初始化和使用的简便性与科学性应不输于 double 类型。不过由于这是一种对象（C++ class），运算效率不及 double 类。

### 二、成员数据

#### 1. 公有成员

- `bool known`已知数性质标识
- `string name`对象名称

#### 2. 私有成员

- `bool finite`有限大标识
- `double denominator`分母
- `double numerator`分子

### 三、成员函数

#### 1. 构造函数（real.cpp）

- 默认构造函数
- 复制构造函数
- 一个 double 参数的构造函数
- 两个 double 参数的构造函数，分别为分子和分母

#### 2. 功能函数（real.cpp）

- `abs()`以新 real 对象返回绝对值
- `fabs()`以 double 返回绝对值
- `to_double()`以 double 返回值
- `zero()`判断是否为零
- `infinite()` 判断是否无穷大
- `denominator()`以 double 返回分母
- `numerator()`以 double 返回分子
- `print()`流输出到屏幕

#### 3. 操作运算对象本身的函数（object_operation.cpp）

- `reciprocal()`倒数
- `rabs()`变为绝对值
- `add()`增加一个数
- `subtract()`减小一个数
- `multiply()`倍乘一个数
- `divide()`除掉一个数

#### 4. 运算符重载（operator.cpp）

下面省略`operator`符号

- `<<()`移位重载，输出到流
- `>>()`移位重载，从流读入
- `~()`倒数，返回新的 real 对象
- `&()`分子分母分别相加，返回新的 real 对象
- `|()`分子分母分别相减，返回新的 real 对象
- `+=()`复合加法赋值，返回 real 引用
- `-=()`复合减法赋值，返回 real 引用
- `*=()`复合乘法赋值，返回 real 引用
- `/=()`复合触发赋值，返回 real 引用
- `+()`加法，返回新的 real 对象
- `-()`减法，返回新的 real 对象
- `-()`取负，返回新的 real 对象
- `*()`乘法，返回新的 real 对象
- `/()`除法，返回新的 rea l对象
- `==()`判断相等
- `!=()`判断不相等
- `<()`判断小于
- `<=()`判断不大于
- `>()`判断大于
- `>=()`判断不小于

