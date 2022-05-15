#include<iostream>
#include<set>
using namespace std;
//利用仿函数自定义排序类型
class mycmp
{
public:
    bool operator()(const int &v1,const int &v2)
    {
        return v1>v2;
    }
};
int main()
{
    set<int,mycmp>s;
    s.insert(10);
    s.insert(9);
    s.insert(44);
    s.insert(6);
    s.insert(13);
    s.insert(10);
    for(set<int,mycmp>::iterator i=s.begin();i!=s.end();i++)
    {
        cout<<*i<<" ";
    }
    cout<<endl;
    return 0;
}