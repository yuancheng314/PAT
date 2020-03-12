#include"stdio.h"
#include "math.h"

int iskeepself(int x);
int length_of(int x);

int main()
{   int M;
    scanf("%d",&M);
    int num[M];
    for(int i=0;i<M;i++) {scanf("%d",&num[i]);}

    for(int i=0;i<M;i++)
    {  
        if(iskeepself(num[i]))
        {   printf("%d %d\n",iskeepself(num[i]),iskeepself(num[i])*num[i]*num[i]);
        }
        else{printf("No\n");}
    }
     
    return 0;
}

int length_of(int x)//求一个数的位数
{   int length=1;
    while((x=x/10)){length++;}
    return length;
}

int iskeepself(int x)//判断是否为自守数
{   int square=x*x;
 
    for(int i=1;i<=9;i++)
    {   int test=i*square;
        if((test%(int)(pow(10,length_of(x))))==x)
        {return i;}
        
    }

    return 0;

}
