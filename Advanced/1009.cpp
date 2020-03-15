#include<cstdio>
#include<iostream>

using namespace std;

int main()
{   double fx[1001]={0.0},gx[1001]={0.0},hx[2001]={0.0},coe;
    int k1,k2,exp,count=0;
    cin>>k1;
    for(int i=1;i<=k1;i++)
    {   cin>>exp>>coe;
        fx[exp]=coe;
    }
    cin>>k2;
    for(int i=1;i<=k2;i++)
    {   cin>>exp>>coe;
        gx[exp]=coe;
    }

    for(int i=0;i<=1000;i++)
    {   for(int j=0;j<=1000;j++)
        {   hx[i+j]+=fx[i]*gx[j];
        }
    }
    
    for(int i=0;i<2001;i++)
    {   if(hx[i])  count++; }
    cout<<count;
    for(int i=2000,j=0;j<=count &&i>=0;i--)
    {   if(hx[i])  
        {
            printf(" %d %.1f",i,hx[i]); 
            j++ ;
        }
    }

    return 0;
}
