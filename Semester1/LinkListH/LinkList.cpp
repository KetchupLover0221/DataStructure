#include "LinkList.h"		// 单链表类

int main(void)
{
	LinkList<double> la;
	int e = 3;
	la.InsertElem(1);
	la.InsertElem(2);
	la.InsertElem(3);
	la.InsertElem(3);
	la.InsertElem(4);
	la.InsertElem(5);
	la.Show();
	la.Inverse();
	la.Show();
	la.LocateElem(4);
	la.CountE(e);
	return 0;               // 返回值0, 返回操作系统
}
