#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__
#include<iostream>
using namespace std;
// 顺序表模板类的申明 
template <class ElemType>
class SqList
{
protected:
	// 顺序表的数据成员
	int length;					// 顺序表的当前长度 
	int maxLength;				// 顺序表的最大容量
	ElemType* elems;			// 元素存储空间的首地址 

public:
	// 顺序表的函数成员
	SqList(int size = DEFAULT_SIZE);	// 构造一个空表 
	SqList(ElemType v[], int n, int size = DEFAULT_SIZE);	// 根据数组v的内容构造顺序表 
	SqList(const SqList<ElemType>& sa);        // 复制构造函数
	bool IsEmpty() const;		// 判断顺序表是否为空
	int GetLength() const;		// 取顺序表长度			 
	virtual ~SqList();			// 析构函数
	void Clear();				// 将顺序表清空
	void Show() const;	// 遍历顺序表
	void LocateElem(const ElemType& e) const;	// 元素定位，求指定元素在顺序表中的位置
	void GetElem(int i, ElemType& e) const;	// 取顺序表中第i个元素的值	
	void SetElem(int i, const ElemType& e);	// 修改顺序表中第i个元素的值
	void DeleteElemI(int i);      // 删除顺序表中第i个元素		
	void InsertElem(int i, const ElemType& e); // 在顺序表第i个位置插入元素
	void InsertElem(const ElemType& e);        // 在顺序表表尾插入元素
	void Deletemin(ElemType& e);				// 删除最小值
	void DeleteElemE(ElemType& e);				//删除定值e
	void DeleteElemS();							//删除重复值
	void Reverse();								//逆置
};


// 顺序表函数成员的实现部分

template <class ElemType>
// 操作结果：构造一个最大容量为size的空顺序表
SqList<ElemType>::SqList(int size)
{
	elems = new ElemType[size];		    
	//assert(elems);                      
	maxLength = size;					
	length = 0;							
}

template <class ElemType>
//根据数组v中的内容构造顺序表
SqList<ElemType>::SqList(ElemType v[], int n, int size)
{
	elems = new ElemType[size];		                         
	maxLength = size;					
	length = n;							
	for (int i = 0; i < length; i++)	
		elems[i] = v[i];
}

template <class ElemType>
// 析构
SqList<ElemType>::~SqList()
{
	delete[]elems;						
}

template <class ElemType>
//	返回顺序表中元素个数
int SqList<ElemType>::GetLength() const
{
	return length;
}

template <class ElemType>
// 如顺序表为空，则返回true，否则返回false
bool SqList<ElemType>::IsEmpty() const
{
	return length == 0;
}

template <class ElemType>
// 清空顺序表
void SqList<ElemType>::Clear()
{
	length = 0;
}

template <class ElemType>
// 遍历输出
void SqList<ElemType>::Show()const
{
	cout << "顺序表为：" << endl;
	for (int i = 0; i < length; i++)
		cout <<(elems[i])<< endl;
}

template <class ElemType>
// 求元素e在顺序表中的序号
void SqList<ElemType>::LocateElem(const ElemType& e) const
{
	int i = 0;
	while (i < length && elems[i] != e)
		i++;
	if (i < length)
		cout << "元素位于 "<<i + 1<<endl;
	else
		cout << "Not exist."<<endl;
}

template <class ElemType>
// 当顺序表存在第i个元素时，用e返回其值
void SqList<ElemType>::GetElem(int i, ElemType& e) const
{
	if (i < 1 || i > length)
		cout << "Not exist."<<endl;	// 元素不存在
	else {
		e = elems[i - 1];
		cout <<"元素存在，为： "<< e <<endl;	// 元素存在
	}
}

template <class ElemType>
// 将顺序表的第i个位置的元素赋值为e。
void SqList<ElemType>::SetElem(int i, const ElemType& e)
{
	if (i < 1 || i > length)
		cout <<"Not exist."<<endl;	// 位置错
	else 
	{
		elems[i - 1] = e;
		cout <<"该元素已改为 " <<e << endl;		// 修改成功
	}
}

