#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int main()
{   int N,count=0;
    string s,info,pass,user[1000],pwd[1000];
    cin>>N;
    for(int i=0;i<N;i++)
    {   cin>>info>>pass;
        if(pass.find("0")!=-1 ||pass.find("1")!=-1||pass.find("l")!=-1 ||pass.find("O")!=-1 )
        {   user[count]=info;
            replace(pass.begin(),pass.end(),'1','@');
            replace(pass.begin(),pass.end(),'0','%');
            replace(pass.begin(),pass.end(),'l','L');
            replace(pass.begin(),pass.end(),'O','o');
            pwd[count++]=pass;
        }
    }
    if(!count) 
    {   if(N>=2) cout<<"There are "<<N<<" accounts and no account is modified";
        else cout<<"There is 1 account and no account is modified";
    }
        
    else
    {   cout<<count<<endl;
        for(int i=0;i<count;i++)
            cout<<user[i]<<" "<<pwd[i]<<endl;
    }
    
    return 0;
}