#include<iostream>
using namespace std;
template<class T>
class Mystring
{
public:
    Mystring(int Capacity)
    {
        this->m_Capacity=Capacity;
        this->size=0;
        this->pAddress=new T[Capacity];
    }
    //拷贝构造函数(防止浅拷贝)
    Mystring(Mystring&string)
    {
        this->m_Capacity=string.m_Capacity;
        this->pAddress=new T[string.m_Capacity];
        this->size=string.size;
        //将原数组的数据拷贝过来
        for(int i=0;i<this->size;i++)
        {
            this->pAddress[i]=string.pAddress[i];
        }
    }
    //尾插法
    void Push_Back(const T&val)
    {
        //判断是否到达最大容量
        if(this->size==this->m_Capacity)
        {
            cout<<"该数组已到达最大容量"<<endl;
            return;
        }
        this->pAddress[this->size++]=val;
    }
    //尾删法
    void pop_Back()
    {
        if(this->size==0)
        {
            cout<<"该数组没有数据"<<endl;
            return;
        }
        this->size--;
    }
    //重载[]可以通过下标访问数据
    T& operator[](int index)
    {
        return this->pAddress[index];
    }
    //返回数组容量大小
    int Getcapacity()
    {
        return this->m_Capacity;
    }
    //返回数组大小
    int Getsize()
    {
        return this->size;
    }
    //析构函数释放堆区数据，防止内存泄露
    ~Mystring()
    {
        if(this->pAddress!=NULL)
        {
            delete[]this->pAddress;
            this->pAddress=NULL;
        }
    }
    //operator = 防止浅拷贝问题
    Mystring& operator=(const Mystring&string)
    {
        //先判断原来堆区是否有数据，如果有先释放
        if(this->pAddress!=NULL)
        {
            delete[]this->pAddress;
            this->size=0;
            this->m_Capacity=0;
            this->pAddress=NULL;
        }
        //提供深拷贝
        this->m_Capacity=string.m_Capacity;
        this->pAddress=new T[string.m_Capacity];
        this->size=string.size;
        //将原数组的数据拷贝过来
        for(int i=0;i<this->size;i++)
        {
            this->pAddress[i]=string.pAddress[i];
        }
    }
private:
    T*pAddress;//指针指向堆区开辟的真实数组
    int m_Capacity;//数组容量
    int size;//当前下标
};
