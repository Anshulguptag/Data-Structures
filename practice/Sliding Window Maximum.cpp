 #include<bits/stdc++.h>
 using namespace std;

 void FindMax(int input[],int output[],int size,int window)
 {
     for(int i=0;i<size-window+1;i++)
     {
         int max = input[i];
         for(int j=i;j<i+window;j++)
         {
             if(input[j]>max)
                max = input[j   ];
         }
         output[i] = max;
     }
 }

 int main()
 {

     int input[] = {12, 1, 78, 90, 57, 89, 56};
     int size = *(&input+1)-input;
     int window = 3;
     int output[size-window+1];

     FindMax(input,output,size,window);

     for(int i=0;i<size-window+1;i++)
        cout<<output[i]<<" ";

 }
