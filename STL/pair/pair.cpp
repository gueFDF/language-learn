#include<iostream>
#include<string>
using namespace std;
int main()
{
    pair<string,int>person1("猪八戒",18);
    pair<string,int>person2;
    person2=make_pair("孙悟空",19);
    cout<<"姓名： "<<person1.first<<"年龄： "<<person1.second<<endl;
    cout<<"姓名： "<<person2.first<<"年龄： "<<person2.second<<endl;
    return 0;
}