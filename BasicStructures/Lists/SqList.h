#ifndef __SQ_LIST_H__
#define __SQ_LIST_H__
#include<iostream>
using namespace std;
// ˳���ģ��������� 
template <class ElemType>
class SqList
{
protected:
	// ˳�������ݳ�Ա
	int length;					// ˳���ĵ�ǰ���� 
	int maxLength;				// ˳�����������
	ElemType* elems;			// Ԫ�ش洢�ռ���׵�ַ 

public:
	// ˳���ĺ�����Ա
	SqList(int size = DEFAULT_SIZE);	// ����һ���ձ� 
	SqList(ElemType v[], int n, int size = DEFAULT_SIZE);	// ��������v�����ݹ���˳��� 
	SqList(const SqList<ElemType>& sa);        // ���ƹ��캯��
	bool IsEmpty() const;		// �ж�˳����Ƿ�Ϊ��
	int GetLength() const;		// ȡ˳�����			 
	virtual ~SqList();			// ��������
	void Clear();				// ��˳������
	void Show() const;	// ����˳���
	void LocateElem(const ElemType& e) const;	// Ԫ�ض�λ����ָ��Ԫ����˳����е�λ��
	void GetElem(int i, ElemType& e) const;	// ȡ˳����е�i��Ԫ�ص�ֵ	
	void SetElem(int i, const ElemType& e);	// �޸�˳����е�i��Ԫ�ص�ֵ
	void DeleteElemI(int i);      // ɾ��˳����е�i��Ԫ��		
	void InsertElem(int i, const ElemType& e); // ��˳����i��λ�ò���Ԫ��
	void InsertElem(const ElemType& e);        // ��˳����β����Ԫ��
	void Deletemin(ElemType& e);				// ɾ����Сֵ
	void DeleteElemE(ElemType& e);				//ɾ����ֵe
	void DeleteElemS();							//ɾ���ظ�ֵ
	void Reverse();								//����
};


// ˳�������Ա��ʵ�ֲ���

template <class ElemType>
// �������������һ���������Ϊsize�Ŀ�˳���
SqList<ElemType>::SqList(int size)
{
	elems = new ElemType[size];		    
	//assert(elems);                      
	maxLength = size;					
	length = 0;							
}

template <class ElemType>
//��������v�е����ݹ���˳���
SqList<ElemType>::SqList(ElemType v[], int n, int size)
{
	elems = new ElemType[size];		                         
	maxLength = size;					
	length = n;							
	for (int i = 0; i < length; i++)	
		elems[i] = v[i];
}

template <class ElemType>
// ����
SqList<ElemType>::~SqList()
{
	delete[]elems;						
}

template <class ElemType>
//	����˳�����Ԫ�ظ���
int SqList<ElemType>::GetLength() const
{
	return length;
}

template <class ElemType>
// ��˳���Ϊ�գ��򷵻�true�����򷵻�false
bool SqList<ElemType>::IsEmpty() const
{
	return length == 0;
}

template <class ElemType>
// ���˳���
void SqList<ElemType>::Clear()
{
	length = 0;
}

template <class ElemType>
// �������
void SqList<ElemType>::Show()const
{
	cout << "˳���Ϊ��" << endl;
	for (int i = 0; i < length; i++)
		cout <<(elems[i])<< endl;
}

template <class ElemType>
// ��Ԫ��e��˳����е����
void SqList<ElemType>::LocateElem(const ElemType& e) const
{
	int i = 0;
	while (i < length && elems[i] != e)
		i++;
	if (i < length)
		cout << "Ԫ��λ�� "<<i + 1<<endl;
	else
		cout << "Not exist."<<endl;
}

template <class ElemType>
// ��˳�����ڵ�i��Ԫ��ʱ����e������ֵ
void SqList<ElemType>::GetElem(int i, ElemType& e) const
{
	if (i < 1 || i > length)
		cout << "Not exist."<<endl;	// Ԫ�ز�����
	else {
		e = elems[i - 1];
		cout <<"Ԫ�ش��ڣ�Ϊ�� "<< e <<endl;	// Ԫ�ش���
	}
}

