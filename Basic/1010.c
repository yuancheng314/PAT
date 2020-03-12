#include <stdio.h>

int main()
{   
    int coefficient,index,flag=0;
    while(scanf("%d %d",&coefficient,&index)!=EOF)
    {   if(index!=0)
        {   if(flag++) putchar(' ');
            print("%d %d",coefficient*index,index-1);
        }


    }
    if(flag==0) puts("0 0");
    
    return 0;
}