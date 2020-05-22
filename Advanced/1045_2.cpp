#include<bits/stdc++.h>
using namespace std;
const int maxc=205 ,maxn=10005;
int A[maxc],B[maxn],dp[maxc][maxn];
int main(){
    int N,M,L;
    scanf("%d %d",&N,&M);
    for(int i=1;i<=M;i++)    scanf("%d",&A[i]);
    scanf("%d",&L);
    for(int i=1;i<=L;i++)    scanf("%d",&B[i]);
    
    //数据录入完毕，下面开始dp
    //边界
    for(int i=0;i<=M;i++)    dp[i][0]=0;
    for(int j=0;j<=L;j++)    dp[0][j]=0;
    //状态转移方程
    int maxn=0;
    for(int i=1;i<=M;i++){
        for(int j=1;j<=L;j++){
            //取dp[i-1][j]、dp[i][j-1]的较大值
            maxn=max(dp[i-1][j],dp[i][j-1]);
            dp[i][j]= A[i]==B[j] ? maxn+1 : maxn;
        }
    }
    cout<<dp[M][L];
    
    return 0;
}
