#include<iostream>
using namespace std;
#define MAX 100

int hashfunction(int x,int size)
{
    return x%size;
}

int hashfunction2(int x)
{
    return (8-(x%8));
}

int main()
{
    int arr[] = {50,700,76,85,92,73,101};
    int size = *(&arr+1)-arr;
    int *hash1 = new int[MAX];
    for(int i=0;i<size;i++)
        hash1[i]=NULL;

    //a.) Linear Probing
    for(int i=0;i<size;i++)
    {
        int k = hashfunction(arr[i],size);
        while(hash1[k]!=NULL)
        {
            k = (hashfunction(arr[i],size)+(k+1))%size;
        }
        hash1[k]=arr[i];
    }
    cout<<"Linear Probing: ";
    for(int i=0;i<size;i++)
    {
        cout<<hash1[i]<<" ";
    }

    for(int i=0;i<size;i++)
        hash1[i]=NULL;


    //b.) Quadratic Probing
    for(int i=0;i<size;i++)
    {
        int k = hashfunction(arr[i],size);
        while(hash1[k]!=NULL)
        {
            k = (hashfunction(arr[i],size)+((k+1)*(k+1)))%size;
        }
        hash1[k]=arr[i];
    }
    cout<<"\nQuadratic Probing: ";
    for(int i=0;i<size;i++)
    {
        cout<<hash1[i]<<" ";
    }


    for(int i=0;i<size;i++)
        hash1[i]=NULL;


    //c.) Double hashing
    for(int i=0;i<size;i++)
    {
        int k = hashfunction(arr[i],size);
        while(hash1[k]!=NULL)
        {
            k = (hashfunction(arr[i],size)+(k+1)*hashfunction2(arr[i]))%size;
        }
        hash1[k]=arr[i];
    }
    cout<<"\nDouble Hashing: ";
    for(int i=0;i<size;i++)
    {
        cout<<hash1[i]<<" ";
    }
}
