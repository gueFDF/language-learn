#include<iostream>
using namespace std;
#include<algorithm>
#include<vector>
#include<functional>
class cmp
{
public:
    bool operator()(int a,int b)
    {
        return a>b;
    }
};
int main()
{
    vector<int>v;
    v.push_back(12);
    v.push_back(18);
    v.push_back(16);
    v.push_back(15);
    v.push_back(11);
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    sort(v.begin(),v.end());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    sort(v.begin(),v.end(),cmp());
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    sort(v.begin(),v.end(),less<int>());//利用内置仿函数(谓词)
    for(int i=0;i<v.size();i++)
    {
        cout<<v[i]<<" ";
    }
    cout<<endl;
    return 0;
}