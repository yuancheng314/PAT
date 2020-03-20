#include<iostream>
//#include<string>
#include<algorithm>
using namespace std;
int main()
{   int N,count=0;
    cin>>N;
    string scen,res;
    getchar();

    for(int i=0;i<N;i++)
    {   getline(cin,scen);
        reverse(scen.begin(),scen.end());
        if(i==0)    res=scen;
        else
        {   for(int j=0;j<scen.length() && j<res.length() ;j++)
                if(scen[j]!=res[j])
                {   res=scen.substr(0,j);
                    break;
                }
        }
    }

    if(res.length()==0) {   cout<<"nai";    return 0;   }   
    reverse(res.begin(),res.end());
    cout<<res;

    return 0;
}