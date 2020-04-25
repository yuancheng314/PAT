#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int maxn=100005;
vector<int> primes(maxn);

bool isPrime(int x)
{
    if(x<=1)    return false;
    if(x==2)    return true;
    int ceil=sqrt(x*1.0);
    for(int i=2;i<=ceil;i++)
        if(x%i==0)
            return false;
    return true;
}

void getPrimeTable()
{    int prime_num=0;
     for(int i=2;i<maxn;i++)
         if(isPrime(i))
             primes[prime_num++]=i;
}
struct factor{  int x,cnt=0;    }fac[10];

int main()
{   long long target;
    scanf("%lld",&target);

    if(target==1)   {   printf("1=1"); return 0;}
    getPrimeTable();
    printf("%lld=",target);
    int ceil=sqrt(1.0*target),num=0;
    for(int i=0; primes[i] <=ceil;i++){
        if(target % primes[i]==0){
            fac[num].x=primes[i]; //记录该因子
            fac[num].cnt++;
            target/=primes[i];
            while(target % primes[i] == 0){
                fac[num].cnt++;
                target/=primes[i];
            }
            num++;
        }
        if(target==1) break;
    }

    if(target!=1){
        fac[num].x=target;
        fac[num++].cnt=1; 
    }
    for(int i=0;i<num;i++){ 
        if(i>0)     cout<<"*";
        cout<<fac[i].x;
        if(fac[i].cnt>=2)
            cout<<"^"<<fac[i].cnt;
    }

    return 0;
}