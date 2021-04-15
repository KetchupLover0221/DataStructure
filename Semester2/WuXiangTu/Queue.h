#ifndef __SQ_QUEUE_H__
#define __SQ_QUEUE_H__
#include<iostream>
using namespace std;
// 循环队列类

template<class ElemType>
class SeqQueue
{
protected:
	int front, rear;									 // 队头队尾下标
	int maxSize;										 // 队列容量 
	ElemType* elems;									 // 元素存储空间
	int length;											 // 元素个数

public:
	SeqQueue(int size = 9999);					 // 构造函数
	virtual ~SeqQueue();								 // 析构函数
	int GetLength() const;								 // 求队列长度			 
	bool IsEmpty() const;								 // 判断队列是否为空
	bool IsFull() const;
	void Clear();										 // 将队列清空
	void DelQueue();					     // 出队操作
	void GetHead(ElemType& e) const;				     // 取队头操作
	void EnQueue(const ElemType e);				     // 入队操作
	void DisplayQueue();
	SeqQueue(const SeqQueue<ElemType>& q);			 // 复制构造函数
	SeqQueue<ElemType>& operator =(const SeqQueue<ElemType>& q);// 赋值语句重载
};

// 循环队列类的实现部分

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(int size)
// 操作结果：构造一个容量为size的空循环队列
{
	maxSize = size;							// 设置队列容量
	elems = new ElemType[maxSize];			// 分配元素存储空间
	rear = front = 0;						// 初始化队头与队尾
	length = 0;
}

template <class ElemType>
SeqQueue<ElemType>::~SeqQueue()
// 操作结果：销毁队列
{
	delete[]elems;							// 释放元素存储空间
	length = 0;
}


template<class ElemType>
int SeqQueue<ElemType>::GetLength() const
// 操作结果：返回队列长度			 
{
	return length ;
}

template<class ElemType>
bool SeqQueue<ElemType>::IsEmpty() const
// 操作结果：如队列为空，则返回true，否则返回false
{
	return (length ==0);
}

template<class ElemType>
bool SeqQueue<ElemType>::IsFull() const
// 操作结果：如队列为空，则返回true，否则返回false
{
	return (length == maxSize);
}

template<class ElemType>
void SeqQueue<ElemType>::Clear()
// 操作结果：清空队列
{
	rear = front = 0;
	length = 0;
}

template<class ElemType>
void SeqQueue<ElemType>::DelQueue()
// 操作结果：如果队列非空，那么删除队头元素，并用e返回其值，函数返回SUCCESS,
// 否则函数返回UNDER_FLOW，
{
	if (!IsEmpty()) {	// 队列非空
		front = (front + 1) % maxSize;		// front指向下一元素
		length--;
	}
	else	// 队列为空
		cout<<" UNDER_FLOW";
}

template<class ElemType>
void SeqQueue<ElemType>::GetHead(ElemType& e) const
// 操作结果：如果队列非空，那么用e返回队头元素，函数返回SUCCESS,
// 否则函数返回UNDER_FLOW，
{
	if (!IsEmpty()) {	    // 队列非空
		e = elems[front];		// 用e返回队头元素
	}
	else
		cout << " UNDER_FLOW";
}

template<class ElemType>
void SeqQueue<ElemType>::EnQueue(const ElemType e)
// 操作结果：如果队列已满，返回OVER_FLOW,
// 否则插入元素e为新的队尾，返回SUCCESS
{
	if (IsFull())
		cout<<"OVER_FLOW";
	else {	// 队列未满，入队成功
		length++;
		elems[rear] = e;					// 插入e为新队尾
		rear = (rear + 1) % maxSize;		// rear指向新队尾
	}
}

template<class ElemType>
void SeqQueue<ElemType>::DisplayQueue()
{
	char tmp;
	while(!IsEmpty())
	{
		GetHead(tmp);
		cout << tmp;
		DelQueue();
	}


}

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(const SeqQueue<ElemType>& q)
// 操作结果：由队列q构造新队列--复制构造函数
{
	maxSize = q.maxSize;				    // 设置队列容量
	if (elems != NULL) delete[]elems;		// 释放存储空间
	elems = new ElemType[maxSize];			// 分配存储空间
	front = q.front;						// 复制队头位置	
	rear = q.rear;						// 复制队尾位置
	for (int i = front; i != rear; i = (i + 1) % maxSize)
		elems[i] = q.elems[i];
}

template<class ElemType>
SeqQueue<ElemType>& SeqQueue<ElemType>::operator =(const SeqQueue<ElemType>& q)
// 操作结果：将队列q赋值给当前队列--赋值语句重载
{
	if (&q != this) 
	{
		maxSize = q.maxSize;				// 设置队列容量
		if (elems != NULL) delete[]elems;	// 释放存储空间
		elems = new ElemType[maxSize];		// 分配存储空间
		front = q.front;					// 复制队头位置	
		rear = q.rear;					// 复制队尾位置
		for (int i = front; i != rear; i = (i + 1) % maxSize)
		{
			elems[i] = q.elems[i];
			length++;
		}
		
	}
	return *this;
}

#endif
