// expre_bad_cast_Exception.cpp
// compile with: /EHsc /GR
// #include <typeinfo>
// #include <iostream>

// class Shape {
// public:
//    virtual void virtualfunc() const {}
// };

// class Circle: public Shape {
// public:
//    virtual void virtualfunc() const {}
// };

// using namespace std;
// int main() {
//    Shape shape_instance;
//    Shape& ref_shape = shape_instance;
//    try {
//       Circle& ref_circle = dynamic_cast<Circle&>(ref_shape);
//    }
//    catch (bad_cast b) {
//       cout << "Caught: " << b.what();
//    }
// }

#include<iostream>
using namespace std;
class Calculator
{
public:
	int m_num1;
	int m_num2;
   virtual	int getResult()
   {
	   return 0;
   }
};
class Add :public Calculator
{
public:
	virtual int getResult()  override
	{
		return m_num1 + m_num2;
	}
};
class Sub :public Calculator 
{
public:
	int getResult()  override
	{ 
		return m_num1 - m_num2;	
	}
};
class Mul :public Calculator
{
public:
	int getResult()   override
	{
		return m_num1 * m_num2;
	}
};
int main()
{
	Calculator* abc;
	//加法
	abc = new Add;
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
