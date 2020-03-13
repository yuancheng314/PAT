#include<cstdio>

int main()
{   int num=0;
    char text[81][20];
    while(scanf("%s",text[num++])!=EOF);
    for(int i=num-2;i>0;i--) /*注意这里i的初始值*/
    {   printf("%s ",text[i]);
    }
    printf("%s",text[0]);

    return 0;
}