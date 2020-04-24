#include<iostream>
using namespace std;
int main()
{
    long long n,temp;
    int num=0,high,low,now,base=1;
    cin>>n;
    
    while(n/base!=0)
    {
    	low=n%base;
    	high=n/base/10;
    	now=n/base%10;
    	if(now==0)	num+=high*base;
    	else if (now==1) 	num+=high*base+low+1;
    	else num+=(high+1)*base;
    	 base*=10;
	}
//	  注释的为暴力解法，会超时，得22分 
//    for(int i=1;i<=n;i++)
//    {   temp=i;
//        while(temp>=1)
//        {
//            if(temp%10==1)  num++;
//            temp/=10;
//        }
//    }
    cout<<num;
    return 0;
}
