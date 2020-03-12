#include<stdio.h>
#include<ctype.h>

int main()
{   char s1[82],s2[82],c;
    int error[128]={0};
    scanf("%s %s",s1,s2);
    for(int i=0 ,j=0;s1[i]!='\0';i++,j++)
    {   if(s1[i]!=s2[j] )
        { error[toupper(s1[i])]++;
          j--;
        }
    }
    for(char *p=s1;*p;p++)
    {   c=toupper(*p);
        if(error[(int)c]>0)
        {   putchar(c);   
            error[(int)c]=0;       
        }
    }
    
    return 0;
}
