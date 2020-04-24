#include<iostream>
#include<cstdio>
using namespace std;

struct Fraction {   long long up=0,down=1; };
long long gcd(long long a,long long b) {    return b==0 ? a : gcd(b,a%b);  }

Fraction reduction(Fraction target )
{
    if(target.down<0)
    {
        target.up*=-1;
        target.down*=-1;
    }
    if(target.up==0)    target.down=1;
    else //约分
    {   long long d=gcd(abs(target.up),abs(target.down));
        target.up/=d;
        target.down/=d;
    }
    return target;
}
Fraction add(Fraction f1,Fraction f2)
{
    Fraction sum;
    sum.up=f1.up*f2.down+f2.up*f1.down;
    sum.down=f1.down*f2.down;
    return reduction(sum);
}
void printFraction(Fraction f)
{
    if(f.down==1)   cout<<f.up;
    else if (abs(f.up)>f.down) //假分数
        printf("%lld %lld/%lld",f.up/f.down,abs(f.up)%f.down,f.down);
    else    printf("%lld/%lld",f.up,f.down);
}
int main()
{   int n;
    Fraction sum,temp;
    cin>>n;
    for(int i=0;i<n;i++)
    {   scanf("%lld/%lld",&temp.up,&temp.down);
        sum=add(sum,temp);
    }
    printFraction(sum);
    return 0;
}
