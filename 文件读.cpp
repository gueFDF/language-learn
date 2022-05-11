#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    fstream ifs;
    ifs.open("test.txt",ios::in);
    if(!ifs.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return 0;
    }
    char buf[1024]={0};
    while(ifs>>buf)
    {
        cout<<buf<<endl;
    }
    return 0;
}