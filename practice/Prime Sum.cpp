#include<bits/stdc++.h>
using namespace std;

bool checkPrime(int p)
{
    int i,m=0;
    m = p/2;
    for(i=2;i<=m;i++)
    {
        if(p%i==0)
            return false;
    }
    return true;
}
vector<int> primesum(int A) {
    vector<int> numbers;
    int low=2;
    int high=A;
    int number1,number2;
    for(int i=2;i<A;i++)
    {
        if(checkPrime(i))
        {
            if(checkPrime(A-i))
            {
                numbers.push_back(i);
                numbers.push_back(A-i);
                break;
            }
        }
    }
    return numbers;
}

int main()

{
    vector<int> l = primesum(1048574);
    for (int i=0;i<l.size();i++)
        cout<<l[i]<<" ";
}
