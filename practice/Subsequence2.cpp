#include<bits/stdc++.h>
using namespace std;

int count1 = 0;

int findIndex(string s1)
{
    int M = s1.length();
    int acount = 0;
    int bcount = 0;
    int ccount = 0;
    if(M<=1)
        return -1;
    for(int i=0;i<M;i++)
        {

          if(s1[i]=='a')
            {
               acount++;
               if(bcount!=0)
                  return -1;
            }
          if(s1[i]=='b')
            {
               bcount++;
               if(acount==0 || ccount!=0)
                  return -1;
            }
          if(s1[i]=='c')
            {
               ccount++;
               if(acount==0 || bcount==0)
                  return -1;
            }
        }
        if(acount==0 || bcount==0 || ccount==0)
            return -1;
    return 0;
    }
void PrintSubs(string input,string output)
{
    if(input.length()==0)
    {
        if(findIndex(output)!=-1)
            count1++;

        return;
    }
    PrintSubs(input.substr(1),output);
    PrintSubs(input.substr(1),output+input[0]);
}

int main()
{
    string input = "ababc";
    string output = "";
    PrintSubs(input,output);
    cout<<count1;
}

