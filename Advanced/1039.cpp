#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int getID(char sname[])
{   int id=0;
    for(int i=0;i<=2;i++)
        id=id*26+(sname[i]-'A');
    id=id*10+(sname[3]-'0');
    
    return id;
}

int main()
{   const int MAX=26*26*26*10+1;
    vector<int> stu_cou[MAX];
    int N,K,cid,cnum;
    char sname[5];

    scanf("%d%d",&N,&K);
    for(int i=0;i<K;i++)
    {   scanf("%d %d",&cid,&cnum);
        for(int j=0;j<cnum;j++)
        {   scanf("%s",sname);
            stu_cou[getID(sname)].push_back(cid);
        }
    }
    
    int sid;
    for(int i=0;i<N;i++)
    {   scanf("%s",sname);
        sid=getID(sname);
        sort(stu_cou[sid].begin(),stu_cou[sid].end());
        printf("%s %lu",sname,stu_cou[sid].size());
        
        for(int j=0;j<stu_cou[sid].size();j++)
            printf(" %d",stu_cou[sid][j]);
        printf("\n");
    }

    return 0;
}
