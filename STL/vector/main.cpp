#include<iostream>
#include<vector>
#include<algorithm>
#include<iterator>
using namespace std;
int main()
{
    vector<int>arr;
    arr.push_back(2);
    arr.push_back(9);
    arr.push_back(5);
    arr.push_back(7);
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    sort(arr.begin(),arr.end());
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    arr.erase(arr.begin());
    for(int i=0;i<arr.size();i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}