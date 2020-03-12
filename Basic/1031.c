#include <stdio.h>

int main()
{   int N,count=0,num=0,sum=0;
    /*count用于保存通过检验的身份证号码
      num用于保存符合规则的已判别的位数，
      sum用于保存权重和
    */
    int weight[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
    char suppose[11]={'1','0','X','9','8','7','6','5','4','3','2'};
    char id[19]; //存储字符串的数组一定比字符串长度多一个元素，以容纳下字符串终止符（空字符'\0'）
    scanf("%d",&N);
    for(int i=0;i<N;i++) 
    {   scanf("%s",id);
        for(num=0,sum=0; num< 17 && id[num] >= '0' && id[num] <= '9'; num++)
        { sum+=(id[num]-'0')*weight[num];} //注意id中保存的是char类型，对其中的数字进行运算时应先减去０的ascii码
        if(num==17&&id[17]==suppose[sum%11]) { count++; }
        else {puts(id);}
    }
    if(count==N){printf("All passed");}
    return 0;
}