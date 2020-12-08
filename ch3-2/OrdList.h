#ifndef __ORDLIST_H__
#define __ORDLIST_H__
#include<iostream>
#include<algorithm>
using namespace std;
// ˳���ģ��������� 
template <class ElemType>
class OrdList
{
protected:
	// ˳�������ݳ�Ա
	int length;					// ˳���ĵ�ǰ���� 
	int maxLength;				// ˳�����������
	ElemType* elems;			// Ԫ�ش洢�ռ���׵�ַ 

public:
	// ˳���ĺ�����Ա
	OrdList(int size = DEFAULT_SIZE);	// ����һ���ձ� 
	OrdList(ElemType v[], int n, int size = DEFAULT_SIZE);	// ��������v�����ݹ���˳��� 
	OrdList(const OrdList<ElemType>& la, const OrdList<ElemType>& lb);//�ϲ�����˳���
	bool IsEmpty() const;		// �ж�˳����Ƿ�Ϊ��
	int GetLength() const;		// ȡ˳�����			 
	virtual ~OrdList();			// ��������
	void Clear();				// ��˳������
	void Show() const;	// ����˳���
	void Insert(ElemType& e);	//����
	void DeleteElem(ElemType& e);	//ɾ������e
	void DeleteElemBtw(ElemType& s, ElemType& t);//ɾ��s��t֮��
};


// ˳�������Ա��ʵ�ֲ���

template <class ElemType>
// �������������һ���������Ϊsize�Ŀ�˳���
OrdList<ElemType>::OrdList(int size)
{
	elems = new ElemType[size];
	//assert(elems);                      
	maxLength = size;
	length = 0;
}

template <class ElemType>
//��������v�е����ݹ���˳���
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
//�ϲ�˳���
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
// ����
OrdList<ElemType>::~OrdList()
{
	delete[]elems;
}

template <class ElemType>
//	����˳�����Ԫ�ظ���
int OrdList<ElemType>::GetLength() const
{
	return length;
}

template <class ElemType>
// ��˳���Ϊ�գ��򷵻�true�����򷵻�false
bool OrdList<ElemType>::IsEmpty() const
{
	return length == 0;
}

template <class ElemType>
// ���˳���
void OrdList<ElemType>::Clear()
{
	length = 0;
}

template <class ElemType>
// �������
void OrdList<ElemType>::Show()const
{
	cout << "˳���Ϊ��" << endl;
	for (int i = 0; i < length; i++)
		cout << (elems[i]) << endl;
}

template <class ElemType>
//����
void OrdList<ElemType>::Insert(ElemType & e)
{
	if (length == maxLength)
		cout << "over flow" << endl;	        // ˳�������
	else 
	{
		int i = 0; 
		while(i < length + 1 )
		{
			if (elems[i] > e)
			{
				break;//iΪ�����
			}
			else
				i++;
		}
		if (i == length+1)//����������
		{
			length++;
			elems[i-1] = e;
		}
		else
		{
			length ++ ;
			int j = i;
			for (i = length - 1; i >= j; i--)//����
			{
				elems[i + 1] = elems[i];
			}
			elems[j] = e;
		}
		cout << "�Ѳ���" << e << endl;		   
	}
}

template < class ElemType>
//ɾ������e
void OrdList<ElemType>::DeleteElem(ElemType& e)
{
	int i = 0 ,j;
	while( i < length )
	{
		i++;
		if(elems[i]== e)//��һ��Ŀ��Ԫ��
		{
			j=i+1;
			while (j < length && elems[j] == e)
			{
				j++;//Ŀ��Ԫ���ܳ���
			}
			while (j <= length)
			{
				elems[i++] = elems[j++];
			}
			length = length + i - j;
		}
	}
	cout << "��ɾ�����е� "<< e << endl;
}

template < class ElemType>
//ɾ�� s��t ֮��
void OrdList<ElemType> ::DeleteElemBtw(ElemType& s, ElemType& t)
{
	if (length == 0)
	{
		cout<<"˳���Ϊ��"<<endl;
	}
	else if (s >= t)
	{
		cout<<"��������"<<endl;
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
