#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N,K;
    vector<int> d1(130),d2(130);
    string s;
    cin>>s>>K;
    
    int len=s.length(),copy_len=s.length();
    for(int i=0;i<len;i++)    d1[i]=d2[--copy_len]=s[i]-'0';
    
    int i=0,carry=0,temp,m;
    for(;i<K;i++){
        for( m=0;m<len;m++)  if(d1[m]!=d2[m]) break; //判断d1，d2是否相同，如果最终m=len，则为回文
        if(m==len)  break;
        for(int j=0;j<len;j++){ //大数相加
            temp=carry+d1[j]+d2[j];
            carry=temp/10;
            d2[j]=temp%10;
        }
        while(carry!=0){ //最终的高位产生了进位   
            d2[len++]=carry;
            carry/=10;
        }
         copy_len=len; //将d2倒置存入d1中
         for(int n=0;n<len;n++)    d1[--copy_len]=d2[n];
    }
   
    for(int k=len-1;k>=0;k--)  printf("%d",d2[k]);
    printf("\n%d",i);

    return 0;
}