#include<stdio.h>

int main()
{
    char A[1001] ;
    int B,R,tempremainder=0,temp;
    char* p=A;
    scanf("%s %d",A,&B);
    for(int i=0;A[i];i++)
    {   temp=tempremainder*10+(A[i]-'0');
        tempremainder=temp%B;
        A[i]=temp/B+'0'; /*注意到原来的Ａ中存放的字符类型，
        而temp/B为int类型，所以应该加上'0'*/

    }
    R=tempremainder;
    if(A[0]=='0'&&A[1]!='\0') {p++;};
    /*若最终的商就为０，那么就不应该将第一位舍去，此
    时A[1]='\0'   
    */
    printf("%s %d",p,R);
     
    return 0;
}