
#include"SqList.h"
#include <iostream>
using namespace std;
int main()
{
	SqList<int> l1(10);
	int e = 0;
	int b[6] = { 1,2,2,2,3,2 };
	SqList<int> l2(b, 6, 10);
	l1.InsertElem(1);
	l1.InsertElem(2);
	l1.InsertElem(3);
	l1.InsertElem(3);
	l1.InsertElem(0);
	l1.InsertElem(4);
	l1.InsertElem(5);
	l1.InsertElem(3);
	l1.Show();
	l1.Deletemin(e);//	1/(1)
	l1.Show();
	e = 3;
	l1.DeleteElemE(e);//	1/(2)
	l1.Show();
	l2.Show();
	l2.DeleteElemS();
	l2.Show();
	l2.Inverse();
	l2.Show();

}


