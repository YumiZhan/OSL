// Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "matrix.h"

int main()
{
    matrix m(1, 5);
    cout << m[2][1] << endl;
    m.print();
    return 0;
}
