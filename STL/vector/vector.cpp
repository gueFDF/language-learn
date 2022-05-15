#include<iostream>
#include<vector>
#include<iterator>
#include<algorithm>
using namespace std;
void func(int val)
{
    cout<<val<<endl;
}
using namespace std;
int main()
{
    vector<int>arr;
    for(int i=0;i<10;i++)
    {
         arr.push_back(i);
    }
    vector<int>::iterator itbegin=arr.begin();
    vector<int>::iterator itend=arr.end();
    //遍历方法一
    while(itbegin!=itend)
    {
       cout<<*itbegin<<endl;
       itbegin++;
    }
    //遍历方法二
    for_each(arr.begin(),arr.end(),func);
    //便利方法二
    for(itbegin;itbegin!=itend;itbegin++)
    {
        cout<<*itbegin<<endl;
    }
    return 0;
}