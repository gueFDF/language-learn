#include<iostream>
using namespace std;
class MyAdd
{
public:
    int operator()(int a,int b)
    {
        return a+b;
    } 
};
int main()
{
    MyAdd add;
    cout<<add(18,15)<<endl;
    return 0;
}
