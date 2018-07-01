#include<iostream>
#include<list>
#include<algorithm>
using namespace std;

int main()
{
    list<int> l;
    l.push_back(0);
    for(int i=0;i<10;i++)
    {
        l.push_back(i*2);
    }
    /*We cannot randomly access a list
    cout<<l[10];
    */
    list<int>::iterator i1; //i1 is a pointer which have the address
    i1=find(l.begin(),l.end(),8); //find and contain the address of that node which contain value 8
    l.insert(i1,5); //replace the value of that node i.e. 8 with 5
    i1 = find(l.begin(),l.end(),2); //find and contain the address of that node which contain value 2
    l.erase(i1);//delete that value from the node and replace it with 0

    for(list<int>::iterator itr=l.begin();itr!=l.end();itr++)
    {
        cout<<*itr<<endl;
    }


    return 0;
}
