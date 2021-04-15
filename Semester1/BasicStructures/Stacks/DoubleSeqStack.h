#ifndef __DoubleSeqStack_H__
#define __DoubleSeqStack_H__
using namespace std;


// 顺序栈模板类
template<class ElemType>
class DoubleSeqStack
{
protected:
	// 顺序栈的数据成员:
	int top;										// 栈1栈顶
	int tail;										// 栈2栈顶
	int maxSize;									// 栈的最大容量 
	ElemType* elems;								// 元素存储空间
	const int num =2;										// 栈编号

public:
	//  顺序栈的方法声明及重载编译系统默认方法声明:
	DoubleSeqStack(int size = 1000);				// 构造函数
	virtual ~DoubleSeqStack();							// 析构函数
	int GetLength(int num) const;							// 求栈的长度			 
	bool IsEmpty(int num) const;							// 判断栈是否为空
	void Clear();									// 将栈清空
	void Push(const ElemType e,int num);				    // 入栈
	void Pop(ElemType& e, int num);					    // 出栈
};


// 顺序栈类的实现部分

template<class ElemType>
DoubleSeqStack<ElemType>::DoubleSeqStack(int size)
// 操作结果：构造一个最大容量为size的空栈
{
	maxSize = size;						// 栈的最大容量
	if (elems != NULL) delete[]elems;	// 释放已有存储空间
	elems = new ElemType[maxSize];		// 分配新的存储空间
	top = -1;
	tail = maxSize;
}

template<class ElemType>
DoubleSeqStack<ElemType>::~DoubleSeqStack()
// 操作结果：销毁栈
{
	delete[]elems;					// 释放栈的存储空间
}

template <class ElemType>
int DoubleSeqStack<ElemType>::GetLength(int num) const
// 操作结果：返回栈中元素个数
{
	if (num == 1)
		return top + 1;
	else
		return tail - 1;
}

template<class ElemType>
bool DoubleSeqStack<ElemType>::IsEmpty(int num) const
// 操作结果：如栈为空，则返回true，否则返回false
{
	if (num == 1)
		return top == -1;
	else
		return  tail == maxSize;
}

template<class ElemType>
void DoubleSeqStack<ElemType>::Clear()
// 操作结果：清空栈
{
	top = -1;
	tail = maxSize;
}


template<class ElemType>
void DoubleSeqStack<ElemType>::Push(const ElemType e, int num)

{
	if (top == tail -1) // 栈已满
		cout<< "OVER_FLOW";
	else 
	{	
		if(num ==1)
			elems[++top] = e;	// 将元素e追加到栈1顶 
		if (num == 2)
			elems[--tail] = e;// 将元素e追加到栈2顶 
	}
}



template<class ElemType>
void DoubleSeqStack<ElemType>::Pop(ElemType& e, int num)
{
	if (IsEmpty(num))	 // 栈空
		cout <<"UNDER_FLOW";
	else 
	{ 
		if(num ==1)
		e = elems[top--]; // 用e返回栈顶元素
		if (num == 2)
			e = elems[tail++];

	}
}



#endif
