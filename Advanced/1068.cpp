#include<bits/stdc++.h>
using namespace std;
int N,M;
bool choice[10005][10005];
int coins[105],dp[105]={0};
bool cmp(int a,int b){ return a>b; }
int main(){
    cin>>N>>M;
   
    for(int i=1;i<=N;i++)    scanf("%d",&coins[i]);
    sort(coins+1,coins+N+1,cmp);
    
    for(int i=1;i<=N;i++){
        for(int j=M;j>=coins[i];j--){
            //状态转移方程
            if(dp[j]<=dp[j-coins[i]]+coins[i]){
                dp[j]=dp[j-coins[i]]+coins[i];
                choice[i][j]=1; //放入第i件物品
            }
            else choice[i][j]=0;
        }
    }
    
    if(dp[M]!=M)    printf("No Solution");
    else{ //记录最优路径
        vector<int> ans;
        int k=N,v=M;
        while(v>0){
            if(choice[k][v]==1){
                v-=coins[k];
                ans.push_back(coins[k]);
            }
            k--;
        }
        for(int i=0;i<ans.size();i++){
            if(i!=0) printf(" ");
            printf("%d",ans[i]);
        }
    }
    return 0;
}
