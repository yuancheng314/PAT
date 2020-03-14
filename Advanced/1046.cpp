#include<cstdio>
#include<iostream>
#include<vector>
using namespace std;

int main()
{   int N,distance,M,a,b;
    cin>>N;
    vector<int> D(N+1,0);
    /*D[i]中存储第一个点顺时针到第i个点的距离，D[0]中存储整个环的长度*/
    for(int i= 2;i<=N;i++)
    {   scanf("%d",&distance);
        D[i]=distance+D[i-1];
    }
    scanf("%d",&distance);
    D[0]=D[N]+distance;
    double half_D=D[0]/2;

    cin>>M;
    vector<int> exit(M);
    for(int i=0;i<M;i++)
    {   cin>>a>>b;
        if(a>b) 
        {   int temp=a;  
            a=b;
            b=temp;
        }
        printf("%d\n",D[b]-D[a]<=half_D ? D[b]-D[a] : D[0]-(D[b]-D[a]) ); 
    }

    return 0;
}
