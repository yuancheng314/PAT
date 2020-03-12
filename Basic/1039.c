#include"stdio.h"

int main()
{
    int tell[128]={0};
    int more=0,less=0;
    char x;
    //输入欲判断的数组
    while((x=getchar())!='\n')
    {   tell[(int)x]++;
    }
    //输入目标数组
    while((x=getchar())!='\n')
    {   tell[(int)x]--;
    }
    //判断
    for(int i=0;i<128;i++)
    {   if(tell[i]>0)   {more+=tell[i];}
        else if(tell[i]<0) {less-=tell[i];}
    }
    //给出结论
    if(less){printf("No %d",less);}
    else {printf("Yes %d",more);}
    return 0;
}