#include<iostream>
using namespace std;

int main()
{
    int a[10];
    for(int i=0;i<=10;i++)
        cout<<&a[i]<<" ";

    cout<<"\n";
    int n = *(&a+1)-a;
    cout<<&a;
    cout<<"\n"<<(&a+1);
    cout<<"\n"<<*(&a+1);
    cout<<"\n"<<(*(&a+1)-a);
    cout<<"\n"<<sizeof(a);

    int i=10;
    int *p = &i;
    float *pf ;
    cout<<"\n"<<sizeof(pf);
    cout<<"\n"<<p;
    *p = i;
}

