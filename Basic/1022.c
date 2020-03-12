#include<stdio.h>

int main()
{   long A,B,C;
    int D,count=0,res[32]={0};   
    scanf("%ld%ld%d",&A,&B,&D);
    if(A+B==0)  {   printf("0");    }
    if(D==10)
    {   printf("%ld",A+B);
        return 0;   
    }
    C=A+B;
    for(int i=0;C>0;i++)
    {   res[i]=C%D;
        C/=D;
        count++;
    }
    for(int i=count-1;i>=0;i--)
    {   printf("%d",res[i]);   
    }
   
    return 0;
}