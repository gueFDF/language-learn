#include<iostream>
#include<string>
using namespace std;
class Person
{
public:
    Person(string name,int age)
    {
        m_name=name;
        m_age=age;
    }
    string m_name;
    int m_age;
};
template<class T>
bool cmp(T&a,T&b)
{
    if(a==b)
    return true;
    else
    false;
}
template<>bool cmp(Person&p1,Person&p2)
{
    if(p1.m_age==p2.m_age&&p1.m_name==p2.m_name)
    return true;
    else
    return false;
}
int main()
{
    Person p1={"张三",18};
    Person p2={"张三",18};
    if(cmp(p1,p2))
    {
        cout<<"是同一个人"<<endl;
    } 
    else
    {
        cout<<"不是同一个人"<<endl;
    }
    return 0;
}