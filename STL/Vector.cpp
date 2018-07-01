#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<int> v(10); //vecor v of int type and size 10
    for(int i=1;i<v.size();i++)
    {
        v[i]=10*i;
    }
    cout<<"Vector v: "<<endl;
    for(int i=1;i<10;i++)
    {
        cout<<v[i]<<endl;
    }

    cout<<"If the vector is empty: "<<v.empty()<<endl;
    v.push_back(-1);
    cout<<"Pushing at the back: "<<v[10]<<endl;

    v.resize(15);
    cout<<"After resizing: "<<endl;
    for(int i=1;i<v.size();i++)
    {
        cout<<v[i]<<endl;
    }

    //make copy of vector v
    vector<int> v1=v;
    cout<<"Vector v1(copy of v): "<<endl;
    for(int i=1;i<10;i++)
    {
        cout<<v1[i]<<endl;
    }

    return 0;
}
