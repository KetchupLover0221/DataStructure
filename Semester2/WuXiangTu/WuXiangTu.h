#pragma once
#include <iostream>
#include"Queue.h"
using namespace std;

SeqQueue<char> q1;//路径队列

template <class ElemType>
class WuXiangTu
{
protected:
	int vexNum, vexMaxNum, arcNum;//点数、最大点数、边数
	int** arcs;//边
	ElemType* vertexes;//顶点信息
	int * tag;//标志
public:
	WuXiangTu(ElemType es[], int vertexNum, int vertexMaxNum = 9999);//顶点数组、顶点数、最多顶点数
	WuXiangTu(int vertexMaxNum = 9999);
	~WuXiangTu();
	void Clear();//顶点与边设为0
	bool IsEmpty();
	int GetOrder(ElemType& d) const;//得到顶点序号
	void GetElem(int v, ElemType& d) const;//用d返回编号为v的元素值
	void SetElem(int v, const ElemType& d);//将编号为v的元素设为d
	int GetVexNum()const;//顶点数
	int GetArcNum() const;//边数
	int FirstAdjVex(int v)const;//编号为v的第一个邻接点
	int NextAdjVex(int v1, int v2) const;//顶点v1 除v2 外的下一个邻接点
	void InsertVex(const ElemType& d);//插入点
	void InsertArc(int v1, int v2, int weight); //v1 v2 间插入边
	void DeleteVex(const ElemType& d);//删除点
	void DeleteArc(int v1, int v2);//删除边
	int GetTag(int v);//v顶点的状态
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
	delete[]vertexes;					// 释放顶点数据
	delete[]tag;						    // 释放标志
	for (int v = 0; v < vexMaxNum; v++)	// 释放邻接矩阵的行
		delete[]arcs[v];
	delete[]arcs;					    // 释放邻接矩阵
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
			return v;	    // 顶点d存在,返回它的序号 
	return -1;	        // 顶点d不存在,返回-1
}

template<class ElemType>
void  WuXiangTu<ElemType>::GetElem(int v, ElemType& d) const
{
	if (v < 0 || v >= vexNum)
		cout<<"NOT_PRESENT";	// v范围错
	else 
	{
		d = vertexes[v];	  // 将顶点v的元素值赋给d
	}
}

template<class ElemType>
void  WuXiangTu<ElemType>::SetElem(int v, const ElemType& d)
{
	if (v < 0 || v >= vexNum)
		cout<<"RANGE_ERROR";	// v范围错,返回位置错
	else 
	{
		vertexes[v] = d;		// 将顶点元素的值改为d 
	}
}

template <class ElemType>
int WuXiangTu<ElemType>::GetVexNum() const
// 操作结果：返回顶点个数			 
{
	return vexNum;
}

template <class ElemType>
int WuXiangTu<ElemType>::GetArcNum() const
// 操作结果：返回边数
{
	return arcNum;
}

template <class ElemType>
int WuXiangTu<ElemType>::FirstAdjVex(int v) const
// 操作结果：返回顶点v的第1个邻接点的序号		 
{
	if (v < 0 || v >= vexNum)
		cout << "v不合法!" <<endl;

	for (int u = 0; u < vexNum; u++)
		if (arcs[v][u] != 0)
			return u;
	return -1;					// 返回-1表示无邻接点
}

template <class ElemType>
int WuXiangTu<ElemType>::NextAdjVex(int v1, int v2) const
// 操作结果：返回顶点v1的相对于v2的下一个邻接点			 
{
	if (v1 < 0 || v1 >= vexNum)
		cout << "v不合法!" << endl;
	if (v2 < 0 || v2 >= vexNum)
		cout << "v不合法!" << endl;
	if (v1 == v2) 
		cout << "v不合法!" << endl;// 抛出异常
	for (int u = v2 + 1; u < vexNum; u++)
		if (arcs[v1][u] != 0)
			return u;
	return -1;						// 返回-1表示无下一个邻接点
}

template<class ElemType>
void  WuXiangTu<ElemType>::InsertVex(const ElemType& d)
{
	if (vexNum == vexMaxNum)
		cout << "图的顶点数不能超过允许的最大数!" << endl;

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
// 操作结果：插入依附顶点v1和v2的边			 
{
	if (v1 < 0 || v1 >= vexNum)
		cout << "v1不合法!" << endl;
	if (v2 < 0 || v2 >= vexNum)
		cout << "v2不合法!" << endl;
	if (v1 == v2)
		cout << "v1不能等于v2!" << endl;

	if (arcs[v1][v2] == 0&& weight !=0) 
	{									// 原无向图中没有边(v1, v2) 
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
		cout << "图中不存在要删除的顶点!" << endl;// 抛出异常

	for (int u = 0; u < vexNum; u++)             // 删除与顶点d相关联的边 
		if (arcs[v][u] != 0) {
			arcNum--;
			arcs[v][u] = 0;
			arcs[u][v] = 0;
		}

	vexNum--;
	if (v < vexNum)
	{//最后一个顶点的信息换到被删顶点的位置
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
// 操作结果：删除依附顶点v1和v2的边			 
{
	if (v1 < 0 || v1 >= vexNum)
		cout << "v1不合法!" << endl;
	if (v2 < 0 || v2 >= vexNum)
		cout << "v2不合法!" << endl;
	if (v1 == v2)
		cout << "v1不能等于v2!" << endl;

	if (arcs[v1][v2] != 0) {	// 原无向图存在边(v1, v2)
		arcNum--;
		arcs[v1][v2] = 0;
		arcs[v2][v1] = 0;
	}
}

template <class ElemType>
int WuXiangTu<ElemType>::GetTag(int v) 
// 操作结果：返回顶点v的标志		 
{
	if (v < 0 || v >= vexNum)
		cout << "v不合法!" << endl;// 抛出异常
	return tag[v];
}

template <class ElemType>
void WuXiangTu<ElemType>::SetTag(int v, int val) 
// 操作结果：设置顶点v的标志为val		 
{
	if (v < 0 || v >= vexNum)
		cout<<"v不合法!"<<endl;	// 抛出异常
	tag[v] = val;
}

template <class ElemType>
void WuXiangTu<ElemType>::Display()
// 操作结果: 显示邻接矩阵无向图
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
		cout << "v1不合法!" << endl;
	if (v2 < 0 || v2 >= vexNum)
		cout << "v2不合法!" << endl;
	if (v1 == v2)
		cout << "v1不能等于v2!" << endl;

		ElemType start;
		GetElem(v1, start);
		q1.EnQueue(start);

	if (arcs[v1][v2] != 0)//长度为1的路径
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
		for (int u = v1+1; u < vexNum; u++)//上三角递归查找所有路径
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
