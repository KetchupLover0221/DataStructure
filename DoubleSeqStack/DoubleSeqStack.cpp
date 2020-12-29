// DoubleSeqStack.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"DoubleSeqStack.h"
using namespace std;
int main()
{
    DoubleSeqStack<int> s1;
    int a = 1, b = 2, c = 3;
    int out1 =0,out2 =0;
    cout << s1.IsEmpty(1) << endl;
    cout << s1.IsEmpty(2) << endl;
    s1.Push(a, 1);
    s1.Push(b, 1);
    s1.Push(c, 1);
    s1.Pop(out1, 1);
    s1.Push(c, 2);
    s1.Push(b, 2);
    s1.Push(a, 2);
    s1.Pop(out2, 2);
    s1.Pop(out2, 2);
    cout << out1 << endl;
    cout << out2 << endl;
}


