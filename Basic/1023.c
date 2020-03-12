#include"stdio.h"

int main()
{
    int num[10];
    for(int i=0;i<=9;i++)
    {   scanf("%d",&num[i]);  }
   
    if(num[0]==0)
    {   for(int j=1;j<=9 ;j++)
        {   for(int k=j;num[k]>0;)
            {   
                printf("%d",k);
                num[k]--;
            }       
        }              
    }
    else
    {   for(int j=1;j<=9 ;j++)
        { 
            for(int k=j;num[k]>0;)
            {   
                printf("%d",k);
                while(num[0])
                {   printf("0");
                    num[0]--;
                }
                num[k]--;
            }         
         }
    } 
    return 0;
}