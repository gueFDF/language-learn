#include<iostream>
#include<map>
using namespace std;
void printmap(map<int,int>&m)
{
    for(map<int,int>::iterator i=m.begin();i!=m.end();i++)
    {
        cout<<"key: "<<(*i).first<<" val: "<<(*i).second<<endl;
    }
    cout<<endl;
}
int main()
{
    map<int,int>m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(8,11));
    m.insert(pair<int,int>(3,109));
    m.insert(pair<int,int>(9,15));
    m.insert(pair<int,int>(3,110));
    m.insert(pair<int,int>(6,70));
    m.insert(make_pair(99,12));//也可以这样插入对组
    m.insert(map<int,int>::value_type(3,30));//这也可以
    m[9]=9999;
    printmap(m);
    m.erase(1);//按Key值删除
    printmap(m);
    m.erase(m.begin());//删除第一个
    printmap(m);
    return 0;
}