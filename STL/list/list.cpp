#include<iostream>
#include<list>
using namespace std;
void printlist(list<int>l)
{
    for(list<int>::iterator i=l.begin();i!=l.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
}
bool cmp(int a,int b)
{
    return a>b;
}
int main()
{
    list<int>l;
    l.push_front(6);
    l.push_front(3);
    l.push_front(8);
    l.push_front(11);
    l.push_front(1);
    l.push_front(33);
    l.push_back(12);
    l.push_back(9);
    l.push_back(8);
    l.push_back(0);
    printlist(l);
    l.pop_front();
    printlist(l);
    l.pop_back();
    printlist(l);
    l.pop_front();
    printlist(l);
    //反转链表
    l.reverse();
    printlist(l);
    //默认为降序排序
    l.sort();
    printlist(l);
    //自定义排序
    l.sort(cmp);
    printlist(l);
    return 0;
}