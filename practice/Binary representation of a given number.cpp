#include<bits/stdc++.h>
using namespace std;

string Binary(int n)
{
    string output = "";
    while(n!=0)
    {
        int rem = n%2;
        n = n/2;
        ostringstream str1;
        str1 << rem;
        output = output + str1.str();
    }
    return output;
}

int main()
{
    cout<<"Enter the value that you want to convert into binary: ";
    int n;
    cin>>n;
    cout<<"Binary representation of "<<n<<" is: "<<Binary(n);
}
