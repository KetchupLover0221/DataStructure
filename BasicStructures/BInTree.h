#pragma once
using namespace std;
#include"BinNode.h"
#include"..\..\wk3\Akm\LinkStack.h"
#include"..\..\wk3\Queue\Queue.h"
template <class T>
class BinaryTree
{
protected:
    BinTreeNode<T>* _root; //���������ڵ��ָ��
    T _refValue;           //����������ʱ�Ľ�����־

    /* ���������� */
    void CreateBinTree_PreOrder(BinTreeNode<T>*& root); //������֪�Ķ�������ǰ���������������

    /* ���������� */
    void PreOrder(BinTreeNode<T>*& root);            //ǰ�����
    void InOrder(BinTreeNode<T>*& root);             //�������
    void PostOrder(BinTreeNode<T>*& root);           //�������
    void PreOrder_NoRecurve(BinTreeNode<T>*& root);  //ǰ������ǵݹ�
    void InOrder_NoRecurve(BinTreeNode<T>*& root);   //��������ǵݹ�
    void PostOrder_NoRecurve(BinTreeNode<T>*& root); //��������ǵݹ�
    void LevelOrder(BinTreeNode<T>*& root);          //��α���

    /* ��ȡ��Ϣ */
    int GetDepth(const BinTreeNode<T>* root) const;                                //��߶�
    int GetNodeNum(const BinTreeNode<T>* root) const;                               //��ڵ����
    BinTreeNode<T>* GetParent(BinTreeNode<T>* root, const BinTreeNode<T>* p) const; //�󸸽ڵ�
    int GetmaxWidth(BinTreeNode<T>* root) const;                                    //�������
    int GetLeafNum(const BinTreeNode<T>* root) const;                               //��Ҷ�ӽڵ���Ŀ

    /* ���� */
    BinTreeNode<T>* CopyTree(const BinTreeNode<T>* originNode); //���ƶ�����
    void DestroyTree(BinTreeNode<T>*& root);                    //ɾ��������
    bool IsEqual(const BinTreeNode<T>*& a, const BinTreeNode<T>*& b) const;
    void ExchangeLeftRight(BinTreeNode<T>*& root);            //������������

public:
    /* ���������� */
    BinaryTree() : _root(NULL) {};
    BinaryTree(T refValue) : _refValue(refValue) { _root = new BinTreeNode<T>; } //���캯����ָ��������־refValue
    virtual ~BinaryTree() { DestroyTree(_root); };
    BinaryTree(const BinaryTree<T>& copy);

    /*���������*/
    BinaryTree<T>& operator=(const BinaryTree<T>& copy);
    bool operator==(BinaryTree<T>* s) { return (IsEqual(_root, s->_root)); }

    /* ���������� */
    void CreateBinTree_PreOrder() { CreateBinTree_PreOrder(_root); } //����������������������

    /* ���������� */
    void PreOrder() { PreOrder(_root); }
    void InOrder() { InOrder(_root); }
    void PostOrder() { PostOrder(_root); }
    void PreOrder_NoRecurve() { PreOrder(_root); }
    void InOrder_NoRecurve() { InOrder(_root); }
    void PostOrder_NoRecurve() { PostOrder(_root); }
    void LevelOrder() { LevelOrder(_root); }

