#include <iostream>
#include <string>
#include <cstdio>

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
class GamePlear : private uncopy
{
public:
    static const int NumTurns = 5; //常量申明式
                                   // int arr[NumTurns];
    // const char *st="123456789";
    std::string ptr;

public:
    GamePlear(std::string p) : ptr(p) {}
    GamePlear() = default;
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
    // const GamePlear c(p);  无法进行拷贝构造

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

//12 .复制对象时勿忘其每一个成分