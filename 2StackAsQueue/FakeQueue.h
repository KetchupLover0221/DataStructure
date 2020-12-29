#pragma once
#include"SeqStack.h"
class AsQueue
{
protected:
	SeqStack<int> S1;
	SeqStack<int> S2;

public:
	AsQueue(int size = 9999);
	int GetLength() const;
	bool IsEmpty() const;
	void Clear();
	void EnQueue(const int e);
	void DelQueue(int& e);
};
AsQueue::AsQueue(int size) : S1(size), S2(size)
{
}

int AsQueue::GetLength() const
{
	return S1.GetLength();
}

bool AsQueue::IsEmpty() const
{
	return S1.IsEmpty();
}

void AsQueue::Clear()
{
	S1.Clear();
}

void AsQueue::EnQueue(const int e)
{
	S1.Push(e);
}

void AsQueue::DelQueue(int& e)
{
	int length = S1.GetLength();
	for (int i = 0; i < length; i++)
	{
		int temp = 0;
		S1.Pop(temp);
		S2.Push(temp);
	}
	S2.Pop(e);
	for (int i = 0; i < length - 1; i++)
	{
		int temp = 0;
		S2.Pop(temp);
		S1.Push(temp);
	}
}