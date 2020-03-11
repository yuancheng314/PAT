#include <stdio.h>

int GCD(int x,int y)
{ /*calucate the greatest common divisor of x and y*/
    if(x==0) return 0; /*y is denominator ,cannot be zero */
    int temp;
    while(x%y!=0)
    {   temp=x;   
        x=y;
        y=temp%x;
    }
    return y;
}
//Denominator Molecular

int main()
{   int a1,b1,a2,b2,deno,add,sub,mul,div;
    int inf_flag=0,nega_flag1=0,nega_flag2=0;
    char symbol={'+','-','*','/'};
    scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);

    deno = b1*b2;
    add = a1*b2+a2*b1;
    mul = a1*a2;
    if (a1<0) { a1=-a1; nega_flag1=1;}
    if (a2<0) { a2=-a2; nega_flag2=1;}
    int gcd1=GCD(a1,b1),gcd2=GCD(a2,b2);

    int simp_a1=a1/gcd1,simp_b1=b1/gcd1,;   
    /* print */
    if(gcd1==0)
    {   
        if(gcd2=0)
        {   for(int i=0;i<3;i++) /*add sub mul all the same*/  
            { printf("0 %c 0 = 0",symbol[i]);}
            printf("0 / 0 = Inf");
        }
        else
        {   for(int i=0;i<2;i++)  /*add sub both the same*/ 
            { printf("0 %c %d/%d = %d",symbol[i]);}
            for(int i=2;i<4;i++)  /*mul div both the same*/ 
            { printf("0 %c %d/%d = %d/%d",symbol[i],simp_a1,);}
        }
  
    }
 

    return 0;
}