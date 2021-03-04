#pragma once
#ifndef __SQ_STACK_H__
#define __SQ_STACK_H__
#include<iostream>
using namespace std;
template <class ElemType>
class SeqStack
{
protected:
    int top;
    int maxsize;
    ElemType* elems;

public:
    SeqStack(int size = 9999);
    virtual ~SeqStack();
    int GetLength() const;
    bool IsEmpty() const;
    void Clear();

    void Push(const ElemType e);
    void Top(ElemType& e) const;
    void Pop(ElemType& e);
    SeqStack(const SeqStack<ElemType>& SS);
    SeqStack<ElemType>& operator=(const SeqStack<ElemType>& SS);
};
template <class ElemType>
SeqStack<ElemType>::SeqStack(int size) : maxsize(size), top(-1)
{
    elems = new ElemType[maxsize];
}

template <class ElemType>
SeqStack<ElemType>::~SeqStack()
{
    delete[] elems;
}

template <class ElemType>
int SeqStack<ElemType>::GetLength() const
{
    return top + 1;
}

template <class ElemType>
bool SeqStack<ElemType>::IsEmpty() const
{
    return top == -1;
}

template <class ElemType>
void SeqStack<ElemType>::Clear()
{
    top = -1;
}

template <class ElemType>
void SeqStack<ElemType>::Push(const ElemType e)
{
    if (top == maxsize)
    {
        cout << "OVER_FLOW";
    }
    elems[++top] = e;
}

template <class ElemType>
void SeqStack<ElemType>::Top(ElemType& e) const
{
    if (IsEmpty())
    {
        cout << "UNDER_FLOW";
    }
    e = elems[top];
}

template <class ElemType>
void SeqStack<ElemType>::Pop(ElemType& e)
{
    if (IsEmpty())
    {
        cout << "UNDER_FLOW";
    }
    e = elems[top--];
}

template <class ElemType>
SeqStack<ElemType>::SeqStack(const SeqStack<ElemType>& SS) : maxsize(SS.maxsize), top(SS.top)
{
    elems = new ElemType[maxsize];
    for (int i = 0; i < top + 1; i++)
    {
        elems[i] = SS.elems[i];
    }
}

template <class ElemType>
SeqStack<ElemType>& SeqStack<ElemType>::operator=(const SeqStack<ElemType>& SS)
{
    if (&SS == this)
    {
        return *this;
    }
    delete[] elems;
    maxsize = SS.maxsize;
    top = SS.top;
    elems = new ElemType[maxsize];
    for (int i = 0; i < top + 1; i++)
    {
        elems[i] = SS.elems[i];
    }
    return *this;
}
#endif