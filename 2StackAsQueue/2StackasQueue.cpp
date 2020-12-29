
#include <iostream>
#include"FakeQueue.h"
using namespace std;
int main()
{
	AsQueue AQ;
	int a = 2;
	int b = 3;
	int c = 0;
	cout << AQ.IsEmpty() << endl;
	AQ.EnQueue(a);
	AQ.EnQueue(b);
	AQ.DelQueue(c);
	cout << c << endl;
	cout << AQ.IsEmpty() << endl;
	return 0;
}



