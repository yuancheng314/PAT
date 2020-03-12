#include<stdio.h>
#include<ctype.h>
int main()
{
    char ch;
    int word[128]={0};
    
    while((ch = getchar()) != '\n') /*read the words that lose*/
    {   word[toupper(ch)]=1;   }
  
    while((ch = getchar()) != '\n') 
    {   if( word[toupper(ch)]!=1  && !( word['+'] && isupper(ch) ) )
         {    printf("%c",ch); } 
    }
      
    return 0;
}
