#include<stdio.h>

int reverse(int x)
{   int re=0;
    while(x>0)
    {   re=re*10+x%10;
        x/=10;
    }
    return re;

}

int main()
{   
    int num,flag[10]={0},fi,se;
    scanf("%d",&num);
    if((num%1111)==0) 
    {    printf("%d - %d = 0000",num,num);
         return 0;
    }
    do
    {   
        fi=0;
        se=0;
        for(int i=0;i<4;i++)
        {   flag[num%10]++;
            num/=10;
        }
        for(int i=0;i<10;i++)
        {   while(flag[i]!=0)
            {   se=10*se+i;
                flag[i]--;            
            }
        }
       fi=reverse(se);
        while(fi<1000) 
            {   fi*=10; }  
        num=fi-se;
        printf("%04d - %04d = %04d\n",fi,se,num);
    }while(num!=6174);
    return 0;
}