#include<cstdio>
#include<iostream>
using namespace std;

struct Examer
{   char id[17];
    int test,exam;
};

int main()
{   int N,M;
    cin>>N;
    Examer ex[N];
    for(int i=0;i<N;i++)
    {   scanf("%s %d %d",&ex[i].id,&ex[i].test,&ex[i].exam);
    }

    cin>>M;
    int find[M];
    for(int i=0;i<M;i++)
    {   cin>>find[i];  }
    
    for(int i=0;i<M;i++)
    {   for(int j=0;j<N;j++)
        {   if(find[i]==ex[j].test)
            {   cout<<ex[j].id<<" "<<ex[j].exam<<endl;
                 break;
            }   
        }
    }

    return 0;
}
