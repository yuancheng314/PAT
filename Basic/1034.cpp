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
    Fraction res;
    res.up=f1.up*f2.down+f2.up*f1.down;
    res.down=f1.down*f2.down;
    return reduction(res);
}
Fraction minu(Fraction f1,Fraction f2)
{
    Fraction res;
    res.up=f1.up*f2.down-f2.up*f1.down;
    res.down=f1.down*f2.down;
    return reduction(res);
}

Fraction multi(Fraction f1,Fraction f2)
{
    Fraction res;
    res.up=f1.up*f2.up;
    res.down=f1.down*f2.down;
    return reduction(res);
}

Fraction divide(Fraction f1,Fraction f2)
{
    Fraction res;
    res.up=f1.up*f2.down;
    res.down=f1.down*f2.up;
    return reduction(res);
}

void printFraction(Fraction f)
{   f=reduction(f);
    if(f.up<0)  printf("(");

    if(f.down==1)   cout<<f.up; //整数
    else if (abs(f.up)>f.down) //假分数
        if(f.up%f.down==0)  printf("%d",f.up/f.down);
        else
            printf("%lld %lld/%lld",f.up/f.down,abs(f.up)%f.down,f.down);
    else    printf("%lld/%lld",f.up,f.down); //真分数

    if(f.up<0)  printf(")");
}
int main()
{   int n;
    Fraction op1,op2;
    scanf("%lld/%lld %lld/%lld",&op1.up,&op1.down,&op2.up,&op2.down);
    
    //加法
    printFraction(op1);
    printf(" + ");
    printFraction(op2);
    printf(" = ");
    printFraction(add(op1,op2));
     cout<<"\n";
      //减法
    printFraction(op1);
    printf(" - ");
    printFraction(op2);
    printf(" = ");
    printFraction(minu(op1,op2));
     cout<<"\n";
      //乘法
    printFraction(op1);
    printf(" * ");
    printFraction(op2);
    printf(" = ");
    printFraction(multi(op1,op2));
     cout<<"\n";
      //加法
    printFraction(op1);
    printf(" / ");
    printFraction(op2);
    printf(" = ");
    if(op2.up==0)
        cout<<"Inf";
    else
        printFraction(divide(op1,op2));
    return 0;
}
