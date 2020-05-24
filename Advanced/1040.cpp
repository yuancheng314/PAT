#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int len,ans = 1;
    getline(cin,s);
    len=s.length();
    int dp[len+1][len+1];
    //初始化边界条件
    fill( dp[0],dp[0]+(len+1)*(len+1),0 );
    for(int i=0;i<len;i++){
        dp[i][i]=1;
        if(i<len-1 && s[i]==s[i+1] ){
            dp[i][i+1]=1;
            ans=2;
        }
    }
    //状态转移方程
    for(int L=3;L<=len;L++){ //枚举子串的长度
        for(int i=0;i+L-1<len;i++){ //枚举子串的起始端点
            int j=i+L-1; //子串的右端点
            if(s[i]==s[j]&&dp[i+1][j-1]==1 ){
                dp[i][j]=1;
                ans=L;
            }
        }
    }
    
    printf("%d",ans);
    return 0;
}