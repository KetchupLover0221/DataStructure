#include"LinkList.h"
#include <iostream>

int main()
{
	LinkList<double> la;
	la.InsertElem(0);
	la.InsertElem(2);
	la.InsertElem(3);
	la.InsertElem(3);
	la.InsertElem(4);
	la.Show();
	la.InsertElemI(2, 1);
	la.InsertElemI(1, -1);
	la.Show();
	la.DeleteElemI(1);
	la.DeleteElemI(2);
	la.Show();
	int a[4] = { 3,4,5,6 };
	int b[5] = { 4,5,6,7,8 };
	LinkList<int> l1(a, 4);
	LinkList<int> l2(b, 5);
	l1.Show();
	l2.Show();
	l1.AddList(l2);
	l1.Show();
}


