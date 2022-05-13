#include<iostream>
#include<string>
using namespace std; 
template<class T>
class Person;
template<class T> 
void print2(Person<T>p)
{
    cout<<"a = "<<p.m_a<<endl<<"b = "<<p.m_b<<endl;
}
template<class T>
class Person
{
    //全局函数类内实现
    friend void print(Person<T>p)
    {
        cout<<"a = "<<p.m_a<<endl<<"b = "<<p.m_b<<endl;
    }
    //加一个空模板参数列表
    friend void print2<>(Person<T>p);
public:
    Person(T a,T b)
    {
        m_a=a;
        m_b=b;
    }
private:
    int m_a;
    int m_b;
};
int main()
{
    Person<int>p(100,200);
    print(p);
    print2(p);
}