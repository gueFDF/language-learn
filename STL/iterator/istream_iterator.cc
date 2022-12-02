#include <iostream> 
#include <istream>
#include <iterator> 
#include <vector>
#include <algorithm>
 
int main ( ) 
{ 
    std::istream_iterator<int>p(std::cin);
    std::istream_iterator<int>eof;
    std::cout<<*++p<<std::endl;;
    //++p;

    // std::vector<int>arr(p,eof);

    // for(auto it:arr)
    // {
    //     std::cout<<it<<" ";
    // }
}