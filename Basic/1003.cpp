#include<iostream>
#include<map>
using namespace std;

int main()
{   int n,p=0,t=0;
    string s;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s;
        map<char,int> m;
        for(int j=0;j<s.length();j++)
        {
            m[s[j]]++;
            if(s[j]=='P') p=j;
            else if( s[j]=='T') t=j;
        }
        if(m['P']==1 &&m['T']==1&& m['A']!=0&&m.size()==3&& t-p!=1 && p*(t-p-1) == s.length()-t-1)
            cout<<"YES\n";
        else    cout<<"NO\n";
    }
    return 0;
}