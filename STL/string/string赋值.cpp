#include<iostream>
#include<string>
using namespace std;
int main()
{
    string s1;
    s1="hello world";
    cout<<"s1="<<s1<<endl;
    string s2;
    s2=s1;
    cout<<"s2="<<s2<<endl;
    string s3;
    s3='s';
    cout<<"s3="<<s3<<endl;
    string s4;
    s4.assign("hello world");
    cout<<"s4="<<s4<<endl;
    string s5;
    s5.assign("hello workd",5);
    cout<<"s5="<<s5<<endl;
    string s6;
    s6.assign(5,'e');
    cout<<"s6="<<s6<<endl;
    string s7;
    s7.assign(s6);
    cout<<"s7="<<s7<<endl;
    return 0;
}