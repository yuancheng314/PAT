#include<bits/stdc++.h>
using namespace std;

const int maxc=201,maxn=10005;
int hashtable[maxc],A[maxn],dp[maxn];
int main(){
    int N,M,L,x;
    cin>>N>>M;
    fill(hashtable,hashtable+maxc,-1);
    for(int i=0;i<M;i++){
        scanf("%d",&x);
        hashtable[x]=i;
    }
    int cnt=0; //cnt用于记录喜欢的颜色出现的次数
    scanf("%d",&L);
    for(int i=0;i<L;i++){
        scanf("%d",&x);
        if(hashtable[x]>=0)
            A[cnt++]=hashtable[x];
    }
    
    //完成转换,下面是LIS的模板
    int ans=-1;
    for(int i=0;i<cnt;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(A[j]<=A[i] && dp[i]<dp[j]+1)
                dp[i]=dp[j]+1;
        }
        ans=max(ans,dp[i]);
    }
    
    cout<<ans<<endl;
    return 0;
}
