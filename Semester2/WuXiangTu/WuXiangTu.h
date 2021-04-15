#pragma once
#include <iostream>
#include"Queue.h"
using namespace std;

SeqQueue<char> q1;//·������

template <class ElemType>
class WuXiangTu
{
protected:
	int vexNum, vexMaxNum, arcNum;//������������������
	int** arcs;//��
	ElemType* vertexes;//������Ϣ
	int * tag;//��־
public:
	WuXiangTu(ElemType es[], int vertexNum, int vertexMaxNum = 9999);//�������顢����������ඥ����
	WuXiangTu(int vertexMaxNum = 9999);
	~WuXiangTu();
	void Clear();//���������Ϊ0
	bool IsEmpty();
	int GetOrder(ElemType& d) const;//�õ��������
	void GetElem(int v, ElemType& d) const;//��d���ر��Ϊv��Ԫ��ֵ
	void SetElem(int v, const ElemType& d);//�����Ϊv��Ԫ����Ϊd
	int GetVexNum()const;//������
	int GetArcNum() const;//����
	int FirstAdjVex(int v)const;//���Ϊv�ĵ�һ���ڽӵ�
	int NextAdjVex(int v1, int v2) const;//����v1 ��v2 �����һ���ڽӵ�
	void InsertVex(const ElemType& d);//�����
	void InsertArc(int v1, int v2, int weight); //v1 v2 ������
	void DeleteVex(const ElemType& d);//ɾ����
	void DeleteArc(int v1, int v2);//ɾ����
	int GetTag(int v);//v�����״̬
	void SetTag(int v, int val);
	void Display();
	bool FindPath(int v1, int v2);
};

template <class ElemType>
WuXiangTu<ElemType>::WuXiangTu(int vertexMaxNum)
{
	vexNum = 0;
	vexMaxNum = vertexMaxNum;
	arcNum = 0;

	vertexes = new ElemType[vexMaxNum];

	tag = new int[vexMaxNum];
	arcs = (int**)new int* [vexMaxNum];
	for (int v = 0; v < vexMaxNum; v++)
		arcs[v] = new int[vexMaxNum];
}

template <class ElemType>
WuXiangTu<ElemType>::WuXiangTu(ElemType es[], int vertexNum, int vertexMaxNum)
{
	vexNum = vertexNum;	
	vexMaxNum = vertexMaxNum;
	arcNum = 0;	
	vertexes = new ElemType[vexMaxNum];
	tag = new int[vexMaxNum];
	arcs = (int**)new int* [vexMaxNum];
	for (int v = 0; v < vexMaxNum; v++) 	
		arcs[v] = new int[vexMaxNum];
	for (int v = 0; v < vexNum; v++) 
	{
		vertexes[v] = es[v]; 
		tag[v] = 0;
		for (int u = 0; u < vexNum; u++)  
			arcs[v][u] = 0;
	}
}

template<class ElemType>
WuXiangTu<ElemType>::~WuXiangTu()
{
	delete[]vertexes;					// �ͷŶ�������
	delete[]tag;						    // �ͷű�־
	for (int v = 0; v < vexMaxNum; v++)	// �ͷ��ڽӾ������
		delete[]arcs[v];
	delete[]arcs;					    // �ͷ��ڽӾ���
}

template<class ElemType>
void WuXiangTu<ElemType>::Clear()
{
	vexNum = 0;
	arcNum = 0;
}

template<class ElemType>
bool WuXiangTu<ElemType>::IsEmpty()
{
	return vexNum == 0;
}

template<class ElemType>
int WuXiangTu<ElemType>::GetOrder(ElemType& d) const
{
	for (int v = 0; v < vexNum; v++)
		if (vertexes[v] == d)
			return v;	    // ����d����,����������� 
	return -1;	        // ����d������,����-1
}

template<class ElemType>
void  WuXiangTu<ElemType>::GetElem(int v, ElemType& d) const
{
	if (v < 0 || v >= vexNum)
		cout<<"NOT_PRESENT";	// v��Χ��
	else 
	{
		d = vertexes[v];	  // ������v��Ԫ��ֵ����d
	}
}

template<class ElemType>
void  WuXiangTu<ElemType>::SetElem(int v, const ElemType& d)
{
	if (v < 0 || v >= vexNum)
		cout<<"RANGE_ERROR";	// v��Χ��,����λ�ô�
	else 
	{
		vertexes[v] = d;		// ������Ԫ�ص�ֵ��Ϊd 
	}
}

template <class ElemType>
int WuXiangTu<ElemType>::GetVexNum() const
// ������������ض������			 
{
	return vexNum;
}

template <class ElemType>
int WuXiangTu<ElemType>::GetArcNum() const
// ������������ر���
{
	return arcNum;
}

template <class ElemType>
int WuXiangTu<ElemType>::FirstAdjVex(int v) const
// ������������ض���v�ĵ�1���ڽӵ�����		 
{
	if (v < 0 || v >= vexNum)
		cout << "v���Ϸ�!" <<endl;

	for (int u = 0; u < vexNum; u++)
		if (arcs[v][u] != 0)
			return u;
	return -1;					// ����-1��ʾ���ڽӵ�
}

