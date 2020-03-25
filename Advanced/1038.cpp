#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(string a,string b)
{   return a+b<b+a; }
int main()
{   int N,temp;
    string res;
    cin>>N;
    vector<string> num(N);
    for(int i=0;i<N;i++)
    {   cin>>num[i];
    }
    sort(num.begin(),num.end(),cmp);

    for(int i=0;i<N;i++)
    {   
        res+=num[i];
    }
    while(res[0]=='0'&&res.length()>0)   
    {   res.erase(res.begin());   
    }
    if(res.length()==0)     cout<<0;
    else    cout<<res;
    
    return 0;
}