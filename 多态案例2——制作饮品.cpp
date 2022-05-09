#include<iostream>
using namespace std;
class Drinking
{
public:
 
    //煮水
    virtual void boil()=0;
    //冲泡
    virtual void Brew()=0;
    //倒入杯子
    virtual void PourIncup()=0;
    //加入辅料
    virtual void Putsomething()=0;
    //制作饮品
    void make()
    {
        boil();
        Brew();
        PourIncup();
        Putsomething();
    }
};
class coffe:public Drinking
{
public:
    //煮水
    void boil()
    {
        cout<<"煮农夫山泉"<<endl;
    }
    //冲泡
    void Brew()
    {
        cout<<"冲咖啡"<<endl;
    }
    //倒入杯子
    void PourIncup()
    {
        cout<<"倒入杯子"<<endl;
    }
    //加入辅料
    void Putsomething()
    {
        cout<<"加入牛奶和糖"<<endl;
    }
};
class tea:public Drinking
{
public:
    //煮水
    void boil()
    {
        cout<<"煮农自来水"<<endl;
    }
    //冲泡
    void Brew()
    {
        cout<<"冲茶叶"<<endl;
    }
    //倒入杯子
    void PourIncup()
    {
        cout<<"倒入茶壶"<<endl;
    }
    //加入辅料
    void Putsomething()
    {
        cout<<"加入枸杞"<<endl;
    }
};
//
int main()
{
    Drinking*abc;
    abc=new(tea);
    abc->make();
    delete abc;
    abc=new(coffe);
    abc->make();
    return 0;    
}