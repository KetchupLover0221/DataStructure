#include"BinNode.h"
#include<iostream>

template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode()  //�޲�
{
	leftChild = rightChild = NULL;
}

template <class ElemType>
BinTreeNode<ElemType>::BinTreeNode(const ElemType& val,
	BinTreeNode<ElemType>* lChild ,
	BinTreeNode<ElemType>* rChild )
{
	data = val;		// ����Ԫ��ֵ
	leftChild = lChild;	// ����
	rightChild = rChild;	// �Һ���
}
