#include<iostream>
using namespace std;

int main()
{
    int i = 10; //i takes the value 10
    int *j = &i;// *j takes the address of i
    *j = 20;//now value of i is 20 because changement is occur at the same address of i
    cout<<i;
}
