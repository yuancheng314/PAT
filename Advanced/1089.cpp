#include<iostream>
#include<algorithm>
using namespace std;

int main()
{   int N,init[100],mid[100];
    cin>>N;
    for(int i=0;i<N;i++)
    {   scanf("%d",&init[i]);      
    }
    for(int i=0;i<N;i++)
    {   scanf("%d",&mid[i]);     }

    int i,j;
    for( i=0;i<N && mid[i]<=mid[i+1];i++);
    for( j=i+1;init[j]==mid[j] && j<N ;j++);
    if(j==N) //0～i有序，i+1～N第一行等于第二行，说明这是插入排序
    {   cout<<"Insertion Sort\n"; 
        sort(init,init+i+2);
    } else
    {    cout<<"Merge Sort\n";
         int k=1,flag=1,i,j;
         while(flag)
         {  flag=0;
            for(i=0;i<N;i++)
            {   if(init[i]!=mid[i]) 
                //如果init[i]一直等于mid[i]，flag不能重新变为1，说明下一轮merge后，就该输出了
                    flag=1;   
            }
            k*=2;
            for(j=0;j<N/k;j++) // （int）N/k+1所得值即为需要merge的段的个数
                sort(init+j*k,init+(j+1)*k);
            sort(init+j*k,init+N); //merge 最后一组
         }
    }
       
    for(int m=0;m<N;m++)
    {   if(m!=0)    printf(" ");
        printf("%d",init[m]);                
    }

    return 0;
}