    /* ��ȡ��Ϣ */
    BinTreeNode<T>* GetRoot() const { return _root; }
    int GetDepth() const { return GetDepth(_root); }
    int GetNodeNum() const { return GetNodeNum(_root); }
    int GetmaxWidth() const { return GetmaxWidth(_root); }
    int GetLeafNum() const { return GetLeafNum(_root); }
    BinTreeNode<T>* GetParent(const BinTreeNode<T>* p) const { return (_root == NULL || _root == p) ? NULL : GetParent(_root, p); }
    BinTreeNode<T>* GetLeftChild(const BinTreeNode<T>* p) const { return (p == NULL) ? NULL : p->_leftChild; }
    BinTreeNode<T>* GetRightChild(const BinTreeNode<T>* p) const { return (p == NULL) ? NULL : p->_rightChild; }
    BinTreeNode<T>* GetLeftSibling(const BinTreeNode<T>* p) const;
    BinTreeNode<T>* GetRightSibling(const BinTreeNode<T>* p) const;
    /* ���� */
    BinTreeNode<T>* CopyTree() { CopyTree(_root); }
    void DestroyTree() { DestroyTree(_root); }
    bool IsEmpty() const { return (_root == NULL) ? true : false; }
    void InsertLeftChild(BinTreeNode<T>*& p, const T& data);
    void InsertRightChild(BinTreeNode<T>*& p, const T& data);
    T GetElem(BinTreeNode<T>* p) const { return p->_data; }
    void SetElem(BinTreeNode<T>* p, T data) { p->_data = data; }
    void ExchangeLeftRight() { ExchangeLeftRight(_root); }
};

template <class T>
BinaryTree<T>::BinaryTree(const BinaryTree<T>& copy)
{
    _root = CopyTree(copy._root);
}

template <class T>
BinaryTree<T>& BinaryTree<T>::operator=(const BinaryTree<T>& copy)
{
    if (&copy != this)
    {
        _root = CopyTree(copy._root);
    }
    return *this;
}

template <class T>
void BinaryTree<T>::PreOrder(BinTreeNode<T>*& root)
{
    if (root != NULL)
    {
        cout << root->_data << " ";
        PreOrder(root->_leftChild);
        PreOrder(root->_rightChild);
    }
}

template <class T>
void BinaryTree<T>::InOrder(BinTreeNode<T>*& root)
{
    if (root != NULL)
    {
        InOrder(root->_leftChild);
        cout << root->_data << " ";
        InOrder(root->_rightChild);
    }
}

template <class T>
void BinaryTree<T>::PostOrder(BinTreeNode<T>*& root)
{
    if (root != NULL)
    {
        PostOrder(root->_leftChild);
        PostOrder(root->_rightChild);
        cout << root->_data << " ";
    }
}

template <class T>
void BinaryTree<T>::PreOrder_NoRecurve(BinTreeNode<T>*& root)

{
    if (root == NULL)
        return;
    LinkStack<BinTreeNode<T>*> Stack;
    BinTreeNode<T>* p = root;
    while (!Stack.IsEmpty())
    {
        if (p != NULL)
        {
            cout << p->_data << " "; //�ȴ�ӡ���ڵ�
            Stack.Push(p);       //���ڵ���ջ
            p = p->_leftChild;       //ת����ڵ�
        }
        else
        {
            p = Stack.Top(); //���ݵ����ڵ�
            Stack.Pop();     //���ڵ��ջ
            p = p->_rightChild;  //ת���ҽڵ�
        }
    }
}

template <class T>
void BinaryTree<T>::InOrder_NoRecurve(BinTreeNode<T>*& root)

{
    if (root == NULL)
        return;
    LinkStack<BinTreeNode<T>*> Stack;
    BinTreeNode<T>* p = root;
    while (!Stack.IsEmpty())
    {
        if (p != NULL)
        {
            Stack.Push(p); //��ջ
            p = p->_leftChild; //ת����ڵ�
        }
        else
        {
            p = Stack.Top();
            Stack.Pop();         //ջ����ջ
            cout << p->_data << " "; //����ת���ҽڵ�ʱ����ӡջ��
            p = p->_rightChild;      //ת���ҽڵ�
        }
    }
}

template <class T>
void BinaryTree<T>::PostOrder_NoRecurve(BinTreeNode<T>*& root)

