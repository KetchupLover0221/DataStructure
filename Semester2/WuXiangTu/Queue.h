#ifndef __SQ_QUEUE_H__
#define __SQ_QUEUE_H__
#include<iostream>
using namespace std;
// ѭ��������

template<class ElemType>
class SeqQueue
{
protected:
	int front, rear;									 // ��ͷ��β�±�
	int maxSize;										 // �������� 
	ElemType* elems;									 // Ԫ�ش洢�ռ�
	int length;											 // Ԫ�ظ���

public:
	SeqQueue(int size = 9999);					 // ���캯��
	virtual ~SeqQueue();								 // ��������
	int GetLength() const;								 // ����г���			 
	bool IsEmpty() const;								 // �ж϶����Ƿ�Ϊ��
	bool IsFull() const;
	void Clear();										 // ���������
	void DelQueue();					     // ���Ӳ���
	void GetHead(ElemType& e) const;				     // ȡ��ͷ����
	void EnQueue(const ElemType e);				     // ��Ӳ���
	void DisplayQueue();
	SeqQueue(const SeqQueue<ElemType>& q);			 // ���ƹ��캯��
	SeqQueue<ElemType>& operator =(const SeqQueue<ElemType>& q);// ��ֵ�������
};

// ѭ���������ʵ�ֲ���

template<class ElemType>
SeqQueue<ElemType>::SeqQueue(int size)
// �������������һ������Ϊsize�Ŀ�ѭ������
{
	maxSize = size;							// ���ö�������
	elems = new ElemType[maxSize];			// ����Ԫ�ش洢�ռ�
	rear = front = 0;						// ��ʼ����ͷ���β
	length = 0;
}

template <class ElemType>
SeqQueue<ElemType>::~SeqQueue()
// ������������ٶ���
{
	delete[]elems;							// �ͷ�Ԫ�ش洢�ռ�
	length = 0;
}


template<class ElemType>
int SeqQueue<ElemType>::GetLength() const
// ������������ض��г���			 
{
	return length ;
}

template<class ElemType>
bool SeqQueue<ElemType>::IsEmpty() const
// ��������������Ϊ�գ��򷵻�true�����򷵻�false
{
	return (length ==0);
}

template<class ElemType>
bool SeqQueue<ElemType>::IsFull() const
// ��������������Ϊ�գ��򷵻�true�����򷵻�false
{
	return (length == maxSize);
}

template<class ElemType>
void SeqQueue<ElemType>::Clear()
// �����������ն���
{
	rear = front = 0;
	length = 0;
}

template<class ElemType>
void SeqQueue<ElemType>::DelQueue()
// ���������������зǿգ���ôɾ����ͷԪ�أ�����e������ֵ����������SUCCESS,
// ����������UNDER_FLOW��
{
	if (!IsEmpty()) {	// ���зǿ�
		front = (front + 1) % maxSize;		// frontָ����һԪ��
		length--;
	}
	else	// ����Ϊ��
		cout<<" UNDER_FLOW";
}

template<class ElemType>
void SeqQueue<ElemType>::GetHead(ElemType& e) const
// ���������������зǿգ���ô��e���ض�ͷԪ�أ���������SUCCESS,
// ����������UNDER_FLOW��
{
	if (!IsEmpty()) {	    // ���зǿ�
		e = elems[front];		// ��e���ض�ͷԪ��
	}
	else
		cout << " UNDER_FLOW";
}

template<class ElemType>
void SeqQueue<ElemType>::EnQueue(const ElemType e)
// ��������������������������OVER_FLOW,
// �������Ԫ��eΪ�µĶ�β������SUCCESS
{
	if (IsFull())
		cout<<"OVER_FLOW";
	else {	// ����δ������ӳɹ�
		length++;
		elems[rear] = e;					// ����eΪ�¶�β
		rear = (rear + 1) % maxSize;		// rearָ���¶�β
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
// ����������ɶ���q�����¶���--���ƹ��캯��
{
	maxSize = q.maxSize;				    // ���ö�������
	if (elems != NULL) delete[]elems;		// �ͷŴ洢�ռ�
	elems = new ElemType[maxSize];			// ����洢�ռ�
	front = q.front;						// ���ƶ�ͷλ��	
	rear = q.rear;						// ���ƶ�βλ��
	for (int i = front; i != rear; i = (i + 1) % maxSize)
		elems[i] = q.elems[i];
}

template<class ElemType>
SeqQueue<ElemType>& SeqQueue<ElemType>::operator =(const SeqQueue<ElemType>& q)
// ���������������q��ֵ����ǰ����--��ֵ�������
{
	if (&q != this) 
	{
		maxSize = q.maxSize;				// ���ö�������
		if (elems != NULL) delete[]elems;	// �ͷŴ洢�ռ�
		elems = new ElemType[maxSize];		// ����洢�ռ�
		front = q.front;					// ���ƶ�ͷλ��	
		rear = q.rear;					// ���ƶ�βλ��
		for (int i = front; i != rear; i = (i + 1) % maxSize)
		{
			elems[i] = q.elems[i];
			length++;
		}
		
	}
	return *this;
}

#endif
