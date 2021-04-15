#include <iostream>
#include"OrdList.h"
using namespace std;
int main()
{
	int a[5] = { 1,2,4,5,6 };
	int b[5] = { 1,2,3,3,4 };
	int e = 7;
	int f = 3;
	int s = 2, t = 6;
	OrdList<int> l1(a, 5, 10);
	OrdList<int> l2(b, 5, 10);
	cout << "l1:" << endl;
	l1.Show();
	l1.Insert(e);
	l1.Show();
	cout << "l2:" << endl;
	l2.Show();
	l2.DeleteElem(f);
	l2.Show();
	OrdList<int> l3( l1,l2);
	cout << "l3 = l1 + l2: " << endl;
	l3.Show();
	l3.DeleteElemBtw(s, t);
	l3.Show();
}


