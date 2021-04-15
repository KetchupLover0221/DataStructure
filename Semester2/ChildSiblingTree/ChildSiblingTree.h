#pragma once
#include"ChildSiblingNode.h"
template <class type>
struct ChildSiblingTree
{
protected:
	TreeNode<type>* _root;
	//��������
	TreeNode<type>* CreateTree(type nodes[], int parents[], int n, int rootIndex);
	void Destroy(TreeNode<type>*& r);
	int GetHeight(TreeNode<type>* r) const;
	int GetNodeDegree(TreeNode<type>* r) const;             //�󵥸����r�Ķ�
	int GetDegree(TreeNode<type>* r) const;                 //����rΪ���ڵ�����Ķ�
	TreeNode<type>* GetFirstChild(TreeNode<type>* r) const;  //����r�ĵ�һ������
	TreeNode<type>* GetNextSibling(TreeNode<type>* r) const; //����r����һ���ֵ�

public:
	ChildSiblingTree() { _root = NULL; }               //Ĭ�Ϲ��캯��
	ChildSiblingTree(type nodes[], int parents[], int n); //���캯��
	virtual ~ChildSiblingTree() { Destroy(_root); }    //��������
	TreeNode<type>* GetRoot() const;                    //�õ����ĸ����
	int GetHeight() const { return GetHeight(_root); }
	int GetDegree() const { return GetDegree(_root); }
};

template <class type>
TreeNode<type>* ChildSiblingTree<type>::CreateTree(type nodes[], int parents[], int n, int rootIndex)
{ //nodesΪ�ڵ��������飬parentsΪ��Ӧ��˫�ף�nΪ������
	if (rootIndex >= 0 && rootIndex < n)
	{
		TreeNode<type>* root = new TreeNode<type>(nodes[rootIndex]); //�������ڵ�
		TreeNode<type>* subRoot, * cur=NULL;
		for (int i = 0; i < n; i++)
		{ //����root�ĺ���
			if (parents[i] == rootIndex)
			{
				subRoot = CreateTree(nodes, parents, n, i); //�ݹ鹹������
				if (root->_firstChild == NULL)
				{ // �����ĸ�Ϊroot�ĵ�һ������
					root->_firstChild = subRoot;
				}
				else
				{ // subRoot�����ĸ�Ϊcur����һ���ֵ�
					cur->_nextSibling = subRoot;
				}
				cur = subRoot; //cur��¼��ǰ�������ĺ���
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
{ //��װ�����������ҪΪ�˱������NULL��_firstChildʱ������������
	if (r == NULL)
		return NULL;
	else
		return r->_firstChild;
}

template <class type>
TreeNode<type>* ChildSiblingTree<type>::GetNextSibling(TreeNode<type> * r) const
{ //��װ�����������ҪΪ�˱������NULL��_nextSiblingʱ������������
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
{ //�󵥸����r�Ķ�
	TreeNode<type>* p;
	int count = 0;
	for (p = GetFirstChild(r); p != NULL; p = GetNextSibling(p))
		count++;
	return count;
}

template <class type>
int ChildSiblingTree<type>::GetDegree(TreeNode<type> * r) const
{ //����rΪ���ڵ�����Ķ�
	TreeNode<type>* p;
	int maxDegree = GetNodeDegree(r);
	for (p = GetFirstChild(r); p != NULL; p = GetNextSibling(p))
	{
		int subMaxDegree = GetDegree(p);
		maxDegree = (maxDegree > subMaxDegree) ? maxDegree : subMaxDegree;
	}
	return maxDegree;
}