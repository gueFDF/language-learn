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

// #include <iostream>
// #include<memory>
// using namespace std;
// class base
// {
// public: virtual ~base()
// 		{

// 		}
// 		virtual void print()
// 		{
// 			cout<<"we are in base"<<endl;
// 		}
// protected:
// private:
// };
// class derived : public base
// {
// public:
// 	void  print()
// 	{
// 		cout <<"we are in derived"<<endl;
// 	}
// protected:
// private:
// };
// void func(shared_ptr<base>pre)
// {
// 	std::cout<<pre.use_count()<<std::endl;
// }
// int main()
// {
// 	// base *base_ptr1 = new base;
// 	// derived *derived_ptr1 =  static_cast<derived*>(base_ptr1);   //base_ptr1实际指向base，不能转化为derived
// 	// base *base_ptr2 = new derived;
// 	// derived *derived_ptr2 = static_cast<derived*>(base_ptr2);   //base_ptr1实际指向derived，不能转化为derived
// 	shared_ptr<base> ptr(new base);
// 	std::cout<<ptr.use_count()<<std::endl;
// 	func(ptr);
// 	std::cout<<ptr.use_count()<<std::endl;
// 	//derived *derived_ptr2 = new derived;
// 	//base *base_ptr2 = dynamic_cast<base*>(derived_ptr2);
// 	// if (derived_ptr1 == NULL)
// 	// {
// 	// 	cout <<"base pointer pointed to base can be dynamic_cast to derived pointer  is wrong"<<endl;
// 	// }
// 	// else
// 	// {
// 	// 	cout<<"pointer to base can be dynamic_cast to derived pointer  is success"<<endl;
// 	// }

// 	// if (derived_ptr2 == NULL)
// 	// {
// 	// 	cout <<"base pointer pointed to derived can be dynamic_cast to derived pointer  is wrong"<<endl;
// 	// }
// 	// else
// 	// {
// 	// 	cout<<"base pointer pointed to derived can be dynamic_cast to derived pointer  is success"<<endl;
// 	// }
// 	return 0;
// }

// #include <iostream>
// class base
// {
// public:
// 	virtual void f1()
// 	{
// 		std::cout << "base f1()" << std::endl;
// 	}
// 	virtual void f1(int a)
// 	{
// 		std::cout << "base f1(int)" << std::endl;
// 	}
// 	virtual void f3()=0;//纯虚函数
// };

// void base::f3()
// {

// }

// class derived : public base
// {
// public:
// 	using base::f1;
// 	void f1()
// 	{
// 		std::cout << "derived f1()" << std::endl;
// 	}
// 	void f3()
// 	{}
// };
// int main()
// {
// 	derived p;
// 	p.f1();
// 	// p.f1(3); //错误，子类将父类的重名函数覆盖了

// 	//可以使用using
// 	p.f1(1);
// 	return 0;
// }

// #include <iostream>
// class Person
// {
// public:
// 	void S()
// 	{
// 		speak();
// 	}

// private:
// 	virtual void speak()
// 	{
// 		std::cout << "我是人" << std::endl;
// 	}
// };

// class student:public Person
// {
// private:
// 	void speak()
// 	{
// 		std::cout << "我是学生" << std::endl;
// 	}
// };

// int main()
// {
// 	student a;
// 	a.S();
// }

// #include <iostream>
// using namespace std;
// class A
// {
// public:
// 	int m_age;
// };
// class B : virtual public A
// {
// public:
// 	void print()
// 	{
// 		cout << "B" << endl;
// 	}
// };
// class C : virtual public A
// {
// 	void print()
// 	{
// 		cout << "C" << endl;
// 	}
// };
// class D : virtual public B,virtual  public C
// {
// };
// int main()
// {
// 	D a;
// 	a.B::m_age = 2;
// 	a.A::m_age = 1;
// 	// a.C::m_age = 3;
// 	cout << a.B::m_age << endl;
// 	cout << a.m_age << endl;
// 	a.print();
// }

// #include <iostream>

// template <typename C>
// void print2nd(const C &container)
// {
// 	if (container.size() >= 2)
// 	{
// 		typename C::const_iterator iter(container.begin());
// 		container.const_iterator iter(container.begin());
// 	}
// }

// int main()
// {
// 	return 0;
// }

// #include <iostream>
// template<class T>
// class Add
// {
// public:
// 	const T operator()(const T &a, const T &b)
// 	{
// 		return a + b;
// 	}
// };

// int main()
// {
// 	Add<float> add;
// 	std::cout << add(1.3333333,2) << std::endl;
// }
#include<iostream>
template<typename T>
class Rational
{
public:
	Rational(const T&a=0,const T&b=1) :numberator(a),denominator(b){}
	friend const Rational<T> operator*(const Rational<T>&lhs,const Rational<T>&rhs);
	T numberator;
	T denominator;
};

template<typename T>
const Rational<T> operator*(const Rational<T>&lhs,const Rational<T>&rhs)
{
	Rational<T> dst(lhs.numberator*rhs.numberator,lhs.denominator*rhs.denominator);
	return dst;
}


int main()
{
	Rational<int> a(5,6);
	Rational<int> b(7,8);
	//Rational<int>c=a*b;
	Rational<int>d=a*2;//无法连接

	std::cout<<d.numberator<<"    "<<d.denominator<<std::endl;  
	return 0;
}