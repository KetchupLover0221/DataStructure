#ifndef __DoubleSeqStack_H__
#define __DoubleSeqStack_H__
using namespace std;


// ˳��ջģ����
template<class ElemType>
class DoubleSeqStack
{
protected:
	// ˳��ջ�����ݳ�Ա:
	int top;										// ջ1ջ��
	int tail;										// ջ2ջ��
	int maxSize;									// ջ��������� 
	ElemType* elems;								// Ԫ�ش洢�ռ�
	const int num =2;										// ջ���

public:
	//  ˳��ջ�ķ������������ر���ϵͳĬ�Ϸ�������:
	DoubleSeqStack(int size = 1000);				// ���캯��
	virtual ~DoubleSeqStack();							// ��������
	int GetLength(int num) const;							// ��ջ�ĳ���			 
	bool IsEmpty(int num) const;							// �ж�ջ�Ƿ�Ϊ��
	void Clear();									// ��ջ���
	void Push(const ElemType e,int num);				    // ��ջ
	void Pop(ElemType& e, int num);					    // ��ջ
};


// ˳��ջ���ʵ�ֲ���

template<class ElemType>
DoubleSeqStack<ElemType>::DoubleSeqStack(int size)
// �������������һ���������Ϊsize�Ŀ�ջ
{
	maxSize = size;						// ջ���������
	if (elems != NULL) delete[]elems;	// �ͷ����д洢�ռ�
	elems = new ElemType[maxSize];		// �����µĴ洢�ռ�
	top = -1;
	tail = maxSize;
}

template<class ElemType>
DoubleSeqStack<ElemType>::~DoubleSeqStack()
// �������������ջ
{
	delete[]elems;					// �ͷ�ջ�Ĵ洢�ռ�
}

template <class ElemType>
int DoubleSeqStack<ElemType>::GetLength(int num) const
// �������������ջ��Ԫ�ظ���
{
	if (num == 1)
		return top + 1;
	else
		return tail - 1;
}

template<class ElemType>
bool DoubleSeqStack<ElemType>::IsEmpty(int num) const
// �����������ջΪ�գ��򷵻�true�����򷵻�false
{
	if (num == 1)
		return top == -1;
	else
		return  tail == maxSize;
}

template<class ElemType>
void DoubleSeqStack<ElemType>::Clear()
// ������������ջ
{
	top = -1;
	tail = maxSize;
}


template<class ElemType>
void DoubleSeqStack<ElemType>::Push(const ElemType e, int num)

{
	if (top == tail -1) // ջ����
		cout<< "OVER_FLOW";
	else 
	{	
		if(num ==1)
			elems[++top] = e;	// ��Ԫ��e׷�ӵ�ջ1�� 
		if (num == 2)
			elems[--tail] = e;// ��Ԫ��e׷�ӵ�ջ2�� 
	}
}



template<class ElemType>
void DoubleSeqStack<ElemType>::Pop(ElemType& e, int num)
{
	if (IsEmpty(num))	 // ջ��
		cout <<"UNDER_FLOW";
	else 
	{ 
		if(num ==1)
		e = elems[top--]; // ��e����ջ��Ԫ��
		if (num == 2)
			e = elems[tail++];

	}
}



#endif
