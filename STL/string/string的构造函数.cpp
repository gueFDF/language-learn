#include<iostream>
#include<string>
using namespace std;
int main()
{
    const char *str="hello world";
    //string的三个构造函数
    string s1(str);   
    cout<<"s1= "<<s1<<endl;
    string s2(s1);
    cout<<"s2= "<<s2<<endl;
    string s3(10,'a');
    cout<<"s3= "<<s3<<endl;
    return 0;
}