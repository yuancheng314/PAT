#include<cstdio>

using namespace std;

int main()
{   int N,b,count=0,res[1000];
    scanf("%d %d",&N,&b);
    if(!N)  { printf("Yes\n0"); return 0;}
    for(;N>0;count++)
    {   res[count]=N%b;
        N/=b;
    }

    int low=0,high=count-1;
    for(;low<high;low++,high--)
    {
        if(res[low]!=res[high])     
            break; 
    }   
    printf("%s\n",low<high ? "No":"Yes");
    for(int i=count-1;i>=0;i--)
    {   printf("%d",res[i]);
        if(i>0)     printf(" ");
    }

    return 0;
}