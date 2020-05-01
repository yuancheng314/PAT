#include<iostream>
#include<vector>
using namespace std;
//按节处理
int main()
{   string danwei[5]={"Shi","Bai","Qian","Wan","Yi"};
    string shuzi[10]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

    int N,part[3];
    cin>>N;
    if(!N)  { cout<<"ling";  return 0; }
    if(N<0) { cout<<"Fu";   N=-N;   }
    part[0]=N/100000000;
    part[1]=N%100000000/10000;
    part[2]=N%10000;

    for(int i=0;i<3;i++)
    {   int temp=part[i]; //三节内部规则一样，只需在不同的节添加亿、万、啥也不添
        for(int j=3;j>=0;j--) 
        {   int curPos=8-4*i+j;
            if(curPos>=9)   continue;//最多也就九位数
            


        }


    }
    
    return 0;
}