#include <iostream>
#include"Stack.h"
using namespace std;
void test(int &sum)
{
	int x;
	cin >> x;
	if (x == 0)
		sum = 0;
	else
	{
		test(sum);
		sum += x;
	}
	cout << sum<< endl;
}

void Test(int& sum)
{
	SeqStack<int> s1;
	int x;
	sum = 0;
	cin >> x;
	while (x != 0)
	{
		s1.Push(x);
		cin >> x;
	}
	cout << sum << endl;
	while (!s1.IsEmpty())
	{
		s1.Pop(x);
		sum += x;
		cout << sum << endl;
	}
}
int main()
{
	int a = 5;
	test(a);
	//Test(a);
}