template <class ElemType>
// 删除顺序表第i个位置的元素
void SqList<ElemType>::DeleteElemI(int i)
{
	if (i < 1 || i > length)
		cout <<"Not exist."<<endl;      // 位置错
	else {
		for (int j = i; j < length; j++)// 被删除元素之后的元素依次左移一个位置 
			elems[j - 1] = elems[j];
		length--;				// 删除后顺序表元素个数减1
	}
}

template <class ElemType>
// 在顺序表的第i个位置插入元素e
void SqList<ElemType>::InsertElem(int i, const ElemType& e)
{
	if (length == maxLength)
		cout <<"over flow"<<endl;	        // 顺序表已满
	else if (i < 1 || i > length + 1)		// i位置错
		cout <<"position not exist"<<endl;
	else {
		for (int j = length; j >= i; j--)  // 插入位置之后的元素右移
			elems[j] = elems[j - 1];
		elems[i - 1] = e;	               // 将e赋值到顺序表i位置	
		length++;				           // 插入后元素个数加1
		cout<< "已插入" << e << endl;		   // 插入成功
	}
}

template <class ElemType>
// 在顺序表的表尾插入元素e
void SqList<ElemType>::InsertElem(const ElemType& e)
{
	if (length == maxLength)		// 顺序表已满
		cout << "over flow" << endl;
	else {
		elems[length] = e;	    // 将元素e插入到表尾	
		length++;				// 插入后，顺序表元素个数加1
		cout << "已在末尾插入 " << e << endl;			// 插入成功
	}
}

template <class ElemType>
SqList<ElemType>::SqList(const SqList<ElemType>& sa)
// 功能：复制构造函数，由顺序表sa构造新顺序表
{
	int saLength = sa.GetLength();	// 取顺序表sa的长度
	ElemType e;

	maxLength = sa.maxLength;		// 取顺序表的最大容量
	elems = new ElemType[maxLength];// 分配存储空间
	assert(elems);                  // 分配存储空间失败 
	length = 0;					    // 空顺序表元素个数为0

	for (int i = 1; i <= saLength; i++) {
		sa.getElem(i, e);		    // 取出顺序表sa中第i个元素
		insertElem(e);			    // 将e插入到当前顺序表的表尾 
	}
}



template <class ElemType>
// 删除顺序表最小值元素
void SqList<ElemType>::Deletemin(ElemType& e)
{
	if (length == 0)
		cout << "表中无元素" << endl;
	else
	{
		int min = 0;
		for (int i = 1; i < length; i++)
		{
			if (elems[i] < elems[min])
			{
				min = i;
			}
		}
		e = elems[min];
		length--;
		elems[min] = elems[length];
		cout << "已删除最小值 " << e << endl;
	}
}

template <class ElemType>
// 删除给定值e
void SqList<ElemType>::DeleteElemE(ElemType& e)
{
	if (length == 0)
		cout << "表中无元素" << endl;
	int i = 0;
	while (i < length + 1)
	{
		if (elems[i] == e)
		{
			DeleteElemI(i+1);
		}
		else
			i++;
	}
	cout << "已删除所有的 "<< e <<endl;
}

template <class ElemType>
// 删除重复值
void SqList<ElemType>::DeleteElemS()
{
	if (length == 0)
		cout << "表中无元素" << endl;
	int i = 0;
	while (i < length + 1)
	{
		int j = i+1; 
		while (j < length )
		{
			if (elems[i] == elems[j])
				{
					DeleteElemI(j+1);
				}
			else
			{
				j++;
			}
		}
		i++;
	}
	cout << "已删除所有重复项 "  << endl;
}

template <class ElemType>
// 逆置
void SqList<ElemType>::Reverse()
{
	for (int i = 0; i <= (length - 1) / 2; i++)
	{
		swap(elems[i], elems[length - i - 1]);
	}
}
#endif

