#include<iostream>
using namespace std;

void NearestSmallest(int input[],int output[],int size)
{
    for(int i=0;i<size;i++)
    {
        int min =input[i];
        int j = i ;
        while(j!=-1)
        {
            if(input[j]<min)
            {
               min = input[j];
               break;
            }

            j--;
        }
        if(input[i]==min)
            output[i] = -1;
        else
            output[i] = min;
    }
}

int main()
{
    int input[] = {1,3,0,2,5};
    int size =*(&input+1)-input;
    int *output = new int[size];
    NearestSmallest(input,output,size);
    for(int i=0;i<size;i++)
        cout<<output[i]<<",";
}
