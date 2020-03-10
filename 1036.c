#include <stdio.h>
#include <math.h>

int main()
{
    
    int num;
    char x;
    scanf("%d %c",&num,&x);
    int row=(float)num/2+0.5;
    //int row=(num+1)/2
    for(int i=0;i<row;i++)
    {   
        if(i==0||i==(row-1))
        {   
             for(int j=0;j<num;j++ )
            {
                printf("%c",x);
            }
            printf("\n");
        }
        else
        {
           printf("%c",x);
            for(int j=0;j<num-2;j++ )
            {
                printf(" ");
            }
            printf("%c\n",x);
        
        }
    }

    return 0;
}
