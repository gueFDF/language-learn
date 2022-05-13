#include <iostream>
#include <string>
using namespace std;
template <class T>
class father
{
public:
    father(T A, T B)
        : a(A), b(B)
    {
        cout << "1";
    }
   void showperson()
   {
       cout<<a<<" "<<b<<endl;
   }


    T a;
    T b;
};
template <class T>
class Son : public father<T>
{
public:
    Son(T _m, T n, T k)
        : m(_m)
        , father<T>(n, k)
    {
        cout << "Son" << endl;
        father<T>::b=110;
    }

private:
    T m;
};
int main()
{
    Son<int>p(100, 200, 100);
    p.showperson();
    // p.a = 100;
    // p.b = 200;
}