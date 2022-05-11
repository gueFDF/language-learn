#include<iostream>
using namespace std;
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
    myswap<int>(a,b);
    cout<<a<<endl;
    cout<<b<<endl;
    return 0;
}