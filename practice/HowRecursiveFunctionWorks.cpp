#include<iostream>
using namespace std;

void subsequence(string input,string output)
{
    if(input.length()==0)
    {
        cout<<"\nNow "<<input<<" "<<output;
        return;
    }
    cout<<"\nWhen we do not include("<<input[0]<<") ";cout<<input<<" "<<output;
    subsequence(input.substr(1),output);
    cout<<"\nWhen we include ("<<input[0]<<") "<<input<<" "<<output;
    subsequence(input.substr(1),output+input[0]);

}

int main()
{
    subsequence("ab","");
}
