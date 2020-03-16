#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{   int N,K,cnum,cid;
    const int MAX=2501;
    string sname;
    vector<string>course[MAX];
    
    scanf("%d %d",&N,&K);
    for(int i=0;i<N;i++)
    {   
        cin >> sname >> cnum;        
        for(int j=0;j<cnum;j++)
        {    scanf("%d",&cid);
             course[cid].push_back(sname);
        }
    }

    for(int i=1;i<=K;i++)
    {   sort(course[i].begin(),course[i].end());
        printf("%d %lu\n",i,course[i].size());
        for(int j=0;j<course[i].size();j++)
            printf("%s\n",course[i][j].c_str());
    }

    return 0;
}