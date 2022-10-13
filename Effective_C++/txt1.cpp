#include <iostream>
#include <string>
#include <cstdio>
#include<mutex>

std::mutex m;
class uncopy
{
public:
    uncopy(){};

private:
    int a;
    uncopy(const uncopy &);
    uncopy &operator=(const uncopy &);
} //当有子类继承他，那么该子类将不允许使用拷贝构造和operator=

;
class GamePlear /*: private uncopy*/
{
public:
    static const int NumTurns = 5; //常量申明式
                                   // int arr[NumTurns];
    // const char *st="123456789";
    std::string ptr;

public:
    GamePlear(std::string p) : ptr(p) {}
    GamePlear() = default;
    GamePlear(const GamePlear&)=delete;
    const char &operator[](int i) const
    {
        return ptr[i];
    }

    char operator[](int i)
    {
        return const_cast<char &>(static_cast<const GamePlear &>(*this)[i]); //在 no-const operator[]中调用const opeator[]
    }
    void print(void) const
    {
        printf(" I am happy %d\n", NumTurns);
    }
};

const int GamePlear::NumTurns;
int main()
{
    const GamePlear p("abcdefghijklmn");

    GamePlear p2("abcdefghijklmn");
    std::cout << p[2] << std::endl;
    std::cout << p2[2] << std::endl;
    p.print();
    std::string str = p.ptr;
    // const GamePlear c(p);  //无法进行拷贝构造

    int q = 3;
    int m = -15;
    int &pp = m;
    printf("%p  %d\n", &q, q);
    int &pr = q;
    printf("%p  %d\n", &pr, pr);
    pr = std::move(pp);
    printf("%p  %d\n", &pr, pr);
    //进行更改
    m = 19;
    printf("%p  %d\n", &pr, pr);
}

// 1.对于单纯常量，用const 或 enmu 替换 #define
// 2.用 inline 内联函数 替换 #define 宏函数
// const 对象只能访问const修饰的函数
// C++不允许引用改指向对象
//可以在praviate中声明拷贝构造，从而可以杜绝用户使用该功能

//析构函数绝对不要吐出异常，如果一个析构函数调用的函数可能抛出异常，析构函数应该捕捉任何异常，然后吞下或接结束程序

//如果客户需要对某个操作函数运行期间抛出的异常做出反应，那么class应该提供一个普通函数（而Fri在析构函数中）执行该操作

//绝不要在构造函数和析构函数中调用virtual函数

//(可以在派生类构造过程中将数据向上传递给基类的构造函数当中，替换)

// 10,另operator=返回一个referance to*this   这样就可以进行  x=y=z=15类似这样的

// 11.在operator=中处理自我赋值   (总会有用户不小心这么做)

//加一个证同测试

/*
eg:
    if(dst==&src) return *this;
    else
    {
        delete dst;
        dst=new  object(src.object)
    }


但是还会存在异常安全问题

改进
Widget& Widget::operator=(const Widget&rhs)
{
    Bitmap *pOrig=bp;
    pb=new Bitmap(*rhs,pb);
    delete pOrig;
    return *this;
}


也可以使用copy-and-swap技术
*/

//12 .复制对象时勿忘其每一个成分//注：新添加的不能忘，基类的参数不能忘（有继承的情况下）

//不要尝试以某个copying函数实现另外一个copying函数，，如果有很很多重复代码，应该将共用机能放进第三个函数中，并由两个函数共同调用

//13 以对象管理资源
//使用智能指针是一个不错的选择


//14.在资源管理类中小心coping行为

//复制RAII对象必须一并复制他所管理的资源（深拷贝） 
//还可以  ：阻止copying，施行引用计数法



//15,在资源管理类中提供对原始资源的访问
//16.成队使用new和delete是要采用相同的形式
//如果你在new表达式中使用[]，必须在相应的delete表达式中也使用[]。如果你在new表达式中不使用[]，一定不要在相应的delete表达式中只用[]


//17以独立语句将newed对象置入智能指针（防止异常导致，new出来的空间未加入智能指针，从而产生内存泄露）

//18，让接口容易被正确使用，不易被误用

//19.设计class犹如设计type

//20 宁以pass-by-reference-to-const替换pass-by-value
//优点：防止副本拷贝带来的损耗，，，2.防止对象切割
//注意：如果对于内置类型而言，pass-by-value会更加高效


//21.返回对象时，别妄想返回其reference
//防止返回局部变量的引用，防止返回指向堆区的

//22,将成员变两声明为private


//23.宁以non-member，non-friend替换member函数

//24.若所有参数皆需类型转换，请为此采用non-member函数
//如果需要为某个函数的所有参数（包括被this指针所指的那个隐喻参数），进行类型转换，那么这个函数必须是一个non-member

//25.考虑写出一个不抛出异常的swap函数

//26,尽可能延后变量定义式的出现时间
//用的时候再定义，延后这份定义直到能够给他初始值实参为止
//循环中，将变量定义在循环体内，除非你知道复制成本比“构造+析构”，成本低并且正在处理的代码效率高度敏感部分

//27 尽量少做转型动作

// 28.避免返回handles指向对象的内部