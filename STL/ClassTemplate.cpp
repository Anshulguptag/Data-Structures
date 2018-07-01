#include<iostream>
using namespace std;

template<class T>
class something
{
    public:
        T a[2]; //It is declaration of array of size 2
        T add();
        something();
};

template<class T>
something<T>::something()
{
    cout<<"Enter two values: ";
    cin>>a[0]>>a[1]; //In this we take input in a[0] and a[1]
}

template<class T>
T something<T>::add()
{
 return a[0]+a[1];
}

int main()
{
    something<float> floatsomething;
    cout<<"Sum is: "<<floatsomething.add();
    return 0;
}
