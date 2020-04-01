#include<iostream>
#include<algorithm>
#include<vector>
#define max 100001
using namespace std;

struct NODE{
  int address,key,next;
  bool flag=false;
}node[max];

bool cmp(NODE a,NODE b)
{   return !a.flag || !b.flag ? a.flag > b.flag : a.key < b.key;    }

int main()
{   int N,head,address,key,next,count=0;
    scanf("%d %d",&N,&head);
     
    for(int i=0;i<N;i++)
    {   scanf("%d",&address);
        scanf("%d%d",&node[address].key,&node[address].next);
        node[address].address=address;
    }
  
    for(int p=head;p!=-1;p=node[p].next)
    {   node[p].flag=true;
        count++;
    }
    if(!count)  
    {   printf("0 -1");
        return 0;

    }
    sort(node,node+max,cmp);
    printf("%d %05d\n",count,node[0].address);
    for(int i=0;i<count;i++)
    {   if(i!=count-1)  printf("%05d %d %05d\n",node[i].address,node[i].key,node[i+1].address);   
        else   printf("%05d %d -1",node[i].address,node[i].key);
    }

    return 0;
}