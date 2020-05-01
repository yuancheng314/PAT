#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct station  {      double dis,pri;    };

bool cmp(station a,station b)   {   return  a.dis<b.dis;    }

int main()
{   double C,D,Davg;
    int N;

    cin>>C>>D>>Davg>>N;
    vector<station> sta(N+1);
    double Dmax=C*Davg,totalprice=0.0,totaldis=0.0;
    //Dmax代表满油情况下能走的最远路程
    //录入加油站信息
    for(int i=0;i<N;i++)  {   scanf("%lf %lf",&sta[i].pri,&sta[i].dis);   }
    //增设虚拟加油站，油价为0，距离为最大距离
    sta[N].pri=0.0;
    sta[N].dis=D;
    sort(sta.begin(),sta.end(),cmp); //按离起点的距离从近到远排序

    for(auto it=sta.begin();it!=sta.end();it++)
    {   cout<<(*it).dis<<" "<<(*it).pri<<endl;   }

    if(sta[0].dis!=0) {   cout<<"The maximum travel distance = 0.00"; return 0;}
    //否则继续前进

    int now=0,i,suitid;//nowtank表示现在tank中的余油量
    double need=0.0,nowtank=0.0,add=0.0;
    //suitid表示下一个要去的站点

    while(totaldis<D)
    {   if(sta[now+1].dis-sta[now].dis>Dmax)    
        {   printf("The maximum travel distance = %.2f",sta[now].dis+Dmax);
            //当前station到下一个station距离太远了，那就在当前station加满油向前冲吧
            return 0; 
        }
        suitid=now+1; //能走到下一个加油站，那先调整下suitid到下一个加油站
        for( i=now+1;i<=N && sta[i].dis-sta[now].dis<=Dmax ;i++)
        //找到第一个低于当前station价格的加油站或者不能继续前进时退出循环
        {   if(sta[i].pri<sta[now].pri) //下一个站更便宜，那么在当前站点加到够走到下个站点的油就行了
            {   suitid=i;
                need=(sta[suitid].dis-sta[now].dis)/Davg;   
                cout<<"nowtank:"<<nowtank<<" need:"<<need;
                if(nowtank>=need)//下个suit station便宜，余油也够到那儿，那就不加油直接走呗 
                {  add=0.0;
                }
                else add=need-nowtank;

                break;  
            }   
            else if(sta[i].pri<sta[suitid].pri) //下一个站会更贵，那么在当前站点加满
            {   suitid=i;
                add=C-nowtank;
            }    
            
        }
       
        //if(suitid==now)//也即没有找到符合
       

        totalprice+=sta[now].pri*add;
        totaldis=sta[suitid].dis;        
        nowtank=nowtank+add-(sta[suitid].dis-sta[now].dis)/Davg;

        cout<<now<<" "<<"add:"<<add<<" nowtank:"<<nowtank<<" "<<suitid<<endl;
        now=suitid; //更新suitid和余油量
        //余油量为当初的余油量加在当前站点加的油减去为了到下一个加油站，路程中耗去的油
        
        
    }

    printf("\n%.2f",totalprice);


    return 0;
}