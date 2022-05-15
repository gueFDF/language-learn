#include<iostream>
#include<set>
#include<iterator>
#include<algorithm>
using namespace std;
int main()
{
    set<int>tree;
    tree.insert(10);
    tree.insert(9);
    tree.insert(11);
    tree.insert(10);
    tree.insert(10);
    tree.insert(10);
    tree.insert(13);
    tree.insert(0);
    tree.insert(99);
    tree.insert(12);
    for(set<int>::iterator a=tree.begin();a!=tree.end();a++)
    {
        cout<<*a<<" ";
    }
    cout<<endl;
    tree.erase(11);
    for(set<int>::iterator a=tree.begin();a!=tree.end();a++)
    {
        cout<<*a<<" ";
    }
     cout<<endl;
    tree.erase(tree.find(99));
    for(set<int>::iterator a=tree.begin();a!=tree.end();a++)
    {
        cout<<*a<<" ";
    }
     cout<<endl;
     cout<<"size: "<<tree.size()<<endl;
     cout<<"10的个数: "<<tree.count(10)<<endl;
    return 0;
}