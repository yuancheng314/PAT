#include<stdio.h>

int main(void)
{   int sum=0;//和的最大值为100

    char temp, *pinyin[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

    while((temp=getchar())!='\n'){
        sum+=temp-'0';
    }
    if(sum/100){ printf("%s ",pinyin[sum/100]); }
    if(sum/10){ printf("%s ",pinyin[(sum/10)%10]); }
    printf("%s",pinyin[sum%10]);


    return 0;
}