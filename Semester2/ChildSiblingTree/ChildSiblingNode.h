#pragma once
#include<iostream>
using namespace std;
template <class type>
struct TreeNode
{
	type _data;
	TreeNode<type>* _firstChild;  //第一个孩子的指针域
	TreeNode<type>* _nextSibling; //下一个兄弟的指针域

	//构造函数
	TreeNode()
	{
		_firstChild = _nextSibling = NULL;
	}
	TreeNode(type data, TreeNode<type>* firstChild = NULL, TreeNode<type>* nextSibling = NULL)
		: _data(data), _firstChild(firstChild), _nextSibling(nextSibling) {}
};