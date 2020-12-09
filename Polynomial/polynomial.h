#ifndef __POLYNOMIAL_H__
#define __POLYNOMIAL_H__

#include "Assistance.h"			// ���������
#include "LinkList.h"			// ������
#include "PolyItem.h"			// ����ʽ����


// ����ʽ��
class Polynomial
{
protected:
	// ����ʽʵ�ֵ����ݳ�Ա:
	LinkList<PolyItem> polyList;// ����ʽ��ɵ����Ա�

public:
	//  �����������ͷ������������ر���ϵͳĬ�Ϸ�������:
	Polynomial() {};				// �޲ι��캯��
	~Polynomial() {};			// ��������
	int Length() const;			// �����ʽ������			 
	bool IsZero() const;		// �ж϶���ʽ�Ƿ�Ϊ0
	void SetZero();				// ������ʽ��Ϊ0
	void Display();				// ��ʾ����ʽ
	void InsItem(const PolyItem& item);		// ����һ��
	Polynomial operator +(const Polynomial& p) const; // �ӷ����������
	Polynomial(const Polynomial& copy);			// ���ƹ��캯��
	Polynomial(const LinkList<PolyItem>& copyLinkList);
	// �ɶ���ʽ��ɵ����Ա������ʽ
	Polynomial& operator =(const Polynomial& copy);	// ��ֵ�������
	Polynomial& operator =(const LinkList<PolyItem>& copyLinkList);	// ��ֵ�������

	void Cal(double x);
	void Qd();
};


// ����ʽ���ʵ�ֲ���

int Polynomial::Length() const
// ������������ض���ʽ������
{
	return polyList.GetLength();
}

bool Polynomial::IsZero() const
// ��������������ʽΪ0���򷵻�true�����򷵻�false
{
	return polyList.IsEmpty();
}

void Polynomial::SetZero()
// ���������������ʽ��Ϊ0
{
	polyList.Clear();
}

void Polynomial::Display()
// �����������ʾ����ʽ
{
	int pos = 1;
	PolyItem it;
	Status status = polyList.GetElem(pos, it);
	while (status == ENTRY_FOUND) {// ������ʾ����ʽ��ÿһ��
		if (pos > 1 && it.coef > 0)
			cout << "+";
		if (it.coef != 1)
			if (it.coef != -1)
				cout << it.coef;
			else
				cout << "-";
		if (it.expn > 1)
			cout << "x^" << it.expn;
		else
			if (it.expn == 1)
				cout << "x";
		status = polyList.GetElem(++pos, it);	// ȡ����һ��
	}
}

void Polynomial::InsItem(const PolyItem& item)
// ��������������ʽ����һ��
{
	int pos = 1;
	PolyItem it;
	Status status = polyList.GetElem(pos, it);
	while (status == ENTRY_FOUND && it.expn > item.expn) 	// ���Ҳ���λ��
		status = polyList.GetElem(++pos, it);
	polyList.InsertElem(pos, item);					            // �����ʽ����һ��
}

Polynomial Polynomial::operator +(const Polynomial& p) const
// ������������ص�ǰ����ʽ��p֮�͡����ӷ����������
{
	LinkList<PolyItem> la = polyList;			// ��ǰ����ʽ��Ӧ�����Ա�
	LinkList<PolyItem> lb = p.polyList;			// ����ʽp��Ӧ�����Ա�
	LinkList<PolyItem> lc;						// �Ͷ���ʽ��Ӧ�����Ա�
	int aPos = 1, bPos = 1;
	PolyItem aItem, bItem;
	Status aStatus, bStatus;

	aStatus = la.GetElem(aPos++, aItem);			// ȡ��la�ĵ�1�� 
	bStatus = lb.GetElem(bPos++, bItem);			// ȡ��lb�ĵ�1��

	while (aStatus == ENTRY_FOUND && bStatus == ENTRY_FOUND) {
		if (aItem.expn > bItem.expn) {		// la�е���aItemָ����С
			lc.InsertElem(aItem);	// ��aItem׷�ӵ�lc�ı�β 
			aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
		}
		else if (aItem.expn < bItem.expn) {	// lb�е���bItemָ����С
			lc.InsertElem(bItem);	// ��bItem׷�ӵ�lc�ı�β
			bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
		}
		else {	// la�е���aItem��lb�е���bItemָ�����
			PolyItem sumItem(aItem.coef + bItem.coef, aItem.expn);
			if (sumItem.coef != 0)
				lc.InsertElem(sumItem);	// ������ĺ�׷�ӵ�lc�ı�β
			aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
			bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
		}
	}

	while (aStatus == ENTRY_FOUND) {	// ��la��ʣ����׷�ӵ�lc�ĺ���
		lc.InsertElem(aItem);	// ��aItem׷�ӵ�lc�ĺ���
		aStatus = la.GetElem(aPos++, aItem);// ȡ��la�ĵ���һ��
	}

	while (bStatus == ENTRY_FOUND) {	// ��lb��ʣ����׷�ӵ�lc�ĺ���
		lc.InsertElem(bItem);	// ��bItem׷�ӵ�lc�ĺ���
		bStatus = lb.GetElem(bPos++, bItem);// ȡ��lb�ĵ���һ��
	}

	Polynomial fc;							// �Ͷ���ʽ
	fc.polyList = lc;

	return fc;
}

Polynomial::Polynomial(const Polynomial& copy)
// ����������ɶ���ʽcopy�����¶���ʽ�������ƹ��캯��
{
	polyList = copy.polyList;
}

Polynomial::Polynomial(const LinkList<PolyItem>& copyLinkList)
// ����������ɶ���ʽ��ɵ����Ա������ʽ����ת�����캯��
{
	polyList = copyLinkList;
}

Polynomial& Polynomial::operator =(const Polynomial& copy)
// ���������������ʽcopy��ֵ����ǰ����ʽ������ֵ�������
{
	if (&copy != this) {
		polyList = copy.polyList;
	}
	return *this;
}

Polynomial& Polynomial::operator =(const LinkList<PolyItem>& copyLinkList)
// ���������������ʽ��ɵ����Ա�copyLinkList��ֵ����ǰ����ʽ
//	������ֵ�������
{
	polyList = copyLinkList;
	return *this;
}

void Polynomial::Cal(double x)
{
	int i;
	int exp;
	Status st;
	PolyItem it;
	double coe, pow;
	double y = 0;
	for (int i = 1; i <= Length(); i++)
	{
		st = polyList.GetElem(i, it);
		coe = it.coef;
		exp = it.expn;
		pow = 1;
		for (int i = 1; i < exp+1; i++)
		{
			pow = pow * x;
		}
		y += coe * pow;//ax^b
	}
	cout << y << endl;
}

void Polynomial::Qd()
{
	int i;
	Status st;
	PolyItem it;
	for (int i = 1; i <= Length(); i++)
	{
		st = polyList.GetElem(i, it);
		if (it.expn == 0)
		{
			polyList.DeleteElem(i, it);
		}
		else
		{
			it.coef = it.coef * it.expn;
			it.expn--;
			polyList.SetElem(i, it);
		}
	}
}
#endif
