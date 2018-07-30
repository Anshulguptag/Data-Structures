#include<bits/stdc++.h>

using namespace std;

struct Height
{
    int feet;
    int inches;
};

int main()
{
    Height arr[] = {{ 1, 3 },
        { 10, 5 },
        { 6, 8 },
        { 3, 7 },
        { 5, 9 }
        };
    int size  = *(&arr+1)-arr;
    int maximum = 0;
    for(int i=0;i<size;i++)
    {
        int height = 12*arr[i].feet + arr[i].inches;
        if(height>maximum)
            maximum = height;
    }
    cout<<"max :: "<<maximum;
}
