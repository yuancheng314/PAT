#include<stdio.h>

int reverse(char* texts,int start,int end)
{   if(end<=start) {return texts;}
    char temp;
    while(start>end)
    {   temp=texts[start];
        texts[start++]=texts[end];
        texts[end--]=temp;
    }
    return texts;
    
}


int main()
{
    char texts[81];
    fgets(texts,81,stdin);
    //reverse(texts,0,12);
    puts(reverse(texts,0,12));
    return 0;
}