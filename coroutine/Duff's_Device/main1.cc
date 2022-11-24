#include <iostream>
using namespace std;

void PrintValue(int value)
{
    static int state;
    switch (state)
    {
    case 0:goto LELVE1;break;
    case 1:goto LELVE2;break;
    case 2:goto LELVE3;break;
    case 3:goto LELVE4;break;
    }

LELVE1:
    std::cout << value << endl;
    state = 1;
    return;
LELVE2:
    std::cout << value + 1 << endl;
    state=2;
    return;
LELVE3:
    std::cout << value + 2 << endl;
    state=3;
    return;
LELVE4:
    std::cout << value + 3 << endl;
    state=4;
    return;
}

int main()
{
    int i = 0;
    for (i = 0; i < 4; i++)
    {
        std::cout<<"in the" <<i<<"loop"<<std::endl;
        PrintValue(1);
    }
    return 0;
}