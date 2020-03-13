#include<cstdio>
#include<cstring>
#define MOD 1000000007

int main()
{   const int MAX=100001;
    char str[MAX];
    int leftP[MAX]={0},ans=0,rightT=0;

    scanf("%s",str);
    int len=strlen(str);
    for(int i=0;i<len;i++)
    {   if(i>0)
        {  leftP[i]=leftP[i-1]; }
        if(str[i]=='P')
        {   leftP[i]++;    }
    }
    for(int i=len-1;i>=0;i--)
    {   if(str[i]=='T')
        {   rightT++;   }
        else if(str[i]=='A')
        {   ans=(ans+leftP[i]*rightT) % MOD; }
    }

    printf("%d",ans);
    return 0;
}
