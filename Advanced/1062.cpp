#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

struct  student
{   int id,vir,tal,sum;
};

bool cmp(student a,student b)
{   if(a.vir+a.tal!=b.vir+b.tal)
        return   a.vir+a.tal>b.vir+b.tal;
    else if(a.vir!=b.vir)
        return a.vir>b.vir;
    else 
        return a.id<b.id;
}

int main()
{   int N,L,H;
    student test;
    vector<student> stu[4];
    scanf("%d%d%d",&N,&L,&H);
    int count=N;
    for(int i=0;i<N;i++)
    {   scanf("%d%d%d",&test.id,&test.vir,&test.tal);
        if(test.vir<L || test.tal<L)
            count--;
        else if(test.vir>=H && test.tal>=H)
            stu[0].push_back(test);
        else if(test.vir>=H && test.tal<H)
            stu[1].push_back(test);
        else if(test.vir<H && test.tal<H && test.vir>=test.tal)
            stu[2].push_back(test);
        else 
            stu[3].push_back(test);
    }
    printf("%d\n",count);
    for(int i=0;i<4;i++)
    {   sort(stu[i].begin(),stu[i].end(),cmp);
        for(int j=0;j<stu[i].size();j++)
            printf("%d %d %d\n",stu[i][j].id,stu[i][j].vir,stu[i][j].tal);
    }

    return 0;
}