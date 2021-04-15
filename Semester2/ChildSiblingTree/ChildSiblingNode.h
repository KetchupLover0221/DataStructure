#pragma once
#include<iostream>
using namespace std;
template <class type>
struct TreeNode
{
	type _data;
	TreeNode<type>* _firstChild;  //��һ�����ӵ�ָ����
	TreeNode<type>* _nextSibling; //��һ���ֵܵ�ָ����

	//���캯��
	TreeNode()
	{
		_firstChild = _nextSibling = NULL;
	}
	TreeNode(type data, TreeNode<type>* firstChild = NULL, TreeNode<type>* nextSibling = NULL)
		: _data(data), _firstChild(firstChild), _nextSibling(nextSibling) {}
};