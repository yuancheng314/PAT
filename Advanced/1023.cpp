#include<iostream>
using namespace std;

int main(){
    string s;
    int d[22]={0},count[10]={0},double_d[22]={0};
    cin>>s;
    int len=s.length(),now=0;
    for(int i=len-1;i>=0;i--){
        d[now++]=s[i]-'0';
        count[s[i]-'0']++;
    }

    int carry=0;
    for(int i=0;i<len;i++)
    {
        double_d[i]=(2*d[i]+carry)%10;
        carry=(2*d[i]+carry)/10;
        count[double_d[i]]--;
    }
    
    while(carry!=0){
        double_d[len++]=carry%10;
        carry/=10;
    }
    int i;
    for( i=0;i<10;i++) if(count[i]!=0)   break;
    if(i!=10)   printf("No\n");
    else printf("Yes\n");

    for(int i=len-1;i>=0;i--)
        printf("%d",double_d[i]);
    return 0;
}