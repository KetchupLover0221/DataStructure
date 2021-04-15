#include "ChildSiblingTree.h"
#include<iostream>
using namespace std;
int main()
{
	char items[] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H' };
	int parents[] = { -1, 0, 0, 0, 1, 1, 4, -1 };
	int n = 8;
	ChildSiblingTree<char> t(items, parents, n);
	//           A           H
	//     B    C    D   
	//   E  F      
	// G        
	cout << "树的度为：" << t.GetDegree() << endl;
	cout << "树的高度为：" << t.GetHeight() << endl;

}
