#include<iostream>
#include<cmath>
using namespace std;

bool isPrime(int x)
{   if(x<=1) return false;
    if(x==2) return true;
    int ceil=sqrt(x*1.0);
    for(int i=2;i<=ceil;i++)
        if(x%i==0)
            return false;
    return true;
}

int main()
{   int n,base;
    while(scanf("%d",&n)!=EOF)
    {
        if(n<0) break;
        scanf("%d",&base);
        if(!isPrime(n))
            printf("No\n");
        else //是负数　那么先进制转换再反转，再转换
        {   int len=0,arr[101];
            do{
                arr[len++]=n%base;
                n/=base;
            }while(n!=0);
            for(int i=0;i<len;i++)
                n=n*base+arr[i];
            printf("%s\n", isPrime(n) ? "Yes" : "No");
        }
    }

    return 0;
}