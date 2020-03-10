#include"stdio.h"
struct student
{
/*为什么保存10个字符串需要11个空间？
ANS:字符串要多1个用来存放’\0’（结束标识符）
*/
 char name[11];
 char id[11];
 int score;
};

int main()
{   
    int n;
    scanf("%d",&n);
    struct student stu[n];
    for(int i=0;i<n;i++)
    {   scanf("%s %s %d",&stu[i].name,&stu[i].id,&stu[i].score);
    }
    int max=0,min=0;
    for(int i=1;i<n;i++)
    {   if(stu[i].score<stu[min].score){min=i;}
        if(stu[i].score>stu[max].score){max=i;}
    }
    printf("%s %s\n",stu[max].name,stu[max].id);
    printf("%s %s",stu[min].name,stu[min].id);
    return 0;
}