#include <stdio.h>

long get_Dpart(long num,int D_num)
{   long P_num=0;   
    for(;num>0;num/=10)
    {   if(num%10==D_num)
        {   P_num=P_num*10+D_num; }
    }

    return P_num;
}

int main()
{
    long A,B;
    int D_A , D_B;
    scanf("%ld %d %ld %d",&A,&D_A,&B,&D_B);
    printf("%ld",get_Dpart(A,D_A)+get_Dpart(B,D_B));
    return 0;
}