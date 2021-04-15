#pragma once
#include"ChildSiblingNode.h"
template <class type>
struct ChildSiblingTree
{
protected:
	TreeNode<type>* _root;
	//辅助函数
	TreeNode<type>* CreateTree(type nodes[], int parents[], int n, int rootIndex);
	void Destroy(TreeNode<type>*& r);
	int GetHeight(TreeNode<type>* r) const;
	int GetNodeDegree(TreeNode<type>* r) const;             //求单个结点r的度
	int GetDegree(TreeNode<type>* r) const;                 //求以r为根节点的树的度
	TreeNode<type>* GetFirstChild(TreeNode<type>* r) const;  //求结点r的第一个孩子
	TreeNode<type>* GetNextSibling(TreeNode<type>* r) const; //求结点r的下一个兄弟

public:
	ChildSiblingTree() { _root = NULL; }               //默认构造函数
	ChildSiblingTree(type nodes[], int parents[], int n); //构造函数
	virtual ~ChildSiblingTree() { Destroy(_root); }    //析构函数
	TreeNode<type>* GetRoot() const;                    //得到树的根结点
	int GetHeight() const { return GetHeight(_root); }
	int GetDegree() const { return GetDegree(_root); }
};

template <class type>
TreeNode<type>* ChildSiblingTree<type>::CreateTree(type nodes[], int parents[], int n, int rootIndex)
{ //nodes为节点数据数组，parents为对应的双亲，n为结点个数
	if (rootIndex >= 0 && rootIndex < n)
	{
		TreeNode<type>* root = new TreeNode<type>(nodes[rootIndex]); //创建根节点
		TreeNode<type>* subRoot, * cur=NULL;
		for (int i = 0; i < n; i++)
		{ //查找root的孩子
			if (parents[i] == rootIndex)
			{
				subRoot = CreateTree(nodes, parents, n, i); //递归构建子树
				if (root->_firstChild == NULL)
				{ // 子树的根为root的第一个孩子
					root->_firstChild = subRoot;
				}
				else
				{ // subRoot子树的根为cur的下一个兄弟
					cur->_nextSibling = subRoot;
				}
				cur = subRoot; //cur记录当前遍历到的孩子
			}
		}
		return root;
	}
	else
		return NULL;
}

template <class type>
ChildSiblingTree<type>::ChildSiblingTree(type nodes[], int parents[], int n)
{
	_root = CreateTree(nodes, parents, n, 0);
}

template <class type>
void ChildSiblingTree<type>::Destroy(TreeNode<type>*& r)
{
}
template <class type>
TreeNode<type>* ChildSiblingTree<type>::GetRoot() const
{
	return _root;
}

template <class type>
TreeNode<type>* ChildSiblingTree<type>::GetFirstChild(TreeNode<type>* r) const
{ //封装这个函数，主要为了避免调用NULL的_firstChild时发生错误的情况
	if (r == NULL)
		return NULL;
	else
		return r->_firstChild;
}

template <class type>
TreeNode<type>* ChildSiblingTree<type>::GetNextSibling(TreeNode<type> * r) const
{ //封装这个函数，主要为了避免调用NULL的_nextSibling时发生错误的情况
	if (r == NULL)
		return NULL;
	else
		return r->_nextSibling;
}

template <class type>
int ChildSiblingTree<type>::GetHeight(TreeNode<type> * r) const
{
	if (r == NULL)
		return 0;
	else
	{
		TreeNode<type>* p;
		int subMaxHeight = 0;
		for (p = GetFirstChild(r); p != NULL; p = GetNextSibling(p))
		{
			int subHeight = GetHeight(p);
			subMaxHeight = (subMaxHeight > subHeight) ? subMaxHeight : subHeight;
		}
		return subMaxHeight + 1;
	}
}

template <class type>
int ChildSiblingTree<type>::GetNodeDegree(TreeNode<type> * r) const
{ //求单个结点r的度
	TreeNode<type>* p;
	int count = 0;
	for (p = GetFirstChild(r); p != NULL; p = GetNextSibling(p))
		count++;
	return count;
}

template <class type>
int ChildSiblingTree<type>::GetDegree(TreeNode<type> * r) const
{ //求以r为根节点的树的度
	TreeNode<type>* p;
	int maxDegree = GetNodeDegree(r);
	for (p = GetFirstChild(r); p != NULL; p = GetNextSibling(p))
	{
		int subMaxDegree = GetDegree(p);
		maxDegree = (maxDegree > subMaxDegree) ? maxDegree : subMaxDegree;
	}
	return maxDegree;
}