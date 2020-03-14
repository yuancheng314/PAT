#include<cstdio>
#include<iostream>

using namespace std;

int main()
{   const int N=54;   

    char  A[5]={'S','H','C','D','J'};
    int start[N+1],end[N+1],K,shuf[N+1];
    scanf("%d",&K);
    for(int i=1;i<=N;i++)
    {   scanf("%d",&shuf[i]); 
        start[i]=i;     
    }

    for(int step=0;step<K;step++)
    {   for(int i=1;i<=N;i++)
        {   end[shuf[i]]=start[i];   }
        for(int i=1;i<=N;i++)
        {   start[i]=end[i];  }
    }

    for(int i=1;i<=N;i++)
    {   if(i!=1)    printf(" "); 
        start[i]--; //原始的数是1-54，将其变为0-53后方便取余操作
        printf("%c%d",A[start[i]/13],start[i]%13+1);
    }

    return 0;
}
