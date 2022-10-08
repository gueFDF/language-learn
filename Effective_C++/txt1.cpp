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
    char operator[](int i) const
    {
        return ptr[i];
    }
};

const int GamePlear::NumTurns;
int main()
{
    const GamePlear p("abcdefghijklmn");
    std::cout << p[2] << std::endl;
    // const int *p = &p.NumTurns;
}

// 1.对于单纯常量，用const 或 enmu 替换 #define
// 2.用 inline 内联函数 替换 #define 宏函数