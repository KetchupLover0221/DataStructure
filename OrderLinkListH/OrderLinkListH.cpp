
#include <iostream>
#include"Orderll.h"
int main()
{
    int a[5] = { 1,4,3,2,5 };
    LinkList<int> l1(a, 5);
    l1.Show();
    l1.InsertElemE(3);
    l1.Show();
    l1.DeleteElemE(3);
    l1.Show();
}

