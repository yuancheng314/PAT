#include<stdio.h>
#define ABS(X) ((X) >= 0 ? (X) : -(X))

int get_max(int N) 
//寻找对于给定的数，沙漏上半部分应为多少行
{   N=(N+1)/2;
    /*先对原始数N进行操作，将N+1后折半，
    看此数最多是多少个连续奇数的和*/
    int i=1,sum=1;
    while(sum<=N)
    {   i+=2;
        sum+=i;   
    }
    return (i-1)/2;
}

int main()
{
    int N,row,k;
    char symbol;
    scanf("%d %c",&N,&symbol);
    row=get_max(N);
    for(int i=0;i<row;i++)
    {   k=i;
        while(k--) { putchar(' ');   }
        for(int j=2*i;j<2*row-1;j++)
        {   putchar(symbol); }
        putchar('\n');
    }
    for(int i=row-2;i>=0;i--)
    {   k=i;
        while(k--) {  putchar(' '); }
        for(int j=2*i;j<2*row-1;j++)
        { putchar(symbol); }    
        putchar('\n');
    }
    
    /* for(int i=0;i<2*row-1;i++)
    {   for(int j=0;j< row-1- ABS(row - 1 - i);j++) {   putchar(' ');  }
        for(int j=0;j<2 * ABS(row - 1 - i) + 1;j++) { putchar(symbol); }
        putchar('\n');
    }　//这是别人的方法，个人感觉理解上更有难度，贴出来以供参考。 
    */
    printf("%d",N-2*row*row+1); //由等差数列求和公式推导
    return 0;
}