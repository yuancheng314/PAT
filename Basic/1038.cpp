#include<iostream>
#include<vector>
using namespace std;
int main()
{   int N,K,score;
    scanf("%d",&N);
    vector<int> grade(101);     
    while(N--)
    {   scanf("%d",&score);
        grade[score]++;
    }
    scanf("%d",&K);
    for(int i=0;i<K;i++)
    {   scanf("%d",&score);   
        if(i!=0) printf(" ");
        printf("%d",grade[score]);
    }

    return 0;
}