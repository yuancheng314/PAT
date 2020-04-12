#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> num;
int main()
{   int N1,N2,now;
    scanf("%d",&N1);
    for(int i=0;i<N1;i++)
    {
        scanf("%d",&now);
        num.push_back(now);
    }
    scanf("%d",&N2);
    for(int i=0;i<N2;i++)
    {
        scanf("%d",&now);
        num.push_back(now);
    }
    sort(num.begin(),num.end());
    int size=N1+N2;
    printf("%d",size%2==0 ? num[size/2-1]:num[size/2]);

    return 0;
}