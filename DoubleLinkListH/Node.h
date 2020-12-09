#ifndef __DBL_NODE_H__
#define __DBL_NODE_H__


// ˫����������
template <class ElemType>
struct DblNode
{
	// ���ݳ�Ա:
	ElemType data;				// ������
	DblNode<ElemType>* prior;	// ָ��ǰ������ָ����
	DblNode<ElemType>* next;	// ָ���̽���ָ����
	int freq;					//����Ƶ��
// ���캯��:
	DblNode();						// �����ݵĹ��캯��
	DblNode(ElemType item,
		DblNode<ElemType>* priorlink = NULL,
		DblNode<ElemType>* nextlink = NULL,
		int freq =0);// ��֪�������ָ�������ṹ
};


// ˫�����������ʵ�ֲ���

template<class ElemType>
DblNode<ElemType>::DblNode()
// �������������ָ����Ϊ�յĽ��
{
	prior = NULL;
	next = NULL;
	freq = 0;
}

template<class ElemType>
DblNode<ElemType>::DblNode(ElemType item,
	DblNode<ElemType>* priorlink,
	DblNode<ElemType>* nextlink,
	int freq )
	// �������������һ��������Ϊitem��priorָ����Ϊpriorlink��nextָ����Ϊnextlink�Ľ��
{
	data = item;
	prior = priorlink;
	next = nextlink;
	freq = 0;
}

#endif
