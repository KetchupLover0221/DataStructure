// WuXiangTu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include"WuXiangTu.h"
int main()
{
	char vex[] = { 'A', 'B', 'C','D','E' };
	int m[5][5] = {
	{0, 0, 1, 0, 0},
	{0, 0, 0, 1, 0},
	{1, 0, 0, 1, 0},
	{0, 1, 1, 0, 0},
	{0, 0, 0, 0, 0},
	};
	WuXiangTu<char>g(vex, 5, 5);
	for (int u = 0; u < 5; u++)
		for (int v = 0; v < 5; v++)
			if (m[u][v] != 0) g.InsertArc(u, v, m[u][v]);

	g.Display();

	if (!g.FindPath(0, 1))
	{
		cout << "Not Exist." << endl;
	}
	if (!g.FindPath(0, 4))
	{
		cout << "Not Exist." << endl;
	}
}

