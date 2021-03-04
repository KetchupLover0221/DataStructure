#include "BInTree.h"
#include <iostream>
using namespace std;
int main()
{
    BinaryTree<string> t1("#");

    t1.CreateBinTree_PreOrder(); //124##5##3#6##

    t1.PreOrder();
    cout << endl;

    t1.PreOrder_NoRecurve();
    cout << endl;

    t1.InOrder();
    cout << endl;

    t1.InOrder_NoRecurve();
    cout << endl;

    t1.PostOrder();   
    cout << endl;

    t1.PostOrder_NoRecurve();
    cout << endl;

    t1.LevelOrder();
    cout << endl;

   cout<< t1.GetDepth()<<endl;

   cout << t1.GetLeafNum() << endl;
    
   t1.ExchangeLeftRight();
   t1.PreOrder();
   cout << endl;
   

}