{
    if (_root == NULL)
        return;
    LinkStack<BinTreeNode<T>*> Stack;
    LinkStack<BinTreeNode<T>*> Tag;
    BinTreeNode<T>* p = root;
    while (!Stack.IsEmpty())
    {
        if (p != NULL)
        {
            Stack.Push(p);
            Tag.Push(0);
            p = p->_leftChild;
        }
        else
        {
            if (Tag.Top() == 0) //��ʱ��ڵ��Ѿ�������
            {
                p = Stack.Top(); //Ԥ��ջ
                Tag.Pop();
                Tag.Push(1); //��Tagջ����Ϊ1����ʾ�Ѿ���������ڵ�
                p = p->_rightChild;
            }
            else //��ʱ�ҽڵ��Ѿ�������
            {
                Stack.Pop(); //������ջ
                Tag.Pop();
                cout << p->_data << " ";
                p = Stack.Top();
                p = p->_rightChild;
            }
        }
    }
}

template <class T>
void BinaryTree<T>::LevelOrder(BinTreeNode<T>*& root)
//��α���
{
    SeqQueue<BinTreeNode<T>*> Queue;
    BinTreeNode<T>* p;
    if (root != NULL)
        Queue.EnQueue(root); //�����ǿգ������
    while (!Queue.IsEmpty())
    {
        Queue.GetHead(p);    //ȡ��ͷ
        Queue.DelQueue();     //����
        cout << p->_data << " "; //��ӡ��ӡ��

        if (p->_leftChild != NULL) //����ڵ�ǿգ����
        {
            Queue.EnQueue(p->_leftChild);
        }
        if (p->_rightChild != NULL) //���ҽڵ�ǿգ����
        {
            Queue.EnQueue(p->_rightChild);
        }
    }
}


template <class T>
void BinaryTree<T>::ExchangeLeftRight(BinTreeNode<T>*& root)
{
    if (root != NULL)
    {
        swap(root->_leftChild, root->_rightChild);
        ExchangeLeftRight(root->_leftChild);
        ExchangeLeftRight(root->_rightChild);
    }
}

template <class T>
void BinaryTree<T>::DestroyTree(BinTreeNode<T>*& root)
//���ٶ��������ݹ���С���ɾ��������ɾ�����������ɾ�Լ�
{
    if (root != NULL)
    {
        DestroyTree(root->_leftChild);
        DestroyTree(root->_rightChild);
        delete root;
        root = NULL;
    }
}

template <class T>
BinTreeNode<T>* BinaryTree<T>::CopyTree(const BinTreeNode<T>* originNode)
//���ƶ�����������һ��ָ�룬����һ����originNodeΪ�����ƵĶ������ĸ���
{
    if (originNode == NULL)
    {
        return NULL;
    }
    BinTreeNode<T>* p = new BinTreeNode<T>;
    p->_data = originNode->_data;
    p->_leftChild = CopyTree(originNode->_leftChild);
    p->_rightChild = CopyTree(originNode->_rightChild);
    return p;
}

template <class T>
bool BinaryTree<T>::IsEqual(const BinTreeNode<T>*& a, const BinTreeNode<T>*& b) const
{
    if (a == NULL && b == NULL)
    {
        return true;
    }
    if (a != NULL && b != NULL && a->_data == b->_data && IsEqual(a->_leftChild, b->_rightChild) && IsEqual(a->_rightChild, b->_rightChild))
    {
        return true;
    }
    else
    {
        return false;
    }
}

template <class T>
int BinaryTree<T>::GetNodeNum(const BinTreeNode<T>* root) const
{
    if (root == NULL)
    {
        return 0;
    }
    return 1 + GetNodeNum(root->_leftChild) + GetNodeNum(root->_rightChild);
}

template <class T>
int BinaryTree<T>::GetDepth(const BinTreeNode<T>* root) const
{
    if (root == NULL)
    {
        return 0;
    }
    int i = GetDepth(root->_leftChild);
    int j = GetDepth(root->_rightChild);
    return i > j ? i + 1 : j + 1;
}

template <class T>
BinTreeNode<T>* BinaryTree<T>::GetParent(BinTreeNode<T>* root, const BinTreeNode<T>* p) const
//��root��ʼ����p�ĸ��ڵ�
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->_leftChild == p || root->_rightChild == p) //����ҵ������ظ��ڵ�root
    {
        return root;
    }
    if (GetParent(root->_leftChild, p) == p) //�ݹ���������������
    {
        return GetParent(root->_leftChild, p);
    }
    else //�ݹ�������������
    {
        return GetParent(root->_rightChild, p);
    }
}

