#include"stdio.h"

int main()
{   char x;
    int count[10]={0};
    while((x=getchar())!='\n')   
    {   count[x-'0']++;
    }
    for(int i=0;i<10;i++)
    {   if(count[i])
        {printf("%d:%d\n",i,count[i]);}
    }   
    
     
    return 0;
}