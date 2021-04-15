#include "UFSets.h"
int main()
{
	const int n = 6;

	int a[n] = { 1, 2, 3, 4, 5, 6 };

	int b[n] = { 1, 3, 3, 2, 1 };
	int c[n] = { 2, 4, 5, 6, 3 };
	//			   1
	//		2	   6    	3
	//		              4   5
	UnionFindSets<int> Set1(a, n);
	Set1.Show();
	cout << endl;
	cout << Set1.CollapsingFind(3) << endl;
	cout<< "Depth Union";
	for (int i = 0; i < n; i++)
	{
		Set1.DepthUnion(b[i], c[i]);
		//cout << Set1.CollapsingFind(3) << endl;
	}
	Set1.Show();
	cout << Set1.CollapsingFind(3) << endl;
}