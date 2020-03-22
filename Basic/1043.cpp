#include<iostream>
using namespace std;

int main()
{   
    int hash[128]={0};
    char c;
    while((c=getchar())!=EOF) hash[c]++;
    while(hash['P']>0||hash['A']>0||hash['T']>0||hash['e']>0||hash['s']>0||hash['t']>0)
    {   if(hash['P']-->0)   printf("P");
        if(hash['A']-->0)   printf("A");
        if(hash['T']-->0)   printf("T");
        if(hash['e']-->0)   printf("e");
        if(hash['s']-->0)   printf("s");
        if(hash['t']-->0)   printf("t");
    }
    return 0;
}