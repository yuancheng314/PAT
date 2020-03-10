#include<stdio.h>

int main()
{   int N,max=0;
    scanf("%d",&N);
    int school[100001]={0},num,score;
    for(int i=0;i<N;i++)
    {   scanf("%d%d",&num,&score);
        school[num]+=score;
    
    }
    for(int i=1;i<=N;i++)
    {   if(school[i]>school[max])
        {  max=i; }
    }
    printf("%d %d",max,school[max]);
    return 0;
}