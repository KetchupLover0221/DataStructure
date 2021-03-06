#pragma once
using namespace std;
#include"BinNode.h"
#include"..\..\wk3\Akm\LinkStack.h"
#include"..\..\wk3\Queue\Queue.h"
template <class T>
class BinaryTree
{
protected:
    BinTreeNode<T>* _root; //二叉树根节点的指针
    T _refValue;           //创建二叉树时的结束标志

    /* 创建二叉树 */
    void CreateBinTree_PreOrder(BinTreeNode<T>*& root); //利用已知的二叉树的前序遍历创建二叉树

    /* 遍历二叉树 */
    void PreOrder(BinTreeNode<T>*& root);            //前序遍历
    void InOrder(BinTreeNode<T>*& root);             //中序遍历
    void PostOrder(BinTreeNode<T>*& root);           //后序遍历
    void PreOrder_NoRecurve(BinTreeNode<T>*& root);  //前序遍历非递归
    void InOrder_NoRecurve(BinTreeNode<T>*& root);   //中序遍历非递归
    void PostOrder_NoRecurve(BinTreeNode<T>*& root); //后序遍历非递归
    void LevelOrder(BinTreeNode<T>*& root);          //层次遍历

    /* 获取信息 */
    int GetDepth(const BinTreeNode<T>* root) const;                                //求高度
    int GetNodeNum(const BinTreeNode<T>* root) const;                               //求节点个数
    BinTreeNode<T>* GetParent(BinTreeNode<T>* root, const BinTreeNode<T>* p) const; //求父节点
    int GetmaxWidth(BinTreeNode<T>* root) const;                                    //求最大宽度
    int GetLeafNum(const BinTreeNode<T>* root) const;                               //求叶子节点数目

    /* 其他 */
    BinTreeNode<T>* CopyTree(const BinTreeNode<T>* originNode); //复制二叉树
    void DestroyTree(BinTreeNode<T>*& root);                    //删除二叉树
    bool IsEqual(const BinTreeNode<T>*& a, const BinTreeNode<T>*& b) const;
    void ExchangeLeftRight(BinTreeNode<T>*& root);            //交换左右子树

public:
    /* 构造与析构 */
    BinaryTree() : _root(NULL) {};
    BinaryTree(T refValue) : _refValue(refValue) { _root = new BinTreeNode<T>; } //构造函数，指定结束标志refValue
    virtual ~BinaryTree() { DestroyTree(_root); };
    BinaryTree(const BinaryTree<T>& copy);

    /*运算符重载*/
    BinaryTree<T>& operator=(const BinaryTree<T>& copy);
    bool operator==(BinaryTree<T>* s) { return (IsEqual(_root, s->_root)); }

    /* 创建二叉树 */
    void CreateBinTree_PreOrder() { CreateBinTree_PreOrder(_root); } //用先序遍历结果创建二叉树

    /* 遍历二叉树 */
    void PreOrder() { PreOrder(_root); }
    void InOrder() { InOrder(_root); }
    void PostOrder() { PostOrder(_root); }
    void PreOrder_NoRecurve() { PreOrder(_root); }
    void InOrder_NoRecurve() { InOrder(_root); }
    void PostOrder_NoRecurve() { PostOrder(_root); }
    void LevelOrder() { LevelOrder(_root); }

    /* 获取信息 */
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
    /* 其他 */
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
            cout << p->_data << " "; //先打印父节点
            Stack.Push(p);       //父节点入栈
            p = p->_leftChild;       //转到左节点
        }
        else
        {
            p = Stack.Top(); //回溯到父节点
            Stack.Pop();     //父节点出栈
            p = p->_rightChild;  //转到右节点
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
            Stack.Push(p); //入栈
            p = p->_leftChild; //转到左节点
        }
        else
        {
            p = Stack.Top();
            Stack.Pop();         //栈顶出栈
            cout << p->_data << " "; //即将转到右节点时，打印栈顶
            p = p->_rightChild;      //转到右节点
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
            if (Tag.Top() == 0) //此时左节点已经遍历完
            {
                p = Stack.Top(); //预出栈
                Tag.Pop();
                Tag.Push(1); //将Tag栈顶改为1，表示已经遍历完左节点
                p = p->_rightChild;
            }
            else //此时右节点已经遍历完
            {
                Stack.Pop(); //真正出栈
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
//层次遍历
{
    SeqQueue<BinTreeNode<T>*> Queue;
    BinTreeNode<T>* p;
    if (root != NULL)
        Queue.EnQueue(root); //若根非空，则入队
    while (!Queue.IsEmpty())
    {
        Queue.GetHead(p);    //取队头
        Queue.DelQueue();     //出队
        cout << p->_data << " "; //打印打印！

        if (p->_leftChild != NULL) //若左节点非空，入队
        {
            Queue.EnQueue(p->_leftChild);
        }
        if (p->_rightChild != NULL) //若右节点非空，入队
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
//销毁二叉树，递归进行。先删左子树再删右子树，最后删自己
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
//复制二叉树，返回一个指针，给出一个以originNode为根复制的二叉树的副本
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
//从root开始搜索p的父节点
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->_leftChild == p || root->_rightChild == p) //如果找到，返回父节点root
    {
        return root;
    }
    if (GetParent(root->_leftChild, p) == p) //递归在左子树中搜索
    {
        return GetParent(root->_leftChild, p);
    }
    else //递归右子树中搜索
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
//创建二叉树
{
    T data;
    cout << "input data: " << endl;
    if (cin >> data)
    {
        if (data != _refValue)
        {
            root = new BinTreeNode<T>(data);
            CreateBinTree_PreOrder(root->_leftChild);  //递归创建左子树
            CreateBinTree_PreOrder(root->_rightChild); //递归创建右子树
        }
        else
        {
            root = NULL;
        }
    }
}

template <class T>
int BinaryTree<T>::GetmaxWidth(BinTreeNode<T>* root) const
//获取二叉树最大宽度，采用层序遍历
{
    SeqQueue<BinTreeNode<T>*> Queue;
    BinTreeNode<T>* p;
    int maxWidth = 0, curWidth = 0, nextWidth; //最大节点数，当前层节点数，下一层节点数
    if (root != NULL)                          //根节点
    {
        maxWidth = 1;
        curWidth = 1;
        Queue.EnQueue(root); //若根非空，则入队
    }
    while (!Queue.IsEmpty())
    {
        nextWidth = 0; //nextWidth归零
        for (int i = 0; i < curWidth; i++)
        {
            p = Queue.GetHead(); //取队头
            Queue.DelQueue();  //出队

            if (p->_leftChild != NULL) //若当前节点有左孩子，nextWidth++
            {
                Queue.EnQueue(p->_leftChild);
                nextWidth++;
            }
            if (p->_rightChild != NULL) //若当前节点有右孩子，nextWidth++
            {
                Queue.EnQueue(p->_rightChild);
                nextWidth++;
            }
        }
        curWidth = nextWidth; //此时进入下一层的遍历
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

