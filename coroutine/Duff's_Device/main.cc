#include <iostream>
using namespace std;
#define yield()       \
    state = __LINE__; \
    return;           \
    case __LINE__:;

#define begin()           \
    static int state = 0; \
    switch (state)        \
    {                     \
    case 0:

#define end() \
    }

void PrintValue()
{
    begin();
    cout << " 1 " << endl;
    yield();
    cout << " 2 " << endl;
    yield();
    cout << " 3 " << endl;
    yield();
    cout << " 4 " << endl;
    end();
}

void Printnum()
{
    begin();
    cout << " a " << endl;
    yield();
    cout << " b " << endl;
    yield();
    cout << " c " << endl;
    yield();
    cout << " d " << endl;
    end();
}

int main()
{
    int n=4;
    while (n--)
    {
        PrintValue();
        Printnum();
    }

    return 0;
}