#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;

int main()
{   int M;
    string id,b,c,unlock,lock,earlist,latest;
 
    cin>>M>>id>>earlist>>latest;
    lock=unlock=id; //将初值都赋为第一个的签到签退时间
    for(int i=1;i<M;i++)
    {   cin>>id>>b>>c;
        if(b<earlist) 
        {   unlock=id;
            earlist=b;    
        }
        if(c>latest)   
        {   lock=id;
            latest=c;    
        }    
    }

    cout<<unlock<<" "<<lock;
    return 0;
}
