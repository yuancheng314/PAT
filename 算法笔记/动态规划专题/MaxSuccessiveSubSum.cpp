/* 动态规划 最大连续子序列和
测试输入：
6
-2 11 -4 13 -5 2
预期输出：
20
*/
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int A[n],dp[n],k=0;
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
        if(i>0){
            dp[i]=max(dp[i-1]+A[i],A[i]);
            k=dp[i]>dp[k] ? i : k;
        }
        else dp[i]=A[i];
    }
    printf("%d\n",dp[k]);
    return 0;
}