#include<stdio.h>
/* note:the fllowing code don't abtain all the 
scores of the problem,but I can't improve anymore.*/
int main()
{
    int a,b,res[10]={0},count=0;
    scanf("%d %d",&a,&b);
    if((a+=b)==0) /*if a equals zero ,print zero  directly*/
    {   printf("0"); 
        return 0; 
    }
    if(a<0) { printf("-"); a=-a; }
    /* if a is negative,print signal first
        and let a equals its ABS.
    */
    while( a>0 )
    {   res[count++]=a%1000;
        a/=1000;
    }
    for(int i=count-1;i>0;i--)
    /*count-1 equals numbers in array res */
    {   if(res[i]>0) { printf("%d,",res[i]); }
        else { printf("000,"); } 
        
    }
    if(res[0]>0) { printf("%d",res[0]); }
    else { printf("000"); }   
    return 0;
}

