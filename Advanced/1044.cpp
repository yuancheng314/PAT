#include<iostream>
#include<algorithm>
using namespace std;

int main()
{   int N,M,temp;
    cin>>N>>M;
   
    int sum[N+1]={0},nearM=1e9;
    for(int i=1;i<=N;i++)
    {   scanf("%d",&sum[i]);
        sum[i]+=sum[i-1];
    }
    
    for(int i=1;i<=N;i++)   //枚举左端点 
    {   int j=lower_bound(sum,sum+N+1,sum[i-1]+M)-sum; //求右端点
        if(sum[j]-sum[i-1]==M)//查找成功
        {   nearM=M;
            break;
        }
        else if(j<=N && sum[j]-sum[i-1]<nearM) //注意添加j<=N,避免返回值越界产生的错误
        {   nearM=sum[j]-sum[i-1];  }
    }

    for(int i=1;i<=N;i++)
    {   int j=lower_bound(sum,sum+N+1,sum[i-1]+M)-sum; 
        if(sum[j]-sum[i-1]==nearM)
        {   printf("%d-%d\n",i,j);      }
    }
    
    return 0;
}