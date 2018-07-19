#include<bits/stdc++.h>
using namespace std;

int findMax(int i,int j,int arr[6][6])
{
  int sum = 0 ;
  for(int m = i; m<i+3; m++)
  {
      for(int n = j; n<j+3; n++)
      {
          sum = sum + arr[m][n];
      }
  }
  return sum;
}

int main()
{
    int arr[6][6] = {{-1,-1,0,-9,-2,-2},{-2,-1,-6,-8,-2,-5},{-1,-1,-1,-2,-3,-4},{-1,-9,-2,-4,-4,-5},{-7,-3,-3,-2,-9,-9},{-1,-3,-1,-2,-4,-5}};
    int max1 = -1000000;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
            if(findMax(i,j,arr)>max1)
                max1 = findMax(i,j,arr);
    }
    cout<<max1;
}
