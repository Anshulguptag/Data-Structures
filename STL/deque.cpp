#include<iostream>
#include<deque>
using namespace std;

int main()
{
    deque<int> d(5);

    for(int i=1;i<d.size();i++)
    {
        d[i]=i*3;
    }
    cout<<"Deque d: "<<endl;
    for(int i=1;i<d.size();i++)
    {
        cout<<d[i]<<endl;
    }
    d.push_back(30);
    d.push_front(0);
    cout<<"After pushing at end and front: "<<endl;
    for(int i=1;i<d.size();i++)
    {
        cout<<d[i]<<endl;
    }

    //Rest all functions are similar to vector
    return 0;
}
