#include<bits/stdc++.h>
using namespace std;

int main()
{
    string number = "1234";
    int d;
    for(int i=number.length()-1;i>=0;i--)
    {
        if((int)number[i]>(int)number[i-1])
        {
            d = i-1;
            break;
        }
    }
    int min = number[d+1];
    int index = d+1;
    for(int i=d+1;i<number.length();i++)
    {
        if(min>number[i] && number[i]>number[d])
            {
                min = number[i];
                index = i;
            }
    }

    char ch = number[d];
    number[d] = number[index];
    number[index] = ch;

    for(int i=d+1;i<number.length()-1;i++)
    {
        int j = i+1;
        while(j>d+1)
        {
            if((int)number[j]<(int)number[j-1])
            {

                char temp = number[j];
                number[j] = number[j-1];
                number[j-1] = temp;

                //cout<<"yes";
            }
            j--;
        }
    }
    cout<<number;

}
