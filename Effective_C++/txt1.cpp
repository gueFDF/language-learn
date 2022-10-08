#include <iostream>
#include <string>
class GamePlear
{
public:
    static const int NumTurns = 5; //常量申明式
                                   // int arr[NumTurns];
    // const char *st="123456789";
    std::string ptr;

public:
    GamePlear(std::string p) : ptr(p) {}
    const char &operator[](int i) const
    {
        return ptr[i];
    }

    char operator[](int i)
    {
        return const_cast<char&>(static_cast<const GamePlear&>(*this)[i]);   //在 no-const operator[]中调用const opeator[]
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
    std::cout << p2[2]<<std::endl;
    p.print();
    std::string str = p.ptr;
}

// 1.对于单纯常量，用const 或 enmu 替换 #define
// 2.用 inline 内联函数 替换 #define 宏函数
// const 对象只能访问const修饰的函数