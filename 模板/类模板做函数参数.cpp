#include<iostream>
#include<string>
using namespace std;
template<class T1,class T2>
class Person
{
public:
    Person(T1 name,T2 age)
    {
        this->m_name=name;
        this->m_age=age;
    }
    void showperson()
    {
        cout<<"姓名： "<<this->m_name<<endl;
        cout<<"年龄： "<<this->m_age<<endl;
    }
    T1 m_name;
    T2 m_age;
};
template<class T>
//方法一 整个类模板化
void show1(T&p)
{
    p.showperson();
}
//方法二 指定传入类型
void show2(Person<string,int>&p)
{
    p.showperson();
}
//方法三 参数模板化
template<class T1,class T2>
void show3(Person<T1,T2>&p)
{
    p.showperson();
}
int main()
{
    Person<string,int>p("孙悟空",99999);
    show1(p);
    show2(p);
    show3(p);
    return 0;
}