#include <stdio.h>
int main(void){
    int num;
    scanf("%d",&num);
    for(int i=1;i<=num;i++)
    {   long int a,b,c;
        scanf("%ld %ld %ld", &a, &b, &c);
        if(a+b>c){printf("Case #%d: true\n",i);}
        else{printf("Case #%d: false\n",i);}
    }

    return 0;
}