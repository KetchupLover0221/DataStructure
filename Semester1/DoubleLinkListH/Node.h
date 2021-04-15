#ifndef __DBL_NODE_H__
#define __DBL_NODE_H__


// 双向链表结点类
template <class ElemType>
struct DblNode
{
	// 数据成员:
	ElemType data;				// 数据域
	DblNode<ElemType>* prior;	// 指向前驱结点的指针域
	DblNode<ElemType>* next;	// 指向后继结点的指针域
	int freq;					//访问频度
// 构造函数:
	DblNode();						// 无数据的构造函数
	DblNode(ElemType item,
		DblNode<ElemType>* priorlink = NULL,
		DblNode<ElemType>* nextlink = NULL,
		int freq =0);// 已知数据域和指针域建立结构
};


// 双向链表结点类的实现部分

template<class ElemType>
DblNode<ElemType>::DblNode()
// 操作结果：构造指针域为空的结点
{
	prior = NULL;
	next = NULL;
	freq = 0;
}

template<class ElemType>
DblNode<ElemType>::DblNode(ElemType item,
	DblNode<ElemType>* priorlink,
	DblNode<ElemType>* nextlink,
	int freq )
	// 操作结果：构造一个数据域为item、prior指针域为priorlink和next指针域为nextlink的结点
{
	data = item;
	prior = priorlink;
	next = nextlink;
	freq = 0;
}

#endif
