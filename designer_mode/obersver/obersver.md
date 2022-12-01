# 设计者模式（1）观察者模式 （Observer）C++11实现


## 意图
观察者模式（Observer），又叫发布-订阅模式（Publish/Subscribe），定义对象间一种一对多的依赖关系，使得每当一个对象改变状态，则所有依赖于它的对象都会得到通知并自动更新。
该模式属于行为型模式。

## 参与者

* ```Subject```：抽象主题（抽象被观察者），抽象主题角色把所有观察者对象保存在一个集合里，每个主题都可以有任意数量的观察者，抽象主题提供一个或者多个接口，可以增加和删除观察者对象。
* ```ConcreteSubject```：具体主题（具体被观察者），该角色将有关状态存入具体观察者对象，在具体主题的内部状态发生改变时，给所有注册过的观察者发送通知。
* ```Observer```：抽象观察者，是观察者者的抽象类，它定义了一个或者多个更新接口，使得在得到主题更改通知时更新自己。
* ```ConcreteObserver```：具体观察者，实现抽象观察者定义的更新接口，以便在得到主题更改通知时更新自身的状态。
## 优点

* 观察者模式可以实现表示层和数据逻辑层的分离，抽象了更新接口，使得可以有各种各样不同的表示层作为具体观察者角色
* 观察者模式在观察目标和观察者之间建立一个抽象的耦合
* 观察者模式支持广播通信

## 缺点

* 在应用观察者模式时需要考虑一下开发效率和运行效率的问题，程序中包括一个被观察者、多个观察者，将所有的观察者都通知到会花费很多时间。如果考虑到性能问题，可以实现一个异步非阻塞的观察者模式，在每次fire subject的时候创建一个新的线程执行代码。

* 观察者模式没有相应的机制让观察者知道所观察的目标对象是怎么发生变化的，而仅仅只是知道观察目标发生了变化。





## 代码实现
```cpp
#include <iterator>
#include <memory>
#include<mutex>
#include<iostream>
#include<vector>

class Observer;
typedef std::vector<std::weak_ptr<Observer>>::iterator Iterator;//迭代器

//抽象被观察者
class Subject
{
public:
    virtual void Attach(std::weak_ptr<Observer>)=0;//注册观察者对象的接口
    virtual Iterator Detach(Iterator it)=0;//删除观察者对象的接口
    virtual void notifyObservers()=0;//告知所有观察者update
};

//抽象观察者

class Observer
{
public:
    virtual void update()=0;//更新自身状态
};

//被观察者
class ConcreteSubject :public::Subject
{   
public:
    void Attach(std::weak_ptr<Observer>s)
    {
        //vector的add是线程安全的
        observers_.push_back(s);
    }
    Iterator Detach(Iterator it)
    {
        //线程不安全，要在临界区调用此接口
        return observers_.erase(it);
    }

    void notifyObservers()
    {
        lock.lock();
        Iterator it=observers_.begin();
        while(it!=observers_.end())
        {
            //先尝试将weak_ptr提升为share_ptr
            std::shared_ptr<Observer>obj=it->lock();
            if(obj)//提升成功，说明该对象未被其他线程析构
            {
                obj->update();//更新
                ++it;
            }
            else//提升失败，说明该对象已被其他线程析构
            {
                //从观察者集合中将已被析构对象删除
                //因为此处属于临界区，是线程安全的
                it=Detach(it);
            }

        }
        lock.unlock();
    }
    
private:
    mutable std::mutex lock;
    std::vector<std::weak_ptr<Observer>> observers_;//观察者集合

};

//////////////观察者按需求定义即可，需要继承抽象观察者////////////////
//以下为例
class Teacher :public::Observer
{
public:
    void update()
    {
        std::cout<<"Teacher is update"<<std::endl;
    }
    ~Teacher()
    {
        std::cout<<"Teacher is ~"<<std::endl;
    }
};

class Student:public::Observer
{
public:
    void update()
    {
        std::cout<<"Student is update"<<std::endl;
    }
    ~Student()
    {
        std::cout<<"Student is ~"<<std::endl;
    }
};

```


测试
```cpp
int main()
{
    
    ConcreteSubject subject;
    
    std::shared_ptr<Observer> teacher(new Teacher);
    subject.Attach(teacher);
    {
        std::shared_ptr<Observer> student(new Student);
        subject.Attach(student);
        subject.notifyObservers();
    }


    subject.notifyObservers();

}
```
执行结果
```
Teacher is update
Student is update
Student is ~
Teacher is update
Teacher is ~
```

## 迭代器失效问题分析
在学习该模型时，遇到了一个bug,问题锁定在notifyObservers()当中,当时的实现如下
```cpp
void notifyObservers()
{
    lock.lock();
    Iterator it=observers_.begin();
    while(it!=observers_.end())
    {
        std::shared_ptr<Observer>obj=it->lock();
        if(obj)
        {
            obj->update();
        }
        else
        {
            Detach(it);
        }
        it++;
    }
}
```
当时执行main时，就会报段错误，经过检查不难发现，问题是```迭代器失效了```


## 删除导致迭代器失效
这个问题其实很好分析，在一顺序容器当中(vector,queue..等)，数据是顺序存储的，当删除一个元素后，内存中的数据会往前移动，以保证数据的紧凑。所以删除一个元素后，该元素后面的其他元素的地址都会发生改变。在删除操作前所持有的迭代器就会有失效的可能。看下面的例子。
```cpp
#include <iterator>
#include<iostream>
#include<vector>
using namespace std;
int main()
{ 
  vector<int>arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);

  vector<int>::iterator it=arr.begin()+3;

  cout<<"删除操作前该迭代器所指向的元素："<<endl;
  cout<<*it<<endl;

  cout<<"进行删除操作"<<endl;
  arr.erase(arr.begin());
  cout<<"删除操作前该迭代器所指向的元素："<<endl;
  cout<<*it<<endl;
}
```
执行结果如下
```
删除操作前该迭代器所指向的元素：
4
进行删除操作
删除操作前该迭代器所指向的元素：
5
```


## 添加导致迭代器失效

你的添加的操作也是可能导致迭代器失效的。vector的容量是动态的开辟的，当容量不够的话，会进行realloc操作进行扩容，若该数组的后面的空间不足，realloc函数会找一片更大的空间，将原数据拷贝进去。若在此事件发生前，获取一个迭代器，此事件发生后，该迭代器会失效。看下面例子
```cpp
#include <iterator>
#include<iostream>
#include<vector>
using namespace std;
int main()
{ 
  vector<int>arr;
  arr.push_back(1);
  arr.push_back(2);
  arr.push_back(3);
  arr.push_back(4);
  arr.push_back(5);

  vector<int>::iterator it=arr.begin()+3;

  cout<<"此事件发生前该迭代器所指向的元素："<<endl;
  cout<<*it<<endl;

  for(int i=0;i<100;i++)
  {
    arr.push_back(9);
  }
  cout<<"此事件发生后该迭代器所指向的元素："<<endl;
  cout<<*it<<endl;
}
```
执行结果
```
此事件发生前该迭代器所指向的元素：
4
此事件发生后该迭代器所指向的元素：
21854
```
此时该迭代器就指向一个未初始化的空间