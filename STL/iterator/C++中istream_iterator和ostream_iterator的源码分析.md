# 概述
在一篇博客当中无意间发现了```istream_iterator```和```iostream_iterator```的使用，感觉用法很神奇，就专门去研究了一下，觉得还挺有意思的，所以就专门写了一篇博客来聊聊这两个迭代器的实现,一下为```gnu2.9```版本的源码。


# istream_iterator源码
```cpp
template <class T, class Distance = ptrdiff_t> 
class istream_iterator {
  friend bool
  operator== __STL_NULL_TMPL_ARGS (const istream_iterator<T, Distance>& x,
                                   const istream_iterator<T, Distance>& y);
protected:
  istream* stream;
  T value;
  bool end_marker;                                 //判断是否读入结束符，比如C语言中的EOF等等
  void read() {                                    //其中调用的读取函数
    end_marker = (*stream) ? true : false;
    if (end_marker) *stream >> value;              //读入value，若读入信息与类型不符，会将value置为0
    end_marker = (*stream) ? true : false;          //判断上一步>>读取是否成功 
  }
public:
  typedef input_iterator_tag iterator_category;   
  typedef T                  value_type;
  typedef Distance           difference_type;
  typedef const T*           pointer;
  typedef const T&           reference;
 
  istream_iterator() : stream(&cin), end_marker(false) {} //默认构造函数，不会触发输入操作
  istream_iterator(istream& s) : stream(&s) { read(); }   //这种构造函数，后面就紧跟着读取一个数据
  reference operator*() const { return value; }    //返回value的引用
#ifndef __SGI_STL_NO_ARROW_OPERATOR
  pointer operator->() const { return &(operator*()); }  //返回value的地址,前置++
#endif /* __SGI_STL_NO_ARROW_OPERATOR */
  istream_iterator<T, Distance>& operator++() {          //重点重载operator++
    read();                                           //不会创建新类
    return *this;
  }
  istream_iterator<T, Distance> operator++(int)  {      //将operator++重载为输入操作，后置++
    istream_iterator<T, Distance> tmp = *this;    //会创建一个的istream_iterator来保存读入前的iterator
    read();                                      //从流读入后，返回存有读入前数据的istream_iterator
    return tmp;
  }
};
```

## 分析
>std::istream_iterator是单程输入迭代器T，通过调用适当的operator>>. 实际的读取操作是在递增迭代器时执行的，而不是在取消引用时执行的。构造迭代器时读取第一个对象。取消引用仅返回最近读取的对象的副本。
>
>默认构造std::istream_iterator的称为流结束迭代器。当 validstd::istream_iterator到达底层流的末尾时，它就等于流末尾迭代器。取消引用或递增它会进一步调用未定义的行为。

## 使用方法
```cpp
#include <iostream> 
#include <istream>
#include <iterator> 
#include <vector>
int main ( ) 
{ 
    std::istream_iterator<int>p(std::cin); //会触发第一次数据读入
    std::istream_iterator<int>eof;  //结束流

    std::vector<int>arr(p,eof);

    for(auto it:arr)
    {
        std::cout<<it<<" ";
    }
}
```
以上，当读到非int数据停止输入


# ostream_iterator源码
```cpp
template <class T>
class ostream_iterator {
protected:
  ostream* stream;                                                          
  const char* string;                                                       //可以包含第二个参数，输出对应的数据后，输出此stream
public:
  typedef output_iterator_tag iterator_category;                            //迭代器类型
  typedef void                value_type;
  typedef void                difference_type;
  typedef void                pointer;
  typedef void                reference;
 
  ostream_iterator(ostream& s) : stream(&s), string(0) {}                 //缺省一个参数的构造函数，默认string为空
  ostream_iterator(ostream& s, const char* c) : stream(&s), string(c)  {} //包含string的构造函数
  ostream_iterator<T>& operator=(const T& value) {                        //重点！！！重载operator=操作，转换为输出此value
    *stream << value;
    if (string) *stream << string;                                       //如果有默认string再往流中写入该string
    return *this;
  }
  ostream_iterator<T>& operator*() { return *this; }                       //都返回本身
  ostream_iterator<T>& operator++() { return *this; }                      //他的前置++和后置++效果都一样
  ostream_iterator<T>& operator++(int) { return *this; } 
};
```


## 使用方法
```cpp
#include<iostream>

#include<iterator>
#include<algorithm>

int main()
{
    std::istream_iterator<int>Input(std::cin),eof;
    std::ostream_iterator<int>Output(std::cout,"!!");
    std::copy(Input,eof,Output);
}
```

疑问：为什么重载后置++会有一个int型参数
在看源码的过程中，注意到重载后置++会有一个int参数，感觉很疑惑，++不应该为单目运算符吗？唯一操作数不应该是该对象本身么？

我们知道，是不能根据返回值类型进行重载的，那么编译器该怎样区分前置++和后置++呢？想到这，隐约感觉这两个问题之间肯定有什么联系。

根据查资料，果不其然。

前置++与后置++的操作符重载函数，函数原型必须不同。否则就违反了“重载函数必须拥有不同的函数原型”的语法规定。
虽然前置++与后置++的返回类型不同，但是返回类型不属于函数原型。为了绕过语法限制，只好给后置++增加了一个int形参。
原因就是这么简单，真的没其他特殊用意。其实，给前置++增加形参也可以；增加一个double形参而不是int形参，也可以。只是，当时就这么决定了。


为何前置++效率要比后置++效率要高呢，从前置++和后置++的区别上进行分析
1. 返回类型不同
2. 形参不同
3. 代码不同

以下面example为例
```cpp
#include<iostream>
using namespace std;
int main()   
{   
	int a=2;    
	//a++ = 1;   //编译错误    
	++a = 1;     //编译成功   
}  
```

返回类型不同
前置++返回的是引用，后置++返回的是右值，这就是为什么a++=1编译错误，而++a=1没有错误


形参不同
前置++没有形参，而后置++有一个int形参，但是该形参也没有被用到。很奇怪，难道有什么特殊的用意？

其实也没有特殊的用意，只是为了绕过语法的限制。

 

前置++与后置++的操作符重载函数，函数原型必须不同。否则就违反了“重载函数必须拥有不同的函数原型”的语法规定。

虽然前置++与后置++的返回类型不同，但是返回类型不属于函数原型。为了绕过语法限制，只好给后置++增加了一个int形参。

 

原因就是这么简单，真的没其他特殊用意。其实，给前置++增加形参也可以；增加一个double形参而不是int形参，也可以。只是，当时就这么决定了。



代码实现不同
看istream_iterator中的++运算符重载时，就会发现后置++要稍微复杂一点
前置++只需要先自增，再进行拷贝
后置++需要先将自增前的对象拷贝一份，再进行自增，然后返回拷贝的对象