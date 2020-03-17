#include<iostream>
#include<string>

using namespace std;

string deal(string str,int& exp,int N)
{   int index=0;
    while(str.length()>0 && str[0]=='0') //去掉前导0
        str.erase(str.begin());
    if(str[0]=='.')
    {   //去掉前导0后是小数点，说明str是小于1的数字
        str.erase(str.begin());
        while(str.length()>0 && str[0]=='0') //去掉小数点后非零位前的所有0
        {   str.erase(str.begin());
            exp--;
        }
    } 
    else
    {   while(index<str.length() && str[index]!='.')
        {   index++;
            exp++;
        }
        if(index<str.length()) //遇到小数点了
            str.erase(str.begin()+index); //删掉小数点
    }
    
    if(str.length()==0) //原数为0
        exp=0;
    string res;
    index=0; //索引清0
    for(int num=0;num<N;num++) //精度不够时
    {   if(index<str.length()) res+=str[index++];
        else res+='0'; //不够的话添0  
    }
    return res;
}

int main()
{   int N,expA=0,expB=0;
    string A,B,s1,s2;
    cin>>N>>A>>B;
    s1=deal(A,expA,N);
    s2=deal(B,expB,N);
    
    if(s1==s2 && expA==expB)
        cout<<"YES 0."<<s1<<"*10^"<<expA;        
    else
        cout<<"NO 0."<<s1<<"*10^"<<expA<<" 0."<<s2<<"*10^"<<expB;
   return 0;
}
  