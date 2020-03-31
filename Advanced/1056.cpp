#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;

struct Mice {   int weight,num,rank,init; };
bool cmp1(Mice a,Mice b)  {   return a.num<b.num;     }
bool cmp2(Mice a,Mice b)  {   return a.init<b.init;     }
    
int main()
{   int Np,Ng,temp;
    scanf("%d %d",&Np,&Ng);
    Mice mice[Np];

    for(int i=0;i<Np;i++)
    {   scanf("%d",&mice[i].weight);
        mice[i].init=i;
    }
    for(int i=0;i<Np;i++)
    {    scanf("%d",&temp);
         mice[temp].num=i;
    }
    sort(mice,mice+Np,cmp1);

    queue<Mice> q;
    for(int i=0;i<Np;i++)
    {    q.push(mice[i]);
    } 

   while(!q.empty())
    {   int size=q.size();
        if(size==1)//冠军就是他了
        {      
            mice[q.front().num].rank=1;
            break;
        }
        int group = size%Ng ? size/Ng+1 :size/Ng; //计算当前轮次应分的组数
        int count=0,maxweight=-1;
        Mice tempmice,weight_mice;
        for(int i=0;i<size;i++)
        {
            tempmice=q.front();
            mice[tempmice.num].rank=group+1;
            q.pop();
            count++;
            if(tempmice.weight>maxweight)
            {  maxweight=tempmice.weight;
               weight_mice=tempmice;
            }
            if(count==Ng || i==size-1 ) //处理了整整一组Mice或者处理完当前队列轮次中最后一只Mice
            {   q.push(weight_mice);
                count=0;
                maxweight=-1;
            }
        }
    }

    sort(mice,mice+Np,cmp2);
    for(int i=0;i<Np;i++)
    {   if(i!=0)    printf(" ");
           cout<<mice[i].rank;   
     
    }    

    return 0;
}