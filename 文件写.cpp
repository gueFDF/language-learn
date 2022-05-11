#include<iostream>
#include<fstream>
using namespace std;
int main()
{
    ofstream fd;
    fd.open("test.txt",ios::out);
    if(!fd.is_open())
    {
        cout<<"文件打开失败"<<endl;
        return 0;
    }
    fd<<"姓名：张三"<<endl;
    fd<<"年龄:18"<<endl;
    fd<<"年级:通工2104"<<endl;
    fd.close();
    return 0;
}