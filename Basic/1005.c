#include"stdio.h"
/* 最开始拿到这道题想尝试用结构体求解，结构体中第一个元素为输入的数字，第二个数字为
输入数字进行3n+1猜想分解过程中的每一步，然后如果该数组中的数字在原始输入的哪一组数中
出现，则该结构体中的数字不是关键数,然后写了一堆代码，发现太复杂了，后期还涉及排序，更
复杂了，题上最大数字不超过100，且还互不重复，一个大小为100的int数组就可解决，所谓覆盖，
直接置零就完事
 */
int main()
{
    int K,cur,num[101]={0}; 
    //输入的过程
    /*只使用num的第2-101个位置，恰好100个;cur 表示当前读入的数字*/
    scanf("%d",&K);
  
    for(int i=0;i<K;i++)
    {   scanf("%d",&cur);
        num[cur]=1;
    }

    //覆盖的过程
    for(int i=1;i<=100;i++)
    {   if(num[i])
        {   for(int j=i;j>1;)
            /*将i的值赋给j,对j进行3n+1猜想*/
            {   if(j%2){ j=(3*j+1)/2 ;}
                else {j/=2;}
                //判断每操作一步后更新的j值是否被覆盖
                if(j<=100&&num[j])
                /*这一步比较关键，首先得判断j是否小于100，否则若直接判断num[j]可能出现数组越界
                eg. j=81==》j=122 发生越界*/
                {   num[j]=0; //用置0的方式表示该数被覆盖，最后剩下的数自然就是关键数了
                    K--;//表示还剩余的未被覆盖的数字，后面会用K来控制输出结构
                    if(j<i) { break; } //减小时间复杂度的关键一步，不过也比较难以理解
                }
            }

        }
    
    }

    //输出的过程
    
    for(int i=100;i>=1;i--) //要求按从大到小的顺序输出，将数组倒过来即可
    {   if(num[i])
        { 
            printf("%d%c", i, --K ? ' ' : '\0');
            /*PTA的输出格式经常是要求数字与数字之间以空格隔开，最后一个输出不带空格*/
        }
    }

    return 0;
}



