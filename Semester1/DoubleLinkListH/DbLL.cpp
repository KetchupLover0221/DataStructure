#include "DbLL.h"		// 双向循环链表类

int main(void)
{
	int a[5] = { 2,3,6,4,5 };
	int e = 6;
	DblLinkList<int> la(a,5);
	la.Show();
	la.LocateElem(e);
	la.Show();
	la.LocateElem(3);
	la.LocateElem(3);
	la.Show();
}

