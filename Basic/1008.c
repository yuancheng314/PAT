#include"stdio.h"

void RightShift( int arr[],int N, int k)
{
    while(k--)
    {
        char t = arr[N-1];
        for(int i = N-1; i > 0; i--)
            arr[i] = arr[i-1];
        arr[0] = t;
    }
    
    for(int i=0;i<N-1;i++)
    {   printf("%d ",arr[i]);
    }
    printf("%d",arr[N-1]);
}

int main()
{
    int N,M;
    //输入
    scanf("%d %d",&N,&M);
    int table[N];
    for(int i=0;i<N;i++)
    {   scanf("%d",&table[i]);
    }
    //变换&输出
    RightShift(table,N,M);
    
     
    return 0;
}