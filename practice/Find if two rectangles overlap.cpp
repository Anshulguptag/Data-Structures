#include<bits/stdc++.h>
using namespace std;

struct Rectangle
{
    int x1,x2,y1,y2;
};

int main()
{
    Rectangle rect[] = {
                        {0,10,10,0},
                        {5,15,5,-5 }
                        };
   if((rect[0].y1-rect[0].y2) == (rect[1].y1-rect[1].y2) && (rect[0].x1-rect[0].x2) == (rect[1].x1-rect[1].x2))
      cout<<"Overlap";
   else
       cout<<"Not overlap";
}
