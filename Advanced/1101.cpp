#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{   int N,piovt[100000],max=-1,count=0;
    scanf("%d",&N);
    vector<int> a(N),b(N);
    for(int i=0;i<N;i++)
    {   scanf("%d",&a[i]);
        b[i]=a[i]; //拷贝一份输入的数字序列
    }

    sort(a.begin(),a.end());
    for(int i=0;i<N;i++)
    {   if(a[i]==b[i] && b[i]>max)
        {   piovt[count++]=b[i];    }
        if(b[i]>max)
        {   max=b[i];   }
    }
    
    printf("%d\n",count);
    for(int i=0;i<count;i++)
    {   if(i>0) {   printf(" ");   }   
        printf("%d",piovt[i]); 
    }
   printf("\n");
    return 0;
}