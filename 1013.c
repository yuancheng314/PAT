#include "stdio.h"
#include "stdbool.h"
#include "math.h"
int M,N;

bool isprime(int x)
{   if(x==2||x==3){return true;}
    int ceil=(int)(sqrt(x)+0.5);
    for(int i=2;i<=ceil;i++)
    {   if(x%i==0){return false;}
    }
    
    return true;
}

int primes(int M,int N)
{   int count=1;
    int primes[1000]={0};
    primes[0]=2;
    for(int i=3;count<N;i+=2)
    {   if(isprime(i))
        {primes[count++]=i;}
    }
        
    for(int i=M;i<N;i++)
    {   printf("%d",primes[i-1]);
      
      
       printf((i - M + 1) % 10 ? " " : "\n"); 
    }
    printf("%d", primes[N - 1]); //最后一个数字需要单独处理
    return 0;

}

int main(){
    int M,N;
    scanf("%d %d",&M,&N);
    primes(M,N);
    
    return 0;
}