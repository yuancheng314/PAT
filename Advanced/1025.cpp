#include<cstdio>
#include<algorithm>
using namespace std;

struct Student
{   long long re_num;
    int score,fina_r,loc_num,loc_r;
};

bool cmp(Student a,Student b)
{   return a.score!=b.score ? a.score>b.score : a.re_num<b.re_num;
}

int main()
{   int N,K,count=0,total=0; //total+1 records the number of stu
    Student stu[30001];

    scanf("%d",&N); //read
    for(int i=1;i<=N;i++)
    {   scanf("%d",&K);

        for(int j=0;j<K;j++,count++)
        {   scanf("%lld%d",&stu[count].re_num,&stu[count].score); 
            //record sut's re_num , score and loc_num;
            stu[count].loc_num=i;
        }

        sort(stu+(total),stu+(K+total),cmp);//对这个考场的K个人排名得到loc_r
        stu[total].loc_r=1;
        for(int n=total+1;n<total+K;n++)
        {   if(stu[n].score==stu[n-1].score)
            {   stu[n].loc_r=stu[n-1].loc_r;   }
            else 
            {   stu[n].loc_r=(n-total+1);   }
        }

        total+=K; //增加stu的数量
    }

    sort(stu,stu+total,cmp); //sort

    printf("%d\n",total);
    int fina_r=1;
    for(int i=0;i<total;i++) //display
    {   if(i>0 && stu[i].score==stu[i-1].score)     {  stu[i].fina_r= stu[i-1].fina_r;  } 
        else        {   stu[i].fina_r = i+1; }
        
        printf("%013lld %d %d %d\n",stu[i].re_num,stu[i].fina_r,stu[i].loc_num,stu[i].loc_r);
    }
    
    return 0;
}