template <class ElemType>
int WuXiangTu<ElemType>::NextAdjVex(int v1, int v2) const
// ������������ض���v1�������v2����һ���ڽӵ�			 
{
	if (v1 < 0 || v1 >= vexNum)
		cout << "v���Ϸ�!" << endl;
	if (v2 < 0 || v2 >= vexNum)
		cout << "v���Ϸ�!" << endl;
	if (v1 == v2) 
		cout << "v���Ϸ�!" << endl;// �׳��쳣
	for (int u = v2 + 1; u < vexNum; u++)
		if (arcs[v1][u] != 0)
			return u;
	return -1;						// ����-1��ʾ����һ���ڽӵ�
}

template<class ElemType>
void  WuXiangTu<ElemType>::InsertVex(const ElemType& d)
{
	if (vexNum == vexMaxNum)
		cout << "ͼ�Ķ��������ܳ�������������!" << endl;

	vertexes[vexNum] = d;
	tag[vexNum] = 0;
	for (int v = 0; v <= vexNum; v++)
	{
		arcs[vexNum][v] = 0;
		arcs[v][vexNum] = 0;
	}
	vexNum++;
}

template <class ElemType>
void WuXiangTu<ElemType>::InsertArc(int v1, int v2, int weight)
// ���������������������v1��v2�ı�			 
{
	if (v1 < 0 || v1 >= vexNum)
		cout << "v1���Ϸ�!" << endl;
	if (v2 < 0 || v2 >= vexNum)
		cout << "v2���Ϸ�!" << endl;
	if (v1 == v2)
		cout << "v1���ܵ���v2!" << endl;

	if (arcs[v1][v2] == 0&& weight !=0) 
	{									// ԭ����ͼ��û�б�(v1, v2) 
		arcNum++;
		arcs[v1][v2] = weight;
		arcs[v2][v1] = weight;
	}
}

template <class ElemType>
void WuXiangTu<ElemType>::DeleteVex(const ElemType& d)
{
	int v;
	for (v = 0; v < vexNum; v++)
		if (vertexes[v] == d)
			break;
	if (v == vexNum)
		cout << "ͼ�в�����Ҫɾ���Ķ���!" << endl;// �׳��쳣

	for (int u = 0; u < vexNum; u++)             // ɾ���붥��d������ı� 
		if (arcs[v][u] != 0) {
			arcNum--;
			arcs[v][u] = 0;
			arcs[u][v] = 0;
		}

	vexNum--;
	if (v < vexNum)
	{//���һ���������Ϣ������ɾ�����λ��
		vertexes[v] = vertexes[vexNum];
		tag[v] = tag[vexNum];
		for (int u = 0; u <= vexNum; u++)
			arcs[v][u] = arcs[vexNum][u];
		for (int u = 0; u <= vexNum; u++)
			arcs[u][v] = arcs[u][vexNum];
	}
}

template <class ElemType>
void WuXiangTu<ElemType>::DeleteArc(int v1, int v2)
// ���������ɾ����������v1��v2�ı�			 
{
	if (v1 < 0 || v1 >= vexNum)
		cout << "v1���Ϸ�!" << endl;
	if (v2 < 0 || v2 >= vexNum)
		cout << "v2���Ϸ�!" << endl;
	if (v1 == v2)
		cout << "v1���ܵ���v2!" << endl;

	if (arcs[v1][v2] != 0) {	// ԭ����ͼ���ڱ�(v1, v2)
		arcNum--;
		arcs[v1][v2] = 0;
		arcs[v2][v1] = 0;
	}
}

template <class ElemType>
int WuXiangTu<ElemType>::GetTag(int v) 
// ������������ض���v�ı�־		 
{
	if (v < 0 || v >= vexNum)
		cout << "v���Ϸ�!" << endl;// �׳��쳣
	return tag[v];
}

template <class ElemType>
void WuXiangTu<ElemType>::SetTag(int v, int val) 
// ������������ö���v�ı�־Ϊval		 
{
	if (v < 0 || v >= vexNum)
		cout<<"v���Ϸ�!"<<endl;	// �׳��쳣
	tag[v] = val;
}

template <class ElemType>
void WuXiangTu<ElemType>::Display()
// �������: ��ʾ�ڽӾ�������ͼ
{

	for (int v = 0; v < vexNum; v++)
		cout << "\t" << vertexes[v];
	cout << endl;

	for (int v = 0; v < vexNum; v++) {
		cout << vertexes[v];
		for (int u = 0; u < vexNum; u++)
			if (arcs[v][u] == 0) cout << "\t" << "0";
			else { cout << "\t" << arcs[v][u]; }
		cout << endl;
	}
}

template<class ElemType>
bool WuXiangTu<ElemType>::FindPath(int v1, int v2)
{
	if (v1 < 0 || v1 >= vexNum)
		cout << "v1���Ϸ�!" << endl;
	if (v2 < 0 || v2 >= vexNum)
		cout << "v2���Ϸ�!" << endl;
	if (v1 == v2)
		cout << "v1���ܵ���v2!" << endl;

		ElemType start;
		GetElem(v1, start);
		q1.EnQueue(start);

	if (arcs[v1][v2] != 0)//����Ϊ1��·��
	{

		ElemType end;
		GetElem(v2, end);
		q1.EnQueue(end);

		cout << "Exist. Path:";
		q1.DisplayQueue();
		cout << endl;
		return 1;
	}

	else
	{
		for (int u = v1+1; u < vexNum; u++)//�����ǵݹ��������·��
		{
			if (arcs[v1][u] != 0)
			{
				if (FindPath(u, v2))
					return 1;
				else
				{
					q1.DelQueue();
				}
			}
		}
		return 0;
	}
}
