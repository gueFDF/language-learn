#include<iostream>

#include<iterator>
#include<algorithm>

int main()
{
    std::istream_iterator<int>Input(std::cin),eof;
    std::ostream_iterator<int>Output(std::cout,"!!");
    std::copy(Input,eof,Output);
}