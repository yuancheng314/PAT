#include<iostream>
#include<string>
using namespace std;

int main()
{   string a;
    getline(cin,a);
    int hash[128]={0},max=95,len=a.length();
    for(int i=0;i<len;i++)
    {   hash[tolower(a[i])]++;
    }
    for(int i=95;i<128;i++)
    {   if(hash[i]>hash[max]) 
            max=i;   
    }
    printf("%c %d",(char)max,hash[max]);

    return 0;
}