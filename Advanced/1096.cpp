#include<iostream>
#include<cmath>
using namespace std;

int main()
{   long long n;
    scanf("%lld",&n);

    int maxn=sqrt(n*1.0)+1,len=0,start=0;

    for(int i=2;i<=maxn;i++)
    {
        int j,temp=1;
        for(j=i;j<=maxn;j++)
        {
            temp*=j;
            if(n%temp!=0)   break;
        }
        if(j-i>len) //更新最大长度和起始位置
        {
            len=j-i;
            start=i;
        }
    }

    if(start==0) //没找到,也就是说n是素数
        cout<<1<<endl<<n;
    else{
        cout<<len<<endl;
        for(int i=0;i<len;i++){
            printf("%d",start+i);
            if(i!=len-1)    printf("*");
        }
    }


    return 0;
}