#include<iostream>
using namespace std;

void mergesort(int unsorted[10])
{
    int value,hole;
    for (int i=1;i<10;i++)
    {
        value = unsorted[i];
        hole = i;
        while(hole>0 && unsorted[hole-1]>value)
        {
            unsorted[hole]=unsorted[hole-1];
            hole = hole-1;
        }
        unsorted[hole] = value;
    }
}

int main()
{
    int unsorted[10];
    int i;
    int *array1;
    cout<<"Enter the elements of Array: \n";
    for (i=0;i<10;i++)
    {
        cout<<"Unsorted ["<<i<<"]: ";
        cin>>unsorted[i];
    }
    cout<<"\nSorted Array is: \n";
    mergesort(unsorted);
    for (i=0;i<10;i++)
    {
        cout<<"Sorted ["<<i<<"]: "<<unsorted[i]<<"\n";
    }

}
