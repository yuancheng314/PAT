#include<iostream>
#include<cstdio>
#include<string>
using namespace std;

int main()
{   string a,b,c,d;
    string day[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};

    cin>>a>>b>>c>>d;
    //第一个循环找Day，第二个循环寻找HH,第三个循环用于找MM
    int i;
    for(i=0;i<a.length() && i<b.length();i++)
    {   if(a[i]==b[i] && a[i]>='A' && a[i]<='G')
        {    cout<<day[a[i]-'A']<<" ";
             break;
        }
    }

    for( ++i;i<a.length() && i<b.length();i++)
    {   if(a[i]==b[i])
        {    if(isdigit(a[i]) )     {  printf("%02d:",a[i]-'0'); break; }
             else if(a[i]>='A' && a[i]<='N' )   {  printf("%02d:",a[i]-'A'+10); break;}  
        }
    }
    
    for(int j=0;j<c.length() && j<d.length();j++)
    {   if(c[j]==d[j] && isalpha(c[j]))
        {    printf("%02d",j);
             break;        
        }
    }

    return 0;
}