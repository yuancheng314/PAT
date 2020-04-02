#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int N,K,P;
vector<int> fac,ans,temp;
int nowpow=0,nowk=0,base=1,nowsum=0,maxfacsum=-1;

bool dfs(int base,int nowk,int nowsum,int facsum)
{   if(nowk==K && nowsum==N )//完结撒花 
    {
        if(facsum>maxfacsum)
        {    ans=temp;  
             maxfacsum=facsum;
        }        
        return true;
    }
    if(nowsum>N || nowk>K)  return false;

    if(base>=1) //还能继续
    {   temp.push_back(base);
        dfs(base,nowk+1,nowsum+fac[base],facsum+base); //试试
        temp.pop_back(); //不选
        dfs(base-1,nowk,nowsum,facsum);        
    }    
}

int main()
{   
    scanf("%d%d%d",&N,&K,&P);
        
    while(nowpow<=N)
    {    fac.push_back(nowpow);
         nowpow=pow(base++,P);
    }    
    
    bool res=dfs(fac.size()-1,0,0,0);//
    
    if(maxfacsum==-1)    {   cout<<"Impossible"; }
    else
    {   printf("%d = ",N);
        for(  int i=0; i<ans.size()  ; i++  )
        {   if(i!=0)    printf(" + ");
            cout<< ans[i]<<"^"<<P;
        }
    }  

    return 0;
}