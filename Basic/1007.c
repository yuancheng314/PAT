#include"stdio.h"
#include "math.h"
#include "stdbool.h"
bool isprime(int x) //常规判断素数
{   if(x==2||x==3){return true;}
    int ceil=(int)(sqrt(x)+0.5);
    for(int i=2;i<=ceil;i++)
    { if(x%i==0) {return false;}

    } 
    
    return true;
}

int solution(int N)
{   if(N<=4){ printf("0"); return 0;}
    int count=1;//N>=5自然就至少有３和５这一组素数对
    for(int i=5;i+2<=N; )
    { if(isprime(i)&&isprime(i+2))
      {count++;}
      i+=2;/*除了2其他素数都是奇数，每次i+2*/
    }
    printf("%d",count);
    return count;

}

int main()
{
    int N;
    scanf("%d",&N);
    solution(N);
     
    return 0;
}