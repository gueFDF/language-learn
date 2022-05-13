#include<iostream>
using namespace std;
void myswap(int &a,int &b)
{
    cout<<"骗你的，调错函数了"<<endl;
}
template<typename T>
void myswap(T &a,T &b)
{
    T temp;
    temp=a;
    a=b;
    b=temp;
}

int main()
{
    int a=1;
    int b=2;
    myswap(a,b);
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}