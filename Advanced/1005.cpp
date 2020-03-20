#include<iostream>
using namespace std;
int main()
{   string a,num[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};
    cin>>a;
    int sum=0,res[10],count=0;
    for(int i=0;i<a.length();i++)
        sum+=a[i]-'0';
    while(sum/10)
    {   res[count++]=sum%10;
        sum/=10;
    }
    cout<<num[sum];
    for(int i=count-1;i>=0;i--)
        cout<<" "<<num[res[i]];

    return 0;
}