#include <stdio.h>

int main()
{   int N,M,now;
    scanf("%d%d",&N,&M);
   
    int sales[1000]={0};
    for(int i=0;i<M;i++)
    {  for(int j=0;j<N;j++)
       {    scanf("%d",&now);
            sales[j]+=now;
       }
    }

    int max=0;
    for(int i=0;i<N;i++)
    {   if(sales[i]>max){ max=sales[i];}
    }
    
    printf("%d",max);
    for(int i=0,count=0;i<N;i++)
    {   if(sales[i]==max){ printf("%c%d",count++? ' ':'\n',i+1); }
    }
    return 0;
}