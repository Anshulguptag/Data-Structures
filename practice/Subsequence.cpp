#include<iostream>
#include<vector>
using namespace std;

vector<string> v;
vector<string> print_subs(string input, string output)
{
    if(input.length()==0)
    {
        v.push_back(output);
        return v;
    }

    print_subs(input.substr(1),output);
    print_subs(input.substr(1),output+input[0]);

    return v;
}

vector<string> Sort(vector<string> sort1)
{
   for(int i=0;i<sort1.size()-1;i++)
   {
       for(int j=i+1;j<sort1.size();j++)
       {
           string s1 = sort1[i];
           string s2 = sort1[j];

           if(s1[0]!=s2[0] && int(s1[0])>int(s2[0]))
           {
               string temp = s1;
               s1 = s2;
               s2 = temp;
           }
           else if(s1[1]!=s2[1] && int(s1[1])>int(s2[1]))
           {
               string temp = s1;
               s1 = s2;
               s2 = temp;
           }
           sort1[i] = s1;
           sort1[j] = s2;
       }
   }
   return sort1;
}

int main()
{
    string input;
    cin>>input;
    string output = "";
    vector<string> v1=print_subs(input,output);
    v1 = Sort(v1);

    for(int i=0;i<v1.size();i++)
    {
        cout<<v1[i]<<"\n";
    }
}
