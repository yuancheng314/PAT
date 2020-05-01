#include<iostream>
#include<algorithm>
using namespace std;

int main(){
    int n;
    cin>>n;
    int A[n],dp[n],start[n]={0},last=0;
    for(int i=0;i<n;i++){
        scanf("%d",&A[i]);
        if(i>0){
            if(dp[i-1]<0){
                dp[i]=A[i];
                start[i]=i;
            }
            else{
                dp[i]=dp[i-1]+A[i];
                start[i]=start[i-1];
            }
            if(dp[i]>dp[last]){//更新最大值
                last=i;
            }
        }
        else dp[i]=A[i];
    }
  	if(dp[last]>=0){
    		printf("%d %d %d\n",dp[last],A[start[last]],A[last]);
    }else
        printf("0 %d %d",A[0],A[n-1]);
    return 0;
}