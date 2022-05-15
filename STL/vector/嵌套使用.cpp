#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
    vector<vector<int>>arr;
    vector<int>v1;
    vector<int>v2;
    vector<int>v3;
    vector<int>v4;
     for(int i=0;i<6;i++)
    {
        v1.push_back(i+1);
        v2.push_back(i+2);
        v3.push_back(i+3);
        v4.push_back(i+4);
    }
    arr.push_back(v1);
    arr.push_back(v2);
    arr.push_back(v3);
    arr.push_back(v4);
    for(vector<vector<int>>::iterator it=arr.begin();it!=arr.end();it++)
    {
        // cout<<"sds"<<endl;
        for(vector<int>::iterator is=(*it).begin();is!=(*it).end();is++)
        {
            cout<<*is<<" ";
        }
        cout<<endl;
    }
    return 0;
}