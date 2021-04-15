#include "Polynomial.h"	// 多项式类
int main(void)
{
    Polynomial a;
    PolyItem it(1,2);
    a.SetZero();
    a.InsItem(it);
    //a.Display();
    a.Cal(3);
    a.Qd();
    a.Display();
}