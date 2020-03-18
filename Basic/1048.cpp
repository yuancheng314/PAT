#include<iostream>
#include<algorithm>
using namespace std;

int main()
{   string A,B,res;
    char num[14]={"0123456789JQK"};

    cin>>A>>B;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    
    int len1=A.length(),len2=B.length();
    if(len1>len2)   B+=string(len1-len2,'0'); 
    else           A+=string(len2-len1,'0');

    for(int i=0;i<A.length();i++)
    {   if(i%2==0) //下标从0开始，故实际开始位为奇数  
            res+=num[(A[i]-'0'+B[i]-'0')%13];
        else
             res+=B[i]-A[i]>=0 ? num[B[i]-A[i]] : num[B[i]-A[i]+10];
    }

    reverse(res.begin(),res.end());
    cout<<res;
    return 0;
}