#include<iostream>
#include<algorithm>
using namespace std;

int flag=0;
struct student
{   int id,best,score[4],rank[4]; };

bool cmp(student a,student b)
{   return a.score[flag]>b.score[flag]; }


int main()
{   int N,M,id,ID[1000000]={0};
   // map<string,student> stu;
    char r[5]={"ACME"};
    
    scanf("%d%d",&N,&M);
    student stu[N];
  
    for(int i=0;i<N;i++) //读入数据
    {   scanf("%d%d%d%d",& stu[i].id,& stu[i].score[1],&stu[i].score[2],&stu[i].score[3]);
        stu[i].score[0]=(stu[i].score[1]+stu[i].score[2]+stu[i].score[3])/3.0+0.5;
    }

    for(flag=0;flag<4;flag++) //确定每科排名
    {   sort(stu,stu+N,cmp);
        stu[0].rank[flag]=1;
        for(int i=1;i<N;i++)
        {   stu[i].rank[flag]=stu[i-1].rank[flag];
            if(stu[i].score[flag]!=stu[i-1].score[flag])
                stu[i].rank[flag]=i+1;
        }
    }
    int min=N;
    for(int i=0;i<N;i++)
    {   ID[stu[i].id]=i+1;  //建立映射关系
        min=N;
        for(int j=0;j<4;j++)
        {   if(stu[i].rank[j]<min)
            {   min=stu[i].rank[j];
                stu[i].best=j;
            }
        }
    
    }
    
    for(int i=0;i<M;i++)
    {   scanf("%d",&id);
        int temp=ID[id];
        if(temp)
        {   
            int best_subject=stu[temp-1].best;
            printf("%d %c\n",stu[temp-1].rank[best_subject],r[best_subject]);
        }
        else printf("N/A\n");
    }

    return 0;
}