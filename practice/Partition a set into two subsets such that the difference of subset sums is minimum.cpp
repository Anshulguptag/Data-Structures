#include<bits/stdc++.h>
using namespace std;

vector<int> arr;
vector<int> arr1;
int sum(vector<int> a)
{
    int sum = 0;
    for(int i=0;i<a.size();i++)
        sum = sum + a[i];

    return sum;
}

void SplitSets()
{
    int sum2 =0,sum1=50;
    while(1)
    {
        int min = arr[0];
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i];
            if(arr[i]<min)
            {
                min = arr[i];
            }
        }
        cout<<"\n";

        vector<int>::iterator i1;

        for(i1=arr.begin();i1!=arr.end();i1++)
        {
            if(*i1 == min)
                arr.erase(i1);
        }
        /*
        arr1.push_back(min);
        sum2 = sum(arr)-sum(arr1);
        if(sum2<0)
            sum2 = -1*sum2;
        if(sum1<sum2)
        {
            cout<<sum2;
            break;
        }
        sum1 = sum2;
        */
    }

}


int main()
{
    arr.push_back(1);
    arr.push_back(6);
    arr.push_back(11);
    arr.push_back(5);
    SplitSets();
}
