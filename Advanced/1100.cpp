#include<cstdio>
#include<iostream>
#include<string>
using namespace std;

void  Mar2Earth(string s,string low[],string high[] )
{   string fi=s.substr(0,3),se; //
    
    if(s.length()>4) //有高位，那么fi 则是高位，否则fi为低位
        se=s.substr(4,3); //单独处理
    
    int t1=0,t2=0;
    for(int i=1;i<=12;i++) //不需要考虑tert,不给tert命中的机会 最后输出的也就是0
    {   if(fi==high[i] ) t1=i;
        if(se==low[i] ||fi==low[i]) t2=i;
    }

   cout<<t1*13+t2;
};

void Earth2Mar(int  i,string low[],string high[])
{   if(i/13) //数字大于等于13 高位存在 输出高位
    {   cout<<high[i/13];    
    }
    if(i%13 && i/13)    cout<<" "; 
    if(i%13 || i==0) //低位存在的条件是，数字本身为0或者除以13后不为0
        cout<<low[i%13]; 
};

int main()
{   int N;
    string low[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
    string high[13]={"tret","tam","hel","maa","huh","tou","kes","hei","elo","syy","lok","mer","jou"};
    string s;
    
    cin>>N;
    getchar();
    for(int i=0;i<N;i++)
    {   getline(cin,s);
        if(s[0]>='0'&&s[0]<='9')
            Earth2Mar(stoi(s),low,high);        
        else    Mar2Earth(s,low,high);
        cout<<endl;
    }

    return 0;
}