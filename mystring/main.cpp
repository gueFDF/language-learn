#include"mystring.hpp"
using namespace std;
void printstring(Mystring<int>&arr)
{
   // cout<<arr.Getsize()<<endl;
   int i;
    for(i=0;i<arr.Getsize();i++)
    {
        cout<< "arr["<<i<<"]:"<<arr[i]<<endl;
    }
}
int main()
{
    Mystring<int>string(111);
    for(int i=0;i<18;i++)
    {
        string.Push_Back(i);
    }
    printstring(string);
    return 0;
}
