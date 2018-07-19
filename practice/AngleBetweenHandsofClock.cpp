#include<bits/stdc++.h>
using namespace std;

int mini(int x,int y)
{
    return (x<y)?x:y;
}

void Findangle(int h,int m)
{
    if(m==60) m=0;
    if(h==12) h=0;
    int angle = (h*30 + (m/60)*30)-(m*6);
    cout<<mini(360-angle,angle);
}

int main()
{
    Findangle(9,60);
}
