#include"BinNode.h"
#include<iostream>

template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode()  //无参
{
	leftChild = rightChild = NULL;
}

template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode(const ElemType& val,
	BinTreeNode<ElemType>* lChild ,
	BinTreeNode<ElemType>* rChild )
{
	data = val;		// 数据元素值
	leftChild = lChild;	// 左孩子
	rightChild = rChild;	// 右孩子
}
