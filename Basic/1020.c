#include <stdio.h>

int main()
{
    int N,D;
    scanf("%d %d",&N,&D);
    double inventory[N];
    double totalprice[N];
    for(int i=0;i<N;i++)
    {   scanf("%lf",&inventory[i]);
    }
    for(int i=0;i<N;i++)
    {   scanf("%lf",&totalprice[i]);
    }
   
    int max;
    double income=0;//income用于记录　现在已经获得的收益
    while(D)
    {   max=0;
       for(int i=0;i<N;i++) //找出余下的单价最高的月饼
        { 
            if (totalprice[i]/inventory[i]>totalprice[max]/inventory[max])
            {  max=i; 
            }            
        }
        
        if(inventory[max]<D)
        {   income+=totalprice[max];
            D-=inventory[max];
            totalprice[max]=0;//将已出售的月饼的总价置为０而不能将该类月饼的余量置为０，否则会发生除０错误
        }
        else //月饼总量已经足够
        {   income+=totalprice[max]*D/inventory[max];//先乘后除，以免精度下降
            D=0;
        }
    }
    printf("%.2f",income);

    return 0;
}