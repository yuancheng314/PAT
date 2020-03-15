#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{   string text;
    cin>>text;
    int len=text.length();
    int n1=(len+2)/3;
    int n2=len+2-2*n1;
   
    int space=n2-2,i=0; //space为需要输出空格的行输出的空格数
    for( int j=1; j<=n1-1;i++,j++) //输出第1至n-1行
    {   cout<<text[i];
        for(int k=1;k<=space;k++)
            cout<<" ";
        cout<<text[len-1-i]<<endl;
    }
    
    for(int m=i;m<len-i;m++) //输出最底部的一行
        cout<<text[m];

    return 0;
}
