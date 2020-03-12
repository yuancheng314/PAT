#include<stdio.h>

int main()
{
    int count,num,A2flag=1,A1=0,A2=0,A3=0,A4=0,countA4=0,A5=0;
    scanf("%d",&count);
    for(int i=0;i<count;i++)
    {   scanf("%d",&num);
    {   if(num%5==0 && num%2==0)
        {   A1+=num;   }
        else if(num%5==1)
        {   A2+=A2flag*num;
            A2flag=-A2flag;
        }
        else if(num%5==2)
        {    A3++;    }
        else if(num%5==3)
        {    A4+=num;
             countA4++;
        }
        else if(num%5==4 && num>A5)
        {   A5=num; }
        
    }
    }
  
    if(A1==0) {  printf("N ");}
    else {   printf("%d ",A1); }
    if(A2==0) {  printf("N ");}
    else {   printf("%d ",A2); }
    if(A3==0) {  printf("N ");}
    else {   printf("%d ",A3); }
    if(A4==0) {  printf("N ");}
    else {   printf("%.1f ",A4*1.0/countA4); }
    if(A5==0) {  printf("N ");}
    else {   printf("%d",A5); }

    return 0;
    
}