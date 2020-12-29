#include <iostream>
#include"Queue.h"
using namespace std;

void Yanghui(int n)
{
	SeqQueue<int> qa;
	qa.EnQueue(1);
	qa.EnQueue(1);
	for (int r = 2; r <= n; r++)//算n行
	{
		for (int p = 1; p < r; p++)
		{
			int h1 = 0, h2 = 0;
			qa.GetHead(h1);
			qa.DelQueue();
			qa.GetHead(h2);
			int temp = h1 + h2;
			qa.EnQueue(temp);
		}
		qa.EnQueue(1);//队尾
	}

	int L = qa.GetLength();
	for (int t = 0; t < L; t++)//遍历输出
	{
		int a = 0;
		qa.GetHead(a);
		qa.DelQueue();
		cout << a << " ";
	}
	cout << endl;
}

int main()
{
	SeqQueue<int> q1(3);
	int a = 2;
	int b = 3;
	int c = 4;
	int d = 0;
	cout << q1.IsEmpty() << endl << q1.IsFull() << endl;
	q1.EnQueue(a);
	q1.EnQueue(b);
	q1.EnQueue(c);
	cout << q1.IsEmpty() << endl << q1.IsFull() << endl;
	q1.DelQueue();
	q1.GetHead(d);
	cout << d << endl;
	Yanghui(5);
}

