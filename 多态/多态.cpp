#include<iostream>
using namespace std;
class Animal
{
public:
    virtual void speak()
    {
        cout<<"动物在说话"<<endl;
    }
};
class Cat:public Animal
{
public:
    void speak()
    {
        cout<<"猫在说话"<<endl;
    }
};
//地址早绑定,在编译阶段确定函数地址
void test(Animal&animal)
{
    animal.speak();
}
int main()
{
    Cat cat;
    cat.Animal::speak();
    test(cat);
    return 0;
}