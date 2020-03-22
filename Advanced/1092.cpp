#include<iostream>
#include<string>
using namespace std;
int main()
{   string a,b;
    cin>>a>>b;
    int more=0,less=0, len1=a.length(),len2=b.length(),hash[128]={0};
    for(int i=0;i<len1;i++)
        hash[a[i]]++;
    for(int i=0;i<len2;i++)
        hash[b[i]]--;
    for(int i=0;i<128;i++)
    {   if(hash[i]>=0)   more+=hash[i];
        else       less-=hash[i];
    }
    if(less)    cout<<"No "<<less;
    else        cout<<"Yes "<<more;

    return 0;
}