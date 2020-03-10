#include"stdio.h"

int main()
{
    int x;
    scanf("%d",&x);
    for(int i=0;i<(x/100);i++)
    {   printf("B");
    }
    for(int i=0;i<(x/10)%10;i++)
    {   printf("S");
    }
    for(int i=1;i<=(x%10);i++)
    {   printf("%d",i);
    }
    
     
    return 0;
}