template <class ElemType>
// ��˳���ĵ�i��λ�õ�Ԫ�ظ�ֵΪe��
void SqList<ElemType>::SetElem(int i, const ElemType& e)
{
	if (i < 1 || i > length)
		cout <<"Not exist."<<endl;	// λ�ô�
	else 
	{
		elems[i - 1] = e;
		cout <<"��Ԫ���Ѹ�Ϊ " <<e << endl;		// �޸ĳɹ�
	}
}

template <class ElemType>
// ɾ��˳����i��λ�õ�Ԫ��
void SqList<ElemType>::DeleteElemI(int i)
{
	if (i < 1 || i > length)
		cout <<"Not exist."<<endl;      // λ�ô�
	else {
		for (int j = i; j < length; j++)// ��ɾ��Ԫ��֮���Ԫ����������һ��λ�� 
			elems[j - 1] = elems[j];
		length--;				// ɾ����˳���Ԫ�ظ�����1
	}
}

template <class ElemType>
// ��˳���ĵ�i��λ�ò���Ԫ��e
void SqList<ElemType>::InsertElem(int i, const ElemType& e)
{
	if (length == maxLength)
		cout <<"over flow"<<endl;	        // ˳�������
	else if (i < 1 || i > length + 1)		// iλ�ô�
		cout <<"position not exist"<<endl;
	else {
		for (int j = length; j >= i; j--)  // ����λ��֮���Ԫ������
			elems[j] = elems[j - 1];
		elems[i - 1] = e;	               // ��e��ֵ��˳���iλ��	
		length++;				           // �����Ԫ�ظ�����1
		cout<< "�Ѳ���" << e << endl;		   // ����ɹ�
	}
}

template <class ElemType>
// ��˳���ı�β����Ԫ��e
void SqList<ElemType>::InsertElem(const ElemType& e)
{
	if (length == maxLength)		// ˳�������
		cout << "over flow" << endl;
	else {
		elems[length] = e;	    // ��Ԫ��e���뵽��β	
		length++;				// �����˳���Ԫ�ظ�����1
		cout << "����ĩβ���� " << e << endl;			// ����ɹ�
	}
}

template <class ElemType>
SqList<ElemType>::SqList(const SqList<ElemType>& sa)
// ���ܣ����ƹ��캯������˳���sa������˳���
{
	int saLength = sa.GetLength();	// ȡ˳���sa�ĳ���
	ElemType e;

	maxLength = sa.maxLength;		// ȡ˳�����������
	elems = new ElemType[maxLength];// ����洢�ռ�
	assert(elems);                  // ����洢�ռ�ʧ�� 
	length = 0;					    // ��˳���Ԫ�ظ���Ϊ0

	for (int i = 1; i <= saLength; i++) {
		sa.getElem(i, e);		    // ȡ��˳���sa�е�i��Ԫ��
		insertElem(e);			    // ��e���뵽��ǰ˳���ı�β 
	}
}



template <class ElemType>
// ɾ��˳�����СֵԪ��
void SqList<ElemType>::Deletemin(ElemType& e)
{
	if (length == 0)
		cout << "������Ԫ��" << endl;
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
		cout << "��ɾ����Сֵ " << e << endl;
	}
}

template <class ElemType>
// ɾ������ֵe
void SqList<ElemType>::DeleteElemE(ElemType& e)
{
	if (length == 0)
		cout << "������Ԫ��" << endl;
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
	cout << "��ɾ�����е� "<< e <<endl;
}

template <class ElemType>
// ɾ���ظ�ֵ
void SqList<ElemType>::DeleteElemS()
{
	if (length == 0)
		cout << "������Ԫ��" << endl;
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
	cout << "��ɾ�������ظ��� "  << endl;
}

template <class ElemType>
// ����
void SqList<ElemType>::Reverse()
{
	for (int i = 0; i <= (length - 1) / 2; i++)
	{
		swap(elems[i], elems[length - i - 1]);
	}
}
#endif

