#include <iostream>
#include <string>
using namespace std;
// template <class T>
class father
{
public:
    father(int A, int B)
        : a(A), b(B)
    {
        cout << "1";
    }
   void showperson()
   {
       cout<<a<<" "<<b<<endl;
   }


    int a;
    int b;
};
// template <class T>
class Son : public father
{
public:
    Son(int _m, int n, int k)
        : m(_m)
        , father(n, k)
    {
        cout << "Son" << endl;
       father:: b=100;
    }

private:
    int m;
};
int main()
{
    Son p(100, 200, 100);
    p.showperson();
    // p.a = 100;
    // p.b = 200;
}