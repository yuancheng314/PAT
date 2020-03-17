#include<cstdio>
#include<iostream>
#include<map>
using namespace std;

int main()
{   map<int,int> color;
    int M,N, a;
    scanf("%d %d",&M,&N);
    int half=M*N/2;
    for(int i=0;i<M*N;i++)
    {    scanf("%d",&a);
         color[a]++;
        /* if(color[a]>half)
         {  cout<<a; return 0;  }
         让这两行生效然后删掉后面的也能AC，但并没有输入完 */
    }

    int max=0;
    int res;
    for(map<int,int>::iterator it=color.begin();it!=color.end();it++)
        if(it->second>max) 
        {   max=it->second;
            res=it->first;
        }
    cout<<res;
    return 0;
}
   