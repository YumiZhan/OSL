// Matrix.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include "matrix.h"

int main()
{
    ifstream ifile("..\\matrix\\matrix.txt");
    matrix m("..\\matrix\\matrix.txt");
    m.print();
    return 0;
}
