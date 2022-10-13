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

// #include<iostream>
// using namespace std;
// class Calculator
// {
// public:
// 	int m_num1;
// 	int m_num2;
//    virtual	int getResult()
//    {
// 	   return 0;
//    }
// };
// class Add :public Calculator
// {
// public:
// 	virtual int getResult()  override
// 	{
// 		return m_num1 + m_num2;
// 	}
// };
// class Sub :public Calculator
// {
// public:
// 	int getResult()  override
// 	{
// 		return m_num1 - m_num2;
// 	}
// };
// class Mul :public Calculator
// {
// public:
// 	int getResult()   override
// 	{
// 		return m_num1 * m_num2;
// 	}
// };
// int main()
// {
// 	Calculator* abc;
// 	//加法
// 	abc = new Add;
// 	abc->m_num1 = 100;
// 	abc->m_num2 = 100;
// 	cout << abc->m_num1 << " + " << abc->m_num2 << " = " << abc->getResult() << endl;
// 	delete abc;
//    //减法
// 	abc = new Sub;
// 	abc->m_num1 = 100;
// 	abc->m_num2 = 100;
// 	cout << abc->m_num1 << " - " << abc->m_num2 << " = " << abc->getResult() << endl;
// 	delete abc;
// 	//乘法
// 	abc = new Mul;
// 	abc->m_num1 = 100;
// 	abc->m_num2 = 100;
// 	cout << abc->m_num1 << " * " << abc->m_num2 << " = " << abc->getResult() << endl;
// 	delete abc;
// 	return 0;
// }

// #include <iostream>
// class math
// {
// public:
// 	math(int _a = 1, int _b = 1) : a(_a), b(_b)
// 	{
// 		count++;
// 	}
// 	~math() {}
// 	void show() const
// 	{
// 		std::cout<<count<<std::endl;
// 	}
// private:
// 	int a;
// 	int b;
// 	static int count;
// };

// int math::count=0;
// // const math &operator*(const math &_a, const math &_b)
// // {

// // }

// int main()
// {
// 	math a;
// 	a.show();
// 	math c;
// 	a.show();
// 	return 0;
// }

// #include <iostream>
// #include <cstdio>
// class Windows
// {
// public:
// 	Windows(int a, int b) : m_a(a), m_b(b){};
// 	virtual ~Windows(){};
// 	virtual void show();
// 	virtual void setab(int a, int b);

// private:
// 	int m_a;
// 	int m_b;
// };

// void Windows::show()
// {
// 	printf("%d ,%d\n", m_a, m_b);
// }

// void Windows::setab(int a, int b)
// {
// 	m_a = a;
// 	m_b = b;
// }
// class specialwindows : public Windows
// {
// public:
// 	specialwindows(int a, int b) : Windows(a, b), m_a(a + 1){};
// 	~specialwindows(){};

// private:
// 	int m_a;
// };

// int main()
// {
// 	specialwindows a(5, 7);
// 	static_cast<Windows*>(&a)->setab(15, 16);  //向上强转，会创建一个父类的副本，修改父类的成员变量，实际上只是对副本的修改

// //	dynamic_cast<Windows*>(&a)->setab(15,16);
// 	//  a.setab(15,16);
// 	//  a:Windows::show();
// 	a.show();
// 	return 0;
// }

#include <iostream>
#include<memory>
using namespace std;
class base
{
public: virtual ~base()
		{
 
		}
		virtual void print()
		{
			cout<<"we are in base"<<endl;
		}
protected:
private:
};
class derived : public base
{
public:
	void  print()
	{
		cout <<"we are in derived"<<endl;
	}
protected:
private:
};
void func(shared_ptr<base>pre)
{
	std::cout<<pre.use_count()<<std::endl;
}
int main()
{
	// base *base_ptr1 = new base;
	// derived *derived_ptr1 =  static_cast<derived*>(base_ptr1);   //base_ptr1实际指向base，不能转化为derived
	// base *base_ptr2 = new derived;
	// derived *derived_ptr2 = static_cast<derived*>(base_ptr2);   //base_ptr1实际指向derived，不能转化为derived
	shared_ptr<base> ptr(new base);
	std::cout<<ptr.use_count()<<std::endl;
	func(ptr);
	std::cout<<ptr.use_count()<<std::endl;
	//derived *derived_ptr2 = new derived;
	//base *base_ptr2 = dynamic_cast<base*>(derived_ptr2);
	// if (derived_ptr1 == NULL)
	// {
	// 	cout <<"base pointer pointed to base can be dynamic_cast to derived pointer  is wrong"<<endl;
	// } 
	// else
	// {
	// 	cout<<"pointer to base can be dynamic_cast to derived pointer  is success"<<endl;
	// }
    
	// if (derived_ptr2 == NULL)
	// {
	// 	cout <<"base pointer pointed to derived can be dynamic_cast to derived pointer  is wrong"<<endl;
	// } 
	// else
	// {
	// 	cout<<"base pointer pointed to derived can be dynamic_cast to derived pointer  is success"<<endl;
	// }
	return 0;
}

