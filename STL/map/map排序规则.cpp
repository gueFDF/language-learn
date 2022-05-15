#include<iostream>
#include<map>
using namespace std;
class Mycmp
{
public:
    bool operator()(int a,int b)
    {
        return a>b;
    }
};
void printmap(map<int,int,Mycmp>&m)
{
    for(map<int,int>::iterator i=m.begin();i!=m.end();i++)
    {
        cout<<"key: "<<(*i).first<<" val: "<<(*i).second<<endl;
    }
    cout<<endl;
}
int main()
{
    map<int,int,Mycmp>m;
    m.insert(pair<int,int>(1,10));
    m.insert(pair<int,int>(8,11));
    m.insert(pair<int,int>(3,109));
    m.insert(pair<int,int>(9,15));
    m.insert(pair<int,int>(3,110));
    m.insert(pair<int,int>(6,70));
    printmap(m);
    return 0;
}