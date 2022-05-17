#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
class func
{
public:
    bool operator()(int val)
    {
        if(val>5)
        return true;
        else
        return false;
    }
};
int main()
{
    vector<int>v;
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    vector<int>::iterator it=find_if(v.begin(),v.end(),func());
    if(it==v.end())
    cout<<"未找到"<<endl;
    else
    cout<<*it<<endl;
}