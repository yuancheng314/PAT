#include<iostream>
#include<algorithm>
using namespace std;
int main()
{   int N,need=0,count=0,index=1,num;//need记录当前状态除0以外不在本位的数字，count记录已经交换的次数
    scanf("%d",&N);
    int pos[N];
    for(int i=0;i<N;i++)
    {   scanf("%d",&num);
        // if(pos[i]==0)  zero=i;
        pos[num]=i; //数字num现在保存在第i位
        if(num !=i && num!=0)  need++;
    }
    
    while(need>0)
    {   while(pos[0]!=0) //0不在属于他的位置   
        {   swap(pos[0],pos[pos[0]]);
            count++;
            need--;
        }        

        if(pos[0]==0)//找到第一个不在本位的数字，将其与0交换
        {   while(index<N)
            {   if(pos[index]!=index)
                {   swap(pos[0],pos[index]);
                    count++;
                    break;
                }
                index++;
            }

        }


    }    

    printf("%d",count);

    return 0;
}