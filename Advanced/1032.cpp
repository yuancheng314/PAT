#include<iostream>
using namespace std;
struct NODE{
    char data;
    int next,flag=false;
}node[100001];

int main()
{   int s1,s2,N,address,next;
    char data;
    scanf("%d %d %d",&s1,&s2,&N);
    for(int i=0;i<N;i++)
    {
        scanf("%d %c %d",&address,&data,&next);
        node[address].data=data;
        node[address].next=next;
    }

    for(int i=s1;i!=-1;i=node[i].next) //将第一条链中出现过的字母的flag改为true
        node[i].flag=true;
    for(int i=s2;i!=-1;i=node[i].next)
        if(node[i].flag==true) //从第二条链中找到在第一条链中出现过的第一个字母
        {
            printf("%05d",i);
            return 0;
        }
    printf("-1");

    return 0;
}