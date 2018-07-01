#include<iostream>
/*
std is the standard namespace. cout, cin and a lot of other things are defined in it.
( This means that one way to call them is by using std::cout and std::cin.)
The keyword using technically means, use this whenever you can. This refers, in this case, to the std namespace.*/
using namespace std;

template<typename T>
T sum(T a,T b)
{
    return a+b;
}
int main()
{
    float x=10.2,y=20.9;
    cout<<"Float sum: "<<sum<float>(x,y)<<endl;
    int a=10,b=10;
    cout<<"Int sum: "<<sum<int>(a,b);

    return 0;
}
