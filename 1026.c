#include<stdio.h>

int main()
{
   int C1,C2,h,m,s;
   scanf("%d%d",&C1,&C2);
   C1=(int)((C2-C1)*1.0/100+0.5);
    h=C1/3600;
    m=(C1%3600)/60;
    s=(C1%3600)%60;
    printf("%02d:%02d:%02d",h,m,s); 
    return 0;
}