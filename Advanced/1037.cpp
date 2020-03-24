#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{   int Nc,Np;
    long long sum=0;

    scanf("%d",&Nc);
    vector<int> cou(Nc);
    for(int i=0;i<Nc;i++)
        scanf("%d",&cou[i]);
    sort(cou.begin(),cou.end());

    scanf("%d",&Np);
    vector<int> pro(Np);
    for(int i=0;i<Np;i++)
        scanf("%d",&pro[i]);
    sort(pro.begin(),pro.end());

    for(int i=Nc-1,j=Np-1;cou[i]>0 && pro[j]>0 ;i--,j--)
        sum+=cou[i]*pro[j];
    for(int i=0,j=0;cou[i]<0 && pro[j]<0 ;i++,j++)
        sum+=cou[i]*pro[j];
    printf("%lld",sum);

    return 0;
}