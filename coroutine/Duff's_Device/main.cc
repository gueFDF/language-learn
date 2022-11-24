#include <iostream>
using namespace std;

void opt1()
{
    std::cout << 1 << endl;
}
void opt2()
{
    std::cout << 2 << endl;
}
void opt3()
{
    std::cout << 3 << endl;
}
void opt4()
{
    std::cout << 4 << endl;
}

#define yield(op, x) state = __LINE__; op(); return x;case __LINE__:;

#define begin()           \
    static int state = 0; \
    switch (state)        \
    {\
    case 0:\

#define end() \
    }

void PrintValue(int value)
{
    begin();
    yield(opt1, );
    yield(opt2, );
    yield(opt3, );
    yield(opt4, );
    end();
}

int main()
{
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        std::cout << "in the " << i << " loop" << std::endl;
        PrintValue(1);
    }
    return 0;
}