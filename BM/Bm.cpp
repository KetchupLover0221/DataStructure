#include <algorithm>
#include <string>
#include <iostream>
#include<time.h>
using namespace std;
#define SIZE 256    //字符集字符数
double gettime(int restart = 0)	   // 参数带默认值，非零表示重新设置计时起点
{
    const double c = 0.0000001/ CLOCKS_PER_SEC;// 毫秒转换至秒
    static long t = clock(); 	// 静态局部变量，第一次调用本函数时，确定计时起点
    if (restart) t = clock();	   // 根据实参决定是否重新确定计时起点
    return c * (clock() - t); 		   // 从上一计时点到现在所经历的时间差
}

void generateBadChar(char* b, int m, int* badchar)//(模式串字符b，模式串长度m，模式串的哈希表)
{
    int i, ascii;
    for (i = 0; i < SIZE; ++i)
    {
        badchar[i] = -1;//哈希表初始化为-1
    }
    for (i = 0; i < m; ++i)
    {
        ascii = int(b[i]);  //计算字符的ASCII值
        badchar[ascii] = i;//重复字符被覆盖，记录的是最后出现的该字符的位置
    }
}
void generateGS(char* b, int m, int* suffix, bool* prefix)//预处理模式串，填充suffix，prefix
{
    int i, j, k;
    for (i = 0; i < m; ++i)//两个数组初始化
    {
        suffix[i] = -1;
        prefix[i] = false;
    }
    for (i = 0; i < m - 1; ++i)//b[0,i]
    {
        j = i;
        k = 0;//公共后缀子串长度(模式串尾部取k个出来，分别比较)
        while (j >= 0 && b[j] == b[m - 1 - k])//与b[0,m-1]求公共后缀子串
        {
            --j;
            ++k;
            suffix[k] = j + 1;
            //相同后缀子串长度为k时，该子串在b[0,i]中的起始下标
            // (如果有多个相同长度的子串，被赋值覆盖，存较大的)
        }
        if (j == -1)//查找到模式串的头部了
            prefix[k] = true;//如果公共后缀子串也是模式串的前缀子串
    }
}
int moveByGS(int j, int m, int* suffix, bool* prefix)//传入的j是坏字符对应的模式串中的字符下标
{
    int k = m - 1 - j;//好后缀长度
    if (suffix[k] != -1)//case1，找到跟好后缀一样的模式子串（多个的话，存的靠后的那个（子串起始下标））
        return j - suffix[k] + 1;
    for (int r = j + 2; r < m; ++r)//case2
    {
        if (prefix[m - r] == true)//m-r是好后缀的子串的长度，如果这个好后缀的子串是模式串的前缀子串
            return r;//在上面没有找到相同的好后缀下，移动r位，对齐前缀到好后缀
    }
    return m;//case3,都没有匹配的，移动m位（模式串长度）
}
int str_bm(char* a, int n, char* b, int m)//a表示主串，长n; b表示模式串,长m
{
    int* badchar = new int[SIZE];//记录模式串中每个字符最后出现的位置
    generateBadChar(b, m, badchar);     //构建坏字符哈希表
    int* suffix = new int[m];
    bool* prefix = new bool[m];
    generateGS(b, m, suffix, prefix);   //预处理模式串，填充suffix，prefix
    int i = 0, j, moveLen1, moveLen2;//j表示主串与模式串匹配的第一个字符
    while (i < n - m + 1)
    {
        for (j = m - 1; j >= 0; --j)  //模式串从后往前匹配
        {
            if (a[i + j] != b[j])
                break;  //坏字符对应模式串中的下标是j
        }
        if (j < 0)   //匹配成功
        {
            delete[] badchar;
            delete[] suffix;
            delete[] prefix;
            return i;   //返回主串与模式串第一个匹配的字符的位置
        }
        //这里等同于将模式串往后滑动 j-badchar[int(a[i+j])] 位
        moveLen1 = j - badchar[int(a[i + j])];//按照坏字符规则移动距离
        moveLen2 = 0;
        if (j < m - 1)//如果有好后缀的话
        {
            moveLen2 = moveByGS(j, m, suffix, prefix);//按照好后缀规则移动距离
        }
        i = i + max(moveLen1, moveLen2);//取大的移动
    }
    delete[] badchar;
    delete[] suffix;
    delete[] prefix;
    return -1;
}

int ViolentMatch(const char* s,const char* p)
{
    int sLen = strlen(s);
    int pLen = strlen(p);

    int i = 0;
    int j = 0;
    while (i < sLen && j < pLen)
    {
        if (s[i] == p[j])
        {
            //①如果当前字符匹配成功（即S[i] == P[j]），则i++，j++    
            i++;
            j++;
        }
        else
        {
            //②如果失配（即S[i]! = P[j]），令i = i - (j - 1)，j = 0    
            i = i - j + 1;
            j = 0;
        }
    }
    //匹配成功，返回模式串p在文本串s中的位置，否则返回-1
    if (j == pLen)
        return i - j;
    else
        return -1;
}


void GetNext(const string& pat, int* next)
//p[k]表示前缀，p[j]表示后缀
{
    int j = 0, k = -1;
    next[0] = -1; //设next[0]的初始值为-1
    while (pat[j] != '\0')
    {
        if (k == -1 || pat[j] == pat[k])
        {
            j++;
            k++;         //j,k向后走
            next[j] = k; //记录到此索引前字符串真子串的长度
        }
        else
            k = next[k]; //寻求新的匹配字符
    }
}

int KMP(const string& ob, const string& pat, const int start = 0)
{
    int* next = new int[pat.length()];
    GetNext(pat, next);
    int i = start, j = 0;
    while ((j == -1) || (ob[i] != '\0' && pat[j] != '\0'))
    {
        if (j == -1 || ob[i] == pat[j])
        {
            i++; //继续对下一个字符比较
            j++; //模式串向右滑动
        }
        else
            j = next[j]; //寻找新的匹配字符位置，模式串尽可能向右滑动
    }
    //delete[] next;
    if (pat[j] == '\0')
        return (i - j); //匹配成功返回下标
    else
        return -1; //匹配失败返回-1
}


int main()
{
    double t;
    string a = "abcabcabcabaabcabcabcabcabcabcd", b = "abcd";
    gettime(1);
    int bm = 0,kmp =0,v=0;
    for (int k = 0; k < 10000; k++)
    {
         bm = str_bm(&a[0], a.size(), &b[0], b.size());
    }
   //cout <<"BM:" <<a << "中第一次出现" << b << "的位置(从0开始)是：" << str_bm(&a[0], a.size(), &b[0], b.size())<<endl;
    t = gettime(0);
    cout << bm << endl;
    cout << "bm查找用时：" << t << "s" << '\n';

    gettime(1);
    for (int k = 0; k < 10000; k++)
    {
        kmp = KMP(a, b);
    }
   // cout << "KMP:" << a << "中第一次出现" << b << "的位置(从0开始)是：" << KMP(a,b)<< endl;
    t = gettime(0);
    cout << "kmp查找用时：" << t << "s" << '\n';

    gettime(1);
    for (int k = 0; k < 10000; k++)
    {
        v = ViolentMatch(&a[0], &b[0]);
    }
    //cout <<"朴素："<< a << "中第一次出现" << b << "的位置(从0开始)是：" << ViolentMatch(&a[0], &b[0])<<endl;
    t = gettime(0);
    cout << "朴素查找用时：" << t << "s" << '\n';
    return 0;
}