#include<iostream>
#include<algorithm>
using namespace std;

const int maxn=1005;
int CBT[maxn],num[maxn],index=0,N;
void inOrder(int root){
    if(root>N)  return; //空节点，直接返回
    inOrder(2*root); //递归左子树
    CBT[root]=num[index++]; //根节点处赋值number[index]
    inOrder(2*root+1); //递归右子树
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)
        scanf("%d",&num[i]);
    sort(num,num+N);
    inOrder(1);

    printf("%d",CBT[1]);
    for(int i=2;i<=N;i++)
        printf(" %d",CBT[i] );

    return 0;
}
