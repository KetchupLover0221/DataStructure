#include"Stack.h"
#include <iostream>
using namespace std;
void Zhongzhui()
{
    char ch;//输入
    char Pch;//前一位
    char sy;//操作符
    int a =0, x, y;
    int Pint = 0;
    SeqStack<int> num(999);
    SeqStack<char> Sym(999);

    Sym.Push('#');//操作符栈首
    Pch = '#';
    int stop = 0;
    cout << "输入表达式" << endl;

    ch = getchar();

    while (stop == 0)//到#停止
    {
        if (isdigit(ch) and Pint ==0)//数字
        {
          a = int(ch) - 48;
          Pint = a;
          num.Push(a);//入数字栈
        }

        else if (isdigit(ch) and Pint != 0)//两位以上数字
        {
            num.Pop(a);
            a = a * 10 + int(ch) - 48;
            Pint = a;
            num.Push(a);//入数字栈
        }
        else if (ch == '#')//停止
        {
            Pint = 0;
            sy = ch;
            Sym.Push(sy);
            Pch = sy;
            break;
        }
        else//操作符
        {
            Pint = 0;
            if (ch == '(')
            {
                sy = ch;
                Sym.Push(sy);
                Pch = sy;
            }

            if (ch == ')')
            {
                Sym.Pop(sy);
                num.Pop(y);
                num.Pop(x);
                if (sy == '+')
                {
                    a = x + y;
                }
                if (sy == '-')
                {
                    a = x - y;
                }
                if (sy == '*')
                {
                    a = x * y;
                }
                if (sy == '/')
                {
                    a = x / y;
                }
                num.Push(a);
                Sym.Pop(sy);
                //Sym.Pop(sy);
                Pch = ')';
            }

            if (ch == '+' )
            {
                if (Pch == '(' or Pch == '#' or Pch == ')')
                {
                    sy = ch;
                    Sym.Push(sy);
                    Pch = sy;
                }
                else 
                {
                    Sym.Pop(sy);
                    num.Pop(y);
                    num.Pop(x);
                    if (sy == '+')
                    {
                        a = x + y;
                    }
                    if (sy == '-')
                    {
                        a = x - y;
                    }
                    if (sy == '*')
                    {
                        a = x * y;
                    }
                    if (sy == '/')
                    {
                        a = x / y;
                    }
                    num.Push(a);
                    sy = ch;
                    Sym.Push(sy);
                    Pch = sy;
                }
            }

            if (ch == '-')
            {
                if (Pch == '(' or Pch == '#' or Pch == ')')
                {
                    sy = ch;
                    Sym.Push(sy);
                    Pch = sy;
                }
                else
                {
                    Sym.Pop(sy);
                    num.Pop(y);
                    num.Pop(x);
                    if (sy == '+')
                    {
                        a = x + y;
                    }
                    if (sy == '-')
                    {
                        a = x - y;
                    }
                    if (sy == '*')
                    {
                        a = x * y;
                    }
                    if (sy == '/')
                    {
                        a = x / y;
                    }
                    num.Push(a);
                    sy = ch;
                    Sym.Push(sy);
                    Pch = sy;
                }
            }

            if (ch == '*')
            {
                if (Pch == '(' or Pch == '#' or Pch == '+' or Pch == '-' or Pch == ')')
                {
                    sy = ch;
                    Sym.Push(sy);
                    Pch = sy;
                }
                else
                {
                    Sym.Pop(sy);
                    num.Pop(y);
                    num.Pop(x);
                    if (sy == '*')
                    {
                        a = x * y;
                    }
                    if (sy == '/')
                    {
                        a = x / y;
                    }
                    num.Push(a);
                    sy = ch;
                    Sym.Push(sy);
                    Pch = sy;
                }
            }

            if (ch == '/')
            {
                if (Pch == '(' or Pch == '#' or Pch == '+' or Pch == '-' or Pch == ')')
                {
                    sy = ch;
                    Sym.Push(sy);
                    Pch = sy;
                }
                else
                {
                    Sym.Pop(sy);
                    num.Pop(y);
                    num.Pop(x);
                    if (sy == '*')
                    {
                        a = x * y;
                    }
                    if (sy == '/')
                    {
                        a = x / y;
                    }
                    num.Push(a);
                    sy = ch;
                    Sym.Push(sy);
                    Pch = sy;
                }
            }
        }
         ch = getchar();
    }
    Sym.Pop(sy);
    Sym.Pop(sy);
    {
        while (sy != '#')
        {
            num.Pop(y);
            num.Pop(x);
            if (sy == '+')
            {
                a = x + y;
            }
            if (sy == '-')
            {
                a = x - y;
            }
            if (sy == '*')
            {
                a = x * y;
            }
            if (sy == '/')
            {
                a = x / y;
            }
            num.Push(a);
            Sym.Pop(sy);
        }

         num.Pop(a);
         cout << a << endl;
    }
}
int main()
{
    Zhongzhui();
}


