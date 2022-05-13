#include<iostream>
#include<string>
using namespace std;
class Calculator
{
public:
    virtual int getResult()=0;  //纯虚函数，子类必须重写
    int m_num1;
    int m_num2;
};
class ADD:public Calculator
{
public:
   int getResult()
   {
       return m_num1+m_num2;
   }
};
class Sub:public Calculator
{
public:
    int getResult()
    {
        return m_num1-m_num2;
    }
};
class Mul:public Calculator
{
public:
    int getResult()
    {
        return m_num1*m_num2;
    }
};
int main()
{
	Calculator* abc;
	//加法
	abc = new ADD;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
	delete abc;
   //减法
	abc = new Sub;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " - " << abc->m_num2 << " = " << abc->getResult() << endl;
	delete abc;
	//乘法
	abc = new Mul;
	abc->m_num1 = 100;
	abc->m_num2 = 100;
	cout << abc->m_num1 << " * " << abc->m_num2 << " = " << abc->getResult() << endl;
	delete abc;
	return 0;
}
