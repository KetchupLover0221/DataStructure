#ifndef __ORDLIST_H__
#define __ORDLIST_H__
#include<iostream>
#include<algorithm>
using namespace std;
// 顺序表模板类的申明 
template <class ElemType>
class OrdList
{
protected:
	// 顺序表的数据成员
	int length;					// 顺序表的当前长度 
	int maxLength;				// 顺序表的最大容量
	ElemType* elems;			// 元素存储空间的首地址 

public:
	// 顺序表的函数成员
	OrdList(int size = DEFAULT_SIZE);	// 构造一个空表 
	OrdList(ElemType v[], int n, int size = DEFAULT_SIZE);	// 根据数组v的内容构造顺序表 
	OrdList(const OrdList<ElemType>& la, const OrdList<ElemType>& lb);//合并两个顺序表
	bool IsEmpty() const;		// 判断顺序表是否为空
	int GetLength() const;		// 取顺序表长度			 
	virtual ~OrdList();			// 析构函数
	void Clear();				// 将顺序表清空
	void Show() const;	// 遍历顺序表
	void Insert(ElemType& e);	//插入
	void DeleteElem(ElemType& e);	//删除所有e
	void DeleteElemBtw(ElemType& s, ElemType& t);//删除s与t之间
};


// 顺序表函数成员的实现部分

template <class ElemType>
// 操作结果：构造一个最大容量为size的空顺序表
OrdList<ElemType>::OrdList(int size)
{
	elems = new ElemType[size];
	//assert(elems);                      
	maxLength = size;
	length = 0;
}

template <class ElemType>
//根据数组v中的内容构造顺序表
OrdList<ElemType>::OrdList(ElemType v[], int n, int size)
{
	elems = new ElemType[size];
	maxLength = size;
	length = n;
	sort(v, v + n);
	for (int i = 0; i < length; i++)
		elems[i] = v[i];
}

template <class ElemType>
//合并顺序表
OrdList<ElemType>::OrdList(const OrdList<ElemType>& la, const OrdList<ElemType>& lb)
{
	maxLength = la.maxLength+ lb.maxLength;
	elems = new ElemType[maxLength];
	length = 0;
	int i = 0, j = 0;
	while (i < la.length && j < lb.length)
	{
		if (la.elems[i] <= lb.elems[j])
		{
			elems[length++] = la.elems[i];
			i++;
		}
		else
		{
			elems[length++] = lb.elems[j];
			j++;
		}
	}
	while (i < la.length)
	{
		elems[length++] = la.elems[i];
		i++;
	}
	while (j < lb.length)
	{
		elems[length++] = lb.elems[j];
		j++;
	}
}

template <class ElemType>
// 析构
OrdList<ElemType>::~OrdList()
{
	delete[]elems;
}

template <class ElemType>
//	返回顺序表中元素个数
int OrdList<ElemType>::GetLength() const
{
	return length;
}

template <class ElemType>
// 如顺序表为空，则返回true，否则返回false
bool OrdList<ElemType>::IsEmpty() const
{
	return length == 0;
}

template <class ElemType>
// 清空顺序表
void OrdList<ElemType>::Clear()
{
	length = 0;
}

template <class ElemType>
// 遍历输出
void OrdList<ElemType>::Show()const
{
	cout << "顺序表为：" << endl;
	for (int i = 0; i < length; i++)
		cout << (elems[i]) << endl;
}

template <class ElemType>
//插入
void OrdList<ElemType>::Insert(ElemType & e)
{
	if (length == maxLength)
		cout << "over flow" << endl;	        // 顺序表已满
	else 
	{
		int i = 0; 
		while(i < length + 1 )
		{
			if (elems[i] > e)
			{
				break;//i为插入点
			}
			else
				i++;
		}
		if (i == length+1)//插入点在最后
		{
			length++;
			elems[i-1] = e;
		}
		else
		{
			length ++ ;
			int j = i;
			for (i = length - 1; i >= j; i--)//后移
			{
				elems[i + 1] = elems[i];
			}
			elems[j] = e;
		}
		cout << "已插入" << e << endl;		   
	}
}

template < class ElemType>
//删除所有e
void OrdList<ElemType>::DeleteElem(ElemType& e)
{
	int i = 0 ,j;
	while( i < length )
	{
		i++;
		if(elems[i]== e)//第一个目标元素
		{
			j=i+1;
			while (j < length && elems[j] == e)
			{
				j++;//目标元素总长度
			}
			while (j <= length)
			{
				elems[i++] = elems[j++];
			}
			length = length + i - j;
		}
	}
	cout << "已删除所有的 "<< e << endl;
}

template < class ElemType>
//删除 s与t 之间
void OrdList<ElemType> ::DeleteElemBtw(ElemType& s, ElemType& t)
{
	if (length == 0)
	{
		cout<<"顺序表为空"<<endl;
	}
	else if (s >= t)
	{
		cout<<"错误输入"<<endl;
	}
	else
	{
		for (ElemType j = s + 1; j < t; j++)
		{
			DeleteElem(j);
		}
	}
}
#endif
