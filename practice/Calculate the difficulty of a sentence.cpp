#include<bits/stdc++.h>
using namespace std;

int main()
{
    string str = "I am a geek";
    int hard=0;
    int easy = 0;
    int tokens = 0;
    for(int k=0;str[k]!='\0';k++)
    {
        if(str[k]==' ')
            tokens++;
    }
    int j=0;
    int flag = 0;
    for(int i=0;i<tokens+1;i++)
    {
        int vowels , consonants, consecutive ;
        vowels = consonants = consecutive = 0;
        while(str[j]!=' ' && str[j]!='\0')
        {
            if(isupper(str[j]))
                str[j] = tolower(str[j]);
            if((int)str[j]>=97 && (int)str[j]<=122)
            {
                if(str[j]=='a' || str[j]=='e' || str[j]=='i' || str[j]=='o' || str[j]=='u')
                   {
                     vowels = vowels + 1;
                     consecutive = 0;
                   }

                else
                {
                    consonants = consonants + 1;
                    consecutive = consecutive +1;
                }
                if(consecutive==4)
                {
                    flag =1;
                    break;
                }
            }
            j++;
            if(flag==1)
                break;
        }

        j=j+1;
        if(consonants>vowels || consecutive==4)
            hard = hard + 1;
        else
            easy = easy + 1;
    }
    cout<<(5*hard + 3*easy);

}
