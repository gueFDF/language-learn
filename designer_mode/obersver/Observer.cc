#include <iterator>
#include <memory>
#include<mutex>
#include<iostream>
#include<vector>
#include<string>

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
                Detach(it);
            }

        }
        lock.unlock();
    }
    
private:
    mutable std::mutex lock;
    std::vector<std::weak_ptr<Observer>> observers_;//观察者集合

};


//具体观察者按需定义，需要继承抽象观察者
class Teacher :public::Observer
{
public:
    Teacher(std::string n):name(n){} 
    void update()
    {
        std::cout<<"Teacher "<< name <<" is update"<<std::endl;
    }
    ~Teacher()
    {
        std::cout<<"Teacher "<< name <<" is ~"<<std::endl;
    }
private:
    std::string name;
};

class Student:public::Observer
{
public:
    Student(std::string n):name(n){} 
    void update()
    {
        std::cout<<"Student "<< name <<"is update"<<std::endl;
    }
    ~Student()
    {
        std::cout<<"Student "<< name <<"is ~"<<std::endl;
    }
private:
    std::string name;
};


int main()
{
    
    ConcreteSubject subject;
    
    std::shared_ptr<Observer> teacher(new Teacher("1"));
    std::shared_ptr<Observer> B(new Teacher("2"));
    std::shared_ptr<Observer> C(new Teacher("3"));
    subject.Attach(teacher);
    {
        std::shared_ptr<Observer> student(new Student("4"));
        subject.Attach(student);
        subject.notifyObservers();
    }


    subject.notifyObservers();

}