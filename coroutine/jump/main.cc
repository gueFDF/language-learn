#include <iostream>
#include <csetjmp>
using namespace std;

jmp_buf buf;
jmp_buf start_buf;

void Func()
{
    std::cout << "begin func1" << std::endl;
    if (setjmp(buf) == 0)
    {
        longjmp(start_buf, 2);
    }
    std::cout << "end func1" << std::endl;
}
int main()
{
    if (setjmp(start_buf) == 0)
    {
        Func();
    }
    std::cout << "jmp back" << std::endl;
    longjmp(buf, 3);
}