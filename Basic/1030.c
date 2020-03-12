#include<stdio.h>

void QuickSort(int *num,int start,int end)
{   if(start>=end) { return; }   
    int flag=num[start],i=start,j=end;
    while(i<j)
    {   while(i<j && num[j]>=flag) 
        {   j--;    }
        num[i]=num[j];
        while(i<j && num[i]<=flag) 
        {   i++;    }
        num[j]=num[i];
    }
    num[i]=flag;

    QuickSort(num,start,i-1);
    QuickSort(num,i+1,end);   
}
int main()
{
    int N;
    long p;
    scanf("%d %ld",&N,&p);
    int num[N], max_len=1;
    for(int i=0;i<N;i++) { scanf("%d",&num[i]); }  /*read*/
    QuickSort(num,0,N-1);   /*sort*/
   
    for(int i=0;N-i > max_len;i++)  /*find*/
    {   for(int j=N;j>0 && j-i>max_len ;j--)
        {   if(num[j-1]<=num[i]*p && j-i>max_len)
            {   max_len = j-i ;  
                break;            
            }  
        }
        if(max_len==N) break;
    }
    printf("%d",max_len); /*print*/

    return 0;
}