template <class T>
BinTreeNode<T>* BinaryTree<T>::GetLeftSibling(const BinTreeNode<T>* p) const
{
    BinTreeNode<T>* r = GetParent(_root, p);
    if (r == NULL)
    {
        return NULL;
    }
    if (r->_rightChild == p)
    {
        return r->_leftChild;
    }
    else
    {
        return NULL;
    }
}

template <class T>
BinTreeNode<T>* BinaryTree<T>::GetRightSibling(const BinTreeNode<T>* p) const
{
    BinTreeNode<T>* r = GetParent(_root, p);
    if (r == NULL)
    {
        return NULL;
    }
    if (r->_leftChild == p)
    {
        return r->_rightChild;
    }
    else
    {
        return NULL;
    }
}

template <class T>
void BinaryTree<T>::InsertLeftChild(BinTreeNode<T>*& p, const T& data)
{
    if (p == NULL)
    {
        return;
    }
    if (p->_leftChild != NULL)
        p->_leftChild->_data = data;
    else
    {
        BinTreeNode<T>* r = new BinTreeNode<T>(data);
        p->_leftChild = r;
    }
}

template <class T>
void BinaryTree<T>::InsertRightChild(BinTreeNode<T>*& p, const T& data)
{
    if (p == NULL)
    {
        return;
    }
    if (p->_rightChild != NULL)
        p->_rightChild->_data = data;
    else
    {
        BinTreeNode<T>* r = new BinTreeNode<T>(data);
        p->_rightChild = r;
    }
}

template <class T>
void BinaryTree<T>::CreateBinTree_PreOrder(BinTreeNode<T>*& root)
//����������
{
    T data;
    cout << "input data: " << endl;
    if (cin >> data)
    {
        if (data != _refValue)
        {
            root = new BinTreeNode<T>(data);
            CreateBinTree_PreOrder(root->_leftChild);  //�ݹ鴴��������
            CreateBinTree_PreOrder(root->_rightChild); //�ݹ鴴��������
        }
        else
        {
            root = NULL;
        }
    }
}

template <class T>
int BinaryTree<T>::GetmaxWidth(BinTreeNode<T>* root) const
//��ȡ����������ȣ����ò������
{
    SeqQueue<BinTreeNode<T>*> Queue;
    BinTreeNode<T>* p;
    int maxWidth = 0, curWidth = 0, nextWidth; //���ڵ�������ǰ��ڵ�������һ��ڵ���
    if (root != NULL)                          //���ڵ�
    {
        maxWidth = 1;
        curWidth = 1;
        Queue.EnQueue(root); //�����ǿգ������
    }
    while (!Queue.IsEmpty())
    {
        nextWidth = 0; //nextWidth����
        for (int i = 0; i < curWidth; i++)
        {
            p = Queue.GetHead(); //ȡ��ͷ
            Queue.DelQueue();  //����

            if (p->_leftChild != NULL) //����ǰ�ڵ������ӣ�nextWidth++
            {
                Queue.EnQueue(p->_leftChild);
                nextWidth++;
            }
            if (p->_rightChild != NULL) //����ǰ�ڵ����Һ��ӣ�nextWidth++
            {
                Queue.EnQueue(p->_rightChild);
                nextWidth++;
            }
        }
        curWidth = nextWidth; //��ʱ������һ��ı���
        if (curWidth > maxWidth)
            maxWidth = curWidth;
    }
    return maxWidth;
}

template <class T>
int BinaryTree<T>::GetLeafNum(const BinTreeNode<T>* root) const
{
    if (root == NULL)
        return 0;
    else if (root->_leftChild == NULL && root->_rightChild == NULL)
        return 1;
    else
        return GetLeafNum(root->_leftChild) + GetLeafNum(root->_rightChild);
}

